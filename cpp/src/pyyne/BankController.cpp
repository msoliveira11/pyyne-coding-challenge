#include <pyyne/BankController.hpp>

using namespace com::pyyne::challenge::bank;
using namespace com::bank1::integration;
using namespace com::bank2::integration;
using namespace com;

BankController::BankController() {

    m_bank1SourcePtr = std::make_shared<Bank1AccountSource>();
    m_bank2SourcePtr = std::make_shared<Bank2AccountSource>();
    m_bankAdapters.push_back(BankAdapter(m_bank1SourcePtr));
    m_bankAdapters.push_back(BankAdapter(m_bank2SourcePtr));
    this->populateAccountIdsVector();

}

void BankController::populateAccountIdsVector() {

    accountIdsVector bank1Accounts;
    bank1Accounts.push_back(123456);
    accountIdsVector bank2Accounts;
    bank1Accounts.push_back(234567);
    m_allBanksAccountsVector.push_back(bank1Accounts);
    m_allBanksAccountsVector.push_back(bank2Accounts);

}

void BankController::printBalances() {

    for (auto& balance : this->getAllBalances()) {
        long accountId = std::get<0>(balance);
        double balanceValue = std::get<1>(balance).balance;
        std::string balanceCurrency = std::get<1>(balance).currency;
        logToScreen(accountId, balanceValue, balanceCurrency);
    }

}

std::vector<std::tuple<long,AccountBalance>> BankController::getAllBalances() {

    std::vector<std::tuple<long,AccountBalance>> balances;

    for (std::size_t bankIndex = 0; bankIndex < m_bankAdapters.size(); ++bankIndex) {
        for (auto& accountId : m_allBanksAccountsVector[bankIndex]) {
            std::tuple<long, AccountBalance> newAccountBalance 
                = std::make_tuple(accountId,m_bankAdapters[bankIndex].getBalance(accountId));
            balances.push_back(newAccountBalance);
        }
    }
    
    return balances;
}

void BankController::printTransactions(Date fromDate, Date toDate) {

    for (auto& transactionList : this->getAllTransactions(fromDate, toDate)) {
        long accountId = std::get<0>(transactionList);
        for (auto& transaction : std::get<1>(transactionList)) {
            logToScreen(accountId, transaction);
        }
    }
}

std::vector<std::tuple<long,std::list<Transaction>>> BankController::getAllTransactions(Date fromDate, Date toDate) {

    std::vector<std::tuple<long,std::list<Transaction>>> transactions;

    for (std::size_t bankIndex = 0; bankIndex < m_bankAdapters.size(); ++bankIndex) {
        for (auto& accountId : m_allBanksAccountsVector[bankIndex]) {
            std::tuple<long, std::list<Transaction>> newTransaction
                = std::make_tuple(accountId,m_bankAdapters[bankIndex].getTransactions(accountId,fromDate,toDate));
            transactions.push_back(newTransaction);
        }
    }
    
    return transactions;
}