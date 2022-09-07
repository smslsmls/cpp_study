#include<bits/stdc++.h>
using ll = long long;
using namespace std;

double interest_array[2] = { 3,4 };

class Saving {
private:
	double interest;
	ll deposit;
	double tax = 0.154;
public:
	Saving(double interest, ll deposit) :interest(interest), deposit(deposit) {}

	Saving(int saving_type, ll deposit) :Saving(interest_array[saving_type], deposit) {}

	void calc(int month) {
		double inter = ((interest / 100) * ((month + 1) / 24.0)) * (deposit * 12);
		cout << (ll)inter + (deposit * month) << '\n';
		inter *= 1 - tax;
		cout << (ll)inter + (deposit * month) << '\n';
	}

	//void get_info() const {
	//	cout << "interest : " << interest << '\n';
	//	cout << "deposit for month : " << deposit << '\n';
	//	cout << "tax : " << tax << '\n';
	//}
};

int main() {
	int saving_type, depos, month;
	cout << "일반 : 0\n특판 : 1\n";
	cin >> saving_type >> depos >> month;
	Saving saving(saving_type, depos);
	//saving.get_info();
	saving.calc(month);
}