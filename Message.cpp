#include "Message.h"

Message::Message(const std::string& text, const std::string& sender, const std::string& receiver) : _text(text), _sender(sender), _receiver(receiver) {}

Message::Message(const Message& other) : _text(other._text), _sender(other._sender), _receiver(other._receiver) {}

Message& Message::operator = (const Message& other) {
    
    if (this == &other) {
        return *this;
    }

    _text = other._text;
    _sender = other._sender;
    _receiver = other._receiver;

    return *this;
}

std::ifstream& operator >>(std::ifstream& is, Message& obj) {
    is >> obj._sender;
    is >> obj._receiver;
    is.seekg(1, std::ios_base::cur);
    std::getline(is, obj._text);
    return is;
}

std::ostream& operator <<(std::ostream& os, const Message& obj) {
    os << obj._sender << " ";
    os << obj._receiver << " ";
    os << obj._text;
    return os;
}

const std::string& Message::getSender() const { return _sender; }
const std::string& Message::getReceiver() const { return _receiver; }