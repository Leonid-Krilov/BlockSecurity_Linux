#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "WorkProgram.h"

class USB : public WorkProgram
{
protected:
  void workProgram() override;

private:
  void searchUSB();

private:
  std::vector<std::string> m_usbDevice;
};