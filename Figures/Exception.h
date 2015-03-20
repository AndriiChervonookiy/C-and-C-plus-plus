#pragma once
#include<string>
class Exception
{
protected:
	std::string message;
public:

	Exception(){
		message = "Message not set";
	}
	Exception(std::string message){
		this->message = message;
	}
	std::string getMessage() {
		return message;
	}
	~Exception(){};
};
