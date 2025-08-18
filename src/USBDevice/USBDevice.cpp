#include "USBDevice.h"

void USBDevice::workDevice()
{
  searchUSB();
  if (m_usbDevice.empty()) {
        std::cout << "USB-устройства не найдены." << std::endl;
    }
    else
    {
      if (!searchKeyFile())
      {
        std::cout << "USB устройство не подошло";
      }
      else
      {
        //проверка ключа
      }
      
    }
}

void USBDevice::searchUSB()
{
  std::string line;
  std::ifstream mount("/proc/mounts");

  while(getline(mount, line))
  {
    if(line.find("/dev/sd") != std::string::npos || line.find("dev/sdb") != std::string::npos)
    {
      m_usbDevice.push_back(line.substr(0, line.find(' ')));
    }
  }
}

bool USBDevice::searchKeyFile()
{
  
  for (const auto& dev : m_usbDevice)
  {
    std::string line;
    std::ifstream fileKey(dev);

    while(getline(fileKey, line))
    {
      if(line.find("fileKey.txt"))
      {
        m_pathFileKey = dev;
        bool success = mountDevice(m_pathFileKey);
        
        return true;
      }
    }
  }
  return false;
}

bool USBDevice::mountDevice(std::string& device)
{
  if (device.empty() || device.find("..") != std::string::npos) {
        return false;  // Базовая проверка безопасности
    }
    
    std::string command = "../script/script_mount.sh " + device;
    return system(command.c_str()) == 0;
}