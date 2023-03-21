#include<bits/stdc++.h>
using namespace std;

class Salary
{
public:
	Salary(int salary) :salary(salary)
	{
		//national_pension = 4.5;
		//health_insurance = 3.495;
		//long_term_care_insurance = 0.4288365;//3.495%*12.27%
		//employment_insurance = 0.9;

		cout << "national pension(���ο���) : ";
		cin >> national_pension;
		cout << "health_insurance(�ǰ�����) : ";
		cin >> health_insurance;
		cout << "long_term_care_insurance(����纸��) : ";
		cin >> long_term_care_insurance;
		cout << "employment_insurance(��뺸��) : ";
		cin >> employment_insurance;
	}

	double get_preminums() {
		return national_pension + health_insurance + long_term_care_insurance + employment_insurance;
	}

	int calc_salary()
	{
		double insurance_premiums = get_preminums();
		return ((salary / 12) * ((100 - insurance_premiums) / 100));
	}
private:
	int salary;
	double national_pension;
	double health_insurance;
	double long_term_care_insurance;
	double employment_insurance;
};

int main() {
	int year_salary = 24000000;
	cout << "Salary(����) : ";
	cin >> year_salary;
	Salary salary(year_salary);
	cout << salary.calc_salary() << endl;
}