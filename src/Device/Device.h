#pragma once
#include <iostream>
#include <string>

class Device
{
public:
  virtual ~Device() = default;
  virtual void workDevice() = 0;
};