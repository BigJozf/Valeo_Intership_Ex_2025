#include "TcpClient.hpp"

namespace valeo
{
  namespace internship
  {
    TcpClient::TcpClient(std::string p_ip, int p_port):
    m_ip(p_ip), m_port(p_port), m_socket(-1)
    {

    }
    TcpClient::~TcpClient()
    {
    }
    std::string TcpClient::getIp()
    {
        return std::string();
    }
    int TcpClient::getPort()
    {
        return 0;
    }
    void TcpClient::setIp(std::string p_ip)
    {
    }
    void TcpClient::setPort(int p_port)
    {
    }
    bool TcpClient::start()
    {
      return false;
    }
    void TcpClient::stop()
    {
      m_socket = -1;
    }
  }
}
