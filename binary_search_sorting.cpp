#include <iostream.h>


int binarySearch(int arr[], int N, int ele)
{
	int low = 0;
	int high = N - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == ele)
			return mid;
		if (arr[mid] > ele)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}



void main()
{
	int *array, N, ele;
	cout << "\nEnter the size of array: ";
	cin >> N;

	array = new int[N];
	cout << "Enter the elements of sorted array: ";
	for (int i = 0; i < N; i++)
		cin >> array[i];

	cout << "Enter an element to be searched: ";
	cin >> ele;

	int res = binarySearch(array, N, ele);
	(res == -1) ? cout << "\nResult: -1 i.e. Element not found!" : cout << "\nElement found at" << res << "!";

	cout << endl;
}	