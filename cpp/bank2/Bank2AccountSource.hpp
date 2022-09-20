#include <date.hpp>
#include <list>
#include <Bank2AccountBalance.hpp>
#include <Bank2AccountTransaction.hpp>

namespace com {
namespace bank2 {
namespace integration {

class Bank2AccountSource 
{
    Bank2AccountBalance getBalance(long accountNum) {
        return Bank2AccountBalance(512.5, "USD");
    }

    std::list<Bank2AccountTransaction> getTransactions(long accountNum, Date fromDate, Date toDate) {
        Bank2AccountTransaction transaction1(125.0, TRANSACTION_TYPES::DEBIT, "Amazon.com");
        Bank2AccountTransaction transaction2(500.0, TRANSACTION_TYPES::DEBIT, "Car insurance");
        Bank2AccountTransaction transaction3(800.0, TRANSACTION_TYPES::CREDIT, "Salary");
        std::list<Bank2AccountTransaction> transactionsList;
        transactionsList.push_back(transaction1);
        transactionsList.push_back(transaction2);
        transactionsList.push_back(transaction3);

        return transactionsList;
    }

};

}
}
}