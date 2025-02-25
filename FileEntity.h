#pragma once
#include <string>

using namespace std;

class FileEntity {
    protected:
    string name;
    string path;
    size_t size = 0;

    public:
    virtual ~FileEntity() = default;

    virtual void deleteSelf();
    FileEntity(string name, string path);
    FileEntity(string name);

    string getName();
    size_t getSize();
    string getPath();

    virtual void setPath(const string &path);
};
