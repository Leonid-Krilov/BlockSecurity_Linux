#include <iostream>
#include <string>

#include "FS_Device.h"
#include "Device.h"
#include "SelectDeviceBluetooth.h"
#include "SelectDeviceUSB.h"

int main()
{
  int type = 2;
  FS_Device* selectDevice = nullptr;
  Device* device = nullptr;

  switch(type)
  {
    case 1:
      selectDevice = new SelectDeviceBluetooth();
      device = selectDevice->createDevice();
      break;
    case 2:
      selectDevice = new SelectDeviceUSB();
      device = selectDevice->createDevice();
      break;
  }

  if(!device)
    std::cout << "Device not create\n";
  else
  {
    std::string key = device->workDevice();
    ///и бесконечный цикл работы программы
  }

  delete device;
  delete selectDevice;

  return 0;
}