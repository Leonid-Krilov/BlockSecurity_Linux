#pragma once 
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include "WorkProgram.h"

class Bluetooth : public WorkProgram
{
protected:
  void workProgram() override;

private:
  int searchBluetoothConnected();
};