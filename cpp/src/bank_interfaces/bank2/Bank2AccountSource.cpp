#include <bank_interfaces/bank2/Bank2AccountSource.hpp>

using namespace com::bank2::integration;

Bank2AccountBalance Bank2AccountSource::getBalance(long accountNum) {
    return Bank2AccountBalance(512.5, "USD");
}

std::list<Bank2AccountTransaction> Bank2AccountSource::getTransactions(long accountNum, Date fromDate, Date toDate) {
        Bank2AccountTransaction transaction1(125.0, TRANSACTION_TYPES::DEBIT, "Amazon.com");
        Bank2AccountTransaction transaction2(500.0, TRANSACTION_TYPES::DEBIT, "Car insurance");
        Bank2AccountTransaction transaction3(800.0, TRANSACTION_TYPES::CREDIT, "Salary");
        std::list<Bank2AccountTransaction> transactionsList;
        transactionsList.push_back(transaction1);
        transactionsList.push_back(transaction2);
        transactionsList.push_back(transaction3);

        return transactionsList;
}