#ifndef LOG_TO_SCREEN_HPP
#define LOG_TO_SCREEN_HPP

#include <iostream>
#include <iomanip>

void logToScreen(std::string outputString) {
    std::cout << outputString << std::endl;
}

void logToScreen(double outputValue) {
    std::cout << std::fixed << std::setprecision(2) << outputValue << std::endl;
}

void logToScreen(int outputValue) {
    std::cout << std::to_string(outputValue) << std::endl;
}

#endif