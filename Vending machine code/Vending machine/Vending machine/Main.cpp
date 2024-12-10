#include <iostream>
#include <string>
using namespace std;

class FoodITM {
public:
	int ID;
	string Name;
	float price;
	FoodITM(int a, string b, float c) {
		ID = a;
		Name = b;
		price = c;
	}
};

int main() {
	FoodITM Drink1(1, "Coke", 3.99);

	cout << Drink1.ID << " " << Drink1.Name << " " << Drink1.price << endl;


	return 0;
}