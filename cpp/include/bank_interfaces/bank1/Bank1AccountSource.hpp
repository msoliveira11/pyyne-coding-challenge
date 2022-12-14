#ifndef BANK1_ACCOUNT_SOURCE_HPP
#define BANK1_ACCOUNT_SOURCE_HPP

#include <string>
#include <list>
#include <chrono>
#include "Bank1Transaction.hpp"
#include <common/Date.hpp>

namespace com {
namespace bank1 {
namespace integration {

class Bank1AccountSource
{
public:
    Bank1AccountSource() = default;
    
    double getAccountBalance(long accountId);
    std::string getAccountCurrency(long accountId);
    std::list<Bank1Transaction> getTransactions(long accountId, 
                                                Date fromDate,
                                                Date toDate);
};

};
}
}
#endif
