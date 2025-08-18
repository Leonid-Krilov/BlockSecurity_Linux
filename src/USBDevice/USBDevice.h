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
  void searchUSB();
  bool searchKeyFile();
  bool mountDevice(std::string& device);

private:
  std::vector<std::string> m_usbDevice;
  std::string m_pathFileKey;
};