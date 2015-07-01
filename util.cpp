#include "util.h"

Util::Util(){
}

QString Util::getStringFromResource(char *resourceName){
    QFile f(resourceName);
    f.open(QIODevice::ReadOnly);
    QString str(f.readAll());
    f.close();
    return str;
}

