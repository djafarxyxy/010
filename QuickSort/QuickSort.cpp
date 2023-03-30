#include <iostream>
using namespace std;

// array of intergers to hold values
int arr[20];
int cmp_count = 0;																	// number of comparasion
int mov_count = 0;																	// number of data movement
int n;

void input() {
	while (true)
	{
		cout << "Masukkan Panjang Element Array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum Panjang Array adalah 20" << endl;
	}
	cout << "\n--------------------" << endl;
	cout << "\nEnter element array" << endl;
	cout << "\n--------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (1 + 1) << ">";
		cin >> arr[i];
	}
}
//Swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}


void q_short(int low, int high)
{
	int pivot, i, j;																// Langkah 1
	if (low > high)
		return;

	// partition the list into two part
	// one containing element less that or equal to pivot
	// outher containing elements greather than pivot

	pivot = arr[low];																// Langkah 2

	i = low + 1;																	// Langkah 3
	j = high;																		// Langkag 4


	while (i <= j)																	// LAngkah 10
	{
		// seacrh for an element greather than pivot 
		while ((arr[i] <= pivot) && (i <= high))									// Langkah 5
		{
			i++;																	// Langkah 6
			cmp_count++;
		}
		cmp_count++;
		// seacrh for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))										// Langkah 7
		{
			j--;																	// Langkah 8
			cmp_count++;
		}
		cmp_count++;
	}
	// Langkah 9
	if (i < j)	// if the greather element is on the left of the elemnt 
	{
		// swap the element at index i whith the element at index j
		swap(i, j);
		mov_count++;
	}
	// j now containt the index of the last element in the sorted list 
	if (low < j)																	// Langkah 11
	{
		// move the pivot to its correc position in the list
		swap(low, j);
		mov_count++;
	}
	// sort the list on the left pivot using quick sort
	q_short(low, j - i);															// Langkah 12


	// sort the list on the right of pivot using quick sort
	q_short(j + 1, high);															// Langkah 13


}


void display() {
	cout << "\n-------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}


int main()
{

	input();
	// sort the array using quick sort
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}