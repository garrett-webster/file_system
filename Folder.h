#pragma once
#include "Drive.h"

class Folder:public Drive {
    ContainerEntity *parent;

public:
    Folder(string name, ContainerEntity *parent);
};
