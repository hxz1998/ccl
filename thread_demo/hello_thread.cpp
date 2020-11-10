/**
 * Created by Xiaozhong on 2020/9/26.
 * Copyright (c) 2020/9/26 Xiaozhong. All rights reserved.
 */
#include <thread>   // 引入头文件
#include <iostream>

using namespace std;

void func_task(int i) { // 声明要执行的任务函数（也可为callable类型）
    cout << i << " * ";
}

class Task {
public:
    void operator()(int i) {
        cout << i << " () ";
    }
};

int main() {
    for (int i = 0; i < 10; ++i) {
        thread t(func_task, i); // 创建线程 t（并为线程指定任务 func_task）
        t.detach();             // 将线程 t 与当前线程分离
    }
    // >: 015 * 9 *  * 2 *  * 7 * 3 * 6 * 4 * 8 *
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        thread t(func_task, i); // 创建线程 t（并为线程指定任务 func_task）
        t.join();               // 将线程 t 并入到当前线程中
    }
    // >: 0 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 *
    cout << endl;


    auto func_lambda = [](int i) { cout << i << " - "; };
    // 024 - 5 -  - 1 - 6 - 7 - 3 - 9 - 8 -  -
    for (int i = 0; i < 10; ++i) {
        thread t(func_lambda, i);
        t.detach();
    }
//    this_thread::sleep_for(chrono::seconds(10));
    cout << endl;

    // 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 -
    for (int i = 0; i < 10; ++i) {
        thread t(func_lambda, i);
        t.join();
    }
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        thread t([](int i) {
            cout << i << " - ";
        }, i);
        t.detach();
    }
    cout << endl;
//    this_thread::sleep_for(chrono::seconds(10));

    for (int i = 0; i < 10; ++i) {
        Task task;
        thread t(task, i);
        t.detach();
    }
    // >: 024 () 3 () 1 ()  () 6 () 8 () 9 () 5 ()
}