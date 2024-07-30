#include "DataReceiver.hpp"
#include <string>
namespace valeo
{
  namespace internship
  {
    DataReceiver::DataReceiver(std::string p_ip, int p_port):
    TcpServer(p_ip, p_port)
    {
    }
    DataReceiver::~DataReceiver()
    {
    }
  }
}
