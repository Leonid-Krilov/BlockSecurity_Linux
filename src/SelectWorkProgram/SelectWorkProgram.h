#pragma once
#include <iostream>
#include <string> 

#include "SelectWork.h"
#include "WorkProgram.h"
#include "Bluetooth.h"
#include "USB.h"

class SelectWorkProgram : public SelectWork
{
public:
  WorkProgram* selectWorkProgram(int select) const override
  {
    if(select == 1)
      return new Bluetooth;

    return new USB;
  }
};