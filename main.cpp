// This is the command line version // 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Add in users option

// Initialized once account is choosen
class Paper_Type_Amount{
private:
	int onek, twok, fivek, tenk, twentyk, fiftyk, onehk, twohk, fivehk;
	vector<int> vector;
public:
	int show_amount();
	void get_data();
	Paper_Type_Amount();
};

int Paper_Type_Amount::show_amount(){
	for (int i=0; i < this->vector.size(); i++){
		return this->vector[i];
	}
	return 0; 
}

void Paper_Type_Amount::get_data(){
	
}

class Budget{
private:
	string account;
	int current_budget = 0;
	int debt = 0;
	const int max_debt = 0;
public:
	int show_current_budget(){return current_budget;}
	int show_debt(){return debt;}
	void show_choices();
	void show_functions();
	void proccess(int choice, int amount);
	void increase(int type, int amount);
	Budget(string name){account=name;} // Do nothing //
};

class Account{
private:
	string username;
public:
	bool login();
	void start();
	Account(){};
};

bool Account::login(){
	int choice;
	string name;
	cout << "\nWelcome to MM. What do you wish to do:\n1.Create account\n2.Exit" << endl;
	cout << "\nYour choice: ";
	cin >> choice;
	if (choice == 1){
		cout << "What is your user name: ";
		cin >> name;
		username = name;
		return true;
		}
	else if (choice == 2){return 0;}
	else {
		login();
		return false;
	}
}

void Budget::show_functions(){
	int action;
	cout << "\nWhat do you wanna do?\n1.Transmit\n2.View budget\n3.View debt\n4.Exit" << endl;
	cout << "\nYour choice: ";
	cin >> action;
	switch (action){
		case 1:
			show_choices();
			show_functions();
			break;
		case 2:
			cout << "You currently have " << show_current_budget() << " dong in your account!" << "\n\n";
			show_functions();
			break;
		case 3:
			cout << "You currently owe " << show_debt() << " dong due to the system!" << "\n\n";
			show_functions();
			break;
		case 4:
			break;
	}
}

void Budget::show_choices(){
	int choice;
	int amount;
	int agreement;
	cout << "Choose the type of paper: \n1. 1000đ\n2. 2000đ\n3. 5000đ\n4. 10,000đ\n5. 20,000đ\n6. 50,000đ\n7. 100,000đ\n8. 200,000đ\n9. 500,000đ\n10.Back (<-)\n" << endl;
	cout << "Your choice: ";
	cin >> choice; 
	if (choice == 10){}
	else{
		cout << "\nPlease insert the amount papers you have: ";
		cin >> amount; 
		cout << "\nAre you sure you want to do this?\n1.Yes\n2.No" << endl;
		cout << "Your choice: ";
		cin >> agreement;
		if (agreement == 1){
			this->proccess(choice, amount);
		} 
		else{
			cout << "Transmission cancelled;\n" << endl;
			show_functions();
		}
	}
}

void Budget::proccess(int choice, int amount){
	switch(choice) {
		case 1:
			this->increase(1000, amount);
			break;
		case 2:
			this->increase(2000, amount);
			break;
		case 3:
			this->increase(5000, amount);
			break;
		case 4:
			this->increase(10000, amount);
			break;
		case 5:
			this->increase(20000, amount);
			break;
		case 6:
			this->increase(50000, amount);
			break;
		case 7:
			this->increase(100000, amount);
			break;
		case 8:
			this->increase(200000, amount);
			break;
		case 9:
			this->increase(500000, amount);
			break;
		// case 10:
		// 	account.show_functions();
	}
}

void Account::start(){
	if (login() == true){
		Budget user(username);
		user.show_functions();
	}
	else{}
}

void Budget::increase(int type, int amount){
	int total = type * amount;
	current_budget += total;
	cout << "\nSuccessfully transmitted " << total << "!\n" << endl;
}

int main(){
	Account account;
	account.start();
	return 0;
}
