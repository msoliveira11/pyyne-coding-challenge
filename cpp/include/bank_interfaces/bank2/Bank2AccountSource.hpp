#ifndef BANK2_ACCOUNT_SOURCE_HPP
#define BANK2_ACCOUNT_SOURCE_HPP

#include <common/Date.hpp>
#include <list>
#include "Bank2AccountBalance.hpp"
#include "Bank2AccountTransaction.hpp"

namespace com {
namespace bank2 {
namespace integration {

class Bank2AccountSource 
{
public:

    Bank2AccountBalance getBalance(long accountNum);

    std::list<Bank2AccountTransaction> getTransactions(long accountNum, Date fromDate, Date toDate);

};

}
}
}

#endif