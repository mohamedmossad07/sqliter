//
// Created by mohamed on 01/08/23.
//

#include <mapper/ColumnMapper.h>
#include <iostream>
namespace mapper {
    int ColumnMapper::map(Column * obj, char * data){
        std::string typeString = std::to_string(obj->type);
        int typeCharsCount = typeString.length();
        typeString.insert(0,std::to_string(typeCharsCount));
        typeString.insert(0,std::to_string(std::to_string(typeCharsCount).length()));
        int colNameCount = obj->name.length();
        typeString.append(std::to_string(std::to_string(colNameCount).length()));
        typeString.append(std::to_string(colNameCount));
        typeString.append(obj->name);
        memcpy(data,typeString.data(),typeString.length());
         //        memset();
        return 0;
    }
    Column* ColumnMapper::unmap(char * data, Column * obj){
        return nullptr;
    }
} // mapper