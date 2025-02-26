#include "TextFile.h"

TextFile::TextFile(FileType type, const string &name, ContainerEntity *parent): FileEntity(type, name), parent(parent) {
    parent->addChild(this);
    this->parent = parent;
    TextFile::setPath(parent->getPath());
}

void TextFile::setContent(const string &content) {
    this->content = content;
    this->size = content.length();
}

void TextFile::setPath(const string& parentPath) {
    this->path = parentPath + "/" + this->name;
}

ContainerEntity* TextFile::getParent() {
    return parent;
}