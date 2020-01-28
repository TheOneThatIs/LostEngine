#pragma once
#include<string>


namespace Lost {
	class Log {
	public:
		static void default();
		static void info(const std::string &msg);
		static void info(const char* msg);
		static void warn(const std::string &msg);
		static void warn(const char* msg);
		static void error(const std::string &msg);
		static void error(const char* msg);

		static void setPattern(const std::string& pattern);
	};
}