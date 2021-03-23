#include <algorithm>
#include <iostream>
#include <vector>

class Record
{
public: 
	Record(int t_count, int t_price);
	int count = 0;
	int price = 0;
	
private:

};

class compareRecord
{
public: 
	compareRecord(bool t_byPrice) { //constructor function 
		byPrice = t_byPrice;
	}

	bool operator()(Record t_count, Record t_countTwo) //functor
	{
		if (byPrice == true)
		{
			return (t_count.price < t_countTwo.price);
		}
		else {
			return (t_count.count < t_countTwo.count);
		}
	}
private:
	bool byPrice = true;
};

Record::Record(int t_count, int t_price)
{
	count = t_count;
	price = t_price;
}

template<typename T>
void sort(std::vector<T>& records,bool t_bool)
{
	std::sort(records.begin(), records.end(), compareRecord(t_bool)); //sorts the record from smallest to biggest
}
int main3()
{
	std::vector<Record> records = { Record(5,20),Record(2,7),Record(9,5) };
	sort(records,true); //sorts for price
	for (auto i : records)
	{
			std::cout << "Price = " << i.price << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	sort(records, false); //sorts for count
	for (auto i : records)
	{
		std::cout << "Count = " << i.count << std::endl;
	}
	system("Pause");
	return 0;
}