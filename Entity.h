#pragma once
#include "Singleton.h"
class Entity : public Singleton<Entity>
{
public:
	unsigned int mouse_x;
	unsigned int mouse_y;
};

