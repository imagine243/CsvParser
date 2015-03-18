//
//  CsvParser.h
//  HelloCpp
//
//  Created by chao on 14-7-7.
//
//

#ifndef __HelloCpp__CsvParser__
#define __HelloCpp__CsvParser__

#include "cocos2d.h"

USING_NS_CC;

class CsvParser : public CCObject{
public:
    
    CsvParser();
    virtual ~CsvParser();
    
    static CsvParser * create(const char * filename);
    bool init(const char * filename);
    
    void parse(const char * filename);
    
    int size();
    std::map<std::string, std::string> findOne(int index);
    int findIndex(const std::string & key,const std::string & value);
    std::vector<std::string> findArray(const std::string & key);
private:
    std::map<std::string, std::vector<std::string> > csvData;
    std::vector<std::string> keyVector;
};

#endif /* defined(__HelloCpp__CsvParser__) */
