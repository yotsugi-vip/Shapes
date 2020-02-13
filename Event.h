#pragma once
#include "framework.h"

enum EventId
{
	IDLE = 0,
	BUSY,
	EDIT,
	L_BUTTON_DOWN,
	L_BUTTON_UP,
	MOUSE_MOVE,
	MAX_EVENT
};

typedef struct Event 
{
	EventId id;
} stEvent;

void MainEvent(void);
void EventSend(stEvent event);
void FpsCtrl( MSG msg );