#ifndef DataTransmetter_hpp
#define DataTransmetter_hpp
#include <string>
#include "TcpClient.hpp"
namespace valeo{
  namespace internship{
    class DataTransmetter : TcpClient
    {
      public:
        DataTransmetter(std::string p_ip, int p_port);
        ~DataTransmetter();
      private:
        std::string m_ip;
        int m_port;
    };
  }
}
#endif
