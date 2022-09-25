#include <bank_interfaces/adapter/BankAdapter.hpp>

using namespace com;
using namespace com::bank1::integration;
using namespace com::bank2::integration;

BankAdapter::BankAdapter(Bank1AccountSource* bank1) {
    m_returnAccountBalance = [bank1] (long accountId) -> AccountBalance {
        AccountBalance accountBalanceToBeReturned;
        accountBalanceToBeReturned.balance = bank1->getAccountBalance(accountId);
        accountBalanceToBeReturned.currency = bank1->getAccountCurrency(accountId);
        return accountBalanceToBeReturned;
    };

    m_returnTransactions = [bank1] (long accountId, Date fromDate, Date toDate) -> std::list<Transaction> {
        std::list<Transaction> transactionsToBeReturned;
        for (auto& transaction : bank1->getTransactions(accountId, fromDate, toDate)) {
            Transaction bank1Transaction;
            bank1Transaction.amount = transaction.getAmount();
            bank1Transaction.type = transaction.getType();
            bank1Transaction.description = transaction.getText();
            transactionsToBeReturned.push_back(bank1Transaction);
        }
        return transactionsToBeReturned;
    };
}

BankAdapter::BankAdapter(Bank2AccountSource* bank2) {
        m_returnAccountBalance = [bank2] (long accountId) -> AccountBalance {
        AccountBalance accountBalanceToBeReturned;
        accountBalanceToBeReturned.balance = (bank2->getBalance(accountId)).getBalance();
        accountBalanceToBeReturned.currency = (bank2->getBalance(accountId)).getCurrency();
        return accountBalanceToBeReturned;
    };

    m_returnTransactions = [bank2] (long accountId, Date fromDate, Date toDate) -> std::list<Transaction> {
        std::list<Transaction> transactionsToBeReturned;
        for (auto& transaction : bank2->getTransactions(accountId, fromDate, toDate)) {
            Transaction bank2Transaction;
            bank2Transaction.amount = transaction.getAmount();
            bank2Transaction.type = static_cast<int>(transaction.getType());
            bank2Transaction.description = transaction.getText();
            transactionsToBeReturned.push_back(bank2Transaction);
        }
        return transactionsToBeReturned;
    };
}

AccountBalance BankAdapter::getBalance(long accountId) {
    return m_returnAccountBalance(accountId);
}

std::list<Transaction> BankAdapter::getTransactions(long accountId, Date fromDate, Date toDate) {
    return m_returnTransactions(accountId, fromDate, toDate);
}
