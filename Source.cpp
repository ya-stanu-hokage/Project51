#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <typeinfo>

bool IsPrime(const int n)
{
	for (int i = 2, end = sqrt(n); i <= end; i++)
		if (n % i == 0)
			return false;
	return n > 1;
}


int main()
{
	//1 /////////////////////////////
	std::default_random_engine dre(std::chrono::system_clock().now().time_since_epoch().count());
	std::uniform_int_distribution<> uid(1, 10);
	std::vector<int> vector_1;
	for (auto i = 0U; i < 10; i++)
	{
		vector_1.push_back(uid(dre));
	}

	//2  ////////////////////////////////
	std::copy(
		std::istream_iterator < int >(std::cin),
		std::istream_iterator < int >(),
		std::back_inserter(vector_1));

	//3 /////////////////////////////////
	std::shuffle(std::begin(vector_1), std::end(vector_1), dre);

	//4 ////////////////////////////////
	std::sort(std::begin(vector_1), std::end(vector_1));
	vector_1.erase(std::unique(std::begin(vector_1), std::end(vector_1)), std::end(vector_1));

	//5  //////////////////////////////////
	std::cout << "Uneven: " << std::count_if(std::begin(vector_1), std::end(vector_1), [](auto a)
		{
			return a % 2;
		}) << std::endl;

	//6   //////////////////////////////
	auto pair = std::minmax_element(std::begin(vector_1), std::end(vector_1));
	std::cout << "Min: " << *pair.first << " Max: " << *pair.second << std::endl;

	//7   //////////////////////////////
	auto prime = std::find_if(std::begin(vector_1), std::end(vector_1), [](auto a)
		{
			for (int i = 2, end = sqrt(a); i <= end; i++)
				if (a % i == 0)
					return false;
			return a > 1;
		});
	if (prime != std::end(vector_1))
	{
		std::cout << "Prime is: " << *prime << std::endl;
	}
	else
		std::cout << "Prime not found" << std::endl;

	//8 ///////////////////////////////
	std::transform(std::begin(vector_1), std::end(vector_1), std::begin(vector_1), [](auto x)
		{
			return x * x;
		});


	//9 /////////////////////////
	std::vector<int> vector_2(std::size(vector_1));
	std::generate(std::begin(vector_2), std::end(vector_2), [&]() {return uid(dre); });

	//10///////////////////////
	int sum = 0;
	std::for_each(std::begin(vector_2), std::end(vector_2), [&sum](auto a)
		{
			sum += a;
		});
	std::cout << "Sum Vector_2: " << sum << std::endl;

	//11 /////////////////////////
	if (std::size(vector_1) >= 2)
		std::fill_n(std::begin(vector_2), 2, 1);

	//12 /////////////////////////
	std::vector<int> vector_3(std::size(vector_1));
	std::transform(std::begin(vector_1), std::end(vector_1), std::begin(vector_2), std::begin(vector_3), [](auto a, auto b)
		{
			return a - b;
		});

	//13  ///////////////////////
	std::replace_if(std::begin(vector_3), std::end(vector_3), [](auto x)
		{
			return x < 0;
		}, 0);

	//14  /////////////////////////	
	vector_3.erase(std::remove(std::begin(vector_3), std::end(vector_3), 0), std::end(vector_3));

	//15 ////////////////////////
	std::reverse(std::begin(vector_3), std::end(vector_3));

	//16  /////////////////////
	std::sort(std::begin(vector_3), std::end(vector_3));
	if (std::size(vector_3) >= 3)
	{
		std::cout << "Max three elements: ";
		for (auto a = (std::end(vector_3)) - 3; a < std::end(vector_3); a++)
		{
			std::cout << *a << ", ";
		}
		std::cout << std::endl;
	}

	//17  ////////////////////////
	std::sort(std::begin(vector_1), std::end(vector_1));
	std::sort(std::begin(vector_2), std::end(vector_2));

	//18  ////////////////////////
	std::vector<int> vector_4(std::size(vector_1) + std::size(vector_2));
	std::merge(std::begin(vector_1), std::end(vector_1), std::begin(vector_2), std::end(vector_2), std::begin(vector_4));

	//19  ///////////////////////
	auto a = std::make_pair(std::lower_bound(std::begin(vector_4), std::end(vector_4), 1),
		std::upper_bound(std::begin(vector_4), std::end(vector_4), 1));

	//20  //////////////////////
	std::copy(vector_1.begin(), vector_1.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;
	std::copy(vector_2.begin(), vector_2.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;
	std::copy(vector_3.begin(), vector_3.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;
	std::copy(vector_4.begin(), vector_4.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	return 0;
}