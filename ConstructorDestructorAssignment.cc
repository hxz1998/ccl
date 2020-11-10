/**
 * Created by Xiaozhong on 2020/11/8.
 * Copyright (c) 2020/11/8 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class NamedObject {
private:
//    const T objectValue;
//    string& name;
    T objectValue;
    string name;
public:
    NamedObject(string n, T val) : name(n), objectValue(val) {}

    NamedObject(const NamedObject<T> &rhs) {
        objectValue = rhs.objectValue;
        name = rhs.name + " copy ";
    }

    friend ostream &operator<<(ostream &os, const NamedObject<T> &rhs) {
        os << rhs.objectValue << " " << rhs.name;
        return os;
    }

    NamedObject &operator=(const NamedObject<T> &rhs) {
        objectValue = rhs.objectValue;
        name = rhs.name + " = ";
        return *this;
    }

};

int main() {
    string newDog = "newDog";
    string oldDog = "oldDog";
    NamedObject<int> od(oldDog, 1);
    NamedObject<int> nd(newDog, 2);
    cout << nd << " : " << od << endl;  // >: 2 newDog : 1 oldDog
    nd = od;    // >: error: use of deleted function 'NamedObject<int>& NamedObject<int>::operator=(const NamedObject<int>&)'
    cout << nd; // >: 1 oldDog =
}