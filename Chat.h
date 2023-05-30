#pragma once

#include <string>
#include <vector>
#include "user.h"
#include "Message.h"

class Chat {

    std::vector<User> _users;
    std::vector<Message> _messages;

public:

    Chat() = default;
    ~Chat() = default;

    size_t countUsers() const;                          //количество пользователей
    size_t countMessages() const;                       //количество сообщений
    
    void loadUsers();                                   //загрузить пользователей из файла
    void loadMessages();                                //загрузить сообщения из файла

    void saveUsers() const;                             //сохранить пользователей в файл
    void saveMessages() const;                          //сохранить сообщения в файл

    //добавить пользователя
    void addUser(const std::string& name, const std::string& login, const std::string& pass);
    //добавить сообщения
    void addMessage(const std::string& text, const std::string& sender, const std::string& receiver);
 
    void showUsers() const;                             //показать пользователей
    void showMessages() const;                          //показать сообщения

    bool havingName(const std::string& name);           //наличие имени
    bool havingLogin(const std::string& login);         //наличие логина
};