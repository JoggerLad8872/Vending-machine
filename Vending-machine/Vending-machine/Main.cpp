//getting this to run drom a github clone:
//go to file - new - project from existing code
//next - select file location - rename the file the exact same - select dropdown - select console application option - click finish
#include <iostream>
#include <string>
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

int main() {
	//the lenghth of the array in which the objects are stored
	const int itemNum = 6;
	int InputID = 3;
	string ItemName;
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

			break;
		}
		//if the item ID inputted is not the same as any stored the item array will count over, this set of code will
		//determine if that happens, then it will clear the console and output "Invalid input"
		if (i >= itemNum - 1) {
			system("cls");
			cout << "Invalid input" << endl;
			main();
		}
	}

	//if the ID inputted is valid it will reach this line of code, clear the console and let the user know what the last item vended was.
	system("cls");
	cout << "Last item vended: " << ItemName << endl;
	main();
	return 0;
}