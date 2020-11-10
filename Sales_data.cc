/**
 * Created by Xiaozhong on 2020/10/7.
 * Copyright (c) 2020/10/7 Xiaozhong. All rights reserved.
 */

#include "Sales_data.hh"
#include <iostream>

double Sales_data::avg_price() const {
    if (units_sold) return revenue / units_sold;
    else return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data::Sales_data(istream &is) {
    read(is, *this);
}

