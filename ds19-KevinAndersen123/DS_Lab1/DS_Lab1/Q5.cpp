#include <iostream>
#include <vector>

class Gamer
{
public:
	Gamer() {}
	//destructor
	~Gamer()
	{
		std::cout << "Destructor called" << std::endl;
	}
	// Define a copy constructor
	Gamer(Gamer const& copy)
	{
		std::cout << "Copy constructor called" << std::endl;
	}
};

int maini()
{
	std::vector<Gamer> gamers(5);
	std::cout << "Size of vector: " << gamers.size() << std::endl;
	std::cout << "Capacity: " << gamers.capacity() << std::endl;
	gamers.clear();
	system("pause");
	return 0;
	//destructer of each element in vector is called
}

int mainii()
{
	std::vector<Gamer> gamers(5);
	std::cout << "Size of vector: " << gamers.size() << std::endl;
	std::cout << "Capacity: " << gamers.capacity() << std::endl;
	gamers.clear();
	std::cout << "Size of vector: " << gamers.size() << std::endl;
	std::cout << "Capacity: " << gamers.capacity() << std::endl;
	system("pause");
	//size is decreased to 0 as all elements deleted
	return 0;
}

int mainiii()
{
	Gamer* kevin = new Gamer();
	std::vector<Gamer*>   gamers = { kevin, new Gamer(), new Gamer() };

	std::cout << "Size of vector: " << gamers.size() << std::endl;
	std::cout << "Capacity: " << gamers.capacity() << std::endl;
	gamers.clear();
	std::cout << "Size of vector: " << gamers.size() << std::endl;
	std::cout << "Capacity: " << gamers.capacity() << std::endl;
	system("pause");
	//capacity stays same, no destructers called
	return 0;
}

	
