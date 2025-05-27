#pragma once 
#include <iostream>

#include "WorkProgram.h"

class Bluetooth : public WorkProgram
{
protected:
  void workProgram() const override;
};