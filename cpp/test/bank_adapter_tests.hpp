#include <bank_interfaces/adapter/BankAdapter.hpp>
#include <memory>
#include <iostream>
#include <common/LogToScreen.hpp>

using namespace com;
using namespace com::bank1::integration;
using namespace com::bank2::integration;

std::shared_ptr<Bank1AccountSource> m_bank1AccountSourcePtr;
std::shared_ptr<Bank2AccountSource> m_bank2AccountSourcePtr;

bool getBalanceTest() {

    m_bank1AccountSourcePtr = std::make_shared<Bank1AccountSource>();
    m_bank2AccountSourcePtr = std::make_shared<Bank2AccountSource>();

    BankAdapter bank1Adapter(m_bank1AccountSourcePtr);
    BankAdapter bank2Adapter(m_bank2AccountSourcePtr);

    long fakeAccountId = 123456;

    logToScreen(bank1Adapter.getBalance(fakeAccountId).balance);
    logToScreen(bank1Adapter.getBalance(fakeAccountId).currency);
    logToScreen(bank2Adapter.getBalance(fakeAccountId).balance);
    logToScreen(bank2Adapter.getBalance(fakeAccountId).currency);

    return true;
}

bool getTransactionsTest() {
    m_bank1AccountSourcePtr = std::make_shared<Bank1AccountSource>();
    m_bank2AccountSourcePtr = std::make_shared<Bank2AccountSource>();

    BankAdapter bank1Adapter(m_bank1AccountSourcePtr);
    BankAdapter bank2Adapter(m_bank2AccountSourcePtr);

    long fakeAccountId = 123456;
    Date fakeFromDate;
    Date fakeToDate;
    
    for (const auto& transaction : bank1Adapter.getTransactions(fakeAccountId, fakeFromDate, fakeToDate)) {
        logToScreen(fakeAccountId, transaction);

    }
    for (const auto& transaction : bank2Adapter.getTransactions(fakeAccountId, fakeFromDate, fakeToDate)) {
        logToScreen(fakeAccountId, transaction);
    }

    return true;
}

void bankAdapterTests() {
    logToScreen("------------------ Bank Adapter Tests Begin ------------------");
    bool result = getBalanceTest();
    result &= getTransactionsTest();

    std::string outputTestResult = "bankAdapterTests";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen("------------------- Bank Adapter Tests End -------------------");
}