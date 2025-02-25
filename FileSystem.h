#pragma once
#include <string>
#include <vector>

#include "Drive.h"

class FileSystem {
    public:
    static auto findParent(std::string path, std::vector<Drive> drives);
};
