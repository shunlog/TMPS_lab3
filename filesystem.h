#pragma once
#include <string>
#include <vector>

class Component {
public:
    virtual void list_files(std::vector<std::string>& files, const std::string& path) const = 0;
};

class File : public Component {
public:
    File(const std::string& name);

    void list_files(std::vector<std::string>& files, const std::string& path) const override;

private:
    std::string name_;
};

class Directory : public Component {
public:
    Directory(const std::string& name);

    void add(Component* component);

    void list_files(std::vector<std::string>& files, const std::string& path) const override;

private:
    std::string name_;
    std::vector<Component*> children_;
};
