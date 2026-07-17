// Open-Meteo API access and weather-code artwork mapping

void do_geocode_query(const char *q) {
  geoDoc.clear();
  String url = String("https://geocoding-api.open-meteo.com/v1/search?name=") + urlencode(q) + "&count=15";

  HTTPClient http;
  http.useHTTP10(true);  // no chunked encoding, so the body can be parsed as a stream
  http.begin(url);
  if (http.GET() == HTTP_CODE_OK) {
    Serial.println("Completed location search at open-meteo: " + url);
    auto err = deserializeJson(geoDoc, http.getStream());
    if (!err) {
      geoResults = geoDoc["results"].as<JsonArray>();
      populate_results_dropdown();
    } else {
        Serial.println("Failed to parse search response from open-meteo: " + url);
    }
  } else {
      Serial.println("Failed location search at open-meteo: " + url);
  }
  http.end();
}

void fetch_and_update_weather() {
  if (WiFi.status() != WL_CONNECTED) {
    // Reconnect with a bounded wait; never fall back to the blocking captive
    // portal from here — this runs in the UI loop, so just skip this update.
    Serial.println("WiFi no longer connected. Attempting to reconnect...");
    WiFi.reconnect();
    uint32_t start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < WIFI_RECONNECT_TIMEOUT_MS) {
      delay(250);
    }
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi connection still unavailable. Skipping this update.");
      return;
    }
    Serial.println("WiFi connection reestablished.");
  }

  String url = String("http://api.open-meteo.com/v1/forecast?latitude=")
               + latitude + "&longitude=" + longitude
               + "&current=temperature_2m,apparent_temperature,is_day,weather_code"
               + "&daily=temperature_2m_min,temperature_2m_max,weather_code"
               + "&hourly=temperature_2m,precipitation_probability,is_day,weather_code"
               + "&forecast_hours=7"
               + "&timezone=auto";
  if (use_fahrenheit) {
    url += "&temperature_unit=fahrenheit";
  }

  HTTPClient http;
  http.useHTTP10(true);  // no chunked encoding, so the body can be parsed as a stream
  http.begin(url);

  if (http.GET() == HTTP_CODE_OK) {
    Serial.println("Updated weather from open-meteo: " + url);

    // Parse straight from the stream, keeping only the fields we use, to avoid
    // holding the full payload and document in RAM at once
    JsonDocument filter;
    filter["utc_offset_seconds"] = true;
    filter["current"]["temperature_2m"] = true;
    filter["current"]["apparent_temperature"] = true;
    filter["current"]["is_day"] = true;
    filter["current"]["weather_code"] = true;
    filter["daily"]["time"] = true;
    filter["daily"]["temperature_2m_min"] = true;
    filter["daily"]["temperature_2m_max"] = true;
    filter["daily"]["weather_code"] = true;
    filter["hourly"]["time"] = true;
    filter["hourly"]["temperature_2m"] = true;
    filter["hourly"]["precipitation_probability"] = true;
    filter["hourly"]["is_day"] = true;
    filter["hourly"]["weather_code"] = true;

    JsonDocument doc;

    if (deserializeJson(doc, http.getStream(), DeserializationOption::Filter(filter)) == DeserializationError::Ok) {
      float t_now = doc["current"]["temperature_2m"].as<float>();
      float t_ap = doc["current"]["apparent_temperature"].as<float>();
      int code_now = doc["current"]["weather_code"].as<int>();
      int is_day = doc["current"]["is_day"].as<int>();

      const LocalizedStrings* strings = get_strings(current_language);

      int utc_offset_seconds = doc["utc_offset_seconds"].as<int>();
      configTime(utc_offset_seconds, 0, "pool.ntp.org", "time.nist.gov");
      Serial.print("Updating time from NTP with UTC offset: ");
      Serial.println(utc_offset_seconds);

      char unit = use_fahrenheit ? 'F' : 'C';
      lv_label_set_text_fmt(lbl_today_temp, "%.0f°%c", t_now, unit);
      lv_label_set_text_fmt(lbl_today_feels_like, "%s %.0f°%c", strings->feels_like_temp, t_ap, unit);
      lv_img_set_src(img_today_icon, choose_image(code_now, is_day));

      JsonArray times = doc["daily"]["time"].as<JsonArray>();
      JsonArray tmin = doc["daily"]["temperature_2m_min"].as<JsonArray>();
      JsonArray tmax = doc["daily"]["temperature_2m_max"].as<JsonArray>();
      JsonArray weather_codes = doc["daily"]["weather_code"].as<JsonArray>();

      int daily_count = min((int)times.size(), 7);
      for (int i = 0; i < daily_count; i++) {
        const char *date = times[i];  // "YYYY-MM-DD"
        if (!date || strlen(date) < 10) continue;
        int year = atoi(date + 0);
        int mon = atoi(date + 5);
        int dayd = atoi(date + 8);
        int dow = day_of_week(year, mon, dayd);
        const char *dayStr = (i == 0) ? strings->today : strings->weekdays[dow];

        float mn = tmin[i].as<float>();
        float mx = tmax[i].as<float>();

        lv_label_set_text_fmt(lbl_daily_day[i], "%s", dayStr);
        lv_label_set_text_fmt(lbl_daily_high[i], "%.0f°%c", mx, unit);
        lv_label_set_text_fmt(lbl_daily_low[i], "%.0f°%c", mn, unit);
        lv_img_set_src(img_daily[i], choose_icon(weather_codes[i].as<int>(), (i == 0) ? is_day : 1));
      }

      JsonArray hours = doc["hourly"]["time"].as<JsonArray>();
      JsonArray hourly_temps = doc["hourly"]["temperature_2m"].as<JsonArray>();
      JsonArray precipitation_probabilities = doc["hourly"]["precipitation_probability"].as<JsonArray>();
      JsonArray hourly_weather_codes = doc["hourly"]["weather_code"].as<JsonArray>();
      JsonArray hourly_is_day = doc["hourly"]["is_day"].as<JsonArray>();

      int hourly_count = min((int)hours.size(), 7);
      for (int i = 0; i < hourly_count; i++) {
        const char *date = hours[i];  // "YYYY-MM-DDTHH:MM"
        if (!date || strlen(date) < 16) continue;
        int hour = atoi(date + 11);
        String hour_name = hour_of_day(hour);

        float precipitation_probability = precipitation_probabilities[i].as<float>();
        float temp = hourly_temps[i].as<float>();

        if (i == 0) {
          lv_label_set_text(lbl_hourly[i], strings->now);
        } else {
          lv_label_set_text(lbl_hourly[i], hour_name.c_str());
        }
        lv_label_set_text_fmt(lbl_precipitation_probability[i], "%.0f%%", precipitation_probability);
        lv_label_set_text_fmt(lbl_hourly_temp[i], "%.0f°%c", temp, unit);
        lv_img_set_src(img_hourly[i], choose_icon(hourly_weather_codes[i].as<int>(), hourly_is_day[i].as<int>()));
      }
    } else {
      Serial.println("JSON parse failed on result from " + url);
    }
  } else {
    Serial.println("HTTP GET failed at " + url);
  }
  http.end();
}

// Map a WMO weather code to its large image and small icon in one place so the
// two can never fall out of sync
static WeatherArt choose_art(int code, int is_day) {
  switch (code) {
    // Clear sky
    case  0:
      return is_day
        ? WeatherArt{ &image_sunny, &icon_sunny }
        : WeatherArt{ &image_clear_night, &icon_clear_night };

    // Mainly clear
    case  1:
      return is_day
        ? WeatherArt{ &image_mostly_sunny, &icon_mostly_sunny }
        : WeatherArt{ &image_mostly_clear_night, &icon_mostly_clear_night };

    // Partly cloudy
    case  2:
      return is_day
        ? WeatherArt{ &image_partly_cloudy, &icon_partly_cloudy }
        : WeatherArt{ &image_partly_cloudy_night, &icon_partly_cloudy_night };

    // Overcast
    case  3:
      return { &image_cloudy, &icon_cloudy };

    // Fog / mist
    case 45:
    case 48:
      return { &image_haze_fog_dust_smoke, &icon_haze_fog_dust_smoke };

    // Drizzle (light → dense)
    case 51:
    case 53:
    case 55:
      return { &image_drizzle, &icon_drizzle };

    // Freezing drizzle
    case 56:
    case 57:
      return { &image_sleet_hail, &icon_sleet_hail };

    // Rain: slight showers & rain showers (slight → moderate)
    case 61:
    case 80:
    case 81:
      return is_day
        ? WeatherArt{ &image_scattered_showers_day, &icon_scattered_showers_day }
        : WeatherArt{ &image_scattered_showers_night, &icon_scattered_showers_night };

    // Rain: moderate
    case 63:
      return { &image_showers_rain, &icon_showers_rain };

    // Rain: heavy & rain showers: violent
    case 65:
    case 82:
      return { &image_heavy_rain, &icon_heavy_rain };

    // Freezing rain
    case 66:
    case 67:
      return { &image_wintry_mix_rain_snow, &icon_wintry_mix_rain_snow };

    // Snow fall (light, moderate, heavy) & snow showers (light)
    case 71:
    case 73:
    case 75:
    case 85:
      return { &image_snow_showers_snow, &icon_snow_showers_snow };

    // Snow grains
    case 77:
      return { &image_flurries, &icon_flurries };

    // Heavy snow showers
    case 86:
      return { &image_heavy_snow, &icon_heavy_snow };

    // Thunderstorm (light)
    case 95:
      return is_day
        ? WeatherArt{ &image_isolated_scattered_tstorms_day, &icon_isolated_scattered_tstorms_day }
        : WeatherArt{ &image_isolated_scattered_tstorms_night, &icon_isolated_scattered_tstorms_night };

    // Thunderstorm with hail
    case 96:
    case 99:
      return { &image_strong_tstorms, &icon_strong_tstorms };

    // Fallback for any other code
    default:
      return is_day
        ? WeatherArt{ &image_mostly_cloudy_day, &icon_mostly_cloudy_day }
        : WeatherArt{ &image_mostly_cloudy_night, &icon_mostly_cloudy_night };
  }
}

const lv_img_dsc_t* choose_image(int code, int is_day) {
  return choose_art(code, is_day).image;
}

const lv_img_dsc_t* choose_icon(int code, int is_day) {
  return choose_art(code, is_day).icon;
}
