/**
 * Created by Xiaozhong on 2020/11/10.
 * Copyright (c) 2020/11/10 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class BaseClass {
private:
    string name;
public:
    BaseClass() = default;

    BaseClass(int sz, char c) { name = string(sz, c); }

    BaseClass(const BaseClass &rhs) : name(rhs.name) {}

    BaseClass &operator=(const BaseClass &rhs) {
        if (this == &rhs) return *this;
        this->name = rhs.name;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const BaseClass &rhs) {
        os << rhs.name;
        return os;
    }
};

class DeriveClass : public BaseClass {
private:
    int age;
public:
    DeriveClass(int a, int sz, char c) : BaseClass(sz, c), age(a) {}

    // 必须要调用基类的拷贝构造函数，否则不会拷贝构造完全
    DeriveClass(const DeriveClass &rhs) : age(rhs.age), BaseClass(rhs) {}

    DeriveClass &operator=(const DeriveClass &rhs) {
        if (&rhs == this) return *this;
        age = rhs.age;
        // 如果不调用下面这句，将会出现没有拷贝基类 name 值的问题！
        BaseClass::operator=(rhs);
        return *this;
    }

    friend ostream &operator<<(ostream &os, const DeriveClass &rhs) {
        os << (BaseClass) rhs << "\t" << rhs.age;
        return os;
    }
};

int main() {
    DeriveClass d1(18, 3, '1');
    DeriveClass d2(20, 5, '2');
    DeriveClass d3(d1);
    d1 = d2;
    cout << d1 << endl << d2 << endl << d3;
    /**
     * 正常输出：
     * 22222    20
     * 22222    20
     * 111      18
     */
    /**
     * 如果按照前两点建议，那么出现这样的情况概不负责；
     * 111      20
     * 22222    20
     *          18
     */
}



