#pragma once
#include <iostream>
#include <string> 

#include "FS_Device.h"
#include "Device.h"
#include "USBDevice.h"

class SelectDeviceUSB : public FS_Device
{
public:
  Device* createDevice() override
  {
    return new USBDevice;
  }
};