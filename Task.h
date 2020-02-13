#pragma once
#include "Singleton.h"
#include <list>
#include <Windows.h>

class Task
{
public:
	virtual void Draw( HDC hdc ) {};
	POINT Start;
	POINT End;
};

class TaskManager : public Singleton<TaskManager>
{
public:
	void RegisterTask( Task* task );
	Task* GetTask();
	void DestroyTask();
	void AllDraw( HDC hdc );
private:
	std::list<Task*> TaskList;
};

