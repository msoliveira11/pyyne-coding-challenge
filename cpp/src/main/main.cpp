#include <pyyne/BankController.hpp>
#include <common/LogToScreen.hpp>
#include <common/Date.hpp>

using namespace com::pyyne::challenge::bank;

int main(int, char**) {
    std::unique_ptr<BankController> controller = 
        std::make_unique<BankController>();

    logToScreen("Retrieving account balances:");
    controller->printBalances();

    logToScreen("Retrieving account transactions:");
    Date toDate;
    Date fromDate;
    controller->printTransactions(fromDate,toDate);
}
