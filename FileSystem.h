#pragma once
#include <stdexcept>
#include <string>
#include <vector>

#include "Drive.h"
#include "FileType.h"

class FileSystem {
    public:
    static vector<ContainerEntity*> drives;
    static FileEntity* findFile(const std::string& path);
    static FileEntity* findFileHelper(const std::string& path, vector<FileEntity*> &children);
    static FileEntity* createFile(const string& type, const string& fileName, const string& parentPath);
    static Drive* createFile(const string& type, const string& fileName);
    static void deleteFile(const string& path);
    static void writeToFile(const string& path, const string& content);
    static void moveFile(const string& from, const string& to);
};
