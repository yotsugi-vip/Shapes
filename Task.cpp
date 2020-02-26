#include "Task.h"

TaskManager::TaskManager()
{

}

TaskManager::~TaskManager()
{

}

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
	this->ActiveTask = task;
}

Task* TaskManager::GetTask()
{
	return this->ActiveTask;
}

void TaskManager::DestroyTask()
{
	for (Task* task : this->TaskList)
	{
		delete task;
	}

	this->TaskList.clear();
}

Task* TaskManager::DetectTop(POINT point)
{
	Task* task = nullptr;
	
	/* �ŏ�ʂɕ`�悳��Ă�����̂���m�F���� */
	for ( size_t i = this->TaskList.size(); i > 0; i-- )
	{
		task = this->TaskList[i-1];

		if (point.x >= task->Start.x && point.x <= task->End.x
		 && point.y >= task->Start.y && point.y <= task->End.y)
		{
			this->ActiveTask = task;
			return this->ActiveTask;
		}
	}
	return nullptr;
}