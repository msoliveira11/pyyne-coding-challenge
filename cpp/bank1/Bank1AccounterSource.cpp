#include "Bank1AccounterSource.hpp"

using namespace com::bank1::integration;

double Bank1AccounterSource::getAccountBalance(long accountId) {
    return 215.5;
}

std::string Bank1AccounterSource::getAccountCurrency(long accountId) {
    return "USD";
}

std::list<Bank1Transaction> Bank1AccounterSource::getTransactions(long accountId, Date fromDate, Date toDate) {
    Bank1Transaction trans1;
    Bank1Transaction trans2;
    Bank1Transaction trans3;
    std::list<Bank1Transaction> transactionsList;
    transactionsList.push_back(trans1);
    transactionsList.push_back(trans2);
    transactionsList.push_back(trans3);
    return transactionsList;
}