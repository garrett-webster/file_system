#include "TextFile.h"

TextFile::TextFile(const string &name, const string& content, ContainerEntity *parent): FileEntity(name), content(content), parent(parent) {
    this->size = content.length();
    parent->addChild(this);
}
