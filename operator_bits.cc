/**
 * Created by Xiaozhong on 2020/10/24.
 * Copyright (c) 2020/10/24 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

int main() {
    unsigned char bits = 155;
    unsigned int offset = 8;
    // <<
    /*
     *           1001 1011
     * 1001 1011 0000 0000
     * >: 9b00
     */
    cout << hex << (bits << offset) << endl;
    // >>
    /*
     *           1001 1011
     * 0000 0000 0000 0000 1001 1011
     * >: 0
     */
    cout << hex << (bits >> offset) << endl;
    short neg_i = -308;
    /*
     * 308:
     *  0000 0001 0011 0100
     * -308:
     *  1111 1110 1100 1011(反码)
     *  1111 1110 1100 1100（补码）
     *  1111 1111 1111 1111
     * >: fecc fffe
     */
    cout << hex << (unsigned short) (neg_i) << " " << (unsigned short) (neg_i >> offset) << endl;

    unsigned char bits_o = 132;
    // |
    /*
     * 1001 1011
     * 1000 0100
     * 1001 1111
     * >: 9f
     */
    cout << hex << (bits | bits_o) << endl;

    // &
    /*
     * 1001 1011
     * 1000 0100
     * 1000 0000
     * >: 80
     */
    cout << hex << (bits & bits_o) << endl;

    // ^
    /*
     * 1001 1011
     * 1000 0100
     * 0001 1111
     * >: 1f
     */
    cout << hex << (bits ^ bits_o) << endl;

    // ~
    /*
     * 1001 1011
     * 0110 0100
     * >: ffffff64
     */
    cout << hex << (~bits) << endl;
}