#include "USBDevice.h"

void USBDevice::workDevice()
{
  if (!searchUSB())
  {
    std::cout << "\nUSB-устройства не найдены!\n" << std::endl;
  }
  else
  {
    std::ifstream fileKey(m_pathFileKey);
    fileKey.is_open();

    while (std::getline(fileKey, m_key))
    {
      if (m_key.empty())
        std::cout << "\nFile with KEY clear!\n";
      else
      {
        rocFileKey();
        
      }
    }
  
    fileKey.close();
  }
}

namespace fs = std::filesystem;
const std::string FILEKEY = "/FileKey.txt";
const std::string ROCKEY = "/ROCKEY.txt";

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

      m_pathFileKey = mount_point + FILEKEY;
      m_pathOpenKey = mount_point + ROCKEY;
        
      if (fs::exists(m_pathFileKey) && fs::is_regular_file(m_pathFileKey))
        {
          m_device = device;
          return true;
        }
    }
  }
  return false;
}

const std::string PATHROCFILE = "../data/Key.txt";

void USBDevice::rocFileKey()
{
  std::string stringROCKey;
  std::ifstream fileROCKey;
  std::vector<std::string> vectorKey;

  fileROCKey.open(PATHROCFILE);
  while (std::getline(fileROCKey, stringROCKey))
  {
    size_t pozition = stringROCKey.find("|");

    if (pozition != std::string::npos)
    {
      m_closeKey = stringROCKey.substr(0, pozition - 1);
      m_totalKey = stringROCKey.substr(pozition + 2);
    }
  }
  fileROCKey.close();

  fileROCKey.open(m_pathOpenKey);
  while (std::getline(fileROCKey, stringROCKey))
  {
    size_t pozition = stringROCKey.find("|");

    if (pozition != std::string::npos)
    {
      m_openKey = stringROCKey.substr(0, pozition - 1);
      m_totalKey = stringROCKey.substr(pozition + 2);
    }
  }
  fileROCKey.close();

}

bool USBDevice::mountDevice(std::string& device)
{
  if (device.empty() || device.find("..") != std::string::npos) {
        return false;  // Базовая проверка безопасности
    }
    
    std::string command = "../bin/script_mount.sh " + device;
    return system(command.c_str()) == 0;
}