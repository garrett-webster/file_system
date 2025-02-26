#pragma once
#include "Drive.h"

class ZipFile: public Drive {
    ContainerEntity *parent;
public:
    void addChild(FileEntity *child) override;
    void removeChild(FileEntity *child) override;
    ZipFile(FileType type, string name, ContainerEntity *parent);
    ContainerEntity* getParent();
};

