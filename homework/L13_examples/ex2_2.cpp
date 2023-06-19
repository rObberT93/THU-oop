#include <algorithm>
#include <iostream>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}
int main(){
	int arr[5] = { 5, 2, 3, 1, 7 };
	std::sort(arr, arr + 5, comp);
	for (int x : arr) {
		cout << x << " ";
	}  // 1 2 3 5 7
	return 0;
}
