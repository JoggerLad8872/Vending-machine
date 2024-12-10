#include <iostream>
#include <string>
using namespace std;

class FoodITM {
public:
	int ID;
	string Name;
	float price;
	//default constructor: A constructor is needed whenever an object is declared, if no constructor exists the program will not work properly
	//the default constructor acts as an empty constcructor 
	FoodITM() {};

	FoodITM(int a, string b, float c) {
		ID = a;
		Name = b;
		price = c;
	}
};

int main() {
	//the lenghth of the array in which the objects are stored
	const int itemNum = 6;
	//declares the array
	FoodITM item[itemNum];
	//declares each individual object in the array
	item[0] = FoodITM(1, "Water", 1.00);
	item[1] = FoodITM(2, "Pepsi", 1.70);
	item[2] = FoodITM(3, "Pepsi Max", 1.70);
	item[3] = FoodITM(4, "Cherry Pepsi", 1.95);
	item[4] = FoodITM(5, "Spicy Doritos", 1.95);
	item[5] = FoodITM(6, "Egg", 2.99);
	cout << item[0].ID << endl;




	return 0;
}