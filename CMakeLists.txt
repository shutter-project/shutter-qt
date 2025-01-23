cmake_minimum_required(VERSION 3.19)
project(shutter VERSION 0.999.1 LANGUAGES CXX)

configure_file(gen_version.h.in gen_version.h)
add_library(version version.cpp version.h)
target_include_directories(version PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools DBus)

qt_standard_project_setup()

set(CMAKE_AUTORCC true)
qt_add_executable(shutter
    main.cpp
    shutter.qrc
    mainwindow.cpp mainwindow.h mainwindow.ui
    aboutdialog.cpp aboutdialog.h aboutdialog.ui
    singleapp.cpp singleapp.h
    selectionwindow.cpp selectionwindow.h
)

qt_add_translations(
    TARGETS shutter
    TS_FILES shutter_ru_RU.ts
)

target_link_libraries(shutter
    PRIVATE
        Qt::Core
        Qt::DBus
        Qt::Widgets
        version
)

include(GNUInstallDirs)

install(TARGETS shutter
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET shutter
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
