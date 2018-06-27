#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void fill_vector(vector <int> &array, size_t numb)
{
	size_t i = 0;
	while (i < numb)
	{
		array.push_back(1 + rand() % 9);
		i++;
	}
}

void show_vector(vector <int> &array)
{
	cout << "vector:";
	for (auto it = array.begin(); it != array.end(); ++it)
		cout << *it << ends;
	cout << endl;
}

void clear_vector(vector <int> &array, size_t numb)
{
	array.erase(array.begin(), array.begin() + numb);
}

void fill_map(map <char, int> &array, size_t numb)
{
	size_t i = 0;
	char c = 'a';
	while (i < numb)
	{
		array.insert(pair<char, int>(c, 1 + rand() % 9));
		++c;
		i++;
	}
}

void clear_map(map <char, int> &array, size_t numb)
{
	for (int i = 0; i < numb; ++i)
		array.erase(array.begin());
}

void show_map(map <char, int> &array)
{
	cout << "map:";
	for (auto it = array.begin(); it != array.end(); ++it)
	{
		cout << it->second << ends;
	}
	cout << endl;
}

void compare_containers(vector <int> &vec, map <char, int> &map_array)
{
	bool check;
	auto it_vec = vec.begin();
	auto it_map = map_array.begin();
	for (; it_map != map_array.end(); ++it_map)
		if (!(find(vec.begin(), vec.end(), it_map->second) != vec.end()))
			map_array.erase(it_map);
	 it_vec = vec.begin();
	 it_map = map_array.begin();
	for (; it_vec != vec.end(); ++it_vec)
	{
		check = false;
		for (; it_map != map_array.end(); ++it_map)
			if (*it_vec == it_map->second)
				check = true;
		if (!check)
			vec.erase(it_vec);
	}
	cout << endl;
}

int main()
{
	size_t numb;
	cout << "Enter number of elements" << endl;
	cin >> numb;
	vector <int> vec_random_numbers;
	map <char, int> map_random_numbers;
	srand(time(nullptr));
	fill_vector(vec_random_numbers, numb);
	fill_map(map_random_numbers, numb);
	int erase = 1 + rand() % 15;
	cout << "Numbers of deleted elements "<<erase << endl << endl;

	if (erase <= numb)
	{
		clear_vector(vec_random_numbers, erase);
		clear_map(map_random_numbers, erase);
		show_vector(vec_random_numbers);
		show_map(map_random_numbers);
		compare_containers(vec_random_numbers, map_random_numbers);
		show_vector(vec_random_numbers);
		show_map(map_random_numbers);
	}
	else
		cout << "smth went wrong" << endl;
	system("pause");
	return 0;
}