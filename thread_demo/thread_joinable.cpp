/**
 * Created by Xiaozhong on 2020/9/27.
 * Copyright (c) 2020/9/27 Xiaozhong. All rights reserved.
 */

#include <thread>
#include <iostream>

using namespace std;

int main() {
    thread t1([] {
        cout << this_thread::get_id() << ": ";
        for (int i = 0; i < 10; ++i) cout << i << " ";
    });
    cout << "t1 id: " << t1.get_id() << endl;   // >: t1 id: 2
    cout << t1.joinable() << endl;  // >: 1
    if (t1.joinable()) {
        t1.join();
    }
    cout << endl << t1.joinable() << endl;  // >: 0
}