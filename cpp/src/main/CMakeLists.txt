add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} 
        bankController
        common)

target_include_directories(${PROJECT_NAME}
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
)
