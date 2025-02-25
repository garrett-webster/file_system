#include "ContainerEntity.h"

#include <utility>

ContainerEntity::ContainerEntity(string name) : FileEntity(std::move(name)){}

// TODO: Check if an object is a drive before adding it. If it is, don't add it... Something has gone horribly wrong
void ContainerEntity::addChild(FileEntity *child) {
    children.push_back(child);
    children.back()->setPath(this->path + "/" + children.back()->getName());
    this->size += children.back()->getSize();
}

// Recursively deletes all children of the drive as well as itself
void ContainerEntity::deleteSelf() {
    for (auto& child : children) {
        child->deleteSelf();
        delete child;  // Free memory
    }
    children.clear();
}

FileEntity* ContainerEntity::searchChildren(string path) {
    for (auto& child : children) {
        if (child->getPath() == path) {
            return child;
        }

        // Check if the child is a ContainerEntity
        ContainerEntity* containerChild = dynamic_cast<ContainerEntity*>(child);
        if (containerChild) {
            FileEntity* found = containerChild->searchChildren(path);
            if (found) return found;  // Return if found in the recursive call
        }
    }

    return nullptr;
}