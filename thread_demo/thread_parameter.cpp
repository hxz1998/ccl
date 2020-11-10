/**
 * Created by Xiaozhong on 2020/9/28.
 * Copyright (c) 2020/9/28 Xiaozhong. All rights reserved.
 */

#include <thread>
#include <iostream>
#include <string>

using namespace std;

class Task {
public:
    void do_something(string &name) {
        name = "hello~ " + name;
        cout << name << " -> ";
    }
};

void hello(const string name) {
    cout << "Hello~ " << name << endl;
}

int main() {
    thread t1(hello, "Cherry"); // >: Hello~ Cherry

    string buffer = "hello";
    thread t2([](string buf) {
        buf.append("world!");
        cout << this_thread::get_id() << " - " << buf << endl;
        // >: 3 - helloworld!
    }, buffer);
    t2.join();
    cout << this_thread::get_id() << " - " << buffer << endl;
    // >: 1 - hello

    // 会出现编译错误！
    /**
     *  thread t3([](string &buf) {
     *      buf.append("world!");
     *      cout << this_thread::get_id() << " string buf: " << " - " << buf << endl;
     *  }, buffer);
     */

    thread t_ref([](string &buf) {
        buf.append(" world!");
        cout << this_thread::get_id() << " - " << buf << endl;
        // >: 4 - hello world!
    }, ref(buffer));
    t_ref.join();
    cout << this_thread::get_id() << " - " << buffer << endl;
    // >: 1 - hello world!

    Task task;
    string name = "Cherry";
    cout << name << " -> ";
    thread t4(&Task::do_something, &task, std::ref(name));
    t4.join();
    cout << name << endl;
    // >: Cherry -> hello~ Cherry -> hello~ Cherry
    while (true);
}

class thread {
public:
    // 首先声明可变长度模板，有一个必须提供的参数是 _Callable ，其余为可选参数
    template<typename _Callable, typename... _Args>
    explicit
    thread(_Callable &&__f, _Args &&... __args) {
        // 查看是否激活 gthr 代理
#ifdef GTHR_ACTIVE_PROXY
        // Create a reference to pthread_create, not just the gthr weak symbol.
    auto __depend = reinterpret_cast<void(*)()>(&pthread_create);
#else
        auto __depend = nullptr;
#endif
        // 创建执行函数，并且将参数进行传递
        _M_start_thread(_S_make_state(  // 创建状态
                __make_invoker(         // 创建执行函数，并执行
                        std::forward<_Callable>(__f),   // callable 类型转换
                        std::forward<_Args>(__args)...) // 参数类型转换
                        ),
                        __depend);
    }

private:
    // 用来执行的包装器 (forwarded tuple elements...)
    template<typename _Tuple>
    struct _Invoker {
        // ... 省略
    };

    template<typename... _Tp>
    using __decayed_tuple = tuple<typename std::decay<_Tp>::type...>;

public:
    // 返回一个可调用的包装器，里面有：
    // tuple{DECAY_COPY(__callable), DECAY_COPY(__args)...}.
    template<typename _Callable, typename... _Args>
    static _Invoker<__decayed_tuple<_Callable, _Args...>>
    __make_invoker(_Callable &&__callable, _Args &&... __args) {
        return {__decayed_tuple<_Callable, _Args...>{
                std::forward<_Callable>(__callable), std::forward<_Args>(__args)...
        }};
    }
};