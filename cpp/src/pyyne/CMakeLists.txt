add_library(bankController BankController.cpp)

target_link_libraries(bankController
    PUBLIC
        bank1
        bank2
        bankAdapter
)

target_include_directories(bankController
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PARENT_DIR}/include
)