#include <fstream>
#include <iostream>

#include "book.hpp"

int main() {

	Book myBooks[5] = {
		{1, "Across the River and into the Trees"},
		{2, "For Whom the Bell Tolls"},
		{3, "A Farewell to Arms"},
		{4, "The Sun Also Rises"},
		{5, "A Moveable Feast"},
	};

	// Отворете файла `my_books.bin` за писане в бинарен формат
	// std::ofstream fout = ...
	std::ofstream fout("my_books.bin", std::ios::in | std::ios::binary);

	for (size_t i = 0; i < 5; i++) {
		// Запишете `myBooks[i]` във файла
		// ...
		// fout.write((char*)&myBooks[i], sizeof(myBooks[i]));
		myBooks[i].save(fout);

	}

	fout.close();

	return 0;
}
