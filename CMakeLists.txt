cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Asistencia VERSION 1.0)

find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (tutorial ${SQLITE3_LIBRARIES})
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)