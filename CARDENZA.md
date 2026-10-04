## M5Unified runtime migration exception

Bruce uses TFT_eSPI, a custom keyboard reader, Wire1 and custom ES8311/audio setup rather than M5Unified for Cardputer. Adding M5.begin solely for detection would duplicate display/SPI ownership and activate the bus_HAL M5 adapter. It remains an independent-driver exception for this phase: existing separate stock and Cardenza builds are preserved. A future lightweight detection/HAL integration must first resolve custom bus ownership; no runtime-unified Bruce support is claimed.

# Cardenza support

This target retains the original Cardputer display and matrix-keyboard layout.
It verifies the ES8156 codec on SDA2/SCL1 and uses stereo Philips I2S,
16-bit samples and 32 BCLK per frame on BCLK41/LRCK43/DOUT42.
GPIO21 is held high to disable the keyboard LED. Cardenza has no battery,
charging detector, IMU or PSRAM; unavailable hardware is not simulated.
The original application license and third-party notices remain in force.

Build the normal application with `pio run -e cardenza`. Install only
`.pio/build/cardenza/firmware.bin` through Software Launcher. Preserve the
existing bootloader, partition table, otadata and shared NVS.
The target refuses whole shared-NVS erasure during Arduino recovery while
allowing normal NVS page garbage collection and unrelated partition writes.
Run `python3 support/test_nvs_guard.py` to verify this forwarding contract.
Successful compilation does not prove physical display, keys, audio or RF.
No wireless/security functionality is executed by these build checks.

The full app requires a 4 MiB slot. Storage startup can use SD/default settings
without internal LittleFS; internal filesystem features require a dedicated
compatible partition. No automatic partition-table rewrite is added.
`cardenza-radio-disabled` is a separate guarded startup-test variant.
FastLED is pinned to the requested 3.10.3 to avoid a font macro conflict.
Startup skips default Grove/GPS and CC1101 configuration because GPIO2/1
belong to the codec; external modules require verified explicit wiring.
The HAL license is `support/CARDENZA-HAL-LICENSE`.

Cardenza embeds the original web resources with native gzip, without uploading
them to an external online minifier. Other board build behavior is unchanged.
