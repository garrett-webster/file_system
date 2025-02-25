#include "TextFile.h"

TextFile::TextFile(const string &name, ContainerEntity *parent): FileEntity(name), parent(parent) {
    parent->addChild(this);
}

void TextFile::setContent(const string &content) {
    this->content = content;
    this->size = content.length();
}

void TextFile::setPath(const string& parentPath) {
    this->path = parentPath + "/" + this->name;
}