cmake_minimum_required(VERSION 3.16)

project(internship_challenge)

# enable_testing()

include_directories(
  include
)

file(GLOB SRC "src/*.cpp")

message("source file : " ${SRC})
add_library(
  ${PROJECT_NAME}
  SHARED
  ${SRC}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery/lib)
install(DIRECTORY include DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery)
install(DIRECTORY ${CMAKE_HOME_DIRECTORY}/5_External/Help/data DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery)
install(DIRECTORY ${CMAKE_HOME_DIRECTORY}/5_External/Help/lib DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery)
install(FILES ${CMAKE_HOME_DIRECTORY}/5_External/Help/src/integrationApplication.cpp DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery/src)
install(FILES ${CMAKE_HOME_DIRECTORY}/5_External/Help/inc/AnnotationFileReader.hpp DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery/inc)
install(FILES ${CMAKE_HOME_DIRECTORY}/5_External/Help/CMakeLists.txt DESTINATION ${CMAKE_HOME_DIRECTORY}/delivery)
#To be continued