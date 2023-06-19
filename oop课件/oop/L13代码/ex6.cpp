#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int arr[5] = {2, 3, 4, 1, 5};
	sort(arr, arr + 5, comp);
	sort(arr, arr + 5, greater<int>());
	return 0;
}

