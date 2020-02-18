#include "Event.h"
#include <queue>
#include <functional>
#include <map>

std::queue<stEvent> EventQueue;
static bool nowPaint = false;


void EvLButtonDown();
void EvMouseMove();
void EvLButtonUp();
void EvRButtonDown();

std::map< EventId, std::function<void(void)> > EventTable = { 
	{ EventId::IDLE,			nullptr			},
	{ EventId::BUSY,			nullptr			},
	{ EventId::EDIT,			nullptr			},
	{ EventId::L_BUTTON_DOWN,	EvLButtonDown	},
	{ EventId::R_BUTTON_DOWN,	EvRButtonDown	},
	{ EventId::L_BUTTON_UP,		EvLButtonUp		},
	{ EventId::R_BUTTON_UP,		nullptr			},
	{ EventId::MOUSE_MOVE,		EvMouseMove		},
};

std::map < Status, std::function<void(void)> > EventTable_s =
{
	{ Status::Normal,			nullptr			},
	{ Status::Edit,				nullptr			},
};

static time_t t = 0;
static int i = 0;
void FpsCtrl( MSG msg )
{
	WCHAR wc[256];
	int l = 0;
	if (t == 0)
	{
		t = GetTickCount64();
	}
	else
	{
		if (GetTickCount64() - t > 1000)
		{
			l = wsprintfW(wc, L"LOOP:%d", i);
		
			HDC hdc = GetDC(msg.hwnd);
			TextOutW(hdc, 10, 10, wc, l);
			TextOut(hdc, 10, 10, L"HELLO", 5);
			ReleaseDC(msg.hwnd, hdc);
			
			OutputDebugString(wc);
			t = 0;
			i = 0;
		}
		else
		{
			i++;
			
		}
	}
}

void MainEvent()
{
	stEvent event;

	if (!EventQueue.empty())
	{
		event = EventQueue.front();

		EventQueue.pop();

		if (nullptr != EventTable[event.id])
		{
			EventTable[event.id]();
		}
	}
}

void EventSend( stEvent event ) 
{
	EventQueue.push(event);
}


void EvLButtonDown() 
{
	if (TaskManager::GetInstance()->IsDraw)
	{
		Rect* task = new Rect();
		task->Start.x = Entity::GetInstance()->Datas.mouse.x;
		task->Start.y = Entity::GetInstance()->Datas.mouse.y;
		task->End.x = Entity::GetInstance()->Datas.mouse.x;
		task->End.y = Entity::GetInstance()->Datas.mouse.y;
		TaskManager::GetInstance()->RegisterTask(task);
		nowPaint = true;
	}
	else
	{	
		Task* task = TaskManager::GetInstance()->DetectTop(Entity::GetInstance()->Datas.mouse);

		if (nullptr != task)
		{
			nowPaint = true;
		}
	}
}

void EvMouseMove()
{
	if (TaskManager::GetInstance()->IsDraw && nowPaint)
	{
		Task* task = TaskManager::GetInstance()->GetTask();
		task->End.x = Entity::GetInstance()->Datas.mouse.x;
		task->End.y = Entity::GetInstance()->Datas.mouse.y;
	}
	else if( nowPaint )
	{
		Task* task = TaskManager::GetInstance()->GetTask();
		task->Start.x += Entity::GetInstance()->Datas.mouse.x;
		task->Start.y += Entity::GetInstance()->Datas.mouse.y;
		task->End.x += Entity::GetInstance()->Datas.mouse.x;
		task->End.y += Entity::GetInstance()->Datas.mouse.y;
	}
}

void EvRButtonDown() 
{
	TaskManager::GetInstance()->IsDraw ? TaskManager::GetInstance()->IsDraw = false 
		: TaskManager::GetInstance()->IsDraw = true;
}

void EvLButtonUp()
{
	TaskManager::GetInstance()->IsDraw = false;
	nowPaint = false;
}