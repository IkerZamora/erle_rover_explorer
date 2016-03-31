cmake_minimum_required(VERSION 2.8.3)
project(erle_rover_explorer)

#set(CMAKE_PREFIX_PATH "/usr/local/lib")

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS
  roscpp
  mavros
  mav_msgs
 )

#
###################################
## catkin specific configuration ##
###################################

catkin_package(
  CATKIN_DEPENDS
    roscpp
    mavros
    mav_msgs
)


###########
## Build ##
###########

add_executable(${PROJECT_NAME}
  src/erle_rover_explorer.cpp
)
#
#
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} 	${GAZEBO_LIBRARIES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME})

