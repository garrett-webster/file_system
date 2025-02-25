#include "Folder.h"

Folder::Folder(string name, Drive *parent) : Drive(name), parent(parent) {
    path = parent->getPath() + "/" + name;
    parent->addChild(this);
}