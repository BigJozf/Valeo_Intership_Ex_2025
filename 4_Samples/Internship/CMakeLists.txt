cmake_minimum_required(VERSION 3.16)

find_package(OpenCV)

include_directories(
  inc
  ../../3_Implementations/inc
  ../../5_External/include
)

link_directories(
  ../5_External/include/${CMAKE_SYSTEM_NAME}
)

if( EXISTS ${OpenCV_DIR} )
  add_executable(
    internshipProg
    src/prog2.cpp
  )
  target_link_libraries(
    internshipProg
    ${OpenCV_LIBS}
  )
else()
  add_executable(
    internshipProg
    src/prog1.cpp
  )
endif()

install(TARGETS internshipProg DESTINATION $ENV{PWD}/delivery/bin)