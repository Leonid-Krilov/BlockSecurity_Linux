#include <WorkDatabase.h>

WorkDatabase::WorkDatabase()
{

}

WorkDatabase::WorkDatabase(std::string host, std::string port, std::string dbname, std::string user, std::string password)
{
  std::string conninfo = "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + password;
  m_connection = PQconnectdb(conninfo.c_str());
}

WorkDatabase::~WorkDatabase()
{
  PQfinish(m_connection);
}

void WorkDatabase::checkConnectionDatabase()
{
  if (PQstatus(m_connection) != CONNECTION_OK)
  {
    std::cerr << "Connection failed: " << PQerrorMessage(m_connection) << std::endl;
    PQfinish(m_connection);
    m_connection = nullptr;
  }
  else
  {
    std::cout << "\nConnection successful!" << std::endl;
  }
}

void WorkDatabase::addLog()
{
  
}