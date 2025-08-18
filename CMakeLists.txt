cmake_minimum_required(VERSION 3.10)

project(BlockSecurity_back)

  

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
  src/Device  
  src/BluetoothDevice
  src/USBDevice
  src/SelectDevice
  src/Cripta
  script/
)

set(SOURCE
  src/main.cpp
  
  src/BluetoothDevice/BluetoothDevice.cpp

  src/USBDevice/USBDevice.cpp

  src/Cripta/Cript.cpp
  src/Cripta/Encript.cpp
)

set(HEADERS
  src/SelectDevice/FS_Device.h
  src/SelectDevice/SelectDeviceBluetooth.h
  src/SelectDevice/SelectDeviceUSB.h

  src/Device/Device.h

  src/BluetoothDevice/BluetoothDevice.h

  src/USBDevice/USBDevice.h

  src/Cripta/Cript.h
  src/Cripta/Encript.h
)

add_executable(BlockSecurity_Linux ${SOURCE} ${HEADERS})

target_link_libraries(BlockSecurity_Linux PRIVATE bluetooth)