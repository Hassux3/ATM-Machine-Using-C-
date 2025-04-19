#include <iostream>
#include <string>
using namespace std;

int bank_balance = 10;
bool account_Status = false;

void sleepScreen()
{
	sleep(2);
	system("cls");
	cout << "\t\tBank of C++\n";
}


void bank_login()
{
	cout << "\n\nEnter your card here: -> |    | <-\n";
	sleep(1.5);
	cout << "Press 'Enter' to insert the card: ";
	cin.get();
	sleep(2);
	cout << "\nCard inserted successfully!\n" << endl;
	sleep(1);
	cout << "Scanning your card! Please wait...";
	sleep(3);
	cout << "\nScanning successful!\n";
}

void display_menu()
{
	cout << "\n\n\t  ( MENU )" << endl
	     << "Enter 1 to check balance" << endl
	     << "Enter 2 for deposit" << endl
	     << "Enter 3 for withdrawl" << endl
	     << "Enter 4 to close the menu" << endl
	     << "Enter your choice: ";
}

void show_balance()
{
	cout << "Your current account balance is $" << bank_balance << "." << endl;
}

void deposit_amount()
{
	int amount_toDeposit;
	cout << "Enter the amount you want to deposit: $";
	cin >> amount_toDeposit;
	bank_balance += amount_toDeposit;
	cout << "\nThe amount of $" << amount_toDeposit << " has been deposited succesfully." << endl;
	cout << "Your new account balance is $" << bank_balance << "." << endl;
}


void withdrawl_amount()
{
	int amount_toWithdraw;
	cout << "Enter the amount you want to withdraw: $";
	cin >> amount_toWithdraw;

	if (bank_balance < amount_toWithdraw)
		cout << "Sorry, you don't have enough balance..." << endl;
	else
		{
			bank_balance -= amount_toWithdraw;
			cout << "\nThe amount of $" << amount_toWithdraw << " has been withdrawl succesfully." << endl;
			cout << "Your new account balance is $" << bank_balance << "." << endl;
		}
}



int main()
{
	cout << "\t\tBank of C++\n";

	string machine_pincode = "0000";
	string pincode;
	int choice;

	//bank_login();
	bool machine_isON = true;

	int count = 0;
	while (count < 4)
		{
			cout << "\nEnter your 4-digit Pincode: ";
			cin >> pincode;

			if (pincode == machine_pincode)
				{
					cout << "Login Successfull!" << endl;
					sleep(2);
					cout << "Press enter to continue...";
					cin.get();
					system("cls");
					cout << "\t\tBank of C++\n";

					while(machine_isON)
						{
							display_menu();
							cin >> choice;

							switch (choice)
								{
									case 1:
										show_balance();
										sleep(3);
										sleepScreen();
										break;
									case 2:
										deposit_amount();
										sleep(3);
										sleepScreen();
										break;
									case 3:
										withdrawl_amount();
										sleep(3);
										sleepScreen();
										break;
									case 4:
									{
										string quit_Choice;
										cout << "\nAre you sure you want to quit? (yes/no) ";
										cin >> quit_Choice;

										if (quit_Choice == "Yes" || quit_Choice == "yes" )
											{
												cout << "Thanks for using our service...";
												machine_isON = false;
												break;
											}
										break;
									}
									default:
										cout << "Invalid Choice...!\n";
										sleepScreen();
										break;
								}

						}
				}
			else
				{
					cout << "Incorrect Pincode!" << endl;
					count += 1;
					sleepScreen();
					if (count == 3)
						{
							cout << "\nYour Card has been blocked due to three incorrect attempts...!" << endl;
							return 0;
						}
				}
		}



	return 0;
}