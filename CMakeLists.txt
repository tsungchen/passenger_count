CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(PassengerStat CXX)

set(OpenCV_Version 300)
set(OpenCV_PATH "D:/opensource/opencv/build/")
set(OpenCV_INCLUDE_DIR "${OpenCV_PATH}include")
set(OpenCV_LIBRARY_DIR "${OpenCV_PATH}x64/vc11/lib")
set(OpenCV_LIBS 
   opencv_core${OpenCV_Version}d.lib 
	opencv_highgui${OpenCV_Version}d.lib 
	opencv_imgproc${OpenCV_Version}d.lib 
#	opencv_contrib${OpenCV_Version}d.lib 
#	opencv_stitching${OpenCV_Version}d.lib 
	opencv_features2d${OpenCV_Version}d.lib
	)

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${OpenCV_LIBRARY_DIR})
LINK_DIRECTORIES(${CMAKE_BINARY_DIR})


IF(NOT IS_DIRECTORY CMAKE_BUILD_TYPE)
  SET(${CMAKE_BUILD_TYPE} Release ... FORCE)
ENDIF()

IF(NOT ${CMAKE_BUILD_TYPE} MATCHES Debug)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -Ofast")
ENDIF()

IF (NOT MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF()

IF(NOT APPLE AND NOT MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
ENDIF()

#SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_OSX_ARCHITECTURES "${ARCHS_STANDARD}")

#FILE(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/source/*")
#ADD_CUSTOM_TARGET( _source SOURCES ${SRC} )

#target_link_libraries(${OpenCV_LIBS})
#PASSEGER_STAT_LIB
FILE(GLOB PASSENGER_STAT_SRC "src/passenger_stat/*.cpp")
FILE(GLOB PASSENGER_STAT_CXX_HEADER "include/passenger_stat/*.hpp")
FILE(GLOB PASSENGER_STAT_C_HEADER "include/passenger_stat/*.h")

source_group("Src" FILES ${PASSENGER_STAT_SRC})
source_group("Include" FILES ${PASSENGER_STAT_CXX_HEADER} ${PASSENGER_STAT_C_HEADER})

# copy COMPILE_DEFINITIONS
ADD_LIBRARY(
    LibPassengeStat SHARED
	${PASSENGER_STAT_SRC}
	${PASSENGER_STAT_CXX_HEADER}
	${PASSENGER_STAT_C_HEADER}
#	${OpenCV_LIBS}
)

TARGET_LINK_LIBRARIES(
    LibPassengeStat
	${OpenCV_LIBS}
)

#add_definitions(LibPassengeStat -DPASSEGER_API_EXPORT)

# test 
ADD_EXECUTABLE(
    test_passenge_stat
	src/test/test_passenge_stat.cpp
)

# TARGET_COMPILE_FEATURES(test_passenge_stat PRIVATE cxx_range_for)

TARGET_LINK_LIBRARIES(
    test_passenge_stat
	LibPassengeStat.lib
	${OpenCV_LIBS}
)

add_dependencies(
    test_passenge_stat
	LibPassengeStat
)

