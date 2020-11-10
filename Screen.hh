/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */

#ifndef CXX_EXE_SCREEN_HH
#define CXX_EXE_SCREEN_HH

#include <string>
#include <iostream>
#include <vector>

class Screen {

    friend class Windows_Mgr;
//    friend void Windows_Mgr::clear(ScreenIndex index);;

public:
    // 使用类型别名等价地去声明一个类型名字
    typedef std::string::size_type pos;

    Screen() = default; // 默认的构造函数，因为设置了其他的构造函数，所以这个是必须的

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

    char get() const { return contents[cursor]; }   // 隐式内联函数

    inline char get(pos r, pos c) const;          // 显式内联函数

    Screen &move(pos r, pos c);                     // 能在外面被设置为内联函数

    Screen &set(char);

    Screen &set(pos, pos, char);

    /**
     * 虽然有两个不同的版本，但是会根据调用者是否为 常量（const） 来自动判断用哪一个
     */
    Screen &display(std::ostream &os) {
        std::cout << "调用了非常量版本" << std::endl;
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        std::cout << "调用了常量版本" << std::endl;
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &os) const;
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;   // 把自己返回回去
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;   // 将 this 对象作为左值返回
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

#endif //CXX_EXE_SCREEN_HH
