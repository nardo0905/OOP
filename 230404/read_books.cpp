#include <fstream>

#include "book.hpp"

int main() {
	// Отворете файла `my_books.bin` за четене в бинарен формат
	// std::ifstream fin = ...
	std::ifstream fin("my_books.bin", std::ios::in | std::ios::binary);

	// Проверяваме дали не сме стигнали до края.
	while(fin.peek() != EOF) {
		// Прочетете обекта от `fin` и го отпечатайте на `stdout`.
		// ...
		Book book{fin};
		// fin.read((char*)&book, sizeof(book));
		std::cout << book.serialNumber << " " << book.title << std::endl;

	}

	return 0;
}
