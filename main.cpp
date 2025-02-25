#include <iostream>
#include "FileEntity.h"
#include "Drive.h"
#include "Folder.h"
#include "TextFile.h"
#include "ZipFile.h"
#include "FileSystem.h"

using namespace std;

int main() {

    FileSystem::createFile("Drive", "Drive");

    auto zip_file = FileSystem::createFile("ZipFile", "zip_file", "/Drive");
    FileSystem::createFile("Folder", "folder", "/Drive/zip_file");
    FileSystem::createFile("TextFile", "text_file", "/Drive/zip_file/folder");
    string file_name = "file.txt";

    zip_file->setPath(file_name);
    FileEntity *file_entity = FileSystem::findFile("file.txt");
    cout << "for debugging!" << endl;
}