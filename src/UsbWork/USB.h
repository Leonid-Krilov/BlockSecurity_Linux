#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "WorkProgram.h"

class USB : public WorkProgram
{
protected:
  void workProgram() const override;

private:
  void searchUSB() const;

private:
  mutable std::vector<std::string> m_usbDevice;
};