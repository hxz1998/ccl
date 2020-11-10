/**
 * Created by Xiaozhong on 2020/10/7.
 * Copyright (c) 2020/10/7 Xiaozhong. All rights reserved.
 */

#ifndef CXX_EXE_SALES_DATA_HH
#define CXX_EXE_SALES_DATA_HH

#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Sales_data {
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    mutable int assess_ctr = 0;

    double avg_price() const;

public:
    Sales_data() = default;

    // 一旦声明了 explicit ，那么这个构造函数将不能用于隐式转换
//    explicit Sales_data(const string &s) : bookNo(s) {};

    Sales_data(const string &s) : bookNo(s) {};

    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {};

    Sales_data(istream &);

    string isbn() const { return bookNo; };

    Sales_data &combine(const Sales_data &);

    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
        Sales_data sum = lhs;
        sum.combine(rhs);
        return sum;
    }

    friend ostream &print(ostream &, const Sales_data &);

    friend istream &read(istream &, Sales_data &);

    unsigned get_units();

    void do_somethings() const;
};

inline unsigned Sales_data::get_units() {
    return units_sold;
}

inline void Sales_data::do_somethings() const {
    assess_ctr++;
}

inline istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

inline ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

#endif //CXX_EXE_SALES_DATA_HH
