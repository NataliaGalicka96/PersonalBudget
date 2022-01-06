#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile
{
   const string FILE_NAME;

public:
    XMLFile(string fileName):FILE_NAME(fileName)
    {
    };
    string downloadXMLFileName();
    bool fileEmpty();

};
#endif // XMLFILE_H
