#include<bits/stdc++.h>
#define TAX 0.154
using ll = long long;
using namespace std;

double interest_array[2] = { 3,4 };

class Saving {
private:
	double interest = 0;

	ll deposit = 0;

	int saving_type = 0;

	int id = 0;
	string* user_name = nullptr;
public:
	//Saving(double interest, ll deposit) :interest(interest), deposit(deposit) {}

	//Saving(int saving_type, ll deposit) :Saving(interest_array[saving_type], deposit) {}

	Saving(string name, int id) :id(id) {
		user_name = new string();
		*user_name = name;
	}

	Saving(const Saving& rsh) {
		saving_type = rsh.saving_type;
		interest = rsh.interest;
		deposit = rsh.deposit;
		id = rsh.id;
		user_name = new string();
		*user_name = *rsh.user_name;
	}

	void set_type(int type) {
		saving_type = type;
	}

	void set_interest(double change_interest) {
		interest = change_interest;
	}

	void set_deposit(ll change_deposit) {
		deposit = change_deposit;
	}

	double calc_interest(int month) {
		double inter = 0;
		if (saving_type == 0) {
			inter = ((interest / 100) * ((month + 1) / 24.0)) * (deposit * 12);
		}
		else if (saving_type == 1) {
			inter = (deposit * month) * (interest / 100);
		}
		return inter;
	}

	ll calc(int month) {
		double inter = calc_interest(month);
		inter = (ll)(inter + 0.5);
		inter *= 1 - TAX;
		return (ll)inter + (deposit * month);
	}

	//void get_info() const {
	//	cout << "interest : " << interest << '\n';
	//	cout << "deposit for month : " << deposit << '\n';
	//	cout << "tax : " << tax << '\n';
	//}
};

int main() {
	string name;
	int depos, month, id;
	cout << "이름 : ";
	cin >> name;
	cout << "id : ";
	cin >> id;
	cout << "금액 : ";
	cin >> depos;
	cout << "달 수 : ";
	cin >> month;
	Saving saving(name, id);
	saving.set_type(1);
	saving.set_deposit(depos);
	saving.set_interest(3);
	Saving deposit(saving);
	deposit.set_type(0);
	deposit.set_interest(4);
	//saving.get_info();
	cout << id << " / " << name << '\n';
	cout << "적금 : " << "매월 " << depos << "원씩 " << month << "개월 입금하면 " << deposit.calc(month) << "원\n";
	cout << "예금 : " << depos * month << "원 " << month << "개월 거치하면 " << saving.calc(month) << "원\n";
}