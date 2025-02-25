#pragma once
#include <vector>

#include "FileEntity.h"
#include "FileSystem.h"

class ContainerEntity: public FileEntity {
public:
    vector<FileEntity*> children;
    ContainerEntity(string name);
    virtual void addChild(FileEntity* child);
    void deleteSelf() override;

    ContainerEntity* searchChildren(string path);

    Drive createFile(FileType type, string fileName);

    // void deleteFile(string path);
};
