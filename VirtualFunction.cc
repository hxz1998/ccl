/**
 * Created by Xiaozhong on 2020/10/21.
 * Copyright (c) 2020/10/21 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

class BaseEllipse {
private:
    double x, y;
public:
    BaseEllipse(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}

    void move(int nx, int ny) { x = nx, y = ny; }

    virtual ~BaseEllipse() {}

    // 使用 =0 来指出这个类是一个抽象类，这时不可以直接实例化该类，这个虚函数是纯虚函数
    virtual double area() const = 0;

    friend ostream &operator<<(ostream &os, const BaseEllipse &baseEllipse) {
        os << baseEllipse.x << " " << baseEllipse.y << " " << baseEllipse.area();
        return os;
    }
};

class Circle : public BaseEllipse {
private:
    double r = 0;
public:
    Circle() = default;

    Circle(double r0) : r(r0), BaseEllipse(0, 0) {}

    Circle(int x, int y, double r0) : r(r0), BaseEllipse(x, y) {}

    double area() const { return r * r * 3.14; }
};

int main() {
    Circle circle(0, 0, 2);
    cout << circle << endl; // >: 0 0 12.56
    circle.move(3, 9);
    cout << circle << endl; // >: 3 9 12.56
}