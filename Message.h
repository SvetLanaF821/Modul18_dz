#pragma once

#include <string>
#include <fstream>

class Message
{
	std::string _text;
	std::string _sender;
	std::string _receiver;	

public:
	Message() = default;
	Message(const std::string& text, const std::string& sender, const std::string& receiver);
	~Message() = default;

	Message(const Message& other);
	Message& operator = (const Message& other);

	friend std::ifstream& operator >>(std::ifstream& is, Message& obj);
	friend std::ostream& operator <<(std::ostream& os, const Message& obj);

	const std::string& getSender() const;
	const std::string& getReceiver() const;	
};