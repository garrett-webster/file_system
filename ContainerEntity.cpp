#include "ContainerEntity.h"

#include <stdexcept>
#include <utility>

ContainerEntity::ContainerEntity(const FileType type, const string& name) : FileEntity(type, name){}

void ContainerEntity::addChild(FileEntity *child) {
    children.push_back(child);
    // children.back()->setPath(this->path + "/" + children.back()->getName());
    this->size += children.back()->getSize();
}

void ContainerEntity::removeChild(FileEntity *child) {
    size -= child->getSize();
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

// Recursively deletes all children of the drive as well as itself
void ContainerEntity::deleteSelf() {
    for (auto& child : children) {
        child->deleteSelf();
        delete child;
    }
    children.clear();
}

void ContainerEntity::setPath(const string &path){
    this->path = path + "/" + this->name;

    // Recursively update the paths of the children
    for (auto& child : children) {
        child->setPath(this->path);
    }
}