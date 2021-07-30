#include "TextFile.h"


string TextFile::getFilename() {
    return FILENAME;
}

bool TextFile::isFileEmpty() {
    bool isEmpty = true;
    fstream fileText;
    fileText.open(getFilename().c_str(), ios::app);

    if (fileText.good() == true) {
        fileText.seekg(0, ios::end);
        if (fileText.tellg() != 0)
            isEmpty = false;
    }

    fileText.close();
    return isEmpty;
}
