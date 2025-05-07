#include <iostream>

class BankAccount
{
    private:
        double balance;
    public:
        void deposit (double amount) {
            if (amount > 0){
                balance += amount;
            }
        }
        void initAccount() {
            balance = 0;
        }

        double getBalance() const {
            return balance;
        }
};

void previewBalance (const BankAccount& account)
{
    std::cout << account.getBalance() << std::endl;
} 

int main() 
{
    BankAccount b1;
    BankAccount b2;
    b1.initAccount();
    b2.initAccount();
    b1.deposit(1000);
    b2.deposit(10);

    previewBalance(b1);
    previewBalance(b2);
    return 0;
}