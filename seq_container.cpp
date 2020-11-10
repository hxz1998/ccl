/**
 * Created by Xiaozhong on 2020/9/10.
 * Copyright (c) 2020/9/10 Xiaozhong. All rights reserved.
 */

#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> nums = {1, 2, 3, 4, 5};
    /**
     *  如果后面需要，可以只改一处地方，就完成了整个实现，如：
     *  vector<int> nums = {1, 2, 3, 4, 5};
     */
    for (auto iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " "; // >: 1 2 3 4 5
}