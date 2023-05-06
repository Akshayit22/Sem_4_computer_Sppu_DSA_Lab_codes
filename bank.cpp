#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class bank
{

public:
	ofstream fout;
	ifstream fin;
	string temp[4];
	int ADMIN_ACCOUNT_TYPE;
	int USER_ACCOUNT_TYPE;
	int USER_LOGGED_IN;
	int accountNumber;
	string accountHolderName;
	string adminUserName;
	string adminAccountPassword;
	int accountBalance;
	string accountPassword;

	bool checkAccount(int);
	void createAccount();
	void creditAmount();
	void withdrawAmount();
	void saveFileData();
	void syncFileData();
	void searchByAccountNumber();
	void sortByAccountNumber();
	void sortByAccountBalance();
	void loginAccount();
	string encrypt(string);
	string decrypt(string);
	void line();
	void logOutAccount();

	bank()
	{
		ADMIN_ACCOUNT_TYPE = 0;
		USER_ACCOUNT_TYPE = 0;
		USER_LOGGED_IN = 0;
		adminUserName = "admin";
		adminAccountPassword = "aditya";
	}
	
};

void bank ::line()
{

	cout << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void bank ::loginAccount()
{

	int choice;
	string adminUserName1, adminAccountPassword1;
	int usernameCheck, passwordCheck;
	line();
	cout << "\t Account Login";
	line();
	cout << "1. Create an new account" << endl;
	cout << "2. Login with existing account";
	line();
	cout << "Enter your choice: ";
	cin >> choice;
	line();

	if (choice == 1)
	{
		createAccount();
	}
	else if (choice == 2)
	{
		cout << "1. Admin login" << endl;
		cout << "2. User login";
		line();
		cout << "Enter your choice: ";
		cin >> choice;
		line();
		if (choice == 1)
		{

			cout << "Enter your username: ";
			cin >> adminUserName1;
			cout << endl;
			cout << "Enter your password: ";
			cin >> adminAccountPassword1;
			line();
			usernameCheck = adminUserName1.compare(adminUserName);
			passwordCheck = adminAccountPassword1.compare(adminAccountPassword);
			if (usernameCheck == 0 && passwordCheck == 0)
			{
				USER_LOGGED_IN = 1;
				ADMIN_ACCOUNT_TYPE = 1;
				USER_ACCOUNT_TYPE = 0;
				line();
				cout << "Log In successful";
				line();
			}
			else
			{
				cout << "Username or Password wrong";
				line();
			}
		}
		else if (choice == 2)
		{
			cout << "Enter your account number: ";
			cin >> accountNumber;
			cout << endl;
			cout << "Enter your password: ";
			cin >> accountPassword;
			line();

			if(checkAccount(accountNumber))
			{
				int i =1;
				fin.open(".Database.txt");
				temp[0] = "1";//to_string(accountNumber);
				while(fin)
				{
					getline(fin,temp[i]);
					i++;
				}
				if (accountPassword == decrypt(temp[2]))
					{
						USER_LOGGED_IN = 1;
						ADMIN_ACCOUNT_TYPE = 0;
						USER_ACCOUNT_TYPE = 1;
						line();
						cout << "Log In successful";
						line();
					}
				else
				{
					cout << "Wrong Password Number";

				}
				fin.close();
			}
			else
			{
				cout << "Wrong Account Number";
				line();
			}
		}
		else
		{
			cout << "Invalid choice";
			line();
		}
	}
	else
	{
		cout << "Invalid choice";
		line();
	}
}
string bank::encrypt(string encrptawd)
{
    int len = encrptawd.length();
    char str[len];
    for(int i=0;i<len;i++)
    {
        str[i] = (encrptawd[i]+len);
    }
    string s = "";
    for (int i = 0; i < len; i++) {
        s = s + str[i];
    }
    return s;
}
string bank::decrypt(string encrptawd)
{
    int len = encrptawd.length();
    char str[len];
    for(int i=0;i<len;i++)
    {
        str[i] = (encrptawd[i]-len);
    }
    string temp = "";
    for (int i = 0; i < len; i++) {
        temp = temp + str[i];
    }
    return temp;
}
bool bank::checkAccount(int acc_num)
{
	ifstream ifile;
	ifile.open("database.txt");
	if(ifile) 
	{
		return true;
	} 
	else 
	{
		return false;
	}
}
void bank ::createAccount()
{
	// Admin only access function
	cout << "Enter an account number for new user: ";
	cin >> accountNumber;
	try
	{
		if(checkAccount(accountNumber))
		{
			throw accountNumber;
		}
		fout.open("Database.txt");
		cout << endl;
		cout << "Enter account holder's name: ";
		cin.ignore();
		getline(cin,accountHolderName);
		fout<<accountHolderName<<endl;
		cout << endl;
		cout << "Enter a password for new user: ";
		cin >> accountPassword;
		fout<<encrypt(accountPassword)<<endl;
		cout << endl;
		// Initial Balance
		accountBalance = 0;
		fout<<accountBalance;
		cout << "Account created successfully";
		fout.close();
		line();
	}
	catch(int accountNumber)
	{
		cout<<accountNumber<<" account number already taken";
		accountNumber=0;
		return ;
	}
}

void bank ::creditAmount()
{
	// User account only access function
	float accountBalance1;
	if (USER_LOGGED_IN == 1 && USER_ACCOUNT_TYPE == 1)
	{

		cout << "Enter ammount to credit: ";
		cin >> accountBalance1;
		accountBalance = accountBalance + accountBalance1;
		line();
		cout << "Ammount credited successfully." << endl;
		cout << "Updated Balance: " << accountBalance;
		fout.open("Database.txt",ios::trunc);
		fout<<accountHolderName<<endl;
		fout<<accountPassword<<endl;
		fout<<accountBalance;
		line();
	}
	else
	{

		cout << "Authentication failed";
		line();
	}

	// Save this data to file
	// Sanket
}

void bank ::withdrawAmount()
{
	// User account only access function
	float accountBalance1;
	if (USER_LOGGED_IN == 1 && USER_ACCOUNT_TYPE == 1)
	{

		cout << "Enter ammount to withdraw: ";
		cin >> accountBalance1;
		accountBalance = accountBalance - accountBalance1;
		line();
		cout << "Ammount withdrawn successfully." << endl;
		cout << "Updated Balance: " << accountBalance;
		line();
		fout.open("Database.txt",ios::trunc);
		fout<<accountHolderName<<endl;
		fout<<accountPassword<<endl;
		fout<<accountBalance;
	}
	else
	{

		cout << "Authentication failed";
		line();
	}

	// Save this data to file
	// Sanket
}

void bank ::logOutAccount()
{

	if (USER_LOGGED_IN == 1)
	{

		if (USER_ACCOUNT_TYPE == 1)
		{
			USER_ACCOUNT_TYPE = 0;
			cout << "Logged out successfully";
			line();
		}
		if (ADMIN_ACCOUNT_TYPE == 1)
		{
			ADMIN_ACCOUNT_TYPE = 0;
			cout << "Logged out successfully";
			line();
		}
	}
else
{
	cout << "No user logged in at this current instance";
	line();
}
}

int main()
{

	// test object
	bank testBankObj;
	testBankObj.loginAccount();

	cout << endl
		 << "Bank.cpp" << endl;
	return 0;
}
