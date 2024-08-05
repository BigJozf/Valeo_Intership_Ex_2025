#include <iostream>
#include <thread>
#include <fstream>
#include <string.h>
#include <string>

#include "DataTypes.hpp"

// #define DEBUG
// #ifdef NDEBUG
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
// #endif

using namespace std;

#define MAX_FRAME 2000
#define IMG_WIDTH 1200
#define IMG_HEIGHT 800
#define IMG_SIZE  IMG_WIDTH*IMG_HEIGHT

bool record;
bool clean;

Mat img;

metadata_t dataToRec;
void onMouseEvent(int event, int x, int y, int flag, void* data)
{
  // switch (event)
  // {
  //   case EVENT_MOUSEMOVE:
  //   /* code */
  //     cout << "Mouse mode detected (x,y) = (" << x << " , " << y << ")" << endl;
  //     if(record)
  //     {
  //       circle(img,Point(x,y),2, Scalar(255,255,255),5, MARKER_CROSS);
  //       dataToRec.center.x = x;
  //       dataToRec.center.y = y;
  //       imshow("display", img);
  //     }
  //   break;
  //   case CV_EVENT_LBUTTONDBLCLK:
  //     record = !record;
  //     break;
  //   case CV_EVENT_RBUTTONDBLCLK:
  //     clean = !clean;
  //     break;
  // default:
  //   break;
  // }

}

int main(int argc, char* argv[])
{
  cout << "Version with OpenCV" << endl;
  // Mat img;
  uint32_t framecounter = 0;
  uint8_t* buffer;
  record = false;
  clean = true;
  //fstream out("../data/annotation.txt",fstream::out|fstream::binary);
  fstream in("../data/annotation.txt", fstream::in|fstream::binary);
  buffer = static_cast<uint8_t*>(malloc(IMG_SIZE));
  memset(buffer,0,IMG_SIZE);
  // namedWindow("display", WINDOW_AUTOSIZE);
  // setMouseCallback("display", onMouseEvent, nullptr);
  dataToRec.frameId = 0;
  dataToRec.center.x = -1;
  dataToRec.center.y = -1;
  dataToRec.bb.lowerRight.x = -1;
  dataToRec.bb.lowerRight.y = -1;
  dataToRec.bb.upperLeft.x = -1;
  dataToRec.bb.upperLeft.y = -1;
  if(in.is_open())
  {
    memset(buffer,0,IMG_SIZE);
    while(in.read((char*)&dataToRec,sizeof(metadata_t)))
    {
      cout << "FrameId : " << dataToRec.frameId << endl;
      cout << "\tCenter x="<< dataToRec.center.x << ", y= " << dataToRec.center.y << endl;
      cout << "BoundingBox = [upperLeft x= " << dataToRec.bb.upperLeft.x << ", y= " << dataToRec.bb.upperLeft.y << "] [lowerLeft x=";
      cout << dataToRec.bb.lowerRight.x << ", y= " << dataToRec.bb.lowerRight.y << "] " << endl;
      img = Mat(Size(IMG_WIDTH,IMG_HEIGHT),CV_8UC1,buffer, Mat::AUTO_STEP);
      circle(img,Point(dataToRec.center.x,dataToRec.center.y),2, Scalar(255,255,255),5, MARKER_CROSS);
      dataToRec.bb.upperLeft.x = dataToRec.center.x - 20;
      dataToRec.bb.upperLeft.y = dataToRec.center.y - 20;
      dataToRec.bb.lowerRight.x  = dataToRec.center.x + 20;
      dataToRec.bb.lowerRight.y  = dataToRec.center.y + 20;
      putText(img, string("FrameId : ") + std::to_string((int)dataToRec.frameId),Point(15,30),5,1,Scalar(255,255,255));
      cvtColor(img,img,COLOR_GRAY2BGR);
      rectangle(img,Point(dataToRec.bb.upperLeft.x,dataToRec.bb.upperLeft.y), Point(dataToRec.bb.lowerRight.x,dataToRec.bb.lowerRight.y), Scalar(255,0,0),2);
      imshow("display", img);
      char k = waitKey(33);
      if((k==' '))
      {
        break;
      }
    }
  }
  // while(1)
  // {
  //   if(clean)
  //   {
  //     memset(buffer,0,IMG_SIZE);
  //     img = Mat(Size(IMG_WIDTH,IMG_HEIGHT),CV_8UC1,buffer, Mat::AUTO_STEP);
  //     putText(img, string("framecouter : ") + std::to_string(framecounter),Point(15,30),CV_FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255));
  //     imshow("display", img);
  //   }
  //   // cout << __LINE__ << " : success to read data" << endl;
  //   //img = imread("../data/decor0.jpg");
  //   out.write((char*)&dataToRec,sizeof(metadata_t));
  //   framecounter++;
  //   dataToRec.frameId++;

  //   //
  //   // cout << "framecounter : " << framecounter << endl;
  //   //imshow("display", img);
  //   char k = waitKey(33);
  //   if((k==' ')||framecounter==MAX_FRAME)
  //   {
  //     break;
  //   }
  // }
  // out.close();
  if(buffer!=nullptr)
  {
    free(buffer);
  }
  return 0;
}
