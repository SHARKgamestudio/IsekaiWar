#pragma once

#pragma region External Dependencies

#include <string>

#pragma endregion

class Debug {
public:
#ifdef _DEBUG
	[[noreturn]]
#endif
	static void Assert(bool condition, std::string message, bool quit = true);
};