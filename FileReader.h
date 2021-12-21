//
// Created by Ivan on 21.12.21.
//

#ifndef LAB_6_FILEREADER_H
#define LAB_6_FILEREADER_H
#include "Date.h"
#include "DateParser.h"

struct FileReaderWriter{
    std::vector<std::string> read(const std::string& filePath) {
        std::ifstream fin(filePath);
        std::string str;
        std::vector<std::string> collection;
        while (fin >> str) {
            collection.push_back(str);
        }
        return collection;
    }
    void DatesNextDay(vector<std::string> collection){
        std::cout << "Next days are: \n";
        DateParser parser;
        for( auto & tmp : collection){
            std::cout << parser.Parse(tmp).NextDay().ToString() << "\n";
        }
    }
    void DatesDuration(vector<std::string> collection){
        std::cout << "Next days are: \n";
        DateParser parser;
        for(int i = 0; i < collection.size() - 1; ++i){
            Date a1 = parser.Parse(collection[i]);
            Date a2 = parser.Parse(collection[i + 1]);
            std::cout << "duration between " << i + 1 << "th and "<< i + 2 << "th day is -- " << a1.Duration(a2) << "\n";
        }
    }
};

#endif //LAB_6_FILEREADER_H
