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
	//declares the array
	FoodITM item[itemNum];
	//declares each individual object in the array
	item[0] = FoodITM(1, "Water", 1.00);
	item[1] = FoodITM(2, "Pepsi", 1.70);
	item[2] = FoodITM(3, "Pepsi Max", 1.70);
	item[3] = FoodITM(4, "Monsert Energy", 1.95);
	item[4] = FoodITM(5, "Spicy Doritos", 1.95);
	item[5] = FoodITM(6, "Egg", 2.99);

	//outputs each items ID, name and price
	for (int i = 0; i < itemNum; i++) {
		cout << item[i].ID << " " << item[i].Name << " " << item[i].Price << endl;
	}

	cout << "\nPlease enter an Item ID: " << ends;
	cin >> InputID;


	for (int i = 0; i < itemNum; i++) {
		if (InputID == item[i].ID) {
			cout << item[i].Name << endl;
			break;
		}
	}









	return 0;
}