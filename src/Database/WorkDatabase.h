#pragma once
#include <iostream>
#include <libpq-fe.h>

class WorkDatabase
{
public:
  WorkDatabase();
  WorkDatabase(std::string host, std::string port, std::string dbname, std::string user, std::string password);

  ~WorkDatabase();

  void checkConnectionDatabase();
  void addLog();

private:
   PGconn* m_connection;
};