#pragma once
#include <string>
#include <vector>

#include "Drive.h"
#include "TextFile.h"

enum FileType {DRIVE, FOLDER, ZIPFILE, TEXTFILE };

class FileSystem {
    public:
    static ContainerEntity* findParent(std::string path, vector<Drive*> &drives);
    static TextFile* findFile(const std::string& path, vector<Drive*> &drives);
    auto createFile(FileType type, string fileName, vector<Drive*> drives, string parentPath, string content);
    auto createFile(FileType type, string fileName, vector<Drive*> drives, string parentPath);
    Drive createFile(FileType type, string fileName);
    void deleteFile(string path, vector<Drive*> drives);
    void writeToFile(const string& path, const string& content, vector<Drive*> drives);
};
