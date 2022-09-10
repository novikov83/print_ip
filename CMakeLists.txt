cmake_minimum_required(VERSION 3.8)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(print_ip VERSION 0.0.${PATCH_VERSION})

add_executable(print_ip print_ip.cpp)

set_target_properties(print_ip PROPERTIES
					CXX_STANDARD 17
					CXX_STANDARD_REQUIRED ON
)

target_compile_options(print_ip PUBLIC -Wall -Wextra -pedantic -Werror)

# Создание пакета deb
# cmake --build . --target package
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT darek@bk.ru)
include(CPack)