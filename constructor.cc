/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include "Sales_data.hh"

int main() {
    Sales_data salesData;
    string hello = "hello";
    salesData.combine(hello);
    // 只能使用一步转换，不能从 "hello"(临时的) -> string -> const string
    // salesData.combine("hello");

}