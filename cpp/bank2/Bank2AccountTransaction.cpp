#include "Bank2AccountTransaction.hpp"

using namespace com::bank2::integration;

Bank2AccountTransaction::Bank2AccountTransaction(double amount, TRANSACTION_TYPES type, std::string text) {
    m_amount = amount;
    m_type = type;
    m_text = text;
}

double Bank2AccountTransaction::getAmount() {
    return m_amount;
}

TRANSACTION_TYPES Bank2AccountTransaction::getType() {
    return m_type;
}

std::string Bank2AccountTransaction::getText() {
    return m_text;
}