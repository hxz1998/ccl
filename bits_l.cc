/**
 * Created by Xiaozhong on 2020/10/23.
 * Copyright (c) 2020/10/23 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <climits>
#include "stddef.h"

#pragma pack(4)
using namespace std;

int main() {
    using namespace std;
    short n_short = SHRT_MAX;
    int n_int = INT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    char n_char = CHAR_MAX;
    cout << "short:\t" << n_short << endl;  // >: short: 32767
    cout << "int:\t" << n_int << " " << sizeof(int) << endl;    // >: int 2147483647 4
    cout << "long:\t" << n_long << " " << sizeof(long) << endl; // >: long 2147483647 4
    cout << "llong:\t" << n_llong << " " << sizeof(long long) << endl;  // >: llong: 9223372036854775807 8
    cout << "char:\t" << (int) n_char << "\t" << CHAR_BIT << endl;  // >: char: 127 8
    long int li = 2147483647;
    cout << sizeof(li) << "\t" << li << endl;   // >: 4 2147483647
    cout << "sizeof double is " << sizeof(double) << endl;  // >: sizeof double is 8
    cout << "sizeof(bool) is " << sizeof(bool) << endl; // >: sizeof(bool) is 1

    struct st1 {
        char name[21];
        double price;
    };
    cout << "sizeof(st1) is " << sizeof(st1) << endl; // >: sizeof(st1) is 32
    struct st2 {
        char name[20];
        double price;
    };
    cout << "sizeof(st2) is " << sizeof(st2) << endl; // >: sizeof(st2) is 32
    struct st3 {
        char name[20];
        int price;
    };
    cout << "sizeof(st3) is " << sizeof(st3) << endl; // >: sizeof(st3) is 24
    struct st4 {
        char c1;
        double d1;
        int i1;
    };
    cout << "sizeof(st4) is " << sizeof(st4) << endl; // >: sizeof(st4) is 24
    struct st5 {
        char c1;
        int i1;
        double d1;
    };
    cout << "sizeof(st5) is " << sizeof(st5) << endl; // >: sizeof(st5) is 16

    struct st66 {
        int a2;
        double d2;
        short s2;
        char c2;
    };
    struct st6 {
        char c1;
        st66 s;
        int i1;
    };
    cout << "sizeof(st66) is " << sizeof(st66) << endl;     // >: sizeof(st66) is 24
    cout << "sizeof(st6) is " << sizeof(st6) << endl;       // >: sizeof(st6) is 40
    cout << "s offset is " << offsetof(st6, s) << endl;     // >: s offset is 8
    cout << "i1 offset is " << offsetof(st6, i1) << endl;   // >: i1 offset is 32

    char16_t c16;
    cout << "sizeof(c16) is " << sizeof(char16_t) << endl;
    char32_t c32;
    float f;
    cout << "sizeof(float) is " << sizeof(float) << endl;

    unsigned char uc = UCHAR_MAX;
    // >: sizeof(unsigned char) is 1 255
    cout << "sizeof(unsigned char) is " << sizeof(unsigned char) << " " << (int) uc << endl;
    unsigned int ui = UINT32_MAX;
    // >: sizeof(unsigned int) is 4 4294967295
    cout << "sizeof(unsigned int) is " << sizeof(unsigned int) << " " << ui << endl;
    unsigned long ul = ULONG_MAX;
    // >: sizeof(unsigned long) is 4 4294967295
    cout << "sizeof(unsigned long) is " << sizeof(unsigned long) << " " << ul << endl;
    unsigned long long ull = ULLONG_MAX;
    // >: sizeof(unsigned long long) is 8 18446744073709551615
    cout << "sizeof(unsigned long long) is " << sizeof(unsigned long long) << " " << ull << endl;
}