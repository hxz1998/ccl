/**
 * Created by Xiaozhong on 2020/10/7.
 * Copyright (c) 2020/10/7 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include "Sales_data.hh"
#include "Screen.hh"
#include "Windows_Mgr.hh"
#include "X.hh"

class LinkScreen {
public:
    LinkScreen(LinkScreen &next) : next(next) {}

private:
    LinkScreen &next;
};

int main() {
    Sales_data data;
    add(data, data);
    read(std::cin, data);
    print(std::cout, data);
    std::cout << std::endl << data.get_units() << std::endl;
    const Sales_data data2;
    data2.do_somethings();
    data.do_somethings();

    Screen screen(24, 80);
    screen.move(1, 2).set('#');
    std::cout << screen.get() << std::endl;

    screen.set('*').display(std::cout); // 调用非常量版本
    std::cout << std::endl;
    screen.display(std::cout);              // 调用非常量版本
    std::cout << std::endl;

    const Screen const_screen(24, 80);
    const_screen.display(std::cout);        // 调用常量版本
    std::cout << std::endl;

    Screen displayer(3, 3, '*');
    displayer.display(std::cout)                // 调用非常量版本
            .set(1, 1, '#').display(std::cout);

    Windows_Mgr manger;
    manger.clear(0);

    X xx;
    helloX(xx);
}