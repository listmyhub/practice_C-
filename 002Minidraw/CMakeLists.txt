cmake_minimum_required(VERSION 3.19)
project(mytest LANGUAGES CXX)

set(CMAKE_PREFIX_PATH D:\\qt1\\6.11.1\\msvc2022_64)
find_package(Qt6  REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(mytest
    WIN32 MACOSX_BUNDLE
    main.cpp
    minidraw.cpp
    minidraw.h
    minidraw.ui
    viewwidget.cpp
    viewwidget.h
   viewwidget.ui
   Shape.h
   Shape.cpp
   Line.h
   Line.cpp
   Ellipse.h
   Ellipse.cpp
   Rect.h
   Rect.cpp
   Poly.h
   Poly.cpp
)

target_link_libraries(mytest
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS mytest
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET mytest
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
