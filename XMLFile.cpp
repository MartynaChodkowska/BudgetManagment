#include "XMLFile.h"


string XMLFile::getFilename() {
    return FILENAME;
}

bool XMLFile::isFileEmpty() {
    bool isEmpty = true;
    fstream xmlFile;
    xmlFile.open(getFilename().c_str(), ios::app);

    if (xmlFile.good() == true) {
        xmlFile.seekg(0, ios::end);
        if (xmlFile.tellg() != 0)
            isEmpty = false;
    }

    xmlFile.close();
    return isEmpty;
}
