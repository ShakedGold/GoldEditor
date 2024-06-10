//
// Created by shake on 08/06/2024.
//

#ifndef WORKSPACECONTAINER_H
#define WORKSPACECONTAINER_H
#include <memory>
#include <unordered_map>

#include "../Workspace/Workspace.h"


class WorkspaceContainer {
public:
    std::pmr::unordered_map<std::string, std::unique_ptr<Workspace>> Workspaces;
    std::unique_ptr<Workspace> SelectedWorkspace;
public:
    void render();
};



#endif //WORKSPACECONTAINER_H
