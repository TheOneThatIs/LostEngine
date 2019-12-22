#pragma once

namespace Lost {

	class IEvent {
	public:
		enum class EventType {
			NONE,
			WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_MOVE, WINDOW_LOST_FOCUS,
			MOUSE_PRESSED, MOUSE_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED,
			GAMEPAD_PRESSED, GAMEPAD_RELEASED, GAMEPAD_JOYSTICK,
			KEY_PRESSED, KEY_RELEASED, KEY_HELD,
			APP_UPDATE, APP_RENDER

		};

		IEvent(){}

		virtual EventType getEventType() {}
	};
}