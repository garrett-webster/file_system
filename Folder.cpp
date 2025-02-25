#include "Folder.h"

Folder::Folder(const string& name, ContainerEntity *parent) : Drive(name), parent(parent) {
    path = parent->getPath() + "/" + name;
    parent->addChild(this);
}