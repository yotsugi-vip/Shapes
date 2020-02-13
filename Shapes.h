#pragma once

#include "resource.h"
#include "Task.h"
#include <vector>

class Rect : public Task
{
public:
	void Draw( HDC hdc );

	//POINT Start;
	//POINT End;
};

class Circle : public Task
{
public:
	void Draw(HDC hdc);

	POINT Start;
	POINT End;
};

class Poly : public Task
{
public:
	void Draw(HDC hdc);
	std::vector<POINT> Points;
};