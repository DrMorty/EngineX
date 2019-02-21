#include "GameObject.h"
#include <iostream>
#include <string>

GameObject::GameObject()
{  
};

GameObject::GameObject(std::string t_name) : name(t_name) 
{
    for (auto component : m_components)
        delete component;
};

GameObject::~GameObject() 
{
};