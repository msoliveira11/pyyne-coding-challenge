#ifndef BANK1_TRANSACTION_HPP
#define BANK1_TRANSACTION_HPP

#include <string>

namespace com {
namespace bank1 {
namespace integration {

class Bank1Transaction
{
public:
    Bank1Transaction(double amount, int type, std::string text);
    double getAmount();
    int getType();
    std::string getText();

public:
    const static int TYPE_CREDIT = 1;
    const static int TYPE_DEBIT = 2;

private:
    double m_amount;
    int m_type;
    std::string m_text;
};

};
}
}
#endif