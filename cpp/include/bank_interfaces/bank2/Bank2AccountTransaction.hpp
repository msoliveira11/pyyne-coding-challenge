#ifndef BANK2_ACCOUNT_TRANSACTION_HPP
#define BANK2_ACCOUNT_TRANSACTION_HPP

#include <string>

namespace com {
namespace bank2 {
namespace integration {

enum TRANSACTION_TYPES {
                            DEBIT,
                            CREDIT
                        };

class Bank2AccountTransaction 
{
public:

    Bank2AccountTransaction(double amount, TRANSACTION_TYPES type, std::string text);

    double getAmount();

    TRANSACTION_TYPES getType();

    std::string getText();

private:

    double m_amount;
    TRANSACTION_TYPES m_type;
    std::string m_text;

};

}
}
}

#endif