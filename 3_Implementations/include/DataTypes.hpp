#ifndef DataTypes_hpp
#define DataTypes_hpp
typedef struct{
  int x;
  int y;
}point_t;

typedef struct{
  point_t upperLeft;
  point_t lowerRight;
} boundingBox_t;

typedef struct{
  uint32_t frameId;
  point_t center;
  boundingBox_t bb;
}metadata_t;

#endif
