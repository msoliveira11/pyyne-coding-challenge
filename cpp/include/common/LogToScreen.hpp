#ifndef LOG_TO_SCREEN_HPP
#define LOG_TO_SCREEN_HPP

#include <iostream>
#include <iomanip>
#include <bank_interfaces/adapter/BankAdapter.hpp>

void logToScreen(std::string outputString);

void logToScreen(double outputValue);

void logToScreen(int outputValue);

void logToScreen(long accountId, double balanceValue, std::string currency);

void logToScreen(long accountId, com::Transaction transaction);

#endif