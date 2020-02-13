#include "Event.h"
#include <queue>
#include <functional>

std::queue<stEvent> EventQueue;
static bool nowPaint = false;


void EvLButtonDown();
void EvMouseMove();
void EvLButtonUp();

std::function<void(void)> EventTable[] =
{
	/* 0 : IDLE */	nullptr,
	/* 1 : BUSY */	nullptr,
	/* 2 : EDIT */  nullptr,
	/* 3 : LBD  */  EvLButtonDown,
	/* 4 : LBU  */  EvLButtonUp,
	/* 5 : MMOVE*/  EvMouseMove,
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

		if (MAX_EVENT > event.id && nullptr != EventTable[event.id])
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
	Rect* task = new Rect();
	task->Start.x = Entity::GetInstance()->Datas.mouse_x;
	task->Start.y = Entity::GetInstance()->Datas.mouse_y;
	task->End.x	  = Entity::GetInstance()->Datas.mouse_x;
	task->End.y	  = Entity::GetInstance()->Datas.mouse_y;
	TaskManager::GetInstance()->RegisterTask(task);
	nowPaint = true;
}

void EvMouseMove()
{
	if (true == nowPaint)
	{
		Task* task = TaskManager::GetInstance()->GetTask();
		task->End.x = Entity::GetInstance()->Datas.mouse_x;
		task->End.y = Entity::GetInstance()->Datas.mouse_y;
	}
}

void EvLButtonUp()
{
	nowPaint = false;
}