#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
	std::string city;
	std::string street;
	int house;
	int apt;
public:
	Address() {
		city = "default";
		street = "default";
		house = 0;
		apt = 0;
	}

	void set_city(std::string city) {
		this->city = city;
	}

	void set_street(std::string street) {
		this->street = street;
	}

	void set_house(int house) {
		this->house = house;
	}

	void set_apt(int apt) {
		this->apt = apt;
	}

	std::string get_city() {
		return city;
	}

	std::string print() {
		return (city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apt));
	}
};

Address* createArray(const int elements)
{
	Address* Arr = new Address[elements];

	return Arr;
}

//Функция удаления динамического массива
void deleteArr(Address* arr, const int elements)
{
	delete[] arr;
	return;
}

void sort(Address* addresses, int size) {
	Address buff;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (addresses[i].get_city() < addresses[j].get_city()) {
				buff = addresses[i];
				addresses[i] = addresses[j];
				addresses[j] = buff;
			}
		}
	}
	return;
}

int main() {
	int size;
	Address* address;

	std::string path_in = "in.txt";
	std::string path_out = "out.txt";

	std::ifstream file_in(path_in);
	std::ofstream file_out(path_out);

	if (file_in.is_open()) {
		file_in >> size;
		address = createArray(size);

		int i = 0;
		while (i < size) {

			std::string city;
			std::string street;
			int house;
			int apt;

			file_in >> city;
			file_in >> street;
			file_in >> house;
			file_in >> apt;

			address[i].set_city(city);
			address[i].set_street(street);
			address[i].set_house(house);
			address[i].set_apt(apt);

			i++;
		}

		sort(address, size);

		file_out << size << std::endl;

		for (int i = 0; i < size; i++) {
			file_out << address[i].print() << std::endl;
		}

		deleteArr(address, size);
	}
	else {
		std::cout << "File not find" << std::endl;
	}

	file_in.close();
	file_out.close();

}