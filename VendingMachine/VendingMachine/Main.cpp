//getting this to run drom a github clone:
//go to file - new - project from existing code
//next - select file location - rename the file the exact same - select dropdown - select console application option - click finish
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class FoodITM {
public:
	int ID;
	string Name;
	double Price;
	//default constructor: A constructor is needed whenever an object is declared, if no constructor exists the program will not work properly
	//the default constructor acts as an empty constcructor 
	FoodITM() {};

	FoodITM(int a, string b, double c) {
		ID = a;
		Name = b;
		Price = c;
	}
};
float moneyStored = 0;
bool canclled = false;
int RE = 12;
int GR = 10;
int WH = 7;

void coinSwitch() {
	//allows for lines of code to be a different colour
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//sets the colour of the outputted text to default (white)
	SetConsoleTextAttribute(hConsole, WH);

	//switch statement that lets the user select the coins they will input they want to input
	int input;
	//using (char)156 is how to show the � symbol, for some reason
	cout << "1: 1p \n2: 2p \n3: 5p \n4: 10p \n5: 20p \n6: 50p \n7: " << (char)156 << "1 \n8: " << (char)156 << "2  \n9: cancle" << endl;
	cin >> input;
	switch (input) {
	case 1:
		cout << "added 1P" << endl;
		moneyStored = moneyStored + 0.01;
		break;
	case 2:
		moneyStored = moneyStored + 0.02;
		break;
	case 3:
		moneyStored = moneyStored + 0.05;
		break;
	case 4:
		moneyStored = moneyStored + 0.1;
		break;
	case 5:
		moneyStored = moneyStored + 0.2;
		break;
	case 6:
		moneyStored = moneyStored + 0.5;
		break;
	case 7:
		moneyStored = moneyStored + 1;
		break;
	case 8:
		moneyStored = moneyStored + 2;
		break;
	case 9:
		canclled = true;

		break;
	default:
		cout << "Invalid coin" << endl;

	}
	system("cls");
	//to add contrast to important outputted values some are highlighted in green or red (this one is green)
	SetConsoleTextAttribute(hConsole, GR);
	cout << "Current money inputted: " << (char)156 << moneyStored << endl;
}

int main() {


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WH);
	//the lenghth of the array in which the objects are stored
	const int itemNum = 6;
	int InputID = 3;
	string ItemName;
	double ItemPrice;
	//declares the array
	FoodITM item[itemNum];
	//declares each individual object in the array
	item[0] = FoodITM(1, "Water", 1.00);
	item[1] = FoodITM(2, "Pepsi", 1.70);
	item[2] = FoodITM(3, "Pepsi Max", 1.70);
	item[3] = FoodITM(4, "Monsert Energy", 1.95);
	item[4] = FoodITM(5, "Spicy Doritos", 1.95);
	item[5] = FoodITM(6, "Egg", 2.99);
	int n = sizeof(item);

	//outputs each items ID, name and price
	for (int i = 0; i < itemNum; i++) {
		cout << item[i].ID << " " << item[i].Name << " " << item[i].Price << endl;
	}

	//Lets the user input the ID of the item they want to select
	cout << "\nPlease enter an Item ID: " << ends;
	cin >> InputID;

	//goes through each object and check if the inputted ID matches any of the objects
	for (int i = 0; i < itemNum; i++) {
		if (InputID == item[i].ID) {
			cout << item[i].Name << endl;
			ItemName = item[i].Name;
			ItemPrice = item[i].Price;

			break;
		}
		//if the item ID inputted is not the same as any stored the item array will count over, this set of code will
		//determine if that happens, then it will clear the console and output "Invalid input"
		if (i >= itemNum - 1) {
			system("cls");
			SetConsoleTextAttribute(hConsole, RE);
			cout << "Invalid input" << endl;
			main();
		}
	}
	system("cls");
	//outputs the name and price of the item the user wants (I can't do pounds)
	cout << "You want to buy " << ItemName << "! that will cost: $" << ItemPrice << endl;

	//while loop that checks if the correct amount of money has been deposited and if the user has cancelled the transaction, if either is true
	//the loop breaks.
	while (ItemPrice > moneyStored && canclled == false) {

		//function that checks what coins the user inputs against the value of the product
		coinSwitch();
	}



	//checks if the while loop was broken as a result of the transaction being canclled
	if (canclled == true) {
		SetConsoleTextAttribute(hConsole, RE);
		cout << "Money refunded: " << (char)156 << moneyStored << endl;
	}

	//if the ID inputted is valid it will reach this line of code, clear the console and let the user know what the last item vended was.
	else {
		cout << "Last item vended: " << ItemName << endl;

		//checks whether or not change will be provided, if there is change it will display the amount of change given
		if (moneyStored - ItemPrice == 0) {
			cout << "No change to be given" << endl;
		}
		else {
			cout << "change given: " << (char)156 << moneyStored - ItemPrice << endl;
		}

	}

	moneyStored = moneyStored * 0;
	canclled = false;
	main();
	return 0;
}