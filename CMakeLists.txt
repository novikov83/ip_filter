cmake_minimum_required(VERSION 3.8)

#set(PATCH_VERSION 3)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(ip_filter VERSION 0.0.${PATCH_VERSION})

find_package(GTest)

#option(WITH_BOOST_TEST "Boost tests" ON)

#install(TARGETS helloworld RUNTIME DESTINATION bin)
#install(TARGETS version RUNTIME DESTINATION lib)

add_executable(ip_filter ip_filter.cpp)

add_executable(my_ip_test my_ip_test.cpp)
target_include_directories(my_ip_test PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(my_ip_test PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

set_target_properties(ip_filter PROPERTIES
					CXX_STANDARD 17
					CXX_STANDARD_REQUIRED ON
)
set_target_properties(my_ip_test PROPERTIES
					CXX_STANDARD 17
					CXX_STANDARD_REQUIRED ON
)

target_compile_options(ip_filter PUBLIC -Wall -Wextra -pedantic -Werror)
target_compile_options(my_ip_test PUBLIC -Wall -Wextra -pedantic -Werror)


# Создание пакета deb
# cmake --build . --target package
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT darek@bk.ru)
include(CPack)