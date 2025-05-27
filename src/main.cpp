#include <iostream>

#include "SelectWorkProgram.h"
#include "WorkProgram.h"

int main()
{
  SelectWorkProgram fabricaStartProgram;

  WorkProgram* startProgram = fabricaStartProgram.selectWorkProgram(1);
  if(startProgram)
  {
    startProgram->workProgram();
    delete startProgram;
  }

  return 0;
}