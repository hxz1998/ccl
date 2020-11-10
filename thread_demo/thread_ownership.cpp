/**
 * Created by Xiaozhong on 2020/9/28.
 * Copyright (c) 2020/9/28 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <thread>

using namespace std;

void do_something() {
    int count = 0;
    while (true) {
        cout << this_thread::get_id() << " ownership! + " << ++count << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    thread t1(do_something);
    this_thread::sleep_for(chrono::seconds(2));

    thread t2 = move(t1);
    cout << "t1.joinable() ? " << t1.joinable() << endl; // >: t1.joinable() ? 0
    cout << "t2.joinable() ? " << t2.joinable() << endl; // >: t2.joinable() ? 1
    /**
     * 2 ownership! + 1
     * 2 ownership! + 2
     * t1.joinable() ? 0
     * t2.joinable() ? 1
     * 2 ownership! + 3
     * 2 ownership! + 4
     * ...
     */

    thread t4 = move(t1); // 虽然转移了过来，但是线程 t4 并没有可执行的函数
    cout << t4.joinable() << endl; // >: 0

    thread t3 = thread(do_something);
    t3 = move(t2); // 会报错，因为 t3 已经和一个函数关联，这时候再给他一个会报错

//    auto handle = t2.native_handle();
//    cout << "handle: " << handle << endl;
//    pthread_cancel(handle);
    while (true); // 在这里空转，不让 main 线程结束掉，否则会丢失输出
}
