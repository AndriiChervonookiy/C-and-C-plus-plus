#pragma once
#include<string>
class Exception {

	std::string message;

public:

	Exception();

	Exception(std::string message);

	std::string getMessage() {
		return message;
	}

	~Exception();
};