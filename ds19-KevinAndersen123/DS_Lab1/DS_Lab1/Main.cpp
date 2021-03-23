#include <iostream>
#include <array>

template <typename T, unsigned SIZE>
T scalarProduct(std::array<T, SIZE> const & t_v1, std::array<T, SIZE> const& t_v2)
{
	T product = 0;

	// Loop for calculate dot product 
	for (int i = 0; i < SIZE; i++)

		product = product + t_v1[i] * t_v2[i];
	return product;
}

int main() 
{
	std::array<float,3U> v1 = { 4.0f ,1.0f, 9.0f}; //vector1
	std::array<float, 3U> v2 = { 1.0f, 6.0f, 8.0f }; //vector2

	int dotProd = scalarProduct(v1, v2);
	std::cout << dotProd << std::endl;
	system("pause");
	return 0;
}
