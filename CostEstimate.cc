/**
 * Created by Xiaozhong on 2020/10/13.
 * Copyright (c) 2020/10/13 Xiaozhong. All rights reserved.
 */

#include "CostEstimate.hh"
#include <iostream>

using namespace std;
const double CostEstimate::FudgeFactor = 1.2;

template<typename T>
inline T callWithMax(const T &a, const T &b) {
    return a > b ? a : b;
}

class Text {
private:
    std::string text;
public:
    const char &operator[](std::size_t pos) const {
        return text[pos];
    }

    char &operator[](std::size_t pos) {
        return const_cast<char &> (         // 使用 const_cast 去掉 const 声明
                static_cast<const Text &>   // 使用 static_cast 把 *this 转换成 const 对象
                (*this)[pos]);              // 使用 (*this)[] 方法返回（这个时候是 const 结果，经过 const_cast 去掉 const 声明
    }
};

int main() {
    int a = callWithMax(1, 2);
    cout << a << endl;
}