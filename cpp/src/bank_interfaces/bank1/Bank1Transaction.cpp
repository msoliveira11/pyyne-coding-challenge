#include <bank_interfaces/bank1/Bank1Transaction.hpp>

using namespace com::bank1::integration;

Bank1Transaction::Bank1Transaction(double amount, int type, std::string text) {
    m_amount = amount;
    m_type = type;
    m_text = text;
}

double Bank1Transaction::getAmount() {
    return m_amount;
}

int Bank1Transaction::getType() {
    return m_type;
}

std::string Bank1Transaction::getText() {
    return m_text;
}
