#pragma once
#include "Drive.h"

class ZipFile: public Drive {
    ContainerEntity *parent;
public:
    void addChild(FileEntity *child);
    ZipFile(string name, ContainerEntity *parent);
};

