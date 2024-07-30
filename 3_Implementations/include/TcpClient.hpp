#ifndef TcpClient_hpp
#define TcpClient_hpp
#include <string>
namespace valeo{
  namespace internship{
    class TcpClient{
    public:
      TcpClient(std::string p_ip, int p_port);
      ~TcpClient();
      bool start();
      bool stop();
    private:
      std::string m_ip;
      int m_port;
    };
  }
}
#endif
