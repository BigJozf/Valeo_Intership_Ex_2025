#ifndef ItfAnnotationFileReader_hpp
#define ItfAnnotationFileReader_hpp
#include <string>
namespace workspace
{
  namespace internship
  {
    class ItfAnnotationFileReader
    {
      public:
        /// @brief Constructor
        ItfAnnotationFileReader(){}
        /// @brief Destructor
        ~ItfAnnotationFileReader(){}
        /// @brief To open the annotation file
        /// @return True if success, false if not.
        virtual bool open() = 0;
        /// @brief To get the next annotation
        /// @return True if success, false if not.
        virtual bool getNext() = 0;
        /// @brief To close the annotation file
        virtual void close() = 0;
      private:
        std::string m_filename;
    };
  }
}
#endif
