#include <iostream>
#include "Commands/CommandFactory.h"
#include "System.h"

int main()
{
	System& banking_system = System::getInstance();
	MyString command;

	std::cout << "Welcome to the banking system!\n";
	while (true) {
		std::cout << "> ";
		std::cin >> command;

		if (command == "exit") {
			break;
		}

		try {
			commandFactory(command);
			if (banking_system.someoneIsLogedIn()) {
				userFactory(banking_system.getCurrentUser())->execute();
			}
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
