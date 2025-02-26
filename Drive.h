#pragma once
#include <string>
#include "ContainerEntity.h"


using namespace std;

class Drive: public ContainerEntity {
protected:
    size_t calculateSize();

public:
    // void deleteSelf() override;
    Drive(FileType type, const string &name);
    bool hasChildWithName(string name);
};