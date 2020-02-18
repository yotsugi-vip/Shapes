#pragma once
#include "Singleton.h"
#include "framework.h"

enum class Status {
	Normal = 0,
	Edit
};

typedef struct Datas
{
	unsigned int status;
	POINT Move;
	POINT Coordinate;
}stDatas;

class Entity : public Singleton<Entity>
{
public:
	stDatas Datas;
	size_t DatsSize;
	Entity();
};

