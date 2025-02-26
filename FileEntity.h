#pragma once
#include <string>
#include "FileType.h"

using namespace std;

class FileEntity {
    protected:
    FileType type;
    string name;
    string path;
    size_t size = 0;

    public:
    virtual ~FileEntity() = default;

    virtual void deleteSelf();
    FileEntity(FileType type, const string& name, const string& path);
    FileEntity(FileType type, const string& name);

    string getName();
    size_t getSize();
    string getPath();
    FileType getType();

    virtual void setPath(const string &path);
};
