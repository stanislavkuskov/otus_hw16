cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
    project(rclst VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(rclst VERSION 0.0.0)
endif()

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(rclst main.cpp)

target_link_libraries(rclst dlib)
target_link_libraries(rclst openblas)

set_target_properties(rclst PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

install(TARGETS rclst RUNTIME DESTINATION bin)


set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT kuskov.stanislav@gmail.com)

include(CPack)