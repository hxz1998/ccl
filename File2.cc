/**
 * Created by Xiaozhong on 2020/11/1.
 * Copyright (c) 2020/11/1 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include "File1.hh"

using namespace std;
class Directory {
    size_t disks;
public:
    Directory() { disks = getFS().numDisks(); }
    size_t getDisks() const { return disks; }
};
int main() {
    Directory directory;
    cout << directory.getDisks();
}