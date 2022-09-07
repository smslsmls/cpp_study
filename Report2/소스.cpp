#include<bits/stdc++.h>
using namespace std;

class Saving {
private:
	double interest;
	int deposit;
	double tax = 0.154;
	double interest_array[2] = { 3.0,4.0 };
public:
	Saving(double interest, int deposit) :interest(interest), deposit(deposit) {}

	Saving(int saving_type, int deposit) :Saving(interest_array[saving_type], deposit) {}

	void calc(int year) {
		double inter = ((interest / 100) * ((year * 12 + 1) / 24.0)) * (deposit * 12);
		cout << (int)inter + (deposit * 12 * year) << '\n';
		inter *= 1 - tax;
		cout << (int)inter + (deposit * 12 * year) << '\n';
	}

	//void get_info() const {
	//	cout << "interest : " << interest << '\n';
	//	cout << "deposit for month : " << deposit << '\n';
	//	cout << "tax : " << tax << '\n';
	//}
};

int main() {
	int saving_type, depos, year;
	cout << "일반 : 0\n특판 : 1\n";
	cin >> saving_type >> depos >> year;
	Saving saving(saving_type, depos);
	//saving.get_info();
	saving.calc(year);
}