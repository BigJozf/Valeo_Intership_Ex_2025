#ifndef TcpClient_hpp
#define TcpClient_hpp
#include <string>
namespace workspace{
  namespace internship
  {
    class TcpClient
    {
    public:
      /// @brief Constructor
      /// @param p_ip
      /// @param p_port
      TcpClient(std::string p_ip="127.0.0.1", int p_port=2525);
      /// @brief Destructor
      ~TcpClient();
      /// @brief To get the ip address that will be use for the communication
      /// @return
      std::string getIp();
      /// @brief To get the port number that will be use for the communication
      /// @return
      int getPort();
      /// @brief To set the ip address that will be use for the communication
      /// @param p_ip
      void setIp(std::string p_ip);
      /// @brief To set the port number that will be use for the communication
      /// @param p_port
      void setPort(int p_port);
      /// @brief To start the communication
      /// @return True if success, false if not
      bool start();
      /// @brief To stop the communication
      void stop();
    private:
      std::string m_ip;
      int m_port;
      int m_socket;
    };
  }
}
#endif
