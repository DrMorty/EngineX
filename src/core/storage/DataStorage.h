#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>
#include <memory>

#include "GameObject.h"

class DataStorage
{
 public:

    DataStorage();
    ~DataStorage();

    std::map<std::string, GameObject> gameObjects;

 private:
};

#endif