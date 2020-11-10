/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */

#ifndef CXX_EXE_WINDOWS_MGR_HH
#define CXX_EXE_WINDOWS_MGR_HH

#include <vector>
#include "Screen.hh"

class Windows_Mgr {
public:
    // 给管理器中每一个屏幕都编号
    using ScreenIndex = std::vector<Screen>::size_type;

    // 按照编号将指定的 Screen 清空内容
    void clear(ScreenIndex index);

private:
    // 默认情况下， Manager 会包含一个空内容的标准尺寸
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

inline void Windows_Mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif //CXX_EXE_WINDOWS_MGR_HH
