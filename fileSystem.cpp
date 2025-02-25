#include "FileSystem.h"

auto FileSystem::findParent(string path, vector<Drive> drives) {
    for (auto drive : drives) {
        FileEntity *result = drive.searchChildren(path);

        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}