#pragma once

enum FileType {DRIVE, FOLDER, ZIPFILE, TEXTFILE, UNKNOWN };

inline FileType stringToType(const std::string& type) {
    if (type == "Drive")    { return DRIVE;    }
    if (type == "Folder")   { return FOLDER;   }
    if (type == "ZipFile")  { return ZIPFILE;  }
    if (type == "TextFile") { return TEXTFILE; }

    return UNKNOWN;
}