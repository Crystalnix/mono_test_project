cmake_minimum_required(VERSION 2.4)
PROJECT(dbusproxy)

find_package(PkgConfig)

pkg_check_modules(DBUS REQUIRED dbus-glib-1)
pkg_search_module(GLIB2 REQUIRED glib-2.0)
include_directories(${DBUS_INCLUDE_DIRS} ${GLIB2_INCLUDE_DIRS})
set(LIBS ${LIBS} ${DBUS_LIBRARIES} ${GLIB2_LIBRARIES})

link_libraries(${LIBS})
ADD_EXECUTABLE(dbusproxy main.cpp)

