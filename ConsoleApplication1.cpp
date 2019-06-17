// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include <iostream>
using namespace std;
class CHuBtai {
protected:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	int MilliSecond;
	int check();
public:
	CHuBtai();
	CHuBtai(int y, int m, int d, int h, int mi, int s, int mis);
	~CHuBtai() {
		cout << "被调用了" << endl;
	}
	void print();
	void AddYearDays();
	int SetDays(int y, int m, int d, int h, int mi, int s, int mis);
	int BackYear();
	int BackMonth();
	int BackDay();
	int BackHour();
	int BackMinute();
	int BackSecond();
	int BackMilliSecond();
};

class hubi : public CHuBtai {
public:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	int MilliSecond;
	int check();
public:
	hubi();
	hubi(int y, int m, int d, int h, int mi, int s, int mis);
	~hubi() {
		cout << "被调用了" << endl;
	}
	void print();
	void AddYearDays();
	int SetDays(int y, int m, int d, int h, int mi, int s, int mis);
	int BackYear();
	int BackMonth();
	int BackDay();
	int BackHour();
	int BackMinute();
	int BackSecond();
	int BackMilliSecond();
};


CHuBtai::CHuBtai() {
	Year = 1999;
	Month = 26;
	Day = 12;
	Hour = 11;
	Minute = 19;
	Second = 59;
	MilliSecond = 2600;
}
CHuBtai::CHuBtai(int y, int m, int d, int h, int mi, int s, int mis) {
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	MilliSecond = mis;
	if (check() == -1 || check() == 1) {
		/*Month = 1;
		Day = 1;
		cout << "输入有误，月日置1" << endl;*/
		int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (Year % 400 == 0 && (Year % 4 == 0 && Year % 100 != 0)) {
			if (leapYearDays[Month - 1] < Day) {
				Day %= leapYearDays[Month - 1];
				Month++;
			}
		}
		else {
			if (flatYearDays[Month - 1] < Day) {
				Day %= flatYearDays[Month - 1];
				Month++; 
			}
		}
		if (Month > 12) {
			Year++;
			Month = 1;
		}
	}
}
int CHuBtai::BackYear() {
	return Year;
}
int CHuBtai::BackMonth() {
	return Month;
}
int CHuBtai::BackDay() {
	return Day;
}
int CHuBtai::BackHour() {
	return Hour;
}
int CHuBtai::BackMinute() {
	return Minute;
}
int CHuBtai::BackSecond() {
	return Second;
}
int CHuBtai::BackMilliSecond() {
	return MilliSecond;
}
int CHuBtai::check() {
	Second += MilliSecond / 1000;
	MilliSecond %= 1000;
	Minute += Second / 60;
	Second %= 60;
	Hour += Minute / 60;
	Minute %= 60;
	Day += Hour / 24;
	Hour %= 24;
	int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Month > 12 || Month < 1)
		return -1;
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) {
		if (leapYearDays[Month - 1] < 1 || Day < 1)
			return 1;
	}
	else {
		if (flatYearDays[Month - 1] < Day || Day < 1)
			return 1;
	}
	return 0;
}
int CHuBtai::SetDays(int y, int m, int d, int h, int mi, int s, int mis) {
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	if (check() == -1 || check() == 1) {
		Month = 1;
		Day = 1;
		cout << "输入有误，月日置1" << endl;
		return -1;
	}
	return 0;
}
void CHuBtai::AddYearDays() {
	int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Day++;
	if (Year % 400 == 0 && (Year % 4 == 0 && Year % 100 != 0)) {
		if (leapYearDays[Month - 1] < Day) {
			Month++;
			Day = 1;
		}
	}
	else {
		if (flatYearDays[Month - 1] < Day) {
			Month++;
			Day = 1;
		}
	}
	if (Month > 12) {
		Year++;
		Month = 1;
	}
}
void CHuBtai::print() {
	cout << Year << "年" << Month << "月" << Day << "日" << Hour << "时" << Minute << "分" << Second << "秒" << MilliSecond << "毫秒" << endl;
}
int main() {
	int count = 1;
	CHuBtai oj(2019, 12, 30, 72, 0, 0, 0);
	/*while (!((oj.BackYear() == 2019) && (oj.BackMonth() == 4) && (oj.BackDay() == 28))) {
	oj.AddYearDays();
	count++;
	}
	cout << count << endl;*/
	oj.print();
	return 0;
}