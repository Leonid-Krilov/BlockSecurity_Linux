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
  std::string workDevice() override;

private:
  bool searchUSB();
  bool mountDevice(std::string& device);

private:
  std::vector<std::string> m_usbDevice;
  std::string m_pathFileKey;
  std::string m_device;
  std::string m_key;
};