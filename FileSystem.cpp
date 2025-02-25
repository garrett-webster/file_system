#include <stdexcept>

#include "FileSystem.h"

#include <iostream>
#include <ostream>

#include "Folder.h"
#include "TextFile.h"
#include "ZipFile.h"

vector<ContainerEntity*> FileSystem::drives;

FileEntity* FileSystem::findFileHelper(const std::string& path, vector<FileEntity*>& children) {
    for (const auto child : children) {
        if (child->getPath() == path) {
            return child;
        }

        auto* result = dynamic_cast<ContainerEntity*>(child);
        // If the child is a ContainerEntity, recursively search its children
        if (result) {
            return findFileHelper(path, result->children);  // Pass child’s children
        }
    }
    return nullptr;
}

FileEntity* FileSystem::findFile(const std::string& path, vector<ContainerEntity*>& children) {
    for (const auto drive : drives) {
        if (drive->getPath() == path) {
            return drive;
        }

        return findFileHelper(path, drive->children);  // Pass child’s children
    }
    return nullptr;
}

FileEntity* FileSystem::createFile(const string& type, const string& fileName, const string& parentPath) {
    auto parent = dynamic_cast<ContainerEntity*>(findFile(parentPath, drives));

    switch (stringToType(type)) {
        case DRIVE:
            throw runtime_error("Drives cannot have parents.");
        case TEXTFILE:
            if (!parent) {
                throw runtime_error("Parent is not a container entity.");
            }
            return new TextFile(fileName, parent);
        case FOLDER:
            if (!parent) {
                throw runtime_error("Parent is not a container entity.");
            }
        return new Folder(fileName, parent);
        case ZIPFILE:
            if (!parent) {
                throw runtime_error("Parent is not a container entity.");
            }
            return new ZipFile(fileName, parent);
    }

    return nullptr;
}

Drive* FileSystem::createFile(const string& type, const string& fileName) {
    if (stringToType(type) != DRIVE) {
        throw runtime_error("File type not supported");
    } else {
        auto* newDrive = new Drive(fileName);
        drives.push_back(newDrive);
        return {newDrive};
    }
}

void FileSystem::deleteFile(const string& path) {
    auto* file = findFile(path, drives);
    if (file) {
        file->deleteSelf();
    } else {
        cout << "Error: File not found: " << path << endl;
    }
}

void FileSystem::writeToFile(const string& path, const string& content) {
    auto* textFile = dynamic_cast<TextFile*>(findFile(path, drives));
    if(textFile) {
        textFile->setContent(content);
    }
}

