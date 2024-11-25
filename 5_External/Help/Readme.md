For reading the annotation file you can build the source file testAnnotation.cpp and link it with the library AnnotationReader (You will found it on lib directory).

The following line can help you to build the application :

```text
include_directories(
  include
  inc
)

link_directories(
  lib
  lib/${CMAKE_SYSTEM_NAME}
)

add_executable(
  testAnnotation
  src/testAnnotation.cpp
)

target_link_libraries(
  testAnnotation
  AnnotationReader
)
```
