Программа, которая может считывать из файлов при своей загрузке и записывать в файлы состояния объектов классов User и Message (для каждого класса свой файл):

class User {
    string _name;
    string _login;
    string _pass;
};
class Message {
    string _text;
    string _sender;
    string _receiver;
};
Файлы недоступны для других пользователей, то есть прочитать или записать информацию в файлы может только пользователь, который запускает программу. 
