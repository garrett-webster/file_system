#pragma once
#include "Drive.h"

class Folder:public Drive {
    FileEntity *parent;

public:
    Folder(string name, Drive *parent);
};
