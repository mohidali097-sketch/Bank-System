#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 100

int SIZE = 3;


class User 
{

protected:

    string username;
    string password;

public:

    User(string uname, string pass)
    {
        username = uname;
        password = pass;
    }

    virtual bool login(string uname, string pass) 
    {
        return (uname == username && pass == password);
    }

    virtual void showMenu() = 0;

};


class Customer : public User 
{

private:

    float balance;

public:

    Customer(string uname, string pass) : User(uname, pass), balance(0.0f) {}

    void deposit(float amount) 
    {

        if (amount > 0) 
        {
            balance += amount;
            cout << "Amount deposited successfully. New balance: " << balance << endl;
        }

        else 
        {
            cout << "Invalid amount." << endl;
        }

    }

    void withdraw(float amount) 
    {

        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            cout << "Amount withdrawn successfully. New balance: " << balance << endl;
        }

        else 
        {
            cout << "Invalid amount or insufficient balance" << endl;
        }

    }

    void showMenu() override 
    {

        int option;

        do 
        {

            cout << "\nCustomer Menu:" << endl;
            cout << "1. View Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Logout" << endl;

            cout << "Choose option: ";
            cin >> option;

            if (option == 1) 
            {
                cout << "Your current balance is: " << balance << endl;
            }

            else if (option == 2) 
            {
                float amount;
                cout << "Enter the amount you want to deposit: ";
                cin >> amount;
                deposit(amount);
            }

            else if (option == 3) 
            {
                float amount;
                cout << "Enter the amount you want to withdraw: ";
                cin >> amount;
                withdraw(amount);
            }

            else if (option == 4) 
            {
                cout << "Logging out..." << endl;
            }

            else 
            {
                cout << "Invalid option." << endl;
            }

        } while (option != 4);

    }

};


class Admin : public User 
{

public:

    Admin(string uname, string pass) : User(uname, pass) {}

    void showMenu() override 
    {
        cout << "Admin logged in." << endl;
    }

};


class BankSystem 
{

    vector<Customer> customers;
    Admin admin;

public:

    BankSystem() : admin("admin", "admin1235") 
    {
        customers.push_back(Customer("wahab", "aw12345"));
        customers.push_back(Customer("mohid", "mohid12345"));
    }

    bool adminLogin() 
    {

        string uname, pass;
        cout << "Enter Admin Username: ";
        cin >> uname;
        cout << "Enter Admin Password: ";
        cin >> pass;

        if (admin.login(uname, pass)) 
        {
            cout << "Admin Login Successful!" << endl;
            return true;
        }

        else 
        {
            cout << "Admin Login Failed!" << endl;
            return false;
        }

    }


    Customer* customerLogin() 
    {

        string uname, pass;
        cout << "Enter Customer Username: ";
        cin >> uname;
        cout << "Enter Customer Password: ";
        cin >> pass;

        for (auto& cust : customers) 
        {
            if (cust.login(uname, pass)) 
            {
                cout << "Customer Login Successful!" << endl;
                return &cust;
            }
        }

        cout << "Invalid customer credentials." << endl;
        return nullptr;

    }

    vector<Customer>& getCustomers() 
    {
        return customers;
    }

};


class Account 
{

private:

    int accountNumber;
    string accountHolderName;
    int accountBalance;

public:

    Account() 
    {
        accountNumber = 0;
        accountHolderName = "";
        accountBalance = 0;
    }

    void createAccount() 
    {
        cout << "Enter the account number : ";
        cin >> accountNumber;
        cout << "Enter the account holder name : ";
        cin >> accountHolderName;
        cout << "Enter the balance : ";
        cin >> accountBalance;
        cout << endl;
    }

    void displayAccounts() 
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Balance : " << accountBalance << endl;
    }

    void updateInfo(Account accounts[]) 
    {

        int accNumber, choice = 0;
        bool found = false;

        do 
        {

            cout << "Enter the account number whose information you want to change : ";
            cin >> accNumber;
            found = false;

            for (int i = 0; i < SIZE; i++) 
            {
                if (accounts[i].accountNumber == accNumber) 
                {
                    found = true;

                    do 
                    {

                        cout << "\n1. Change account number." << endl;
                        cout << "2. Change account holder name." << endl;
                        cout << "3. Exit." << endl;

                        cout << "\nEnter the choice : ";
                        cin >> choice;

                        if (choice == 1) 
                        {
                            cout << "Enter the new account number : ";
                            cin >> accounts[i].accountNumber;
                        }

                        else if (choice == 2) 
                        {
                            cout << "Enter the new account holder name : ";
                            cin >> accounts[i].accountHolderName;
                        }

                        else if (choice == 3) 
                        {
                            cout << "Exiting update menu.\n";
                        }

                        else 
                        {
                            cout << "Invalid choice. Try again.\n";
                        }

                    } while (choice != 3);

                    break;

                }

            }

            if (!found) 
            {
                cout << "Account number not found. Try again.\n";
            }

        } while (!found);

    }

    void deleteAccount(Account accounts[]) 
    {

        int accNumber;
        bool found = false;

        cout << "Enter the account number you want to delete : ";
        cin >> accNumber;

        for (int i = 0; i < SIZE; i++) 
        {
            if (accounts[i].accountNumber == accNumber) 
            {
                found = true;

                for (int j = i; j < SIZE - 1; j++) 
                {
                    accounts[j].accountNumber = accounts[j + 1].accountNumber;
                    accounts[j].accountHolderName = accounts[j + 1].accountHolderName;
                    accounts[j].accountBalance = accounts[j + 1].accountBalance;
                }

                SIZE--;
                i--;
                cout << "Account deleted successfully." << endl;

            }

        }

        if (!found) 
        {
            cout << "Account number not found. Try again.\n";
        }

    }

    void searchAccount(Account accounts[]) 
    {

        int accNumber, choice;
        string accHolderName;
        bool found = false;

        do 
        {

            found = false;
            cout << "\n1. Search by account number." << endl;
            cout << "2. Search by account holder name." << endl;
            cout << "3. Exit." << endl;

            cout << "\nEnter the choice : ";
            cin >> choice;

            if (choice == 1) 
            {
                cout << "Enter the account number: ";
                cin >> accNumber;

                for (int i = 0; i < SIZE; i++) 
                {
                    if (accounts[i].accountNumber == accNumber) 
                    {
                        found = true;
                        accounts[i].displayAccounts();
                        break;
                    }
                }

                if (!found) 
                {
                    cout << "Account not found.\n";
                }

            }

            else if (choice == 2) 
            {

                cout << "Enter the account holder name: ";
                cin >> accHolderName;

                for (int i = 0; i < SIZE; i++) 
                {
                    if (accounts[i].accountHolderName == accHolderName) 
                    {
                        found = true;
                        accounts[i].displayAccounts();
                        break;
                    }
                }

                if (!found) 
                {
                    cout << "Account not found.\n";
                }

            }

            else if (choice != 3) 
            {
                cout << "Invalid choice.\n";
            }

        } while (choice != 3);

    }

    void moneyTransfer(Account accounts[]) 
    {

        int accNumber1, accNumber2, amount;
        int index1 = -1, index2 = -1;

        while (true) 
        {

            cout << "Enter the account number from which you want to transfer money: ";
            cin >> accNumber1;

            for (int i = 0; i < SIZE; i++) 
            {
                if (accounts[i].accountNumber == accNumber1) 
                {
                    index1 = i;
                    break;
                }
            }

            if (index1 != -1) 
            {
                break;
            }

            else 
            {
                cout << "Source account not found. Please try again.\n";
            }

        }

        while (true) 
        {

            cout << "Enter the account number to which you want to transfer money: ";
            cin >> accNumber2;

            for (int i = 0; i < SIZE; i++) 
            {
                if (accounts[i].accountNumber == accNumber2) 
                {
                    index2 = i;
                    break;
                }
            }

            if (index2 != -1) 
            {
                break;
            }

            else 
            {
                cout << "Destination account not found. Please try again.\n";
            }

        }

        cout << "Enter the amount which you want to transfer: ";
        cin >> amount;

        if (amount <= accounts[index1].accountBalance) 
        {
            accounts[index1].accountBalance -= amount;
            accounts[index2].accountBalance += amount;
            cout << "Amount has been transferred successfully.\n";
        }

        else 
        {
            cout << "Insufficient balance. Transfer failed.\n";
        }

    }

    int getAccountNumber() 
    {
        return accountNumber;
    }

};


class Loan 
{

private:

    int loanId;
    int accountNumber;
    double amount;
    double interestRate;
    int durationMonths;

public:

    void createLoan() 
    {
        cout << "\nEnter Loan ID: ";
        cin >> loanId;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Loan Amount: ";
        cin >> amount;
        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;
        cout << "Enter Duration (months): ";
        cin >> durationMonths;
    }

    void displayLoan() 
    {
        cout << "\nLoan ID: " << loanId
            << "\nAccount Number: " << accountNumber
            << "\nAmount: " << amount
            << "\nInterest Rate: " << interestRate
            << "\nDuration: " << durationMonths << " months\n";
    }

    int getAccountNumber() 
    {
        return accountNumber;
    }

    int getLoanId() 
    {
        return loanId;
    }

};


class LoanManager 
{

private:

    Loan loans[MAX];
    int loanCount = 0;

public:

    void addLoan() 
    {

        if (loanCount < MAX) 
        {
            loans[loanCount].createLoan();
            loanCount++;
            cout << "Loan added successfully.\n";
        }

        else 
        {
            cout << "Loan limit reached!\n";
        }

    }

    void displayAllLoans() 
    {

        if (loanCount == 0) 
        {
            cout << "No loans to display.\n";
        }

        else 
        {
            for (int i = 0; i < loanCount; i++) 
            {
                loans[i].displayLoan();
            }
        }

    }

    void searchLoanByAccountNumber() 
    {

        int accNum;
        bool found = false;

        cout << "Enter account number to search loans: ";
        cin >> accNum;

        for (int i = 0; i < loanCount; i++) 
        {
            if (loans[i].getAccountNumber() == accNum) 
            {
                loans[i].displayLoan();
                found = true;
            }
        }

        if (!found) 
        {
            cout << "No loan found for this account.\n";
        }

    }

};


void adminMenu(Account accounts[], LoanManager& loanManager) 
{

    Account a;
    int choice;

    do 
    {

        cout << "\nAdmin Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Update Information\n";
        cout << "4. Delete Account\n";
        cout << "5. Search Account\n";
        cout << "6. Money Transfer\n";
        cout << "7. Loan Management\n";
        cout << "8. Logout\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {

            if (SIZE > MAX) 
            {
                cout << "Cannot create more accounts.\n";
            }

            else 
            {
                for (int i = 0; i < SIZE; i++) 
                {
                    accounts[i].createAccount();
                }
            }

        }

        else if (choice == 2) 
        {
            for (int i = 0; i < SIZE; i++) 
            {
                accounts[i].displayAccounts();
            }
        }

        else if (choice == 3) 
        {
            a.updateInfo(accounts);
        }

        else if (choice == 4) 
        {
            a.deleteAccount(accounts);
        }

        else if (choice == 5) 
        {
            a.searchAccount(accounts);
        }

        else if (choice == 6) 
        {
            a.moneyTransfer(accounts);
        }

        else if (choice == 7) 
        {

            int loanChoice;

            do 
            {

                cout << "\nLoan Management Menu:\n";
                cout << "1. Add Loan\n";
                cout << "2. Display All Loans\n";
                cout << "3. Search Loan by Account Number\n";
                cout << "4. Exit Loan Management\n";

                cout << "Enter choice: ";
                cin >> loanChoice;

                if (loanChoice == 1) 
                {
                    loanManager.addLoan();
                }

                else if (loanChoice == 2) 
                {
                    loanManager.displayAllLoans();
                }

                else if (loanChoice == 3) 
                {
                    loanManager.searchLoanByAccountNumber();
                }

            } while (loanChoice != 4);

        }

    } while (choice != 8);

}



void customerSection(BankSystem& bank) 
{

    Customer* loggedInCustomer = bank.customerLogin();

    if (loggedInCustomer != nullptr) 
    {
        loggedInCustomer->showMenu();
    }

}



int main() 
{

    BankSystem bank;
    Account accounts[MAX];
    LoanManager loanManager;
    int mainChoice;

    do 
    {

        cout << "\nMain Menu:\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) 
        {
            if (bank.adminLogin()) 
            {
                adminMenu(accounts, loanManager);
            }
        }

        else if (mainChoice == 2) 
        {
            customerSection(bank);
        }

        else if (mainChoice == 3) 
        {
            cout << "Exiting program." << endl;
        }

        else 
        {
            cout << "Invalid option. Try again." << endl;
        }

    } while (mainChoice != 3);

    return 0;

}
