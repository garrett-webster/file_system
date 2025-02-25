#pragma once
#include "Drive.h"

class ZipFile: public Drive {
    Drive *parent;
public:
    void addChild(FileEntity *child);
    ZipFile(string name, Drive *parent);
};

