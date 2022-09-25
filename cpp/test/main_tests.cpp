#include "bank1_tests.hpp"
#include "bank2_tests.hpp"
#include "bank_adapter_tests.hpp"

int main() {
    bank1Tests();
    bank2Tests();
    bankAdapterTests();
}