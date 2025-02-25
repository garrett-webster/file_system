#include "ZipFile.h"

ZipFile::ZipFile(string name, ContainerEntity *parent) : Drive(name), parent(parent) {
    path = parent->getPath() + "/" + name;
    parent->addChild(this);
}

void ZipFile::addChild(FileEntity *child){
    children.push_back(child);
    children.back()->setPath(this->path);
    this->size += children.back()->getSize() / 2;
}