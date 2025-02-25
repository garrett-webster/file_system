#include "ContainerEntity.h"

#include <stdexcept>
#include <utility>

ContainerEntity::ContainerEntity(string name) : FileEntity(std::move(name)){}

// TODO: Check if an object is a drive before adding it. If it is, don't add it... Something has gone horribly wrong
void ContainerEntity::addChild(FileEntity *child) {
    children.push_back(child);
    // children.back()->setPath(this->path + "/" + children.back()->getName());
    this->size += children.back()->getSize();
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
    // A pretty clunky way to check if the current object is a Drive (and thus cannot have its path changed)
    if (this->path != "/" + this->name) {
        // Maybe throw an error here instead? Honestly, this bit just needs some reworking
        this->path = path + "/" + this->name;
    }

    // Recursively update the paths of the children
    for (auto& child : children) {
        child->setPath(this->path);
    }
}

// ContainerEntity* ContainerEntity::searchChildren(string path) {
//     for (auto& child : children) {
//         // Check if the child is a ContainerEntity
//         auto* containerChild = dynamic_cast<ContainerEntity*>(child);
//         if (containerChild) {
//             if (child->getPath() == path) {
//                 return containerChild;
//             }
//             auto* found = containerChild->searchChildren(path);
//             if (found) return found;  // Return if found in the recursive call
//         }
//     }
//
//     return nullptr;
// }