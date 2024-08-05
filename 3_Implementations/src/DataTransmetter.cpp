#include "DataTransmetter.hpp"
#include <string>
namespace valeo
{
  namespace internship
  {
    DataTransmetter::DataTransmetter(std::string p_ip, int p_port):
    TcpClient(p_ip, p_port), m_filename("text.txt")
    {
    }
    DataTransmetter::~DataTransmetter()
    {
    }
    void DataTransmetter::setInputFileName(std::string p_filename)
    {
    }
    std::string DataTransmetter::getOutputFilename()
    {
        return std::string();
    }
  }
}
