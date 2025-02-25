#pragma once
#include <string>
#include "ContainerEntity.h"


using namespace std;

class Drive: public ContainerEntity {
protected:
    size_t calculateSize();

public:
    // void deleteSelf() override;
    Drive(const string &name);
    bool hasChildWithName(string name);
};