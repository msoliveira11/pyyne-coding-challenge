add_executable(unit_tests main_tests.cpp)

# find_package(Boost 1.74.0 REQUIRED
#     COMPONENTS
#     unit_test_framework
# )

target_link_libraries(unit_tests
    PUBLIC
        # ${Boost_LIBRARIES}
        bank1
        bank2
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
        # ${Boost_INCLUDE_DIRS}
)

