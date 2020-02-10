#pragma once
#include "Singleton.h"
#include <list>
#include <Windows.h>

class Task
{
public:
	virtual void Draw( HDC hdc ) {};
};

using namespace std;
class TaskManager : public Singleton<TaskManager>
{
public:
	void RegisterTask( Task* task );
	void AllDraw( HDC hdc );
private:
	list<Task*> TaskList;
};

