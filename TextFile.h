#pragma once
#include "FileEntity.h"
#include "ContainerEntity.h"

class TextFile: public FileEntity {
    string content;
    ContainerEntity *parent;

public:
    TextFile(FileType type, const string &name, ContainerEntity *parent);

    void setContent(const string &content);
    void setPath(const string& parentPath) override;
    ContainerEntity* getParent();
};
