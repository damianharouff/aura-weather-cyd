#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

// Language support
enum Language { LANG_EN = 0, LANG_ES = 1, LANG_DE = 2, LANG_FR = 3, LANG_TR = 4, LANG_SV = 5, LANG_IT = 6 };

// NOTE: The custom LVGL fonts (lv_font_montserrat_latin_*) only contain the
// non-ASCII glyphs listed in their generation command (see the header comment
// in each font .c file). If you add a new character here (e.g. Swedish å/Å or
// Turkish ş/ı, which are currently worked around with ASCII), regenerate the
// fonts with lv_font_conv including that character, or it will not render.
// extract_unicode_chars.py lists every non-ASCII character used in the source.

struct LocalizedStrings {
  const char* temp_placeholder;
  const char* feels_like_temp;
  const char* seven_day_forecast;
  const char* hourly_forecast;
  const char* today;
  const char* now;
  const char* am;
  const char* pm;
  const char* noon;
  const char* invalid_hour;
  const char* brightness;
  const char* location;
  const char* use_fahrenheit;
  const char* use_24hr;
  const char* save;
  const char* cancel;
  const char* close;
  const char* location_btn;
  const char* reset_wifi;
  const char* reset;
  const char* change_location;
  const char* aura_settings;
  const char* city;
  const char* search_results;
  const char* city_placeholder;
  const char* wifi_config;
  const char* reset_confirmation;
  const char* language_label;
  const char* weekdays[7];
  const char* use_night_mode;
  const char* flip_display;
};

#define DEFAULT_CAPTIVE_SSID "Aura"

static const LocalizedStrings strings_en = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Feels Like",
  .seven_day_forecast = "SEVEN DAY FORECAST",
  .hourly_forecast = "HOURLY FORECAST",
  .today = "Today",
  .now = "Now",
  .am = "am",
  .pm = "pm",
  .noon = "Noon",
  .invalid_hour = "Invalid hour",
  .brightness = "Brightness:",
  .location = "Location:",
  .use_fahrenheit = "Use °F:",
  .use_24hr = "24hr:",
  .save = "Save",
  .cancel = "Cancel",
  .close = "Close",
  .location_btn = "Location",
  .reset_wifi = "Reset Wi-Fi",
  .reset = "Reset",
  .change_location = "Change Location",
  .aura_settings = "Aura Settings",
  .city = "City:",
  .search_results = "Search Results",
  .city_placeholder = "e.g. London",
  .wifi_config =
    "Wi-Fi Configuration:\n\n"
    "Please connect your\n"
    "phone or laptop to the\n"
    "temporary Wi-Fi access\n point "
    DEFAULT_CAPTIVE_SSID
    "\n"
    "to configure.\n\n"
    "If you don't see a \n"
    "configuration screen \n"
    "after connecting,\n"
    "visit http://192.168.4.1\n"
    "in your web browser.",
  .reset_confirmation =
    "Are you sure you want to reset "
    "Wi-Fi credentials?\n\n"
    "You'll need to reconnect to the Wifi SSID " DEFAULT_CAPTIVE_SSID
    " with your phone or browser to "
    "reconfigure Wi-Fi credentials.",
  .language_label = "Language:",
  .weekdays = {"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"},
  .use_night_mode = "Dim screen at night",
  .flip_display = "Rotate display 180°:"
};

static const LocalizedStrings strings_es = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Sensación",
  .seven_day_forecast = "PRONÓSTICO 7 DÍAS",
  .hourly_forecast = "PRONÓSTICO POR HORAS",
  .today = "Hoy",
  .now = "Ahora",
  .am = "am",
  .pm = "pm",
  .noon = "Mediodía",
  .invalid_hour = "Hora inválida",
  .brightness = "Brillo:",
  .location = "Ubicación:",
  .use_fahrenheit = "Usar °F:",
  .use_24hr = "24h:",
  .save = "Guardar",
  .cancel = "Cancelar",
  .close = "Cerrar",
  .location_btn = "Ubicación",
  .reset_wifi = "Wi-Fi",
  .reset = "Restablecer",
  .change_location = "Cambiar Ubicación",
  .aura_settings = "Configuración Aura",
  .city = "Ciudad:",
  .search_results = "Resultados de Búsqueda",
  .city_placeholder = "ej. Madrid",
  .wifi_config =
    "Configuración Wi-Fi:\n\n"
    "Conecte su teléfono\n"
    "o portátil al punto de\n"
    "acceso Wi-Fi temporal\n"
    DEFAULT_CAPTIVE_SSID
    "\n"
    "para configurar.\n\n"
    "Si no ve una pantalla\n"
    "de configuración después\n"
    "de conectarse, visite\n"
    "http://192.168.4.1\n"
    "en su navegador.",
  .reset_confirmation =
    "¿Está seguro de que desea\n"
    "restablecer las credenciales\n"
    "Wi-Fi?\n\n"
    "Deberá reconectarse al SSID " DEFAULT_CAPTIVE_SSID
    " con su teléfono o navegador\n"
    "para reconfigurar las\n"
    "credenciales Wi-Fi.",
  .language_label = "Idioma:",
  .weekdays = {"Dom", "Lun", "Mar", "Mié", "Jue", "Vie", "Sáb"},
  .use_night_mode = "Pantalla noche",
  .flip_display = "Girar pantalla 180°:"
};

static const LocalizedStrings strings_de = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Gefühlt",
  .seven_day_forecast = "7-TAGE VORHERSAGE",
  .hourly_forecast = "STÜNDLICHE VORHERSAGE",
  .today = "Heute",
  .now = "Jetzt",
  .am = "",
  .pm = "",
  .noon = "Mittag",
  .invalid_hour = "Ungültige Stunde",
  .brightness = "Helligkeit:",
  .location = "Standort:",
  .use_fahrenheit = "°F:",
  .use_24hr = "24h:",
  .save = "Speichern",
  .cancel = "Abbrechen",
  .close = "Schließen",
  .location_btn = "Standort",
  .reset_wifi = "Wi-Fi",
  .reset = "Zurücksetzen",
  .change_location = "Standort ändern",
  .aura_settings = "Aura Einstellungen",
  .city = "Stadt:",
  .search_results = "Suchergebnisse",
  .city_placeholder = "z.B. Berlin",
  .wifi_config =
    "Wi-Fi Konfiguration:\n\n"
    "Verbinden Sie Ihr Telefon\n"
    "oder Laptop mit dem\n"
    "temporären Wi-Fi\n"
    "Zugangspunkt "
    DEFAULT_CAPTIVE_SSID
    "\n"
    "zum Konfigurieren.\n\n"
    "Wenn Sie keinen\n"
    "Konfigurationsbildschirm\n"
    "sehen, besuchen Sie\n"
    "http://192.168.4.1\n"
    "in Ihrem Browser.",
  .reset_confirmation =
    "Sind Sie sicher, dass Sie\n"
    "die Wi-Fi Zugangsdaten\n"
    "zurücksetzen möchten?\n\n"
    "Sie müssen sich erneut mit\n"
    "der SSID " DEFAULT_CAPTIVE_SSID
    " verbinden, um die\n"
    "Wi-Fi Zugangsdaten\n"
    "neu zu konfigurieren.",
  .language_label = "Sprache:",
  .weekdays = {"So", "Mo", "Di", "Mi", "Do", "Fr", "Sa"},
  .use_night_mode = "Nacht-Dimmen",
  .flip_display = "Display um 180° drehen:"
};

static const LocalizedStrings strings_fr = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Ressenti",
  .seven_day_forecast = "PRÉVISIONS 7 JOURS",
  .hourly_forecast = "PRÉVISIONS HORAIRES",
  // Abbreviated so they fit the forecast columns like the other languages
  .today = "Auj.",
  .now = "Maint.",
  .am = "h",
  .pm = "h",
  .noon = "Midi",
  .invalid_hour = "Heure invalide",
  .brightness = "Luminosité:",
  .location = "Lieu:",
  .use_fahrenheit = "Utiliser °F:",
  .use_24hr = "24h:",
  .save = "Sauvegarder",
  .cancel = "Annuler",
  .close = "Fermer",
  .location_btn = "Lieu",
  .reset_wifi = "Wi-Fi",
  .reset = "Réinitialiser",
  .change_location = "Changer de lieu",
  .aura_settings = "Paramètres Aura",
  .city = "Ville:",
  .search_results = "Résultats de recherche",
  .city_placeholder = "ex. Paris",
  .wifi_config =
    "Configuration Wi-Fi:\n\n"
    "Connectez votre téléphone\n"
    "ou ordinateur portable au\n"
    "point d'accès Wi-Fi\n"
    "temporaire "
    DEFAULT_CAPTIVE_SSID
    "\n"
    "pour configurer.\n\n"
    "Si vous ne voyez pas\n"
    "d'écran de configuration\n"
    "après connexion, visitez\n"
    "http://192.168.4.1\n"
    "dans votre navigateur.",
  .reset_confirmation =
    "Êtes-vous sûr de vouloir\n"
    "réinitialiser les\n"
    "identifiants Wi-Fi?\n\n"
    "Vous devrez vous reconnecter\n"
    "au SSID " DEFAULT_CAPTIVE_SSID
    " avec votre téléphone ou\n"
    "navigateur pour reconfigurer\n"
    "les identifiants Wi-Fi.",
  .language_label = "Langue:",
  .weekdays = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"},
  .use_night_mode = "Nuit écran",
  .flip_display = "Pivoter écran 180°:"
};

static const LocalizedStrings strings_tr = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Hissedilen",
  .seven_day_forecast = "YEDI GÜNLÜK TAHMIN",
  .hourly_forecast = "SAATLIK TAHMIN",
  .today = "Bugün",
  .now = "Simdi",
  .am = "öö",
  .pm = "ös",
  .noon = "Öğle",
  .invalid_hour = "Geçersiz saat",
  .brightness = "Parlaklik:",
  .location = "Konum:",
  .use_fahrenheit = "°F Kullan:",
  .use_24hr = "24 Saat:",
  .save = "Kaydet",
  .cancel = "İptal",
  .close = "Kapat",
  .location_btn = "Konum",
  .reset_wifi = "Wi-Fi Sifirla",
  .reset = "Sifirla",
  .change_location = "Konumu Değiştir",
  .aura_settings = "Aura Ayarlari",
  .city = "Şehir:",
  .search_results = "Arama Sonuçları",
  .city_placeholder = "örn. Londra",
  .wifi_config =
    "Wi-Fi Yapilandirmasi:\n\n"
    "Lütfen telefonunuzu veya\n"
    "bilgisayarinizi geçici Wi-Fi\n"
    "erişim noktasina bağlayin "
    DEFAULT_CAPTIVE_SSID
    "\n"
    "yapilandirmak için.\n\n"
    "Bağlandiktan sonra bir\n"
    "yapilandirma ekrani görmezseniz,\n"
    "web tarayicinizda\n"
    "http://192.168.4.1 adresine gidin.",
  .reset_confirmation =
    "Wi-Fi kimlik bilgilerini sifirlamak\n"
    "istediğinizden emin misiniz?\n\n"
    "Wi-Fi kimlik bilgilerini yeniden\n"
    "yapilandirmak için telefonunuz veya\n"
    "tarayiciniz ile " DEFAULT_CAPTIVE_SSID
    " SSID'sine tekrar bağlanmaniz\n"
    "gerekecek.",
  .language_label = "Dil:",
  .weekdays = {"Paz", "Pzt", "Sal", "Çar", "Per", "Cum", "Cmt"},
  .use_night_mode = "Gece kısık",
  .flip_display = "Ekrani 180° döndür:"
};

// Swedish avoids å/Å on purpose: those glyphs are not in the generated fonts
// (see the note at the top of this file)
static const LocalizedStrings strings_sv = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Känns som",
  .seven_day_forecast = "7-DAGARS PROGNOS",
  .hourly_forecast = "TIMPROGNOS",
  .today = "Idag",
  .now = "Nu",
  .am = "",
  .pm = "",
  .noon = "Middag",
  .invalid_hour = "Ogiltig timme",
  .brightness = "Ljusstyrka:",
  .location = "Plats:",
  .use_fahrenheit = "Använd °F:",
  .use_24hr = "24h:",
  .save = "Spara",
  .cancel = "Avbryt",
  .close = "Stäng",
  .location_btn = "Plats",
  .reset_wifi = "Aterställ Wi-Fi",
  .reset = "Aterställ",
  .change_location = "Andra plats",
  .aura_settings = "Aura-inställningar",
  .city = "Stad:",
  .search_results = "Sökresultat",
  .city_placeholder = "t.ex. Stockholm",
  .wifi_config =
    "Wi-Fi-konfiguration:\n\n"
    "Anslut din telefon\n"
    "eller laptop till den\n"
    "tillfälliga Wi-Fi-\n"
    "atkomstpunkten "
    DEFAULT_CAPTIVE_SSID
    "\n"
    "för att konfigurera.\n\n"
    "Om du inte ser en\n"
    "konfigurationsskärm\n"
    "efter anslutning, besök\n"
    "http://192.168.4.1\n"
    "i din webbläsare.",
  .reset_confirmation =
    "Ar du säker pa att du vill\n"
    "aterställa Wi-Fi-\n"
    "autentiseringsuppgifter?\n\n"
    "Du maste ateransluta till\n"
    "SSID " DEFAULT_CAPTIVE_SSID
    " med din telefon eller\n"
    "webbläsare för att\n"
    "omkonfigurera Wi-Fi-\n"
    "autentiseringsuppgifter.",
  .language_label = "Sprak:",
  .weekdays = {"Sön", "Man", "Tis", "Ons", "Tor", "Fre", "Lör"},
  .use_night_mode = "Nattdämpning",
  .flip_display = "Vänd skärm 180°:"
};

static const LocalizedStrings strings_it = {
  .temp_placeholder = "--°C",
  .feels_like_temp = "Percepita",
  .seven_day_forecast = "PREVISIONI A 7 GIORNI",
  .hourly_forecast = "PREVISIONI ORARIE",
  .today = "Oggi",
  .now = "Ora",
  .am = "am",
  .pm = "pm",
  .noon = "Mezzog.",
  .invalid_hour = "Ora non valida",
  .brightness = "Luminosità:",
  .location = "Posizione:",
  .use_fahrenheit = "Utilizzo °F:",
  .use_24hr = "24hr:",
  .save = "Salva",
  .cancel = "Cancellare",
  .close = "Chiudi",
  .location_btn = "Posizione",
  .reset_wifi = "Resetta Wi-Fi",
  .reset = "Reset",
  .change_location = "Cambia posizione",
  .aura_settings = "Impostazioni aura",
  .city = "Città:",
  .search_results = "Risultati di ricerca",
  .city_placeholder = "e.s. Londra",
  .wifi_config =
    "Configurazione Wi-Fi:\n\n"
    "Per favore collega il tuo\n"
    "smartphone o laptop\n"
    "al Wi-Fi temporaneo\n "
    DEFAULT_CAPTIVE_SSID
    "\n"
    "per configurare la rete.\n\n"
    "Se non vedi la \n"
    "Schermata di configurazione \n"
    "dopo il collegamento,\n"
    "visita http://192.168.4.1\n"
    "sul tuo web browser.",
  .reset_confirmation =
    "Sei sicuro di voler ripristinare "
    "le credenziali Wi-Fi ?\n\n"
    "Dovrai riconnetterti al WiFi con SSID " DEFAULT_CAPTIVE_SSID
    " con il tuo telefono o browser a "
    "riconfigurare le credenziali Wi-Fi.",
  .language_label = "Lingua:",
  .weekdays = {"Dom", "Lun", "Mar", "Mer", "Gio", "Ven", "Sab"},
  .use_night_mode = "Schermo notte",
  .flip_display = "Ruota schermo 180°:"
};

static const LocalizedStrings* get_strings(Language current_language) {
  switch (current_language) {
    case LANG_ES: return &strings_es;
    case LANG_DE: return &strings_de;
    case LANG_FR: return &strings_fr;
    case LANG_TR: return &strings_tr;
    case LANG_SV: return &strings_sv;
    case LANG_IT: return &strings_it;
    default: return &strings_en;
  }
}

#endif // TRANSLATIONS_H
