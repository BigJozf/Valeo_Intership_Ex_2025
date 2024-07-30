#ifndef ItfRawFileReader_hpp
#define ItfRawFileReader_hpp
#include <inttypes.h>
#include <string>
namespace valeo{
  namespace internship{
    class ItfRawFileReader
    {
    public:
      ItfRawFileReader(){}
      virtual ~ItfRawFileReader(){}
      virtual bool open(std::string p_filename, uint8_t *p_buffer) = 0;
      virtual void close() = 0;
      virtual bool getNext() = 0;
      virtual uint32_t getWidth() = 0;
      virtual uint32_t getHeight() = 0;
    };
  }
}
#endif
