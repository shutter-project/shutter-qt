cmake_minimum_required(VERSION 3.19)
project(shutter LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(shutter
    WIN32 MACOSX_BUNDLE
    main.cpp
    shuttermainwindow.cpp
    shuttermainwindow.h
    shuttermainwindow.ui
)

qt_add_translations(
    TARGETS shutter
    TS_FILES shutter_ru_RU.ts
)

target_link_libraries(shutter
    PRIVATE
        Qt::Core
        Qt::Widgets
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
