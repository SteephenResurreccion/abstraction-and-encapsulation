#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

bool validInput(string input, float &amount) {
        bool decimalPoint = false;
        for (char c : input) {
            if (!isdigit(c)) {
                if (c == '.' && !decimalPoint) {
                    decimalPoint = true;  // Allow one decimal point
                } else {
                    cout << "	Invalid input. Please enter a valid number." << endl;
                    return false;
                }
            }
        }
        try {
            amount = stof(input);
            return true;
        } catch (...) {
            cout << "	Invalid input. Please enter a valid number." << endl;
            return false;
        }
    }
	class Account{
		private:
			string userInput;
			int switchInput;
			bool loopSwitch=true;
			float amount;
		protected: 
			float balance;
			Account(float accountBalance): balance(accountBalance){}
		public:
			void subMenu(){
				do{
					cout<<"\n	1 - Deposit\n	2 - Withdraw\n	3 - Check Balance\n	4 - Back\n	Input which account to go via number: ";
					cin>>switchInput;
					switch(switchInput){
						case 1:
							cout<<"\n	Deposit\n	Please input amount to deposit: ";
							cin>>userInput;
							if (validInput(userInput, amount)) {
	                            balance += amount;
	                            cout << "	Amount deposited successfully. Press Any Key to Continue";
                        	}
                        	getch(); system("cls");
						break;
						case 2:
							cout<<"\n	Withdraw\n	Please input amount to withdraw: ";
							cin>>userInput;
							if (validInput(userInput, amount)) {
	                            if (amount <= balance) {
	                                balance -= amount;
	                                cout << "	Amount withdrawn successfully. Press Any Key to Continue";
	                            } else 
	                                cout << "	Insufficient balance. Press Any Key to Continue";
                        	}
                        	getch(); system("cls");
						break;
						case 3:
							cout<<"\n	Check Balance"<<"\n\n	Current Balance: "<<balance<<"\n	Press Any Key to Continue";
							loopSwitch=true;
                        	getch(); system("cls");
						break;
						case 4:
							loopSwitch=false;
						break;
					}
				}while(loopSwitch==true);
			}
	};
	class CurrentAccount: public Account{
		public:
			CurrentAccount(float accountBalance): Account(accountBalance){}
	};
	class SavingsAccount: public Account{
		public:
			SavingsAccount(float accountBalance): Account(accountBalance){}
	};
int main(){
	CurrentAccount curAccount(0);
	SavingsAccount savAccount(1000);
	bool loop=true;
	int switchInput;
	
	do{
		cout<<"\n	Main Menu.\n	1 - Savings Account\n	2 - Current Account\n	3 - Exit\n	Input which account to go via number: ";
		cin>>switchInput;
		switch(switchInput){
			case 1:
				savAccount.subMenu();
			break;
			case 2:
				curAccount.subMenu();
			break;
			case 3:
				loop = false;
			break;
		}
	}while(loop==true);
}