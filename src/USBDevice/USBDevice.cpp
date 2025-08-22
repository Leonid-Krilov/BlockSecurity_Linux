#include "USBDevice.h"

void USBDevice::workDevice()
{
  if (!searchUSB()) {
        std::cout << "USB-устройства не найдены." << std::endl;
    }
    else
    {
      std::ifstream fileKey(m_pathFileKey);
      fileKey.is_open();

      while (std::getline(fileKey, m_key))
      {
        
      }

      fileKey.close();
       
      // if (true)
      // {
      //   std::cout << "USB устройство не подошло";
      // }
      // else
      // {
      //   //проверка ключа
      // }
      
    }
}

namespace fs = std::filesystem;
const std::string PATHKEY = "/FileKey.txt";

bool USBDevice::searchUSB()
{
  std::string line;
  std::ifstream mount("/proc/mounts");

  while (getline(mount, line))
  {
    if(line.find("/dev/sd") != std::string::npos && line.find("/dev/sda") == std::string::npos || line.find("/dev/mmcblk") != std::string::npos) 
    {
      m_usbDevice.push_back(line.substr(0, line.find(' ')));

      std::string device, mount_point;
      std::istringstream ss(line);
      ss >> device >> mount_point;

      m_pathFileKey = mount_point + PATHKEY;
        
      if (fs::exists(m_pathFileKey) && fs::is_regular_file(m_pathFileKey))
        {
          m_device = device;
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