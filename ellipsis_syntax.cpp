/**
 * Created by Xiaozhong on 2020/9/8.
 * Copyright (c) 2020/9/8 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

template<typename... Arguments>
class classname;

classname<> c1();

classname<float, int> c2();

classname<float, std::string, std::vector<int>> c3();

template<typename first, typename... Arguments>
class classname2;

// classname2<> c4(); 这是错误的用法！参数必须大于等于 1
classname2<float> c4();

template<typename... Params>
void functionname(Params *... params);

template<typename... Params>
void functionname(Params... params);

template<typename... Params>
void functionname(Params &... params);

template<typename... Params>
void functionname(Params &&... params);

template<typename... Params>
void functionname(const Params &... params);

template<typename First, typename... Params>
void functionname(const First &first, const Params... params);

template<typename... Params>
void tfunc(Params... params) {
    std::cout << sizeof...(params) << std::endl;
}


using namespace std;

void print() {
    cout << endl;
}

template<typename T>
void print(const T &t) {
    cout << t << endl;
}

template<typename First, typename... Rest>
void print(const First &first, const Rest &...rest) {
    cout << first << ", ";
    print(rest...); // 将会根据语法来递归调用
}

int main() {
    print();    // >:
    print(1); // >: 1
    print(10, 20); // >: 10, 20
    print(10, 20, "Alice", 3.14, "Bob"); // >: 10, 20, Alice, 3.14, Bob

    tfunc();        // >: 0
    tfunc(1);       // >: 1
    tfunc(1, 2);    // >: 2
    tfunc(1, 2, "Hello~YouLi~");    // >: 3
}