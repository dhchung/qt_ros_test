cmake_minimum_required(VERSION 3.5)

project(ros_qt_integration_test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  rosbag
  geometry_msgs
  sensor_msgs
)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

catkin_package(
    CATKIN_DEPENDS
        rosbag
        roscpp
)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB CLASS_SOURCES
    "classes/*")

include_directories(classes/
                    ${catkin_INCLUDE_DIRS})


add_executable(${PROJECT_NAME}
               main.cpp
               mainwindow.cpp
               mainwindow.h
               mainwindow.ui
               myglwidget.cpp
               myglwidget.h
               ${CLASS_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets
                      ${catkin_LIBRARIES})
