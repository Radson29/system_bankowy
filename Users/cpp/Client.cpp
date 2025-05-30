#include "../h/Client.h"

Client::Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password) :
               User(firstName, secondName, IDNumber, age, password){}


void Client::messages() const
{
    for (int i = 0; i < container_messages.getSize(); i++) { 
        std::cout << i + 1 << container_messages[i].getMessage() << std::endl;
    }
}

void Client::addMessage(Message&& message)
{
    container_messages.pushBack(message);
}

User* Client::clone() const
{
    return new Client(*this);
}


