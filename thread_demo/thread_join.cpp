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
    t1.join();
    cout << endl;
    thread t2([] {
        cout << this_thread::get_id << ": ";
        for (int i = 0; i < 10; ++i) cout << i << " ";
    });
    t2.join();
    // >: 2: 0 1 2 3 4 5 6 7 8 9
    //    1:0 1 2 3 4 5 6 7 8 9
    // >: 2: 0 1 2 3 4 5 6 7 8 1 :0 1 2 3 4 5 6 7 8 9 9
}