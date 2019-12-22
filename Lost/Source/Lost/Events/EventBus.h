#pragma once
#include<vector>
#include"IEvent.h"

namespace Lost {
	class EventBus {
		std::vector<IEvent*> eventBus;
	public:
		void pushEvent(IEvent &e) {
			eventBus.emplace_back(e);
		}
		void popEvent() {

		}
	};
}