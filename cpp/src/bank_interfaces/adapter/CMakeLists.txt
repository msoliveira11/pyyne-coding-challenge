add_library(bankAdapter BankAdapter.cpp)

target_link_libraries(bankAdapter
    PUBLIC
        bank1
        bank2
)

target_include_directories(bankAdapter
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
)