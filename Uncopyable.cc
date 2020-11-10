/**
 * Created by Xiaozhong on 2020/11/8.
 * Copyright (c) 2020/11/8 Xiaozhong. All rights reserved.
 */

class Uncopyable {
protected:
    Uncopyable() = default;
private:
    Uncopyable(const Uncopyable &);
    Uncopyable &operator=(const Uncopyable &);
};

class SubClass : public Uncopyable {
    // 默认不允许拷贝构造和赋值运算符
};

int main() {
    SubClass s1, s2;
//    s1 = s2;    // error!
}