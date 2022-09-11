#include <string>

namespace com {
    namespace bank1 {
        namespace integration {
            class Bank1Transaction
            {
            public:
                Bank1Transaction(double amount, int type, std::string text);
                virtual ~Bank1Transaction() = 0;
                double getAmount();
                int getType();
                std::string getText();
            
            public:
                static int TYPE_CREDIT;
                static int TYPE_DEBIT;
            
            private:
                double amount;
                int type;
                std::string text;
            };
        };
    }
}