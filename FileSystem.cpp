#include "FileSystem.h"

#include <stdexcept>
#include <utility>

#include "Folder.h"
#include "TextFile.h"

ContainerEntity* FileSystem::findParent(string path, vector<Drive*> &drives) {

    for (auto drive : drives) {
        ContainerEntity *result = drive->searchChildren(path);
        if (drive->getPath() == path) {
            return drive;
        }
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

// FileEntity* FileSystem::findFile(const std::string& path, vector<Drive*> &drives) {
//     for (auto drive : drives) {
//
//         ContainerEntity *result = dynamic_cast<ContainerEntity*>(drive);
//         if (result != nullptr) {
//         }
//         // ContainerEntity *result = drive->searchChildren(path);
//         if (drive->getPath() == path) {
//             return drive;
//         }
//
//
//
//
//         if (result != nullptr) {
//             return result;
//         }
//     }
//     return nullptr;
// }

auto FileSystem::createFile(FileType type, string fileName, vector<Drive*> drives, string parentPath) {
    switch (type) {
        case DRIVE:
            throw runtime_error("Drives cannot have parents.");
        case TEXTFILE:
            throw runtime_error("Text files need a content string.");
        case FOLDER:
            return Folder(move(fileName), FileSystem::findParent(move(parentPath), drives));
        case ZIPFILE:
            return ZIPFILE(move(fileName), FileSystem::findParent(move(parentPath), drives));
    }
}

auto FileSystem::createFile(FileType type, string fileName, vector<Drive*> drives, string parentPath, string content) {
    switch (type) {
        case DRIVE:
            throw runtime_error("Drives cannot have parents.");
        case TEXTFILE:
            throw runtime_error("Text files need a content string.");
        case FOLDER:
            return Folder(move(fileName), FileSystem::findParent(move(parentPath), drives));
        case ZIPFILE:
            return ZIPFILE(move(fileName), FileSystem::findParent(move(parentPath), drives));
    }
}

Drive FileSystem::createFile(FileType type, string fileName) {
    if (type != DRIVE) {
        throw runtime_error("File type not supported");
    } else {
        return {fileName};
    }
}

void FileSystem::deleteFile(string path, vector<Drive*> drives) {
    FileSystem::findParent(std::move(path), drives)->deleteSelf();
}

void FileSystem::writeToFile(const string& path, const string& content, vector<Drive*> drives) {
    FileSystem::findFile(std::move(path), drives)->setContent(content);
}

