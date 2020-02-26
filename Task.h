#pragma once
#include "Singleton.h"
#include <list>
#include <vector>
#include <Windows.h>

class Task
{
public:
	virtual void Draw( HDC hdc ) {};
	POINT Start = { 0 };
	POINT End = { 0 };
};

class TaskManager final : public Singleton<TaskManager>
{
public:
	friend class Singleton<TaskManager>;

public:
	void RegisterTask( Task* task );
	Task* DetectTop(POINT point);
	Task* GetTask();
	void DestroyTask();
	void AllDraw( HDC hdc );
	bool IsDraw = false;

private:
	TaskManager();
	~TaskManager();

private:
	std::vector<Task*> TaskList;
	Task* ActiveTask = nullptr;
};

