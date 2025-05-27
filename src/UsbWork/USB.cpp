#include <USB.h>

void USB::workProgram()
{
  searchUSB();
  if (m_usbDevice.empty()) {
        std::cout << "USB-устройства не найдены." << std::endl;
    } else {
        std::cout << "Найдены USB-устройства:" << std::endl;
        for (const auto& dev : m_usbDevice) {
            std::cout << dev << std::endl;
        }
    }
}

void USB::searchUSB()
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