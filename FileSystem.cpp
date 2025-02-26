#include <stdexcept>

#include "FileSystem.h"

#include <iostream>
#include <ostream>

#include "Folder.h"
#include "TextFile.h"
#include "ZipFile.h"

vector<ContainerEntity*> FileSystem::drives;

// Recursively searches for a file with given path and returns it
FileEntity* FileSystem::findFileHelper(const std::string& path, vector<FileEntity*>& children) {
    for (const auto child : children) {
        if (child->getPath() == path) {
            return child;
        }

        auto* result = dynamic_cast<ContainerEntity*>(child);
        // If the child is a ContainerEntity, recursively search its children
        if (result) {
            return result;
        }
    }
    return nullptr;
}

// Starts a search at the Drive level.
FileEntity* FileSystem::findFile(const std::string& path) {
    FileEntity* result;
    for (const auto drive : drives) {
        if (drive->getPath() == path) {
            return drive;
        }

        result = findFileHelper(path, drive->children);
        if (result) {
            return result;
        }
    }
    return nullptr;
}

FileEntity* FileSystem::createFile(const string& type, const string& fileName, const string& parentPath) {
    auto parent = dynamic_cast<ContainerEntity*>(findFile(parentPath));
    FileType fileType = stringToType(type);

    switch (fileType) {
        case DRIVE:
            throw runtime_error("Drives cannot have a parent.");
        case TEXTFILE:
            if (!parent) {
                throw runtime_error("Parent is not a container entity.");
            }
            return new TextFile(fileType, fileName, parent);
        case FOLDER:
            if (!parent) {
                throw runtime_error("Parent is not a container entity.");
            }
        return new Folder(fileType, fileName, parent);
        case ZIPFILE:
            if (!parent) {
                throw runtime_error("Parent is not a container entity.");
            }
            return new ZipFile(fileType, fileName, parent);
    }

    return nullptr;
}

Drive* FileSystem::createFile(const string& type, const string& fileName) {
    if (stringToType(type) != DRIVE) {
        throw runtime_error("File type not supported");
    } else {
        auto* newDrive = new Drive(DRIVE, fileName);
        drives.push_back(newDrive);
        return newDrive;
    }
}

// Deletes a file with given path and recursively deletes its children
void FileSystem::deleteFile(const string& path) {
    auto* file = findFile(path);
    if (file) {
        file->deleteSelf();
    } else {
        cout << "Error: File not found: " << path << endl;
    }
}

void FileSystem::writeToFile(const string& path, const string& content) {
    auto* textFile = dynamic_cast<TextFile*>(findFile(path));
    if(textFile) {
        textFile->setContent(content);
    } else {
        throw runtime_error("Cannot write to a non-textfile.");
    }
}

void FileSystem::moveFile(const string& from, const string& to) {
    auto* file = findFile(from);
    auto* newParent = dynamic_cast<ContainerEntity*>(findFile(to));
    ContainerEntity *parent;

    if (!file) {
        throw std::runtime_error("File not found: " + from);
    }

    if (!newParent) {
        throw std::runtime_error("Not a valid path: " + to);
    }

    switch (file->getType()) {
        case DRIVE:
            throw runtime_error("Can't move drives.");
        case TEXTFILE: {
            auto *textFile = dynamic_cast<TextFile*>(file);
            parent = textFile->getParent();

            parent->removeChild(textFile);
            newParent->addChild(textFile);
            textFile->setPath(to);
            break;
        }
        case FOLDER: {
            auto *folder = dynamic_cast<Folder*>(file);
            parent = folder->getParent();

            parent->removeChild(folder);
            // This next line is causing issues. I'm not sure why.
            newParent->addChild(folder);
            folder->setPath(to);
            break;
        }
        case ZIPFILE: {
            auto *zipFile = dynamic_cast<ZipFile*>(file);
            parent = zipFile->getParent();

            parent->removeChild(zipFile);
            // This next line is causing issues. I'm not sure why.
            newParent->addChild(zipFile);
            zipFile->setPath(to);
            break;
        }
        default:
            throw runtime_error("File type not supported.");
    }
}
