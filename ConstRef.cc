/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class InitData {
private:
    int id = 0;
    string desc = "";
public:
//    InitData(int _id, string &_desc) {
//        id = _id;
//        desc = _desc;
//    }

    InitData(int _id, string &_desc) : id(_id), desc(_desc) {};
};

class ConstRef {
public:
    ConstRef(int ii) : i(ii), const_i(ii), ref_i(i) {}

private:
    int i;
    const int const_i;
    int &ref_i;
};

class X {
    int j, i;
    // 这个顺序是错误的
//    int i, j;
public:
    X(int val) : j(val), i(j) {

    }
};

class Delegating_Constructor {
    string _name = "";
    int _age = 0;
public:
    // 非委托构造函数
    // 实际上，如果每一个参数都提供了默认值，那么就等于提供了默认构造函数
    Delegating_Constructor(string name = "name", int age = 0) : _name(name), _age(age) {}

    // 此时如果再提供这样的函数，那么将会报错
    // call of overloaded 'Delegating_Constructor()' is ambiguous
    // Delegating_Constructor() {}

    // 委托构造函数，委托上面的构造函数

    Delegating_Constructor(int age) : Delegating_Constructor("", age) {}

    Delegating_Constructor(string name) : Delegating_Constructor(name, 0) {}

    const string toString() {
        return "{name=" + _name + ", age=" + to_string(_age) + "}";
    }
};

class Sales_Data {
private:
    string bookNo;
    int id = 0;
public:
    Sales_Data() = default;

    Sales_Data(const string &s) : bookNo(s) {}

    Sales_Data(int _id) : id(_id) {}

};

int main() {
    Delegating_Constructor delegatingConstructor;
    Delegating_Constructor dint = (Delegating_Constructor) 1;
    cout << dint.toString();
    string name = "Bob";
    // 下面这句不可用，因为有两个第一个参数为 string 类型的构造函数
    // Delegating_Constructor dstring = (Delegating_Constructor) name;

    Sales_Data sdint = (Sales_Data) 1;
    Sales_Data sdstring = (Sales_Data) name;
}