#ifndef _OOP_BOOK_HPP_
#define _OOP_BOOK_HPP_

#include <iostream>
#include <cstring>


struct Book {

	int serialNumber;
	char *title;

	Book(const int serialNumber = 0, const char *title = ""): serialNumber{serialNumber} {

		const size_t len = strlen(title);
		this->title = new char[len + 1];
		strcpy(this->title, title);

	}

	// Конструктор, който прочита (десериализира) книга от входен поток
	Book(std::istream& in) {

		in.read((char*)&serialNumber, sizeof(int));
		size_t size;
		in.read((char*)&size, sizeof(size));
		title = new char[size + 1];
		in.read(title, size);
		title[size] = '\0';

	}

	~Book() {

		delete[] title;

	}

	Book(const Book& other) {

		this->serialNumber = other.serialNumber;
		this->title = new char[strlen(other.title) + 1];
		strcpy(this->title, other.title);

	}

	Book& operator=(const Book& other) {

		if (this != &other) {

			delete[] title;
			this->serialNumber = other.serialNumber;
			this->title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);
		
		}

		return *this;

	}

	// Метод, който записва (сериализира) книга на изходен поток
	void save(std::ostream& out) const {

		out.write((char*)&serialNumber, sizeof(serialNumber));
		const size_t size = strlen(title);
		out.write((char*)&size, sizeof(size));
		out.write(title, size);

	}

};

#endif /* _OOP_BOOK_HPP_ */
