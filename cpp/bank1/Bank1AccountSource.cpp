#include "Bank1AccountSource.hpp"

using namespace com::bank1::integration;

double Bank1AccountSource::getAccountBalance(long accountId) {
    return 215.5;
}

std::string Bank1AccountSource::getAccountCurrency(long accountId) {
    return "USD";
}

std::list<Bank1Transaction> Bank1AccountSource::getTransactions(long accountId, Date fromDate, Date toDate) {
    Bank1Transaction trans1(100.0, Bank1Transaction::TYPE_CREDIT, "Check deposit");
    Bank1Transaction trans2(25.5, Bank1Transaction::TYPE_DEBIT, "Debit card purchase");
    Bank1Transaction trans3(225.0, Bank1Transaction::TYPE_DEBIT, "Rent payment");
    std::list<Bank1Transaction> transactionsList;
    transactionsList.push_back(trans1);
    transactionsList.push_back(trans2);
    transactionsList.push_back(trans3);
    return transactionsList;
}