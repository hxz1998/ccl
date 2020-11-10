/**
 * Created by Xiaozhong on 2020/9/27.
 * Copyright (c) 2020/9/27 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <thread>

using namespace std;

int main() {
    thread t([]{
        for (int i = 0; i < 10; ++i) cout << i << " ";
    });
    t.detach();
    cout << "joinable? " << t.joinable() << endl;   // >: joinable? 0
    cout << t.get_id() << endl; // >: thread::id of a non-executing thread
}