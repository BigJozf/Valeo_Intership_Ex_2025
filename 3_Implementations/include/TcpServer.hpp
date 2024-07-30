#ifndef TcpServer_hpp
#define TcpServer_hpp
#include <string>
namespace valeo{
  namespace internship{
    class TcpServer{
      public:
        TcpServer(std::string p_ip, int p_por);
        ~TcpServer();
      private:
        std::string m_ip;
        int m_port;
    };
  }
}
#endif
