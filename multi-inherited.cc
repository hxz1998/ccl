/**
 * Created by Xiaozhong on 2020/10/21.
 * Copyright (c) 2020/10/21 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <string>

using namespace std;

class Worker {
private:
    string name;
    int id;
public:
    Worker() : name("non-name"), id(0) {}

    Worker(const string &_name, int _id) : name(_name), id(_id) {}

    virtual void show() const { cout << "worker " << *this << " show"; }

    friend ostream &operator<<(ostream &os, const Worker &worker) {
        os << worker.id << " - " << worker.name;
        return os;
    }
};

class Waiter : virtual public Worker {
private:
    int panache = 0;
public:
    Waiter(int p, int id, const string &name) : Worker(name, id), panache(p) {}

    void show() const {
        cout << "Waiter " << *this << " show";
    }

    friend ostream &operator<<(ostream &os, const Waiter &waiter) {
        os << (Worker) waiter << waiter.panache;
        return os;
    }
};

class Singer : virtual public Worker {
private:
    int voice = 0;
public:
    Singer(int v, int id, const string &name) : Worker(name, id), voice(v) {}

    void show() const {
        cout << "Singer " << *this << " show";
    }

    friend ostream &operator<<(ostream &os, const Singer &singer) {
        os << (Worker) singer << " " << singer.voice;
        return os;
    }
};

// 这个时候， SingerWaiter 对象内部，只有一个 Worker 实例
class SingerWaiter : public Waiter, public Singer {
private:
    int cost = 0;
public:
    SingerWaiter(int c, int v, int p, const string &name, int id) :
            Worker(name, id), Singer(v, id, name), Waiter(p, id, name), cost(c) {}

    void show() const {
        Singer::show();
        cout << "SingerWaiter " << *this << " show";
    }

    friend ostream &operator<<(ostream &os, const SingerWaiter &singerWaiter) {
        os << (Singer) singerWaiter << " " << singerWaiter.cost;
        return os;
    }
};

int main() {
    SingerWaiter singerWaiter(1, 2, 3, "xiaoming", 4);
    cout << singerWaiter << endl;
    singerWaiter.show();
}