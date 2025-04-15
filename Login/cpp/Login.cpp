#include "../h/Login.h"
#include <fstream>
#include <sstream>
#include "../../System.h"
#include "../../Users/h/UsersFactory.h"
void Login::registerUser(const MyString& firstName, const MyString& secondName, const MyString& password, const MyString& possition, unsigned id, unsigned age)
{
	currentUser = createUser(firstName, secondName, possition, id, age, password);
	users.pushBack(currentUser);

	std::ofstream ofs("userDataBase.txt", std::ios::app);
	if (!ofs.is_open()) {
		std::cout << "Invalid file name" << std::endl;
		return;
	}

	ofs << firstName.getData() << " "
	<< secondName.getData() << " "
	<< password.getData() << " "
	<< possition.getData() << " "
	<< id << " "
	<< age << std::endl;

	ofs.close();
}

void Login::login(unsigned id, const MyString& password)
{
	std::ifstream ifs("userDataBase.txt");
	if (!ifs.is_open()) {
		std::cout << "Invalid file name" << std::endl;
		return;
	}

	bool found = false;

	while (!ifs.eof()) {
		MyString firstName, secondName, filePassword, position;
		unsigned fileId, age;

		ifs >> firstName >> secondName >> filePassword >> position >> fileId >> age;

		if (ifs.fail()) break;

		if (fileId == id && filePassword == password) {
			currentUser = createUser(firstName, secondName, position, fileId, age, filePassword);
			found = true;
			break;
		}
	}

	if (!found) {
		throw std::runtime_error("User not found or incorrect password.");
	}

	System& system = System::getInstance();
	system.setCurrentUser(currentUser);
}


void Login::signIn(unsigned id, const MyString& password)
{
	try {
		login(id, password);
		std::cout << "Successfully logged in!\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Login::signupUser(const MyString& firstName, const MyString& secondName, const MyString& password, const MyString& possition,  unsigned id, unsigned age)
{
	try {
		login(id, password);
	}
	catch (...) {
		registerUser(firstName, secondName, password, possition, id, age);
		System& inst = System::getInstance();
		inst.addUser(std::move(currentUser));
	}
}

User* Login::getUser()
{
	return currentUser;
}

Vector<Polymorphic_Ptr<User>> Login::getUsers()
{
	return users;
}
