/**
 * Created by Xiaozhong on 2020/11/12.
 * Copyright (c) 2020/11/12 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <memory>

using namespace std;

char *f() {
    char *name = new char[20];
    for (int i = 0; i < 20; ++i) name[i] = 'a';
    return name;
}

class BaseClass {
private:
    static BaseClass *base;
public:
    BaseClass() {}

    void printHello() const {
        cout << "Hello, World!" << endl;
    }

    static BaseClass *getBaseClass() {
        if (base == nullptr) base = new BaseClass();
        return base;
    }

};

BaseClass *BaseClass::base = new BaseClass();

struct FontHandle {
};

FontHandle getFont() {
    return FontHandle();
}

class Font {
public:
    explicit Font(FontHandle fontHandle)
            : f(fontHandle) {}

    operator FontHandle() const { return f; }

private:
    FontHandle f;
};

void changeFontSize(FontHandle f, int newSize) {
    //
}

void process(shared_ptr<BaseClass> pb) {}

int main() {
    {
        unique_ptr<char> ap(f());
        shared_ptr<char> sp(f());
        cout << "1213" << endl;
        unique_ptr<BaseClass> up(BaseClass::getBaseClass());
        up.get()->printHello(); // >: Hello, World!
        (*up).printHello();     // >: Hello, World!
        shared_ptr<BaseClass> spb(new BaseClass());
        process(spb);
        process(shared_ptr<BaseClass>(new BaseClass()));
    }
    f();

    Font font(getFont());
    changeFontSize(font, 1);

    return 0;
}