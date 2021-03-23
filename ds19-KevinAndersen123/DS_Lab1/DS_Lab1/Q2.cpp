#include <iostream>
#include <vector>
#include <string>
#include <array>

template<typename T>
std::pair<T, T>minMax(std::vector<T>t_vector)
{

	std::pair<T, T> elements;
	elements.first = t_vector[0];
	elements.second = t_vector[0];

	for (T element : t_vector)
	{
		if (elements.first < element)
		{
			elements.first = element;
		}
		if (elements.second > element)
		{
			elements.second = element;
		}
	}
	return elements;
}

int main2()
{
	std::vector<float> m_elements1 = { 3,9,7,8,1};
	std::vector<std::string> m_elements2 = { "Joe","Kevin","Bob", "Sebastian" };

	std::cout << "Numeric = Min value: " + std::to_string(minMax(m_elements1).second) + " Max Value: " + std::to_string(minMax(m_elements1).first) << std::endl;
	std::cout << "String = Min value: " + minMax(m_elements2).second + " Max Value: " + minMax(m_elements2).first << std::endl;
	system("pause");
	return 0;
}