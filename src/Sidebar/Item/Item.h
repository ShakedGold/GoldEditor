//
// Created by shake on 08/06/2024.
//

#ifndef ITEM_H
#define ITEM_H

#include <functional>
#include <string>

class Item {
public:
    std::function<void()> OnClick;
    bool IsFocused;
private:
    std::string m_Name;
public:
    explicit Item(const std::string& name);
    std::string getName() const;
    void setName(const std::string& name);
    void render();
};



#endif //ITEM_H
