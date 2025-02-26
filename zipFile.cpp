#include "ZipFile.h"

ZipFile::ZipFile(FileType type, string name, ContainerEntity *parent) : Drive(type, name), parent(parent) {
    path = parent->getPath() + "/" + name;
    parent->addChild(this);
}

void ZipFile::addChild(FileEntity *child){
    children.push_back(child);
    children.back()->setPath(this->path);
    this->size += children.back()->getSize() / 2;
}

void ZipFile::removeChild(FileEntity *child) {
    size -= children.back()->getSize()/2;
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

ContainerEntity* ZipFile::getParent() {
    return parent;
}