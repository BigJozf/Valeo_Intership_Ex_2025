#include "DataTransmetter.hpp"
#include <string>
namespace valeo
{
  namespace internship
  {
    DataTransmetter::DataTransmetter(std::string p_ip, int p_port):
    TcpClient(p_ip, p_port)
    {
    }
    DataTransmetter::~DataTransmetter()
    {
    }
  }
}
