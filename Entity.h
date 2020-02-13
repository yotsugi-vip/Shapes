#pragma once
#include "Singleton.h"

enum Status {
	Normal = 0,
	Edit
};

typedef struct Datas
{
	unsigned int mouse_x;
	unsigned int mouse_y;
	unsigned int status;
}stDatas;

class Entity : public Singleton<Entity>
{
public:
	stDatas Datas;
	size_t DatsSize;
	Entity();
};

