#include <string>

namespace com {
namespace bank2 {
namespace integration {

class Bank2AccountBalance 
{
public:
    Bank2AccountBalance(double balance, std::string);
    double getBalance();
    std::string getCurrency();
private:
    double m_balance;
    std::string m_currency;
};
   
}
}
}