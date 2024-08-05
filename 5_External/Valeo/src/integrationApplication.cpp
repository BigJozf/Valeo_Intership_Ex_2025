//C++ include
#include <iostream>
#include <thread>
#include <fstream>
//C include
#include <unistd.h>
//Dev include
#include "DataReceiver.hpp"
#include "DataTransmetter.hpp"
#include "DataTypes.hpp"
#include "AnnotationFileReader.hpp"

using namespace std;

void start_server(std::string p_ip, int p_port, std::string p_filename)
{
  valeo::internship::DataTransmetter l_server(p_ip, p_port);
  l_server.setInputFileName(p_filename);
  if(l_server.getIp()!="123.4.5.6")
  {
    cout << "ServerIpManagement NOK" << endl;
  }
  l_server.setIp("127.0.0.1");
  if(l_server.getIp()!="127.0.0.1")
  {
    cout << "ServerIpManagement NOK" << endl;
  }
  if(l_server.getPort()!=12345)
  {
    cout << "ServerPortManagement NOK" << endl;
  }
  l_server.setPort(12300);
  if(l_server.getPort()!=12300)
  {
    cout << "ServerPortManagement NOK" << endl;
  }
  if(l_server.getOutputFilename()!=p_filename)
  {
    cout << "ServerFileManagement NOK" << endl;
  }
  l_server.start();
}

void start_client(std::string p_ip, int p_port, std::string p_filename)
{
  valeo::internship::DataReceiver l_client(p_ip, p_port);
  l_client.setOutputFilename(p_filename);
  if(l_client.getIp()!="123.4.5.6")
  {
    cout << "ClientIpManagement NOK" << endl;
  }
  l_client.setIp("127.0.0.1");
  if(l_client.getIp()!="127.0.0.1")
  {
    cout << "ClientIpManagement NOK" << endl;
  }
  if(l_client.getPort()!=12345)
  {
    cout << "ClientPortManagement NOK" << endl;
  }
  l_client.setPort(12300);
  if(l_client.getPort()!=12300)
  {
    cout << "ClientPortManagement NOK" << endl;
  }
  if(l_client.getInputFilename()!=p_filename)
  {
    cout << "ClientFileManagement NOK" << endl;
  }
  l_client.start();// try to connecte to the server
  while(l_client.isConnected())
  {
    usleep(1000);// getting data from the server and saving it in an output file
  }
  l_client.stop();// closing all
}
int main(int argc, char* argv[])
{
  cout << "[Info] Application to test if all the requirement is satisfy." << endl;
  void* l_metadata = malloc(sizeof(metadata_t));
  valeo::internship::AnnotationFileReader l_reader("../data/annotation.txt", l_metadata);
  thread svrThd(start_server, "127.0.0.1", 12345,"../data/annotation.txt");
  usleep(1000); // wait a while to let the server start before to start client
  thread cltThd(start_client, "123.4.5.6", 12300, "../data/bb_annotation.txt");
  cout << "Filename : " << l_reader.getFilename() << endl;
  if(svrThd.joinable())
  {
    svrThd.join();
  }
  if(cltThd.joinable())
  {
    cltThd.join();
  }
  if(l_reader.open())
  {
    metadata_t l_info;
    l_info.frameId = -1;
    while(l_reader.getNext())
    {
      l_info = *(static_cast<metadata_t*>(l_metadata));
      cout << "FrameId = " << l_info.frameId << endl;
      cout << "\tCenter x="<< l_info.center.x << ", y= " << l_info.center.y << endl;
      cout << "\tBoundingBox = [upperLeft x= " << l_info.bb.upperLeft.x << ", y= " << l_info.bb.upperLeft.y << "] [lowerLeft x=";
      cout << l_info.bb.lowerRight.x << ", y= " << l_info.bb.lowerRight.y << "] " << endl;
      if((l_info.center.x>0) && (l_info.center.y>0))
      {
        if((l_info.bb.lowerRight.x==-1) && (l_info.bb.lowerRight.y) && (l_info.bb.upperLeft.x==-1) && (l_info.bb.upperLeft.y))
        {
          cout << "AnnotationWriter NOK " << endl;
          cout << "BoundingBox NOK " << endl;
          break;
        }
      }
    }
    l_reader.close();
    if(l_info.frameId==-1)
    {
      cout << "AnnotationReader NOK " << endl;
    }
  }
  else
  {
    cout << "AnnotationWriter NOK " << endl;
    cout << "AnnotationReader NOK " << endl;
  }
  cout << "[Info] End of program" << endl;
  free(l_metadata);
  return 0;
}
