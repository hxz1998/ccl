/**
 * Created by Xiaozhong on 2020/11/1.
 * Copyright (c) 2020/11/1 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class FileSystem {
public:
    size_t numDisks() const { return 0; }
};

FileSystem &getFS() {
    static FileSystem tfs;
    return tfs;
}

extern FileSystem tfs;
