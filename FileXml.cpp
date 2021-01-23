#include "FileXml.h"

 CMarkup FileXml::initFile(string fileName)
{
    CMarkup plikXml;

    bool fileExists = plikXml.Load( fileName + ".xml" );

    if ( ! fileExists )
    {
        plikXml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        plikXml.AddElem( "Root" );
    }

    plikXml.Save( fileName + ".xml" );
    return plikXml;
}
