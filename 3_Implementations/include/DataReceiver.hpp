#ifndef DataReicever_hpp
#define DataReicever_hpp
#include <string>
#include "TcpServer.hpp"
namespace valeo{
  namespace internship{
    class DataReceiver : public TcpServer
    {
      public:
        DataReceiver(std::string p_ip, int port);
        ~DataReceiver();
      private:
        std::string m_ip;
        int m_port;
    };
  }
}
#endif
