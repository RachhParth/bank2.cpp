#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int AccountNumber;
    string AccountHolderName;
    int amount;

public:
    void account(int number, string name, int amounts) {
        AccountNumber = number;
        AccountHolderName = name;
        amount = amounts;
    }

    void deposit(int dep) {
        amount += dep;
        cout << "Amount added successfully!\n";
    }

    void getbalance() {
        cout << "Balance : " << amount << endl;
    }

    void displayAccountInfo() {
        cout << "Account Number : " << AccountNumber << endl;
        cout << "Account Holder Name : " << AccountHolderName << endl;
        cout << "Account Balance : " << amount << endl;
    }
};

class SavingAccount : public BankAccount {
    int interestrate;

public:
    void saving(int number, string name, int amounts, int rate) {
        account(number, name, amounts);
        interestrate = rate;
    }

    void calculateInterest() {
        amount += amount * interestrate / 100;
        cout << "Total Amount with interest : " << amount << endl;
    }
};

class CheckingAccount : public BankAccount {
    int overdraftlimit;

public:
    void checking(int number, string name, int amounts, int limit) {
        account(number, name, amounts);
        overdraftlimit = limit;
    }

    void withdraw(int withdrawamount) {
        if (withdrawamount <= amount + overdraftlimit) {
            amount -= withdrawamount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }
};

class FixedDepositAccount : public BankAccount {
    int term;
public:
    void fixed(int number, string name, int amounts, int terms) {
        account(number, name, amounts);
        term = terms;
    }

    void calculateMaturityAmount(int rate) {
        int maturityAmount = amount + (amount * rate * term) / 100;
        cout << "Maturity Amount after " << term << " years: " << maturityAmount << endl;
    }
};