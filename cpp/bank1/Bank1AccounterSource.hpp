#include <string>
#include <list>
#include <chrono>
#include "Bank1Transaction.hpp"

namespace com {
    namespace bank1 {
        namespace integration {
            class Bank1AccounterSource
            {
            public:
                Bank1AccounterSource() = default;
                virtual ~Bank1AccounterSource() = 0;
                double getAccountBalance(long accountId);
                std::string getAccountCurrency(long accountId);
                std::list<Bank1Transaction> getTransactions(long accountId, 
                                                            Date fromDate,
                                                            Date toDate);


            };
        };
    }
}
