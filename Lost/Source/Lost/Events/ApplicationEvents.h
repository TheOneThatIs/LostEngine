#pragma once
#include"IEvent.h"

namespace Lost {
	class WindowResize : public IEvent{
		unsigned int width, height;
	public:
		WindowResize(unsigned width, unsigned height) : width(width), height(height){}

		unsigned int getWidth() const { return width; }
		unsigned int getHeight() const { return height; }

		EventType getEventType() override { return EventType::WINDOW_RESIZE; }
	};

	class WindowMove : public IEvent {
	public:
		WindowMove(){}

	};
}