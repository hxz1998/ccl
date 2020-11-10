/**
 * Created by Xiaozhong on 2020/11/9.
 * Copyright (c) 2020/11/9 Xiaozhong. All rights reserved.
 */

class BaseClass {
private:
    char *data;
public:
    BaseClass &operator=(const BaseClass &rhs) {
        if (&rhs == this) return *this;
        delete data;
        data = rhs.data;
        return *this;
    }
};

int main() {
    BaseClass baseClass;
    baseClass = baseClass;
}

