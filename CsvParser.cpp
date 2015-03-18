//
//  CsvParser.cpp
//  HelloCpp
//
//  Created by chao on 14-7-7.
//
//

#include "CsvParser.h"
#include <fstream>
#include <iostream>
#include "util.h"

CsvParser::CsvParser()
{
    
}

CsvParser::~CsvParser()
{
    
}

CsvParser * CsvParser::create(const char * filename)
{
    CsvParser * pRet = new CsvParser();
    if ( pRet && pRet->init(filename)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool CsvParser::init(const char * filename)
{
    parse(filename);
    return true;
}

//std::string readFileContent(const char * filename)
//{
//    std::string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename);
//    unsigned long size = 0;
//    unsigned char * pByte = NULL;
//    std::string fileContent;
//    
//    pByte = CCFileUtils::sharedFileUtils()->getFileData(filePath.c_str(), "r", &size);
//    
//    if (NULL == pByte || strcmp((const char *)pByte, "") == 0) {
//        CCLOG("read file error %s",filename);
//        return fileContent;
//    }
//    
//    fileContent = std::string((const char *)pByte , size);
//    
//    return fileContent;
//}

void CsvParser::parse(const char * filename)
{
//    std::string fileContent = readFileContent(filename);
//    std::vector<std::string> lineVector;
//    
//    split(fileContent, "\\n", lineVector);
//    
//    split(lineVector[1], ",", keyVector);
//    
//    for (int i = 0; i < keyVector.size(); i++) {
//        std::vector<std::string> temp;
//        this->csvData.insert(std::pair<std::string, std::vector<std::string> >(keyVector[i],temp));
//    }
//    
//    
//    int size = lineVector.size();
//    for (int i = 3 ; i < size; i++) {
//        std::vector<std::string> valueVector;
//        split(lineVector[i], ",", valueVector);
//        for (int j = 0; j < keyVector.size(); j++) {
//            csvData.at(keyVector[j]).push_back(valueVector[j]);
//        }
//        
//    }
    
    std::string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename);
    
    std::ifstream fileIn;
    fileIn.open(filePath.c_str());
    
    if (fileIn.is_open()) {
        
        if (fileIn != NULL) {
            std::string temp;
            getline(fileIn, temp);
            
            CCLOG("first line %s" , temp.c_str());
        }
        
        if (fileIn != NULL) {
            std::string temp;
            getline(fileIn, temp);
            
            CCLOG("second line %s ", temp.c_str());
            
            split(temp, ",", keyVector);
            
            for (int i = 0; i < keyVector.size(); i++) {
                std::vector<std::string> temp;
                this->csvData.insert(std::pair<std::string, std::vector<std::string> >(keyVector[i],temp));
            }

        }
        
        if (fileIn != NULL) {
            std::string temp;
            getline(fileIn, temp);
            
            CCLOG("third line %s ", temp.c_str());
        }
        
        while (fileIn != NULL) {
            std::string temp;
            
            getline(fileIn, temp);
            
            if (temp.empty() || temp == "") {
                break;
            }
            
            CCLOG("line %s ", temp.c_str());
            
            std::vector<std::string> valueVector;
            split(temp, ",", valueVector);
            
            for (int i = 0; i < keyVector.size(); i++) {
                csvData.at(keyVector[i]).push_back(valueVector[i]);
            }
        }
    }
}

int CsvParser::size()
{
    return csvData.at(keyVector[0]).size();
}

std::map<std::string, std::string> CsvParser::findOne(int index)
{
    std::map<std::string, std::string> temp;
    
    int size = this->size();
    
    if (index >= size) {
        return temp;
    }
    
    for (int i = 0; i < keyVector.size(); i++) {
        temp.insert(std::pair<std::string, std::string>(keyVector[i], csvData.at(keyVector[i])[index]));
    }
    return temp;
}

int CsvParser::findIndex(const std::string & key,const std::string & value)
{
    std::vector<std::string> valueVector = this->findArray(key);
    
    int size = valueVector.size();
    for (int i = 0; i < size; i++) {
        if (valueVector[i] == value) {
            return i;
        }
    }
    return -1;
}

std::vector<std::string> CsvParser::findArray(const std::string & key)
{
    return csvData.at(key);
}



