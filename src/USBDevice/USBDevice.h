#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

#include "Device.h"

class USBDevice : public Device
{
protected:
  void workDevice() override;
  
private:
  bool searchUSB();
  bool mountDevice(std::string& device);
  void rocFileKey();

private:
  std::vector<std::string> m_usbDevice;
  std::string m_pathFileKey, m_pathOpenKey;
  std::string m_device;
  std::string m_key;
  std::string m_openKey, m_closeKey, m_totalKey;
};