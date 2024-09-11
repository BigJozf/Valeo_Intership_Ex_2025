#include "AnnotationFileReader.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  void* l_metadata = malloc(sizeof(metadata_t));
  workspace::internship::AnnotationFileReader l_reader("../data/annotation.txt", l_metadata);
  if(l_reader.open())
  {
    cout << "Sucess to open file " << endl;
    while(l_reader.getNext())
    {
      cout << "FrameId = " << static_cast<metadata_t*>(l_metadata)->frameId << endl;
      cout << "\tCenter x="<< static_cast<metadata_t*>(l_metadata)->center.x << ", y= " << static_cast<metadata_t*>(l_metadata)->center.y << endl;
      cout << "\tBoundingBox = [upperLeft x= " << static_cast<metadata_t*>(l_metadata)->bb.upperLeft.x << ", y= " << static_cast<metadata_t*>(l_metadata)->bb.upperLeft.y << "] [lowerLeft x=";
      cout << static_cast<metadata_t*>(l_metadata)->bb.lowerRight.x << ", y= " << static_cast<metadata_t*>(l_metadata)->bb.lowerRight.y << "] " << endl;
    }
    l_reader.close();
  }
  else
  {
    cerr << "Fail to open file !!!" << endl;
  }
  free(l_metadata);
  return 0;
}
