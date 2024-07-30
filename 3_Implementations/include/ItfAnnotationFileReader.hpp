#ifndef ItfAnnotationFileReader_hpp
#define ItfAnnotationFileReader_hpp
#include <string>
namespace valeo{
  namespace internship{
    class ItfAnnotationFileReader
    {
      public:
        ItfAnnotationFileReader(){}
        ~ItfAnnotationFileReader(){}
        virtual void open() = 0;
        virtual void close() = 0;
      private:
        std::string m_filename;
    };
  }
}
#endif
