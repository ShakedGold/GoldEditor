//
// Created by shake on 08/06/2024.
//

#ifndef TAB_H
#define TAB_H
#include <string>


class Tab {
private:
    std::string m_Title;
public:
    Tab(std::string  title);
    bool render() const;
    const std::string& getTitle() const;
};



#endif //TAB_H
