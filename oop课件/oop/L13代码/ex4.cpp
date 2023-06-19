#include <algorithm>
#include <functional>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

template<class Iterator, class Compare>
void mysort(Iterator first, Iterator last, Compare comp)
{
	for (auto i = first; i != last; i++)
		for (auto j = i; j != last; j++)
			if (!comp(*i, *j)) swap(*i, *j);
}
int main()
{
	int arr[5] = { 5, 2, 3, 1, 7 };
	mysort(arr, arr + 5, comp);
	mysort(arr, arr + 5, greater<int>());
	return 0;
}
