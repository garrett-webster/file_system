#include "FileEntity.h"

FileEntity::FileEntity(const string name, const string path) : name(name), path(path) {};

FileEntity::FileEntity(const string name) : name(name) {
    this->path = "/" + name;
};

void FileEntity::deleteSelf() {
    delete this;
}

string FileEntity::getName() {
    return name;
};

size_t FileEntity::getSize() {
    return size;
}

string FileEntity::getPath() {
    return path;
}

void FileEntity::setPath(const string &path){
    this->path = path;
}