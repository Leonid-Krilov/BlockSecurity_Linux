cmake_minimum_required(VERSION 3.10)

project(BlockSecurity_back)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PostgreSQL REQUIRED)

message(STATUS "PostgreSQL include dir: ${PostgreSQL_INCLUDE_DIRS}")
message(STATUS "PostgreSQL libraries: ${PostgreSQL_LIBRARIES}")

include_directories(
  src/Device  
  src/BluetoothDevice
  src/USBDevice
  src/SelectDevice
  src/Cripta
  src/Database
)

set(SOURCE
  src/main.cpp
  
  src/BluetoothDevice/BluetoothDevice.cpp

  src/USBDevice/USBDevice.cpp

  src/Cripta/Cript.cpp

  src/Database/WorkDatabase.cpp
)

set(HEADERS
  src/SelectDevice/FS_Device.h
  src/SelectDevice/SelectDeviceBluetooth.h
  src/SelectDevice/SelectDeviceUSB.h

  src/Device/Device.h

  src/BluetoothDevice/BluetoothDevice.h

  src/USBDevice/USBDevice.h

  src/Cripta/Cript.h

  src/Database/WorkDatabase.h
)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE bluetooth ${PostgreSQL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PostgreSQL_INCLUDE_DIRS})