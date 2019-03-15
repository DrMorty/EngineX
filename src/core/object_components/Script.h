#ifndef SCRIPT_H
#define SCRIPT_H

#include "GameObjectComponent.h"

class Script : public GameObjectComponent
{
 public:

    virtual void start() = 0;
    virtual void update() = 0;     
};

#endif