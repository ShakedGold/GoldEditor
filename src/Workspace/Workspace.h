//
// Created by shake on 08/06/2024.
//

#ifndef WORKSPACE_H
#define WORKSPACE_H
#include <string>

class Workspace {
 public:
  bool IsOpen{};
  std::string Path;

 private:
  const std::string m_Title;
  unsigned int m_BufferSize{};
  char* m_Buffer{};

 public:
  Workspace();
  explicit Workspace(const std::string& title);
  ~Workspace();
  void render();
};

#endif  // WORKSPACE_H
