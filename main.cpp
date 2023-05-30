#include <iostream>
#include "Chat.h"

int main() {

    Chat um;

    um.loadUsers();                                         //загрузить пользователей из файла
    um.loadMessages();                                      //загрузить сообщения из файла

    std::cout << std::endl;

    if (um.countUsers() == 0) {                             //если пользователей нет, то добавить их
        um.addUser("user1", "log1", "pass1");
        um.addUser("user2", "log2", "pass2");
        um.addUser("user3", "log3", "pass3");
    }

    if (um.countMessages() == 0) {                          //если сообщений нет, то добавить сообщения
        um.addMessage("Hi", "user1", "user2");
        um.addMessage("How are you?", "user2", "user1");
        um.addMessage("Hello.", "user3", "all");
    }

    um.showUsers();                                         //вывод информации о пользователях
    um.showMessages();                                      //вывод сообщений

    bool exit = true;
    while (exit) {
        std::cout << "\nAdd user (1 - yes, 0 - no): ";      //добавить пользователей в ручном режиме
        char choice;
        std::cin >> choice;
        std::string name;
        std::string login;
        std::string pass;

        switch (choice) {                               
        case '1':
            std::cout << "Name: ";           
            std::cin >> name;
            std::cout << "Login: ";
            std::cin >> login;
            std::cout << "Password: ";
            std::cin >> pass;

            if (um.havingName(name)) {                      //если введенное имя уже есть
                std::cout << "Error. Name already exists." << std::endl;
            }
            else if (um.havingLogin(login)) {               //если введенный логин уже есть
                std::cout << "Error. Login already exists." << std::endl;
            }
            else {
                um.addUser(name, login, pass);              //добавить пользователя
            }
            break; 

        case '0':
            break;

        default:
            std::cout << "Only 0 or 1." << std::endl;
            break;
        }

        std::cout << "To write a message? (1 - yes, 0 - no): "; //добавить сообщения в ручном режиме
        char choice2;
        std::cin >> choice2;
        std::string sender;
        std::string receiver;
        std::string text;

        switch (choice2) {
        case '1':
            std::cout << "Sender: ";
            std::cin >> sender;
            std::cout << "Receiver: ";
            std::cin >> receiver;
            std::cout << "Text: ";
            std::cin.ignore();
            getline(std::cin, text);

            //если введенные имена отправителя и получателя есть, то добавить сообщение
            if (um.havingName(sender) && (um.havingName(receiver) || receiver == "all")) {
                um.addMessage(text, sender, receiver);                
            }
            else {
                std::cout << "Error. No sender/receiver." << std::endl;
            }
            break;

        case '0':
            break;

        default:
            std::cout << "Only 0 or 1." << std::endl;
            break;
        }
        std::cout << "Any letter/number - repeat, 0 - exit: ";  
        char choice3;
        std::cin >> choice3;
        if (choice3 == '0')
            exit = false;
    }
    
    um.showUsers();                                         //вывод информации о пользователях
    um.showMessages();                                      //вывод сообщений

    um.saveUsers();                                         //запись пользователей в файл
    um.saveMessages();                                      //запись сообщений в файл

    return 0;
}