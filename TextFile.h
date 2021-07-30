#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
#include <vector>

//#include "SupportingMethods.h"

using namespace std;

class TextFile{
    const string FILENAME;

public:
    TextFile(string fileName) : FILENAME(fileName) {}

    string getFilename();
    bool isFileEmpty();
};

#endif // TEXTFILE_H
