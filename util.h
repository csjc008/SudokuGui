#ifndef UTIL_H
#define UTIL_H

#include <QString>

class Util
{
private:
    Util();
public:
    static QString getStringFromResource(char * resourceName);
};

#endif // UTIL_H
