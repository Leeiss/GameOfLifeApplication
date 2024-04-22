cmake_minimum_required(VERSION 3.22)

project(ProyectoQt)

set(required_packages
    build-essential
    qtcreator
    qtbase5-dev
    qt5-qmake
    qt5-doc
    qtbase5-examples
    qtbase5-doc-html
)

foreach(package ${required_packages})
    execute_process(COMMAND sudo apt-get -y install ${package}
                    RESULT_VARIABLE result
                    OUTPUT_QUIET
                    ERROR_QUIET)
    if(NOT ${result} EQUAL 0)
        message(FATAL_ERROR "Не удалось установить пакет ${package}. Пожалуйста, установите его вручную.")
    endif()
endforeach()

find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_executable(ProyectoQt src/mainEjemplo.cpp)


target_link_libraries(ProyectoQt PRIVATE Qt5::Widgets)
