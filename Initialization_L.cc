/**
 * Created by Xiaozhong on 2020/11/1.
 * Copyright (c) 2020/11/1 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class X {
    const int val;
    int &re_val;
public:
    X(int val_, int &re_val_) : val(val_), re_val(re_val_) {
        cout << "X initialization..." << endl;
    }
};

class Y : public X {
public:
    Y(int val, int &re_val) : X(val, re_val) {
        cout << "Y initialization..." << endl;
    };
};

int main() {
    int re_v = 1;
    Y y(1, re_v);
    // >: X initialization...
    //    Y initialization...
}