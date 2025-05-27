#pragma once
#include <iostream>

class WorkProgram
{
public:
  virtual ~WorkProgram() = default;
  virtual void workProgram() = 0;
};