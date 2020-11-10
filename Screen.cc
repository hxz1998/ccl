/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */

#include "Screen.hh"

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::do_display(std::ostream &os) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 && j == 0) {
                os << "┌";
                continue;
            }
            if (i == 0 && j == width - 1) {
                os << "┐";
                continue;
            }
            if (i == height - 1 && j == 0) {
                os << "└";
                continue;
            }
            if (i == height - 1 && j == width - 1) {
                os << "┘";
                continue;
            }
            os << contents[i * width + j];
        }
        os << std::endl;
    }
}