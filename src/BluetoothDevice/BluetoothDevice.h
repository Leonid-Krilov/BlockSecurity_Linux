#pragma once 
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include "Device.h"

class BluetoothDevice : public Device
{
protected:
  void workDevice() override;

private:
  int searchBluetoothConnected();
};