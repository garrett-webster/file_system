#include "FileEntity.h"

FileEntity::FileEntity(FileType type, const string& name, const string& path) : type(type), name(name), path(path) {};

FileEntity::FileEntity(FileType type, const string& name) : type(type), name(name) {
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

FileType FileEntity::getType() {
    return type;
}

void FileEntity::setPath(const string &path){
    this->path = path + "/" + name;
}

