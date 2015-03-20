#pragma once
#include "Exception.h"
#include<string>

class TriangleError : public Exception
{
public:
	TriangleError(){
		message = "Message not set";
	}
	TriangleError(std::string message){
		this->message = message;
	}
	~TriangleError(){}
};
