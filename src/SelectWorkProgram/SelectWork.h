#pragma once

#include <iostream>

#include "WorkProgram.h"

class SelectWork
{
public:
   virtual ~SelectWork() = default;
   virtual WorkProgram* selectWorkProgram(int select) const = 0;
};