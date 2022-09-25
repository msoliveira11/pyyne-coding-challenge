#include <bank_interfaces/bank2/Bank2AccountSource.hpp>
#include <memory>
#include <iostream>
#include <list>
#include <common/LogToScreen.hpp>

using namespace com::bank2::integration;

Bank2AccountSource m_bank2AccountSource;
Bank2AccountBalance m_bank2AccountBalance(10.0, "BRL");
Bank2AccountTransaction m_bank2AccountTransaction(25.4, TRANSACTION_TYPES::DEBIT, "Netflix");

bool bank2BalanceTest() {
    bool result = (m_bank2AccountBalance.getBalance() == 10.0) ? true : false;
    result &= (m_bank2AccountBalance.getCurrency() == "BRL") ? true : false;

    std::string outputTestResult = "bank2BalanceTest";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen(outputTestResult);

    return result;
}

bool bank2TransactionTest() {
    bool result = (m_bank2AccountTransaction.getAmount() == 25.4) ? true : false;
    result &= (m_bank2AccountTransaction.getType() == TRANSACTION_TYPES::DEBIT) ? true : false;
    result &= (m_bank2AccountTransaction.getText() == "Netflix") ? true : false;

    std::string outputTestResult = "bank2TransactionTest";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen(outputTestResult);

    return result;
}

bool bank2SourceTest() {
    Bank2AccountBalance testBalance = m_bank2AccountSource.getBalance(123456);
    
    bool result = (testBalance.getBalance() == 512.5) ? true : false;
    
    std::list<Bank2AccountTransaction> testTransactions = m_bank2AccountSource.getTransactions(123456, Date(), Date());

    std::list<double> amounts = {125.0, 500.0, 800.0};
    std::list<TRANSACTION_TYPES> types = {TRANSACTION_TYPES::DEBIT,
                                          TRANSACTION_TYPES::DEBIT,
                                          TRANSACTION_TYPES::CREDIT};
    std::list<std::string> texts = {"Amazon.com",
                                    "Car insurance",
                                    "Salary"};

    for (auto& transaction : testTransactions) {
        result &= (transaction.getAmount() == amounts.front()) ? true : false;
        result &= (transaction.getType() == types.front()) ? true : false;
        result &= (transaction.getText() == texts.front()) ? true : false;
        amounts.pop_front();
        types.pop_front();
        texts.pop_front();
    }

    std::string outputTestResult = "bank2SourceTest";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen(outputTestResult);

    return result;
}

void bank2Tests() {

    logToScreen("------------------ Bank2 Tests Begin ------------------");
    bool result = bank2BalanceTest();
    result &= bank2TransactionTest();
    result &= bank2SourceTest();

    std::string outputTestResult = "bank2Tests";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen("------------------- Bank2 Tests End -------------------");
}