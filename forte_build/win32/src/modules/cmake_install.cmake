# Install script for directory: C:/Users/Bruno/Documents/4DIAC/forte_2.0.1/src/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/FORTE")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/IEC61131-3/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/PLC01A1/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/ads/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/arrowhead/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/conmeleon_c1/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/convert/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/embrick/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/i2c_dev/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/lms_ev3/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/mlpi/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/odroid/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/piface/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/raspberry_sps/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/reconfiguration/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/rt_events/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/sysfs/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/umic/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/utils/cmake_install.cmake")
  include("C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/wagokbus/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Bruno/Documents/4DIAC/forte_build/win32/src/modules/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
