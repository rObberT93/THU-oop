#include <iostream>
#include <vector>
#include <string>
#include "editor.h"

TextEditor::Position TextEditor::mouse1 = {0, 0};
TextEditor::Position TextEditor::mouse2 = {0, 0};

TextEditor::TextEditor() {
    data.push_back("");
    is_selected = false;
}

void TextEditor::moveCursor(Position dest) {
    is_selected = false;
    mouse1 = dest;
    mouse2 = dest;
}

void TextEditor::select(Position beg, Position end) {
    mouse1 = beg;
    mouse2 = end;
    is_selected = true;
}

void TextEditor::write(const std::string& str) {
    if(is_selected) {
        del();
    }
    data[mouse1.first].insert(mouse1.second, str);
    mouse1.second += str.size();
    mouse2 = mouse1;
}

void TextEditor::newline() {
    if(is_selected) {
        del();
    }
    // 在第mouse1.first + 1 行位置处插入一行
    data.insert(data.begin() + mouse1.first + 1, data[mouse1.first].substr(mouse1.second));
    data[mouse1.first].erase(mouse1.second);
    // 移动光标
    mouse1.first++;
    mouse1.second = 0;
    mouse2 = mouse1;
    is_selected = false;
}

void TextEditor::del() {
    if(!is_selected) { // 未选中
        if((mouse1.first == data.size() - 1) && mouse1.second == data[data.size() - 1].size()) { // 最后一行最后一个字符
            return;
        } else if(mouse1.second != data[mouse1.first].size()){ // 不是最后一个字符
            data[mouse1.first].erase(mouse1.second, 1);
            return;
        } else {
            data[mouse1.first].insert(mouse1.second, data[mouse1.first + 1]); // 是最后一个字符 不是最后一行
            data.erase(data.begin() + mouse1.first + 1);
            return;
        }
    }
    // 选中
    if(mouse1.first == mouse2.first) { // 同行
        data[mouse1.first].erase(mouse1.second, mouse2.second - mouse1.second);
    } else { // 不同行
        data[mouse1.first].erase(mouse1.second);
        data[mouse1.first].insert(mouse1.second, data[mouse2.first].substr(mouse2.second));
        for(int i = mouse2.first; i > mouse1.first; --i) {
            data.erase(data.begin() + i);
        }
    }
    mouse2 = mouse1;
    is_selected = false;
}

void TextEditor::copy() {
    if(is_selected) {
        clipboard.clear();
        int start_col = 0;
        int end_col = 0;
        if(mouse1.first == mouse2.first) { // 同行复制
            start_col = mouse1.second;
            end_col = mouse2.second;
            //if(start_col == end_col) return;
            std::string line = data[mouse1.first].substr(start_col, end_col - start_col);
            clipboard.push_back(line);
        } else { // 跨行复制
            for(int i = mouse1.first; i <= mouse2.first; i++) {
                if(i == mouse1.first) {
                    start_col = mouse1.second;
                    end_col = data[i].size();
                } else if(i == mouse2.first) {
                    start_col = 0;
                    end_col = mouse2.second;
                } else {
                    start_col = 0;
                    end_col = data[i].size();
                }
                std::string line = data[i].substr(start_col, end_col - start_col);
                clipboard.push_back(line);
            }
        }
    }
    else return;
}

void TextEditor::paste() {
    if(is_selected) {
        del();
    }
    if(clipboard.empty()) {
        return;
    }
    std::string tmp = data[mouse1.first].substr(mouse1.second, data[mouse1.first].size() - mouse1.second);
    data[mouse1.first].erase(mouse1.second);
    for(int i = 0, j = mouse1.first; i < clipboard.size(); i++, j++) {
        if(j == mouse1.first) {
            data[j].insert(mouse1.second, clipboard[i].substr(0, clipboard[0].size()));
        } else {
            data.insert(data.begin() + j, clipboard[i].substr(0, clipboard[i].size()));
        }
    }
    mouse1.first += clipboard.size() - 1;
    
    if(clipboard.size() == 1)
        mouse1.second += clipboard[0].size();
    else
        mouse1.second = clipboard[clipboard.size() - 1].size();
    data[mouse1.first].insert(mouse1.second, tmp);
    mouse2 = mouse1;
}

void TextEditor::screenShot() {
    if(is_selected)
        data[mouse2.first].insert(mouse2.second, "*");
    data[mouse1.first].insert(mouse1.second, "*");
    if(data.size() > 0) {
        for(int i = 0; i < data.size() - 1; i++) {
            std::cout << data[i] << std::endl;
        }
        std::cout << data[data.size() - 1] ;
    }else {
        std::cout << data[0];
    }
    data[mouse1.first].erase(mouse1.second, 1);
    if(is_selected) 
        data[mouse2.first].erase(mouse2.second, 1);
}