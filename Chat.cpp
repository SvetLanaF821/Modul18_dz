#include "Chat.h"
#include <iostream>
#include <fstream>
#include <filesystem>

//количество пользователей
size_t Chat::countUsers() const {
    return _users.size();
}

//количество сообщений
size_t Chat::countMessages() const {
    return _messages.size();
}

//загрузить пользователей из файла
void Chat::loadUsers() {
    
    std::ifstream file("users.txt");                            //открыть файл

    if (!file.is_open()) {                                      //если файл не открыт
        std::cout << "File users.txt did't open!" << std::endl;
  
        if (!std::filesystem::exists("users.txt")) {            //если файла нет
            std::cout << "File users.txt does't exist!" << std::endl;
        }
        return;
    }

    User tempUser;
    while (file >> tempUser) {              
        _users.emplace_back(tempUser);                          //загрузить данные
    }

    file.close();                                               //закрыть файл
}

//загрузить сообщения из файла
void Chat::loadMessages() {

    std::ifstream file("messages.txt");                         //открыть файл

    if (!file.is_open()) {                                      //если файл не открыт
        std::cout << "File messages.txt did't open!" << std::endl;

        if (!std::filesystem::exists("messages.txt")) {         //если файла нет
            std::cout << "File messages.txt does't exist!" << std::endl;
        }
        return;
    }

    Message tempMessage;
    while (file >> tempMessage) {
        _messages.emplace_back(tempMessage);                    //загрузить данные
    }

    file.close();                                               //закрыть файл
}

//сохранить пользователей в файл
void Chat::saveUsers() const {                                  

    std::ofstream file("users.txt", std::ios::trunc);           //открыть файл

    if (!file.is_open()) {                                      //если файл не открыт
        std::cout << "File users.txt did't open!" << std::endl;
        return;
    }

    for (const auto& user : _users) {                           
        file << user << std::endl;                              //записать в файл
    }

    file.close();                                               //закрыть файл

    //установить права на файл
    std::filesystem::permissions("users.txt", std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);
}

//сохранить сообщения в файл
void Chat::saveMessages() const {
    
    std::ofstream file("messages.txt", std::ios::trunc);        //открыть файл 

    if (!file.is_open()) {                                      //если файл не открыт
        std::cout << "File messages.txt did't open!" << std::endl;
        return;
    }

    for (const auto& m : _messages) {
        file << m << std::endl;                                 //записать в файл
    }

    file.close();                                               //закрыть файл

    //установить права на файл
    std::filesystem::permissions("messages.txt", std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);
}

//добавить пользователя
void Chat::addUser(const std::string& name, const std::string& login, const std::string& pass) {
    _users.emplace_back(name, login, pass);
}

//добавить сообщения
void Chat::addMessage(const std::string& text, const std::string& sender, const std::string& receiver) {
    _messages.emplace_back(text, sender, receiver);
}

//показать пользователей
void Chat::showUsers() const {
    std::cout << "Users: " << std::endl;
    for (const auto& user : _users) {
        std::cout << user << std::endl;
    }
    std::cout << std::endl;
}

//показать сообщения
void Chat::showMessages() const {
    std::cout << "Messages: " << std::endl;
    for (const auto& m : _messages) {
        std::cout << m << std::endl;
    }
    std::cout << std::endl;
}

//наличие имени
bool Chat::havingName(const std::string& name) {
    for (const auto& user : _users) {
        if (name == user.getUserName())
            return true;
    }    
    return false;
}

//наличие логина
bool Chat::havingLogin(const std::string& login) {
    for (const auto& user : _users) {
        if (login == user.getUserLogin())
            return true;
    }
    return false;
}