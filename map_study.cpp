/**
 * Created by Xiaozhong on 2020/9/1.
 * Copyright (c) 2020/9/1 Xiaozhong. All rights reserved.
 */

#include "map"
#include "unordered_map"
#include "iostream"

/**
 * 程序来自 bits/unordered_map.h
 */
//template<typename _Key,
//        typename _Tp,
//        typename _Hash = hash <_Key>,
//        typename _Pred = equal_to <_Key>,
//        typename _Alloc = allocator <std::pair<const _Key, _Tp>>>
//class unordered_map {
//};
/**
 * 程序来自C++源码 bits/stl_map.h
 */
/*template<typename _Key,
        typename _Tp,
        typename _Compare = std::less<_Key>,
        typename _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
class map {
private:
    /// This turns a red-black tree into a [multi]map.
    typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
    rebind<value_type>::other _Pair_alloc_type;

    typedef _Rb_tree<key_type, value_type, _Select1st<value_type>,
    key_compare, _Pair_alloc_type> _Rep_type;
};*/

int main() {
    using namespace std;
    unordered_map<int, string> unorderedMap;
    unorderedMap.insert(make_pair(0, "Alice"));
    unorderedMap[1] = "Bob";
    unorderedMap.insert(unordered_map<int, string>::value_type(2, "Candy"));
    for (auto iter = unorderedMap.begin(); iter != unorderedMap.end(); iter++) {
        cout << iter->first << " - " << iter->second << endl;
        /*
         * >: 输出如下，可以得知它们在 key 的排序上并没有顺序
         * 2 - Candy
         * 0 - Alice
         * 1 - Bob
         */
    }

    map<int, string> mapper;
    mapper.insert(make_pair(0, "Alice"));
    mapper[1] = "Bob";
    mapper.insert(map<int, string>::value_type(2, "Candy"));
    for (auto &iter : mapper) {
        cout << iter.first << " - " << iter.second << endl;
        /*
         * >: 输出如下，很明显的，它们在 key 的排序上是递增排列的
         * 0 - Alice
         * 1 - Bob
         * 2 - Candy
         */
    }


}