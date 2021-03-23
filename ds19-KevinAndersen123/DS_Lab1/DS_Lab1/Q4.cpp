#include <iostream>
#include <vector>
#include <algorithm>

class Remove
{
public:
	Remove(int t_targetNum) : m_targetNum(t_targetNum) {}
		bool operator() (int t_num)
	{
			std::cout << "Number removed\n";
		return t_num == m_targetNum;
	}
private:
	int m_targetNum;
};


int main4()
{

	std::vector<int> numbers(100);
	int targetNum = 0;
	bool foundNum = true;

	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = i%10;
		
	}

	std::cout << "Enter targer number between 1-9" << std::endl;
	std::cin >> targetNum;
	Remove remove1(targetNum);
	//part 1
	/*while (foundNum)
	{
		std::vector<int>::iterator position = std::find(numbers.begin(), numbers.end(), targetNum);
		if (position != numbers.end())
		{
			numbers.erase(position);
		}
		else
		{
			foundNum = false;
		}
		
	}*/

	//part 2
	/*numbers.erase(std::remove_if(numbers.begin(), numbers.end(), remove1), numbers.end());*/


	//part 3 lamdba 
	numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [targetNum](int i)
		{
			return i == targetNum;
		}), numbers.end());

	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << std::endl;
	}



	system("Pause");
	return 0;
}