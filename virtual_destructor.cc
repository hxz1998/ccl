/**
 * Created by Xiaozhong on 2020/11/8.
 * Copyright (c) 2020/11/8 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class BaseClass {
private:
    char *name;
public:
    BaseClass(int size) {
        name = new char[size];
        for (int i = 0; i < size; ++i) name[i] = 'a';
    }

    virtual ~BaseClass() {
        cout << "delete baseclass" << endl;
        delete name;
    }
};

class DeriveClass : public BaseClass {
private:
    char *count;
public:
    DeriveClass(int size) : BaseClass(size) {
        count = new char[size];
        for (int i = 0; i < size; ++i) count[i] = 'b';
    }

    ~DeriveClass() override {
        cout << "delete driveclass" << endl;
        delete[] count;
    }
};

class DBConnection {
private:
    static DBConnection *db;
public:
    DBConnection() {
        db = new DBConnection();
    };

    static DBConnection *create() {
        return db;
    }

    void close() {};

    ~DBConnection() {
        try {
            db->close();
        } catch (exception e) {
            cout << e.what() << endl;
        }
    }
};

int main() {
    {
        BaseClass *obj = new DeriveClass(16);
        BaseClass obj2(16);
    }
//    delete obj;
    return 0;
}