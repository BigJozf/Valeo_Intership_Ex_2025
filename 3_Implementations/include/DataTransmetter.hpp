#ifndef DataTransmetter_hpp
#define DataTransmetter_hpp
#include <string>
#include "TcpClient.hpp"
namespace valeo
{
  namespace internship
  {
    /// @brief Permit to send annotation trough Tcp communication
    class DataTransmetter : public TcpClient
    {
      public:
        /// @brief Constructor
        /// @param p_ip
        /// @param p_port
        DataTransmetter(std::string p_ip, int p_port);
        /// @brief Destructor
        ~DataTransmetter();
        /// @brief To set the name of the file containing the annotation.
        /// @param p_filename
        void setInputFileName(std::string p_filename);
        /// @brief To get the name of the file containing the annotation that will be load.
        /// @return
        std::string getOutputFilename();
      private:
        std::string m_ip;
        int m_port;
        std::string m_filename;
    };
  }
}
#endif
