#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Markup.h"

using namespace std;

class XMLFile{
    const string FILENAME;

public:
    XMLFile(string fileName) : FILENAME(fileName) {};

    string getFilename();
    bool isFileEmpty();
};

#endif // XMLFILE_H
