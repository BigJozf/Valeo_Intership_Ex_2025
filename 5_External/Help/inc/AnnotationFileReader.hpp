#ifndef AnnotationFileReader_hpp
#define AnnotationFileReader_hpp
#include <fstream>
#include "DataTypes.hpp"
#include "ItfAnnotationFileReader.hpp"
namespace workspace
{
  namespace internship
  {
    class AnnotationFileReader : public ItfAnnotationFileReader
    {
      public:
        AnnotationFileReader(std::string p_filename, void* data);
        bool open();
        std::string getFilename();
        bool getNext();
        void close();
      private:
        std::string m_filename;
        std::fstream m_file;
        metadata_t* m_annotation;
    };
  }
}
#endif
