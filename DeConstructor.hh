/**
 * Created by Xiaozhong on 2020/10/19.
 * Copyright (c) 2020/10/19 Xiaozhong. All rights reserved.
 */

#ifndef DSANDAA_DECONSTRUCTOR_HH
#define DSANDAA_DECONSTRUCTOR_HH

#include <iostream>

using namespace std;

class DeConstructor {
private:
    char *name = nullptr;
public:
    DeConstructor(int size) {
        name = new char[size];
        cout << "创建了一个 " + to_string(size) + " 大小的 char 数组" << endl;
    }

    ~DeConstructor() {
        delete name;
        cout << "把创建出来的数组空间释放掉了" << endl;
    }
};


#endif //DSANDAA_DECONSTRUCTOR_HH
