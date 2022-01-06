#include "XMLFile.h"

string XMLFile::downloadXMLFileName()
{
    return FILE_NAME;
}
bool XMLFile::fileEmpty()
{
    bool fileIsEmpty = true;

    fstream textFile;
    textFile.open(downloadXMLFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            fileIsEmpty = false;
    }

    textFile.close();
    return fileIsEmpty;
}

