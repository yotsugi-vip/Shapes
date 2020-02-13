#include "Task.h"

void TaskManager::AllDraw( HDC hdc )
{
	for (Task* task : TaskManager::TaskList)
	{
		task->Draw(hdc);
	}
}

void TaskManager::RegisterTask(Task* task)
{
	TaskManager::TaskList.push_back(task);
}

Task* TaskManager::GetTask()
{
	return this->TaskList.front();
}

void TaskManager::DestroyTask()
{
	for (Task* task : this->TaskList)
	{
		delete task;
	}

	this->TaskList.clear();
}