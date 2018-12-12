#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> numbers;

numbers.push_back(5);
numbers.push_back(2);
numbers.push_back(27);

sort(numbers.begin(), numbers.end());

 numbers.erase(numbers.begin());
 // numbers.insert(number.begin(),"5");

 for (int i = 0; i < numbers.size(); i++)
{
	cout << "Number in slot i: " << i << " is " << numbers[i] << endl;
}

	return 0;
}
