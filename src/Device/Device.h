#pragma once
#include <iostream>

class Device
{
public:
  virtual ~Device() = default;
  virtual void workDevice() = 0;
};