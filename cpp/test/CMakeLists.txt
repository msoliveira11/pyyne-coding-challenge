add_executable(unit_tests main_tests.cpp)

target_link_libraries(unit_tests
    PUBLIC
        bank1
        bank2
        bankAdapter
        common
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
)

