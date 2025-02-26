#include "Folder.h"

Folder::Folder(FileType type, const string& name, ContainerEntity *parent) : Drive(type, name), parent(parent) {
    path = parent->getPath() + "/" + name;
    parent->addChild(this);
    this->parent = parent;
}

ContainerEntity* Folder::getParent() {
    return parent;
}