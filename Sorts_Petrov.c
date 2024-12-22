//лабораторная 55689900
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void print_menu()
{
	printf("Welcome. (Use only integer numbers, array's max size is 50000, max number is 50000)\n");
	printf("-1. Exit\n");
	printf("0. Input array\n");
	printf("1. Random generate array\n");
	printf("11. Get original array\n");
	printf("2. Print array\n");
	printf("10. Print the original array\n");
	printf("3. Insertion sort\n");
	printf("4. Quicksort\n");
	printf("5. Counting sort\n");
	printf("6. Selection sort\n");
	printf("7. Bubble sort\n");
	printf("8. Binary search\n");
	printf("9. Line search\n");
	printf("12. Check if array is sorted\n");
}

void input_array(int a[], int n)
{
	// array is a; len is n;
	int current_element;
	int i;
	printf("Do not enter more than %d numbers\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &current_element);
		a[i] = current_element;
	}
	printf("Input done\n");
}

void random_generate_array(int a[], int n)
{
	int l, r, t, i;
	printf("Set the left border of the range:\n");
	scanf_s("%d", &l);
	printf("Set the right border of the range:\n");
	scanf_s("%d", &r);
	if (l == r)
	{
		printf("Incorret borders!\n");
		return;
	}
	if (l > r)
	{
		t = l;
		l = r;
		r = t;
	}
	for (i = 0; i < n; i++)
	{
		a[i] = l + rand() % (r - l);
	}
	printf("Random generation done\n");
}

void print_array(int a[], int n)
{
	// array is a; len is n;
	int i;
	printf("Your array: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void insertion_sort(int a[], int n)
{
	int i, j, current_element;
	int count_swap = 0;
	for (i = 1; i < n; i++)
	{
		current_element = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > current_element)
		{
			a[j + 1] = a[j];
			count_swap++;
			j--;
		}
		a[j + 1] = current_element; 
		if (a[j + 1] != current_element)
			count_swap++;
		// если вайл ни разу не запустится, то a[i - 1 + 1] , т. е.(a[i] = a[i])
	}
	printf("Swaps count is %d\n", count_swap);
	printf("Sorting done\n");
}

void selection_sort(int a[], int n)
{
	int i, j, t, minimum_index;
	int count_swap = 0;
	for (i = 0; i < n; i++)
	{
		minimum_index = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[minimum_index])
			{
				minimum_index = j;
			}
		}
		t = a[i];
		a[i] = a[minimum_index];
		a[minimum_index] = t;
		count_swap++;
	}
	printf("Swaps count is %d\n", count_swap);	
	printf("Sorting done\n");
}

void counting_sort(int a[], int n)
{
	//Создал функцию, которая ищет минимум в массиве
	int minimumo = find_minimum(a, n);
	if (minimumo < 0)
		minimumo *= -1;
	int* help = (int*)calloc(n, sizeof(int));
	int i, j;
	int index = 0;
	for (i = 0; i < minimumo * 2; i++)
	{
		help[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		help[a[i] + minimumo]++;
	}
	for (i = 0; i < minimumo * 2; i++)
	{
		for (j = 0; j < help[i]; j++)
		{
			a[index] = i - minimumo;
			index++;
		}
	}
	printf("Sorting done\n");
}

void bubble_sort(int a[], int n)
{
	int count_swap = 0;
	int x = 0;
	int l = 0;
	int r = n - 1;
	int i;
	int flag = 1;
	while ((l <= r) && (flag == 1))
	{
		flag = 0;
		//слева
		for (i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				x = a[i];
				a[i] = a[i + 1];
				a[i + 1] = x;
				count_swap++;
				flag = 1;
			}
		}
		--r;
		//справа
		for (i = r; i > l; i--)
		{
			if (a[i - 1] > a[i])
			{
				x = a[i];
				a[i] = a[i-1];
				a[i-1] = x;
				count_swap++;
				flag = 1;
			}
		}
		++l;
	}
	printf("Swaps count is %d\n", count_swap);
	printf("Sorting done\n");
}

int binary_search(int a[], int n, int finding)
{
	int count_compare = 0;
	int l, r, c;
	l = 0;
	r = n - 1;
	while (l <= r)
	{
		c = (l + r) / 2;
		if (a[c] == finding)
		{
			count_compare++;
			printf("Count compare is %d\n", count_compare);
			return c;
		}
		else if (a[c] > finding)
		{
			count_compare += 2;
			r = c - 1;
		}
		else
		{
			count_compare += 3;
			l = c + 1;
		}
	}
	printf("Count compare is %d\n", count_compare);
	return -1;
}

int line_search(int a[], int n, int finding)
{
	int count_compare = 0;
	int found = 0;
	int i;
	int index_result = -1;
	for (i = 0; i < n; i++)
	{
		count_compare++;
		if (a[i] == finding)
		{
			found = 1;
			index_result = i;
			break;
		}
	}
		if (found == 1)
		{
			printf("Count compare is %d\n", count_compare);
			return index_result;
		}
		else
			printf("Count compare is %d\n", count_compare);
			return -1;
}

void quicksort(int a[], int n)
{
	int t;
	int i = 0;
	int j = n - 1;
	int c = a[n / 2];
	do
	{
		while (a[i] < c)
		{
			i++;
		}
		while (a[j] > c)
		{
			j--;
		}
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		quicksort(a, j + 1);
	}
	if (i < n)
	{
		quicksort(&a[i], n - i);
	}
}

void copy(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

int is_array_check(int is_array)
{
	if (is_array == 0)
	{
		printf("You heven't entered array yet, please enter array with 0 or 1 navigation variables\n");
		return 0;
	}
	else
		return 1;
}

void is_sorted_(int a[], int n)
{
	int array_sorted_quicksort[50000];
	//проверяю по квиксорту потому что квиксорт сделан точно правильно
	copy(a, array_sorted_quicksort, n);
	quicksort(array_sorted_quicksort, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != array_sorted_quicksort[i])
		{
			printf("Array isnt sorted!\n");
			return;
		}
	}
	printf("Array is sorted\n");
}

int array_[50000]; // our array
int array_copy[50000]; // copy of our array;
int main()
{
	int search_result;
	int n; // array's len
	int finding; //element to find
	int c = 0; // navigation variable
	int is_sorted = 0;
	int is_array = 0;
	LARGE_INTEGER freq, start, finish;
	double timer;
	QueryPerformanceFrequency(&freq);
	srand(time(NULL));
	printf("//////////////////////////////////////////\n");
	print_menu();
	while (c != -1)
	{
		printf("Choose navigation variable\n");
		printf("//////////////////////////////////////////\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case -1:
			break;
		case 0:
			printf("Enter array's len:\n");
			scanf_s("%d", &n);
			if ((n == 0) || (n >= 50000))
			{
				printf("Inncorect length\n");
				is_array = 0;
				break;
			}
			printf("Start entering numbers\n");
			input_array(array_copy, n);
			is_sorted = 0;
			is_array = 1;
			copy(array_copy, array_, n);
			break;
		case 1:
			printf("Enter array's len:\n");
			scanf_s("%d", &n);
			if ((n == 0) || (n >= 50000))
			{
				printf("Inncorect length\n");
				is_array = 0;
				break;
			}
			random_generate_array(array_copy, n);
			is_sorted = 0;
			is_array = 1;
			copy(array_copy, array_, n);
			break;
		case 2:
			if (is_array_check(is_array) == 0)
				break;
			print_array(array_, n);
			break;
		case 3:
			if (is_array_check(is_array) == 0)
				break;
			QueryPerformanceCounter(&start);
			insertion_sort(array_, n);
			QueryPerformanceCounter(&finish);
			timer = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("Your rime: %0.7f\n", timer);
			is_sorted = 1;
			break;
		case 4:
			if (is_array_check(is_array) == 0)
				break;
			QueryPerformanceCounter(&start);
			quicksort(array_, n);
			QueryPerformanceCounter(&finish);
			timer = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("Your rime: %0.7f\n", timer);
			is_sorted = 1;
			printf("Sorting done\n");
			break;
		case 5:
			if (is_array_check(is_array) == 0)
				break;
			QueryPerformanceCounter(&start);
			counting_sort(array_, n);
			QueryPerformanceCounter(&finish);
			timer = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("Your rime: %0.7f\n", timer);
			is_sorted = 1;
			break;
		case 6:
			if (is_array_check(is_array) == 0)
				break;
			QueryPerformanceCounter(&start);
			selection_sort(array_, n);
			QueryPerformanceCounter(&finish);
			timer = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("Your rime: %0.7f\n", timer);
			is_sorted = 1;
			break;
		case 7:
			if (is_array_check(is_array) == 0)
				break;
			QueryPerformanceCounter(&start);
			bubble_sort(array_, n);
			QueryPerformanceCounter(&finish);
			timer = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			printf("Your rime: %0.7f\n", timer);
			is_sorted = 1;
			break;
		case 8:
			if (is_array_check(is_array) == 0)
				break;
			if (is_sorted == 0)
			{
				printf("Please, firstly sort array and than use binary search\n");
				break;
			}
			printf("Enter element, that you want to find\n");
			scanf_s("%d", &finding);
			search_result = binary_search(array_, n, finding);
			if (search_result == -1)
			{
				printf("No element in array\n");
			}
			else
				printf("Element in array, index is %d\n", search_result);
			break;
		case 9:
			if (is_array_check(is_array) == 0)
				break;
			printf("Enter element, that you want to find\n");
			scanf_s("%d", &finding);
			search_result = line_search(array_, n, finding);
			if (search_result == -1)
			{
				printf("No element in array\n");
			}
			else
				printf("Element in array, index is %d\n", search_result);
			break;
		case 10: //можно вывезти изначальный массив
			if (is_array_check(is_array) == 0)
				break;
			print_array(array_copy, n);
			break;
		case 11:
			is_sorted = 0;
			is_array = 1;
			copy(array_copy, array_, n);
			printf("Now you got original array\n");
			break;
		case 12:
			if (is_array_check(is_array) == 0)
				break;
			is_sorted_(array_, n);
			break;
		default:
			printf("You choose wrong navigation variable, please watch menu\n");
			break;
		}
	}
	return 0;
}
