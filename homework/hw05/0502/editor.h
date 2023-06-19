#pragma once

#include <vector>
#include <string>
#include <list>

class TextEditor {
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data; // 数据区，亦可采用其他数据结构
    std::vector<std::string> clipboard; // 剪贴板，亦可采用其他数据结构
    static Position mouse1;
    static Position mouse2;
    bool is_selected;
public:
    TextEditor();
    void moveCursor(Position dest);
    void select(Position beg, Position end);
    void write(const std::string& str);
    void newline();
    void del();
    void copy();
    void paste();
    void screenShot();
};