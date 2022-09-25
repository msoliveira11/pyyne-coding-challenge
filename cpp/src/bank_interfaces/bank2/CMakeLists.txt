add_library(bank2 Bank2AccountSource.cpp Bank2AccountTransaction.cpp Bank2AccountBalance.cpp)

target_include_directories(bank2
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
)