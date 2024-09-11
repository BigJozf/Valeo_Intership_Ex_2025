#include "TcpServer.hpp"

namespace workspace
{
  namespace internship
  {
    TcpServer::TcpServer(std::string p_ip, int p_port):
    m_ip(p_ip), m_port(p_port), m_socket(-1)
    {

    }
    TcpServer::~TcpServer()
    {
    }
    std::string TcpServer::getIp()
    {
        return std::string();
    }
    int TcpServer::getPort()
    {
        return 0;
    }
    void TcpServer::setIp(std::string p_ip)
    {
    }
    void TcpServer::setPort(int p_port)
    {
    }
    bool TcpServer::start()
    {
      return false;
    }
    void TcpServer::stop()
    {
      m_socket = -1;
    }
  }
}
