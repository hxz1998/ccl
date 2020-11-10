/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */

#ifndef CXX_EXE_X_HH
#define CXX_EXE_X_HH

#include <iostream>

using std::cout, std::endl;

class X {

    friend void helloX(const X &x) {
        cout << "hello World!" << x.id << endl;
    }

private:
    int id;
public:
    X() = default;

    int get_id() const;
};


#endif //CXX_EXE_X_HH
