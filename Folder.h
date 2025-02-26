#pragma once
#include "Drive.h"

class Folder:public Drive {
    ContainerEntity *parent;

public:
    Folder(FileType type, const string& name, ContainerEntity *parent);
    ContainerEntity* getParent();
};
