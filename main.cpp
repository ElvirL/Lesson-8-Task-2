/*
Задание 2. Реализация программы симуляции мобильного телефона
Что нужно сделать
Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную книгу. Телефон и отдельные записи 
адресной книги должны быть реализованы с помощью классов. Все номера телефонов задаются в формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

• Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта. Оба эти параметра команда получает 
от пользователя через стандартный ввод.
• Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. Сам по себе звонок 
симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
• Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение. 
Само сообщение также вводится через стандартный ввод.
• Команда exit — выход из программы.

Советы и рекомендации
Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса.
*/

#include <iostream>
#include <string>
#include <map>

class PhoneNumber{
    std::string number;

    public:
    bool number_is_correct(std::string n){
        if (n.size() != 12){
            std::cout << "Неверный формат номера" << std:: endl;
            return false;
        }
        if (n[0] != '+' || n[1] != '7'){
            std::cout << "Неверный формат номера" << std:: endl;
            return false;
        }
        for (int i=1; i<12; ++i){
            if (n[i] < '0' && n[i] > '9'){
                std::cout << "Неверный формат номера" << std:: endl;
                return false;
            }
        }
        return true;
    }

    void set_number(std::string n){
        number = n;
    }

    std::string get_number(){
        return number;
    }

};

class Phone{
    std::map<std::string,PhoneNumber> PhoneBook;

    public:
    void add(){
        std::cout << "Введите имя нового контакта: ";
        std::string name;
        std::cin >> name;

        std::cout << "Введите номер телефона: ";
        std::string number;
        std::cin >> number;

        PhoneNumber n;
        while (!n.number_is_correct(number)){
            std::cout << "Введите номер телефона: ";
            std::cin >> number;
        }
    
        n.set_number(number);
        PhoneBook[name] = n;
    }

    void call(){
        std::cout << "Введите имя контакта или номер телефона: ";
        std::string n;
        std:: cin >> n;
        bool is_find = false;
        for (std::map<std::string, PhoneNumber>::iterator it = PhoneBook.begin(); it!= PhoneBook.end(); ++it){
            if (it->first == n || it->second.get_number() == n){
                std::cout << "CALL " << it->second.get_number() << std::endl;
                is_find = true;
                break;
            }
        }
        if (!is_find){
                std::cout << "Контакт не найден" << std::endl;
        }
    }

    void sms(){
        std::cout << "Введите имя контакта или номер телефона: ";
        std::string n;
        std::cin >> n;
        bool is_find = false;
        std::string find_number;

        for (std::map<std::string, PhoneNumber>::iterator it = PhoneBook.begin(); it!= PhoneBook.end(); ++it){
            if (it->first == n || it->second.get_number() == n){
                find_number = it->second.get_number();
                is_find = true;
                break;
            }
        }
        if (!is_find){
            std::cout << "Контакт не найден" << std::endl;
        }
        else {
            std::cout << "Введите сообщение:" << std::endl;
            std::string message;
            std::cin >> message;
            std::cout << "SMS on number: " << find_number << " is send" << std::endl;
        }
    }
};

int main(){
    setlocale(LC_ALL, "Russian");
    
    std::cout << "Введите команду: ";
    std::string command;
    std::cin >> command;

    Phone phone;

    while (command != "exit"){
        if (command == "add"){
            phone.add();
        }
        else if (command == "call"){
            phone.call();
        }
        else if (command == "sms"){
            phone.sms();
        }
        std::cout << "Введите команду: ";
        std::cin >> command;
    }
}