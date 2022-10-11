#include<bits/stdc++.h>
using ll = long long;
using namespace std;

bool operator>(const tm& p1, const tm& p2) {
	if (p1.tm_hour > p2.tm_hour)
		return true;
	else if (p1.tm_hour < p2.tm_hour)
		return false;
	else {
		if (p1.tm_min > p2.tm_min)
			return true;
		else if (p1.tm_min < p2.tm_min)
			return false;
		else {
			if (p1.tm_sec > p2.tm_sec)
				return true;
			else
				return false;
		}
	}
}

bool operator<=(const tm& p1, const tm& p2) {
	if (p1.tm_hour < p2.tm_hour)
		return true;
	else if (p1.tm_hour > p2.tm_hour)
		return false;
	else {
		if (p1.tm_min < p2.tm_min)
			return true;
		else if (p1.tm_min > p2.tm_min)
			return false;
		else {
			if (p1.tm_sec <= p2.tm_sec)
				return true;
			else
				return false;
		}
	}
}

tm operator+(const tm& p1, const tm& p2) {
	tm t;
	t.tm_hour = p1.tm_hour + p2.tm_hour;
	t.tm_min = p1.tm_min + p2.tm_min;
	t.tm_sec = p1.tm_sec + p2.tm_sec;
	if (t.tm_sec > 59)
	{
		t.tm_sec -= 60;
		t.tm_min++;
	}
	if (t.tm_min > 59)
	{
		t.tm_min -= 60;
		t.tm_hour++;
	}
	if (t.tm_hour > 23)
		t.tm_hour -= 24;
	return t;
}

tm operator-(const tm& p1, const tm& p2) {
	tm t;
	t.tm_hour = p1.tm_hour - p2.tm_hour;
	t.tm_min = p1.tm_min - p2.tm_min;
	t.tm_sec = p1.tm_sec - p2.tm_sec;
	if (t.tm_sec < 0)
	{
		t.tm_sec += 60;
		t.tm_min--;
	}
	if (t.tm_min < 0)
	{
		t.tm_min += 60;
		t.tm_hour--;
	}
	if (t.tm_hour < 0)
		t.tm_hour += 24;
	return t;
}

double del_decimal(double dou) {
	return (dou - (int)dou);
}

tm double2tm(double time) {
	tm t;
	t.tm_hour = time;
	t.tm_min = 60 * del_decimal(time);
	t.tm_sec = 60 * del_decimal(60 * del_decimal(time));
	return t;
}

tm _1sec = { 1,0,0,0,0,0,0,0,0 };

class Timer {
public:

	tm get_time()
	{
		timer = time(NULL);
		t = localtime(&timer);
		return *t;
	}

private:

	time_t timer;
	struct tm* t;
};

class Human {
public:

	Human(double speed) :walking_speed(speed) {}

	tm time2walk(double dist) {
		tm walking_time;
		walking_time = double2tm(dist / walking_speed);
		return walking_time + _1sec;
	}

private:

	double walking_speed;
};

class Bus {
public:
	Bus(tm first_bus, tm last_bus, tm bus_dispatch)
		:first_bus(first_bus), last_bus(last_bus), bus_dispatch(bus_dispatch)
	{
		for (tm dispatch = first_bus; dispatch <= last_bus; dispatch = dispatch + bus_dispatch) {
			bus_dispatch_time.push_back(dispatch);
		}
	}

	tm calc(Human human, double dist) {
		tm now_time = timer.get_time();
		tm walktime = human.time2walk(dist);
		if (now_time + walktime > last_bus) {
			return first_bus - walktime;
		}
		for (tm dispatch : bus_dispatch_time) {
			if (now_time + walktime <= dispatch) {
				return dispatch - walktime;
			}
		}
	}

private:
	Timer timer;
	tm first_bus;
	tm last_bus;
	tm bus_dispatch;
	vector<tm> bus_dispatch_time;
};

int main() {
	//int hour, min, sec;
	//cout << "bus info (h:m:d)\n";
	//cout << "first bus : ";
	//scanf("%d:%d:%d", &hour, &min, &sec);
	//tm first_bus = { sec,min,hour,0,0,0,0,0,0 };
	//cout << "last bus : ";
	//scanf("%d:%d:%d", &hour, &min, &sec);
	//tm last_bus = { sec,min,hour,0,0,0,0,0,0 };
	//cout << "bus dispatch time : ";
	//scanf("%d:%d:%d", &hour, &min, &sec);
	//tm bus_dispatch = { sec,min,hour,0,0,0,0,0,0 };

	tm first_bus = { 0,0,6,0,0,0,0,0,0 };
	tm last_bus = { 0,0,22,0,0,0,0,0,0 };
	tm bus_dispatch = { 0,20,0,0,0,0,0,0,0 };
	
	double walking_speed = 4.0;

	//cout << "walking speed (km/h) : ";
	//cin >> walking_speed;

	double dist = 0.47;

	//cout << "distance to bus station (km) : ";
	//cin >> dist;

	Human human(walking_speed);

	Bus bus(first_bus, last_bus, bus_dispatch);
	tm calc_result = bus.calc(human, dist);

	cout << calc_result.tm_hour << ":" << calc_result.tm_min << ":" << calc_result.tm_sec << endl;
}