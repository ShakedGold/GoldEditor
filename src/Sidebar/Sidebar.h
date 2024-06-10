//
// Created by shake on 08/06/2024.
//

#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <memory>
#include <vector>

#include "Item/Item.h"


class Sidebar {
private:
    std::string m_Title;
    std::vector<std::unique_ptr<Item>> m_Items;
public:
    explicit Sidebar(const std::string& title);
    void render() const;
    void addItem(Item& item);
};



#endif //SIDEBAR_H
