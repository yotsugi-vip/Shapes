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