#include <iostream>
#include "FileEntity.h"
#include "Drive.h"
#include "Folder.h"
#include "TextFile.h"
#include "ZipFile.h"
#include "FileSystem.h"

using namespace std;

int main() {
    vector<Drive*> drives;


    auto drive = Drive("Drive");
    drives.push_back(&drive);
    auto zip_file = ZipFile("zip_file", &drive);
    auto folder = Folder("folder", &zip_file);
    auto text_file = TextFile("text_file", "This is content of size 26", &folder);
    //
    // string file_name = "file.txt";
    //
    // zip_file.setPath(file_name);

    // drive->deleteSelf();
    FileEntity *file_entity = FileSystem::findParent("/Drive/zip_file", drives);
    cout << "for debugging!" << endl;
}