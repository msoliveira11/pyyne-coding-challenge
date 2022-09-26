#ifndef BANK_CONTROLLER_HPP
#define BANK_CONTROLLER_HPP

#include <vector>
#include <tuple>
#include <common/Date.hpp>
#include <bank_interfaces/bank1/Bank1AccountSource.hpp>
#include <bank_interfaces/bank2/Bank2AccountSource.hpp>
#include <bank_interfaces/adapter/BankAdapter.hpp>
#include <common/LogToScreen.hpp>

namespace com {
namespace pyyne {
namespace challenge {
namespace bank {

typedef std::vector<long> accountIdsVector;
typedef std::vector<accountIdsVector> bankAccountVector;

/* This class was part of the code available to start the solution.
   I used it to fill the missing information needed to simulate the application.
*/
class BankController 
{
public:
    BankController();

    void printBalances();

    void printTransactions(Date fromDate, Date toDate);

private:

    std::vector<std::tuple<long,com::AccountBalance>> getAllBalances();
    std::vector<std::tuple<long,std::list<Transaction>>> getAllTransactions(Date fromDate, Date toDate);
    void populateAccountIdsVector();

    bankAccountVector m_allBanksAccountsVector;
    std::shared_ptr<com::bank1::integration::Bank1AccountSource> m_bank1SourcePtr;
    std::shared_ptr<com::bank2::integration::Bank2AccountSource> m_bank2SourcePtr;
    std::vector<com::BankAdapter> m_bankAdapters;
};

} // namespace bank
} // namespace challenge
} // namespace pyyne
} // namespace com

#endif