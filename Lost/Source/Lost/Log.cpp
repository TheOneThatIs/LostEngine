#include "Log.h"
#include<spdlog/spdlog.h>
#include<spdlog/sinks/stdout_color_sinks.h>
#include<gl/glew.h>

namespace Lost {
	auto console = spdlog::stdout_color_st("Logger");

	void Log::default() {
		console->set_pattern("%^[%l %r]\t%v%$");
	}

	void Log::info(const std::string& msg) {
		console->info(msg);
	}
	void Log::info(const char* msg) {
		console->info(msg);
	}
	void Log::warn(const std::string &msg) {
		console->warn(msg);
	}
	void Log::warn(const char* msg) {
		console->warn(msg);
	}
	void Log::error(const std::string& msg) {
		console->error(msg);
	}
	void Log::error(const char* msg) {
		console->error(msg);
	}

	void Log::setPattern(const std::string& pattern) {
		console->set_pattern(pattern);
	}
}