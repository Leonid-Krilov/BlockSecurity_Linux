#pragma once
#include <iostream>
#include <string>

class Device
{
public:
  virtual ~Device() = default;
  virtual std::string workDevice() = 0;
};