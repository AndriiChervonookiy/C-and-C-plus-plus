#include "Exception.h"

Exception::Exception(){
	message = "Message not set";
}

Exception::Exception(std::string message) {
	this->message = message;
}

Exception::~Exception(){}