#pragma once
#include <string>
#include <fstream>

class User
{
    std::string _name;
    std::string _login;
    std::string _pass;    

public:
    User() = default;
    User(const std::string& name, const std::string& login, const std::string& pass);
    ~User() = default;

    User(const User& other);
    User& operator = (const User& other);
    
    friend std::ifstream& operator >> (std::ifstream& is, User& obj);
    friend std::ostream& operator << (std::ostream& os, const User& obj);

    std::string getUserLogin() const;
    std::string getUserName() const;
};