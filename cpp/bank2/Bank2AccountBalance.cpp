#include "Bank2AccountBalance.hpp"

using namespace com::bank2::integration;

Bank2AccountBalance::Bank2AccountBalance(double balance, std::string currency) {
    m_balance = balance;
    m_currency = currency;
}

double Bank2AccountBalance::getBalance() {
    return m_balance;
}

std::string Bank2AccountBalance::getCurrency() {
    return m_currency;
}