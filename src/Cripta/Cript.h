#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Cript
{
public:
  Cript();
//private:
  void eulerCript();
  void eulerEncript();
  void createKey();
private:
  int m_openNumber, m_closeNumber, m_totalNumber;
  std::string m_stringKey = "Test123%";
  std::vector<int> m_keyVector;
  std::vector<char> m_criptVector;
};