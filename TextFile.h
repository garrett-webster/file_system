#pragma once
#include "Drive.h"
#include "FileEntity.h"

class TextFile: public FileEntity {
    string content;
    FileEntity *parent;

    public:
    TextFile(const string &name, const string& content, ContainerEntity *parent);
};
