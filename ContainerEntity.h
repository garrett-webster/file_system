#pragma once
#include <vector>

#include "FileEntity.h"

class ContainerEntity: public FileEntity {
public:
    vector<FileEntity*> children;
    ContainerEntity(string name);
    virtual void addChild(FileEntity* child);
    void deleteSelf() override;

    FileEntity* searchChildren(string path);
};
