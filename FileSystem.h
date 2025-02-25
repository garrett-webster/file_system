#pragma once
#include <stdexcept>
#include <string>
#include <vector>

#include "Drive.h"
#include "TextFile.h"

enum FileType {DRIVE, FOLDER, ZIPFILE, TEXTFILE };

inline FileType stringToType(const string& type) {
    if (type == "Drive")    { return DRIVE;    }
    if (type == "Folder")   { return FOLDER;   }
    if (type == "ZipFile")  { return ZIPFILE;  }
    if (type == "TextFile") { return TEXTFILE; }

    throw runtime_error("Invalid type");
}

class FileSystem {
    public:
    static vector<ContainerEntity*> drives;
    static FileEntity* findFile(const std::string& path, vector<ContainerEntity*> &children = drives);
    static FileEntity* findFileHelper(const std::string& path, vector<FileEntity*> &children);
    static FileEntity* createFile(const string& type, const string& fileName, const string& parentPath);
    static Drive* createFile(const string& type, const string& fileName);
    static void deleteFile(const string& path);
    static void writeToFile(const string& path, const string& content);
};
