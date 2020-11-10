/**
 * Created by Xiaozhong on 2020/10/20.
 * Copyright (c) 2020/10/20 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <string>

using namespace std;

class TableTennisPlayer {
private:
    string name;
    bool hasTable;
public:

    TableTennisPlayer(const string &name) : TableTennisPlayer(name, false) {}

    TableTennisPlayer(const string &_name, bool _hasTable) : name(_name), hasTable(_hasTable) {}

    bool has_table() const { return hasTable; }

    void set_table(bool _hasTable) { hasTable = _hasTable; }

    friend ostream &operator<<(ostream &os, TableTennisPlayer &tableTennisPlayer) {
        os << tableTennisPlayer.name << " " << tableTennisPlayer.hasTable << ".";
        return os;
    }
};

class RatedPlayer : public TableTennisPlayer {
private:
    int rating = 0;
public:
    // 构造自己的同时，把基类也给构造好了
    RatedPlayer(int r = 0) : rating(r), TableTennisPlayer("", false) {}

    RatedPlayer(const string &name = "non-name", int r = 0, bool hasTable = false) :
            rating(r), TableTennisPlayer(name, hasTable) {}
};

int main() {
    TableTennisPlayer tableTennisPlayer("xiaoming");
    cout << tableTennisPlayer << endl;
    RatedPlayer rateplayer(12);
    cout << rateplayer << endl;
}