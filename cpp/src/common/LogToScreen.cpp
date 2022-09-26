
#include <common/LogToScreen.hpp>

void logToScreen(std::string outputString) {
    std::cout << outputString << std::endl;
}

void logToScreen(double outputValue) {
    std::cout << std::fixed << std::setprecision(2) << outputValue << std::endl;
}

void logToScreen(int outputValue) {
    std::cout << std::to_string(outputValue) << std::endl;
}

void logToScreen(long accountId, double balanceValue, std::string currency) {
    std::cout << "Account number: " << std::to_string(accountId)
              << " Balance: " << currency 
              << std::fixed << std::setprecision(2) << balanceValue << std::endl;
}

void logToScreen(long accountId, com::Transaction transaction) {
    std::cout << "Account number: " << std::to_string(accountId)
              << " Transaction Type: " << transaction.type 
              << "  Description: " << transaction.description
              << std::endl;
}
