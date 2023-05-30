#include "user.h"

User::User(const std::string& name, const std::string& login, const std::string& pass) : _name(name), _login(login), _pass(pass) {}
User::User(const User& other) : _name(other._name), _login(other._login), _pass(other._pass) {}

User& User::operator = (const User& other) {
   
    if (this == &other) {
        return *this;
    }

    _name = other._name;
    _login = other._login;
    _pass = other._pass;

    return *this;
}

std::ifstream& operator >> (std::ifstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}

std::ostream& operator << (std::ostream& os, const User& obj) {
    os << obj._name << " ";
    os << obj._login << " ";
    os << obj._pass;
    return os;
}

std::string User::getUserLogin() const { return _login; }
std::string User::getUserName() const { return _name; }