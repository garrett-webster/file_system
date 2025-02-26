#pragma once
#include <vector>

#include "FileEntity.h"

class ContainerEntity: public FileEntity {
public:
    vector<FileEntity*> children;
    ContainerEntity(FileType type, const string& name);
    virtual void addChild(FileEntity* child);
    virtual void removeChild(FileEntity* child);
    void deleteSelf() override;
    void setPath(const string &path) override;

    // ContainerEntity* searchChildren(string path);
};
