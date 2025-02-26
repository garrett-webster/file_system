#include <iostream>
#include "FileEntity.h"
#include "FileSystem.h"

using namespace std;


int main() {

    FileSystem::createFile("Drive", "Drive1");
    // FileSystem::createFile("Drive", "Drive2");
    // auto* zip = FileSystem::createFile("ZipFile", "zipFile", "/Drive1");
    // FileSystem::createFile("TextFile", "text_file", "/Drive1/zipFile");
    //
    // zip->setPath("/Drive2");


    FileSystem::createFile("Drive", "Drive2");
    FileSystem::createFile("TextFile", "text_file", "/Drive1");
    FileSystem::createFile("ZipFile", "zipFile", "/Drive1");

    FileSystem::moveFile("/Drive1/zipFile", "/Drive2");
    FileSystem::moveFile("/Drive1/text_file", "/Drive2/zipFile");

    // auto zip_file = FileSystem::createFile("ZipFile", "zip_file", "/Drive");
    // FileSystem::createFile("Folder", "folder", "/Drive/zip_file");
    // string file_name = "file.txt";
    //
    // zip_file->setPath(file_name);
    FileEntity *file_entity = FileSystem::findFile("/Drive2/folder/text_file");
    cout << "for debugging!" << endl;
}