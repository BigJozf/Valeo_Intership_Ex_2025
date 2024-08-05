#include "DataReceiver.hpp"
#include <string>
namespace valeo
{
  namespace internship
  {
    DataReceiver::DataReceiver(std::string p_ip, int p_port):
    TcpServer(p_ip, p_port), m_filename("text.txt")
    {

    }
    DataReceiver::~DataReceiver()
    {
    }
    bool DataReceiver::isConnected()
    {
        return false;
    }
    void DataReceiver::setOutputFilename(std::string p_filename)
    {
    }
    std::string DataReceiver::getInputFilename()
    {
        return std::string();
    }
  }
}
