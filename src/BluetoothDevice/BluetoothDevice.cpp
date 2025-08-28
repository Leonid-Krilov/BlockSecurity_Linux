#include "BluetoothDevice.h"

std::string BluetoothDevice::workDevice()
{
  searchBluetoothConnected();
  return "true";
}

int BluetoothDevice::searchBluetoothConnected()
{
  int dev_id = hci_get_route(nullptr);
  int sock = hci_open_dev(dev_id);
  
  if (dev_id < 0 || sock < 0)
  {
    std::cerr << "Ошибка открытия сокета Bluetooth" << std::endl;
    return 1;
  }

  inquiry_info* devices = nullptr;
  int max_rsp = 255; // Макс. количество устройств
  int flags = IREQ_CACHE_FLUSH; // Обновить кеш
  int duration = 8;  // Продолжительность поиска (1.28 * duration сек)

  
  int num_rsp = hci_inquiry(dev_id, duration, max_rsp, nullptr, &devices, flags);
  if (num_rsp < 0)
  {
    std::cerr << "Ошибка поиска устройств" << std::endl;
    close(sock);
    return 1;
  }

  char addr[19] = {0};
  char name[248] = {0};
    
  std::cout << "Найдено классических Bluetooth-устройств: " << num_rsp << std::endl;
    
  for (int i = 0; i < num_rsp; i++)
  {
    ba2str(&(devices+i)->bdaddr, addr);
        
    if (hci_read_remote_name(sock, &(devices+i)->bdaddr, sizeof(name), name, 0) < 0)
    {
      strcpy(name, "[неизвестно]");
    }
      
    std::cout << "Устройство: " << addr << " \tИмя: " << name << std::endl;

    int dd = hci_open_dev(dev_id); 
    int8_t rssi;
    uint16_t handle;
    
    if (hci_read_rssi(dd, handle, &rssi, 1000) != 0)
    {
      std::cout << "Устройство: " << addr << " \tRSSI: " << (int)rssi << " dBm" << std::endl;
    }
  }

  free(devices);
  close(sock);
  return 0;
}