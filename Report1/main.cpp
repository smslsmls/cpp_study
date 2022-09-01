#include<bits/stdc++.h>
using namespace std;

class Saving {
private:
	double interest;
	int deposit;
public:
	Saving(double interest, int deposit) :interest(interest), deposit(deposit) {}

	void calc(int year) {
		double inter = ((interest/100) * ((year * 12 + 1) / 24.0))* (deposit * 12);
		cout << (int)inter + (deposit * 12 * year) << '\n';
		inter *= 0.846;
		cout << (int)inter + (deposit * 12 * year) << '\n';
	}
};

int main() {
	int depos,year;
	cin >> depos>>year;
	Saving saving(3.55, depos);
	saving.calc(year);
}