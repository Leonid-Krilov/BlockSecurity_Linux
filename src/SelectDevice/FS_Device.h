#pragma once

#include <iostream>

#include "Device.h"

class FS_Device
{
public:
   virtual ~FS_Device() = default;
   virtual Device* createDevice() = 0;
};