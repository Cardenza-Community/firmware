#ifndef BLE_API_HPP
#define BLE_API_HPP
#if !defined(LITE_VERSION)
#include "services/BLESerialService.h"
#ifndef CARDENZA_TARGET
#include "services/BatteryService.hpp"
#endif

class BLE_API {
public:
    BLE_API();
    void setup();
    void end();
    void update_mtu(uint16_t mtu);

private:
    NimBLEServer *pServer;
    #ifndef CARDENZA_TARGET
    BatteryService battery_service;
    #endif
    BLESerialService serial_service;
};
#endif
#endif // BLE_API_HPP
