#ifndef BANK_ADAPTER_HPP
#define BANK_ADAPTER_HPP

#include <list>
#include <functional>
#include <memory>
#include <common/Date.hpp>
#include <bank_interfaces/bank1/Bank1AccountSource.hpp>
#include <bank_interfaces/bank2/Bank2AccountSource.hpp>

namespace com {

struct AccountBalance {
    double balance;
    std::string currency;
};

struct Transaction {
    double amount;
    int type;
    std::string description;
};

class BankAdapter {
private:
    std::function<AccountBalance(long)> m_returnAccountBalance;
    std::function<std::list<Transaction>(long, Date, Date)> m_returnTransactions;

public:
    BankAdapter(std::shared_ptr<bank1::integration::Bank1AccountSource> bank1);
    BankAdapter(std::shared_ptr<bank2::integration::Bank2AccountSource> bank2);

    AccountBalance getBalance(long accountId);
    std::list<Transaction> getTransactions(long accountId, Date fromDate, Date toDate);
};

}
#endif