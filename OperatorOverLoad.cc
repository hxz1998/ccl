/**
 * Created by Xiaozhong on 2020/10/20.
 * Copyright (c) 2020/10/20 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Time {
private:
    int hours = 0;
    int minutes = 0;
public:
    Time() = default;

    Time(int _hours, int _minutes) : hours(_hours), minutes(_minutes) {}

    Time operator+(const Time &time) const {
        Time tmp;
        tmp.minutes = minutes + time.minutes;
        tmp.hours = hours + time.hours + tmp.minutes / 60;
        tmp.minutes %= 60;
        return tmp;
    }
    friend ostream &operator<<(ostream &os, const Time &time) {
        os << time.hours << " hourse " << time.minutes << " minutes.";
        return os;
    }
};

int main() {
    Time start(1, 2);
    cout << start << endl;  // >: 1 hourse 2 minutes.
    Time end(10, 20);
    end = start + end;
    cout << end << endl;    // >: 11 hourse 22 minutes.
}