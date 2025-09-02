#include "Cript.h"

Cript::Cript()
{
  
}

void Cript::eulerCript()
{
  for (char simbol : m_stringKey)
    m_keyVector.push_back(static_cast<int>(simbol));

  for (int simbol : m_keyVector)
  {
    simbol = pow(simbol, m_openNumber);
    simbol %= m_totalNumber;
    m_criptVector.push_back(static_cast<char>(simbol));
  }

  std::string stringKey(m_criptVector.begin(), m_criptVector.end());
  m_stringKey = stringKey;
}

void Cript::eulerEncript()
{
  for (char simbol : m_stringKey)
    m_criptVector.push_back(static_cast<int>(simbol));

  for (int simbol : m_criptVector)
  {
    simbol = pow(simbol, m_closeNumber);
    simbol %= m_totalNumber;
    m_keyVector.push_back(static_cast<char>(simbol));
  }
  
  std::string stringKey(m_criptVector.begin(), m_criptVector.end());
  m_stringKey = stringKey;
}

void Cript::createKey()
{
  srand(time(0));
  bool checkNumber = false;

  while(!checkNumber)
  {
    int minVal = 1;
    int maxVal = 100;
    int firstRandNumber = minVal + (rand() % (maxVal - minVal + 1));
    int secondRandNumber = minVal + (rand() % (maxVal - minVal + 1));

    for (int i=2; i<10; i++)
      if(firstRandNumber % i == 0)
        firstRandNumber = 0;

    for (int i=2; i<10; i++)
      if(secondRandNumber % i == 0)
        secondRandNumber = 0;

    if(firstRandNumber != 0 && secondRandNumber != 0)
      checkNumber = true;
  }
}