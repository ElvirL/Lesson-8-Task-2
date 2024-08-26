/*
������� 2. ���������� ��������� ��������� ���������� ��������
��� ����� �������
���������� ��������� ������� ��������� ������ ���������� ��������.
�� ���������� �������� ����� ������� � ���������� ���. ����� ��������� ������� �������� �������� �����. ������� � ��������� ������ 
�������� ����� ������ ���� ����������� � ������� �������. ��� ������ ��������� �������� � ������� +7 <10 ����>.

������������ ��������������� � ���������� � ������� ������:

� ������� add ��������� � �������� ����� ����� ����� �������� � ����������� ��� � ������ ��������. ��� ��� ��������� ������� �������� 
�� ������������ ����� ����������� ����.
� ������� call ����������� � ������������ ��� �������� ��� ����� ��������, �� ������� ��������� ���������. ��� �� ���� ������ 
������������ � ������� ������ � ������� ��������� CALL � ������� ��������, �� ������� �������������� �����.
� ������� sms. ����������� � ������������ ����� �������� (��� ��� ��������), �� ������� ��������� ������� ���������. 
���� ��������� ����� �������� ����� ����������� ����.
� ������� exit � ����� �� ���������.

������ � ������������
��� �� ���� ��� ������ �������� �� ���� ������ ����������� � ������� ���������� ������.
*/

#include <iostream>
#include <string>
#include <map>

class PhoneNumber{
    std::string number;

    public:
    bool number_is_correct(std::string n){
        if (n.size() != 12){
            std::cout << "�������� ������ ������" << std:: endl;
            return false;
        }
        if (n[0] != '+' || n[1] != '7'){
            std::cout << "�������� ������ ������" << std:: endl;
            return false;
        }
        for (int i=1; i<12; ++i){
            if (n[i] < '0' && n[i] > '9'){
                std::cout << "�������� ������ ������" << std:: endl;
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
        std::cout << "������� ��� ������ ��������: ";
        std::string name;
        std::cin >> name;

        std::cout << "������� ����� ��������: ";
        std::string number;
        std::cin >> number;

        PhoneNumber n;
        while (!n.number_is_correct(number)){
            std::cout << "������� ����� ��������: ";
            std::cin >> number;
        }
    
        n.set_number(number);
        PhoneBook[name] = n;
    }

    void call(){
        std::cout << "������� ��� �������� ��� ����� ��������: ";
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
                std::cout << "������� �� ������" << std::endl;
        }
    }

    void sms(){
        std::cout << "������� ��� �������� ��� ����� ��������: ";
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
            std::cout << "������� �� ������" << std::endl;
        }
        else {
            std::cout << "������� ���������:" << std::endl;
            std::string message;
            std::cin >> message;
            std::cout << "SMS on number: " << find_number << " is send" << std::endl;
        }
    }
};

int main(){
    setlocale(LC_ALL, "Russian");
    
    std::cout << "������� �������: ";
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
        std::cout << "������� �������: ";
        std::cin >> command;
    }
}