#pragma once
#include <iostream>
#include <memory>

#include "FS_Device.h"
#include "Device.h"
#include "BluetoothDevice.h"
#include "USBDevice.h"

class SelectDeviceBluetooth : public FS_Device
{
public:
  Device* createDevice() override
  {
    return new BluetoothDevice;
  }
};