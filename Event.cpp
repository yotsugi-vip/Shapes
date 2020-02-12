#include "Event.h"
#include <queue>

#include <functional>
std::queue<stEvent> EventQueue;

std::function<void(void)> EventTable[] =
{
	/* 0 : IDLE */	nullptr,
	/* 1 : BUSY */	nullptr,
	/* 2 : EDIT */  nullptr,
};

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