#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Device.h"

class USBDevice : public Device
{
protected:
  void workDevice() override;

private:
  void searchUSB();

private:
  std::vector<std::string> m_usbDevice;
};