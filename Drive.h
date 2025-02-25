#pragma once
#include <memory>
#include <string>
#include <vector>
#include "ContainerEntity.h"

#include "FileEntity.h"

using namespace std;

class Drive: public ContainerEntity {
protected:
    size_t calculateSize();

public:
    void deleteSelf() override;
    Drive(const string &name);
    bool hasChildWithName(string name);
    void setPath(string &path);
};