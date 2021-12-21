//
// Created by Ivan on 21.12.21.
//

#ifndef LAB_6_DATEPARSER_H
#define LAB_6_DATEPARSER_H

#include <sstream>
#include "Date.h"
struct DateParser {
    Date Parse(const std::string& str) {
        std::stringstream sin(str);
        short d;
        short m;
        short y;
        char dot ;
        sin >> d >> dot >> m >> dot >> y;
        Date date(d, m, y);
        return date;
    }
};

#endif //LAB_6_DATEPARSER_H
