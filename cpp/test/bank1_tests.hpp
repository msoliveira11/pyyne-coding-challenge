#include <bank_interfaces/bank1/Bank1AccountSource.hpp>
#include <memory>
#include <iostream>
#include <common/LogToScreen.hpp>

using namespace com::bank1::integration;

Bank1Transaction m_bank1Transaction(10.0, Bank1Transaction::TYPE_CREDIT, "test string");
Bank1AccountSource m_bank1Source;

bool bank1TransactionTest() {
    bool result = (m_bank1Transaction.getAmount() == 10.0) ? true : false;
    result &= (m_bank1Transaction.getText() == "test string") ? true : false;
    result &= (m_bank1Transaction.getType() == Bank1Transaction::TYPE_CREDIT) ? true : false;
    
    std::string outputTestResult = "bank1TransactionTest";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen(outputTestResult);
    
    return result;
}

bool bank1AccountSourceTest() {
    bool result = (m_bank1Source.getAccountBalance(123456) == 215.5) ? true : false;
    result &= (m_bank1Source.getAccountCurrency(123456) == "USD") ? true : false;

    std::list<Bank1Transaction> testTransactions = m_bank1Source.getTransactions(123456, Date(), Date());

    std::list<double> amounts = {100.0, 25.5, 225.0};
    std::list<int> types = {Bank1Transaction::TYPE_CREDIT,
                            Bank1Transaction::TYPE_DEBIT,
                            Bank1Transaction::TYPE_DEBIT};
    std::list<std::string> texts = {"Check deposit",
                                    "Debit card purchase",
                                    "Rent payment"};

    for (auto& transaction : testTransactions) {
        result &= (transaction.getAmount() == amounts.front()) ? true : false;
        result &= (transaction.getType() == types.front()) ? true : false;
        result &= (transaction.getText() == texts.front()) ? true : false;
        amounts.pop_front();
        types.pop_front();
        texts.pop_front();
    }

    std::string outputTestResult = "bank1AccountSourceTest";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen(outputTestResult);

    return result;
}

void bank1Tests() {
    logToScreen("------------------ Bank1 Tests Begin ------------------");
    bool result = bank1TransactionTest();
    result &= bank1AccountSourceTest();

    std::string outputTestResult = "bank1Tests";
    outputTestResult += (result) ? " ok" : " failed";

    logToScreen("------------------- Bank1 Tests End -------------------");
}