#ifndef DATA_STORAGE_H
#define DATA_STORAGEH

#include "GameObject.h"

#include <map>
#include <string>
#include <memory>


class DataStorage
{
 public:

    DataStorage();
    ~DataStorage();

    std::map<std::string, GameObject> gameObjects;

 private:

};

#endif