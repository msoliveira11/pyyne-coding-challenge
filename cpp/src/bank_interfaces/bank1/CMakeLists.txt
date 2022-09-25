add_library(bank1 Bank1AccountSource.cpp Bank1Transaction.cpp)

target_include_directories(bank1
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
)