#pragma once
#include "Drive.h"

class Folder:public Drive {
    ContainerEntity *parent;

public:
    Folder(const string& name, ContainerEntity *parent);
};
