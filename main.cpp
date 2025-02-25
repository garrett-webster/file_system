#include <iostream>
#include "FileEntity.h"
#include "Drive.h"
#include "Folder.h"
#include "TextFile.h"
#include "ZipFile.h"

using namespace std;

enum FileType {DRIVE, FOLDER, ZIPFILE, TEXTFILE };

auto createFile(FileType type, string fileName, string parentPath) {
    switch (type) {
        case DRIVE:
            throw runtime_error("Drives cannot have parents");
        case FOLDER:
            return Folder(fileName, parentPath);
    }
}

Drive createFile(FileType type, string fileName) {
    if (type != DRIVE) {
        throw runtime_error("File type not supported");
    } else {
        return {fileName};
    }
}



int main() {
    vector<Drive> drives;


    auto drive = Drive("Drive");
    auto zip_file = ZipFile("zip_file", &drive);
    auto folder = Folder("folder", &zip_file);
    auto text_file = TextFile("text_file", "This is content of size 26", &folder);
    //
    // string file_name = "file.txt";
    //
    // zip_file.setPath(file_name);

    // drive->deleteSelf();
    cout << "for debugging!" << endl;
}