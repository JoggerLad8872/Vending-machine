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
	FoodITM Drink1(1, "Coke", 3.99);
	cout << Drink1.ID << " " << Drink1.Name << " " << Drink1.price << endl;



	const int itemNum = 1;
	FoodITM item[itemNum];
	item[0] = FoodITM(1, "egg", 2.99);
	cout << item[0].ID << endl;




	return 0;
}