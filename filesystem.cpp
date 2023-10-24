#include "filesystem.h"

File::File(const std::string& name) : name_(name) {}

void File::list_files(std::vector<std::string>& files, const std::string& path) const {
    files.push_back(path + "/" + name_);
}

Directory::Directory(const std::string& name) : name_(name) {}

void Directory::add(Component* component) {
    children_.push_back(component);
}

void Directory::list_files(std::vector<std::string>& files, const std::string& path) const {
    std::string newPath = path + "/" + name_;

    for (const auto& child : children_) {
        child->list_files(files, newPath);
    }
}
