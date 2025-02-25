#pragma once
#include "FileEntity.h"
#include "ContainerEntity.h"

class TextFile: public FileEntity {
    string content;
    FileEntity *parent;

public:
    TextFile(const string &name, ContainerEntity *parent);

    void setContent(const string &content);

    void setPath(const string& parentPath) override;
};
