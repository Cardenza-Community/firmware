Import("env")
env.Append(LINKFLAGS=["-Wl,--wrap=esp_wifi_start",
                      "-Wl,--wrap=esp_wifi_set_promiscuous",
                      "-Wl,--wrap=esp_wifi_80211_tx"])
