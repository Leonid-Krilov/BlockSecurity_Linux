cmake_minimum_required(VERSION 3.10)

project(BlockSecurity_back)

  

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    src/BluetoothWork
    src/SelectWorkProgram
    src/UsbWork
)

set(SOURCE
  src/main.cpp
  
  src/BluetoothWork/Bluetooth.cpp

  src/UsbWork/USB.cpp
)

set(HEADERS
  src/SelectWorkProgram/SelectWork.h
  src/SelectWorkProgram/SelectWorkProgram.h
  src/SelectWorkProgram/WorkProgram.h

  src/BluetoothWork/Bluetooth.h

  src/UsbWork/USB.h
)

add_executable(BlockSecurity_Linux ${SOURCE} ${HEADERS})

target_link_libraries(BlockSecurity_Linux PRIVATE bluetooth)