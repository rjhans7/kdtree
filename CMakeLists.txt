# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

cmake_minimum_required(VERSION 3.1...3.15)

project( main )


# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )


if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

  message(STATUS "This project requires the Boost library, and will not be compiled.")

  return()  

endif()

# include for local directory

# include for local package

find_package(Eigen3 3.1.91) #(requires 3.2.0 or greater)
include(CGAL_Eigen_support)


if (NOT TARGET CGAL::Eigen_support)
  message(STATUS "This project requires the Eigen library, and will not be compiled.")

  return()  

endif()


# Creating entries for target: main
# ############################
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})


add_executable( main  main.cpp )

add_to_cached_list( CGAL_EXECUTABLE_TARGETS main )

find_package( Threads )
# Link the executable to CGAL and third-party libraries
target_link_libraries(main PRIVATE CGAL::CGAL PUBLIC CGAL::Eigen_support ${X11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

