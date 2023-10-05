//John Macbean
//csc2710
//9-10-23
//home/students/jmacbean/csc2710/programs/pro1.cpp
//This lab will provide practice loading, passing, processing, and printing arrays.
//Assistance
//Compile: g++ main.cpp 
//Execute: ./a.out

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

struct heap
{
	int S[501];
	int heapsize;
};

void merge(int numbers[], int first, int middle, int last);
void mergeSort(int numbers[], int first, int last);
void quickSort(int [], int, int);
void partition(int [], int, int, int&);
void insertionSort(int n, int S[]);
void selectionSort(int x, int random[]);
void RandomArray(int random[], int size, int y);
void bubbleSort(int [], int);
void siftdown(heap&, int);
int root (heap&);
void removekeys(int, heap&, int[]);
void makeheap(int, heap&);
void heapsort(int, heap&);

int counter_ms = 0;
int counter_qs = 0;
int counter_is = 0;
int counter_ss = 0;
int counter_bs = 0;
int counter_hs = 0;

int main(){
	srand(time(nullptr));
	int x,y;
	cout << "Enter a number between 1-1000: ";
	cin >> x;
	int random[x], random2[x], random3[x], random4[x], random5[x], random6[x];
	RandomArray(random,x,y);
	for (int j = 0; j < x; j++){
		random2[j]=random[j];
		random3[j]=random[j];
		random4[j]=random[j];
		random5[j]=random[j];
		random6[j]=random[j];
	}
	
	//Original array
	cout << "Original array: ";
	for (int i = 0; i < x; i++) {
		cout << random[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	//Selection Sort
	
	clock_t start = clock();
	selectionSort(x, random);
	clock_t end = clock();
	double time = (double) (end-start) / CLOCKS_PER_SEC * 10.0;
	cout << "Selection Sort" << endl;
	cout << "Compares:" << counter_ss << endl;
	cout << "Time:" << time << endl;
	for (int i = 0; i < x; i++)
		{
			cout << random[i] << " ";
		}
	cout << endl<<endl;
	
	//Merge Sort
	clock_t start2 = clock();
	mergeSort(random2, 0,x-1);
	clock_t end2 = clock();
	double time2 = (double) (end2-start2) / CLOCKS_PER_SEC * 10.0;
	cout << "Merge Sort" << endl;
	cout << "Compares:" << counter_ms << endl;
	cout << "Time:" << time2 << endl;
	for (int i = 0; i < x; i++)
		{
			cout << random2[i] << " ";
		}
	cout << endl<<endl;
	
	//Insertion Sort
	clock_t start3 = clock();
	insertionSort(x-1, random3);
	clock_t end3 = clock();
	double time3 = (double) (end3-start3) / CLOCKS_PER_SEC * 10.0;
	cout << "Insertion Sort" << endl;
	cout << "Compares:" << counter_is << endl;
	cout << "Time:" << time3 << endl;
	for (int i = 0; i < x; i++)
		{
			cout << random3[i] << " ";
		}
	cout << endl<<endl;
	
	//Quick sort
	clock_t start4 = clock();
	quickSort(random4,0,x-1);
	clock_t end4 = clock();
	double time4 = (double) (end4-start4) / CLOCKS_PER_SEC * 10.0;
	cout << "Quick Sort" << endl;
	cout << "Compares:" << counter_qs << endl;
	cout << "Time:" << time4 << endl;
	for (int i = 0; i < x; i++)
		{
			cout << random4[i] << " ";
		}
	cout << endl<<endl;
	
	//Bubble sort
	clock_t start5 = clock();
	bubbleSort(random5,x);
	clock_t end5 = clock();
	double time5 = (double) (end5-start5) / CLOCKS_PER_SEC * 10.0;
	cout << "Bubble Sort" << endl;
	cout << "Compares:" << counter_bs << endl;
	cout << "Time:" << time5 << endl;
	for (int i = 0; i < x; i++)
		{
			cout << random5[i] << " ";
		}
	cout << endl<<endl;
	
	//Heap sort
	heap H;
	clock_t start6 = clock();
	int n1=sizeof(random6)/sizeof(random6[0]);
	for (int i = 0; i <= n1; i++)
		{
			H.S[i+1] = random6[i];
		}
	heapsort(n1,H);
	clock_t end6 = clock();
	double time6 = (double) (end6-start6) / CLOCKS_PER_SEC * 10.0;
	cout << "Heap Sort" << endl;
	cout << "Compares:" << counter_hs << endl;
	cout << "Time:" << time6 << endl;
	for (int i = 1; i <= n1; i++)
		{
			cout << H.S[i] << " ";
		}
	cout << endl<<endl;
	
	
	
	return 0;
	
}




void mergeSort(int numbers[], int first, int last) {
	if (first < last) {
		int middle=first+(last-first)/2;
		//Splits both halfs of the arrays until its just 1 number the merges them.
		mergeSort(numbers, first, middle);
		mergeSort(numbers, middle+1, last);
		merge(numbers, first, middle, last);
	}
}

//Merge two sorted subarrays into a single sorted subarray
void merge(int numbers[], int first, int middle, int last) {
	//Copies the data from the arrays into temporary arrays. 
	int l1 = middle-first+1;
	int l2 = last-middle;
	int leftArr[l1];
	int rightArr[l2];
	for (int i=0; i < l1; i++) {
		leftArr[i] = numbers[first+i];
	}
	for (int j=0; j < l2; j++) {
		rightArr[j] = numbers[middle+1+j];
	}
	
	//This part merges the two arrays together. It checks if the length of the array and sorts it until its 0
	int i=0; 
	int j=0; 
	int k=first; 
	while ((i < l1) && (j < l2)) {
		if (leftArr[i] <= rightArr[j]) {
			numbers[k]= leftArr[i];
			i++;
		} 
		else {
			numbers[k]=rightArr[j];
			j++;
		}
		k++;
		counter_ms++;
	}
	//Copy the remaining elements of left the right away in case the arrays are uneven
	while (i < l1) {
		numbers[k]=leftArr[i];
		i++;
		k++;
	}
	//Copy the remaining elements of right the right away in case the arrays are uneven
	while (j < l2) {
		numbers[k]=rightArr[j];
		j++;
		k++;
	}
}

void quickSort(int s[], int low, int high)
{	
	int pivotpoint;
	
	if(high > low)
		{
			partition(s, low, high, pivotpoint);
			quickSort(s, low, pivotpoint -1);
			quickSort(s, pivotpoint + 1, high);
		}
}

void partition(int s[], int low, int high, int& pivotpoint)
{
	int i, j;
	int temp;
	
	int pivotitem = s[low];
	j = low;
	for(i = low + 1; i <= high; i++)
		{
			counter_qs++;
			if (s[i] < pivotitem)
				{
					j++;
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
		}
	pivotpoint = j;
	temp = s[low];
	s[low] = s[pivotpoint];
	s[pivotpoint] = temp;
}

void insertionSort(int n, int S[])
{
	int i, j;
	int x;
	for (i=1; i<=n; i++)
		{
			x = S[i];
			j = i-1;
			while (j>=0 && S[j] > x)
				{
					counter_is++;
					S[j+1] = S[j];
					j--;
				}
			S[j+1] = x;
		}
}

void selectionSort(int x, int random[])
{
	int i;
	int j;
	int small;
	
	for (i = 0; i < x - 1; i++)
		{
			small = i;
			
			for (j = i + 1; j < x; j++)
				{
					counter_ss++;
					if (random[j] < random[small])
						{
							small = j;
						}
				}
			// Swap
			int temp = random[i];
			random[i] = random[small];
			random[small] = temp;
		}
}

void RandomArray(int random[], int size, int y)
{
	int z;
	cout<<"Please select an option (1. Random array 2. Almost sorted 3. Reverse sorted 4. Many duplicates)"<<endl;
	cin>>z;
	if (z==1){
		for (int x = 0; x < size; x++)
			{
				random[x] = rand() % 1000;
			}
	}
	if (z==2){
		cout << "How many numbers would you like sorted at the start: ";
		cin >> y;
		for (int z=0;z<y;z++){
			random[z]=z;
		}
		for (int x = y; x < size; x++)
			{
				random[x] = rand() % 1000+y;
			}
		
	}
	if (z==3){
		for (int i = 0; i < size; ++i) {
			random[i] = size - i - 1;
		}
	}
	if (z==4){
		for (int x = 0; x < size; x++)
			{
				random[x] = rand() % 100;
			}
	}
}

void bubbleSort(int arr[], int n){
	bool swapped;
	
	for (int i=0; i < n-1; i++){
		swapped=false;
		
		for (int j=0; j < n-i-1; j++){
			counter_bs++;
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}

void siftdown(heap& H, int i)
{
	int parent, largerchild;
	int siftkey;
	bool spotfound;
	
	siftkey = H.S[i];
	parent = i;
	spotfound = false;
	while(2*parent<=H.heapsize && ! spotfound)
		{
			counter_hs++;
			if(2*parent<=H.heapsize && H.S[2*parent] < H.S[2*parent + 1])
				{
					largerchild = 2* parent+1;
				}
			else
				largerchild = 2*parent;
			counter_hs++;
			if(siftkey < H.S[largerchild])
				{
					H.S[parent] = H.S[largerchild];
					parent = largerchild;
				}
			else
				spotfound = true;
		}
	H.S[parent] = siftkey;
}

int root (heap& H)
{
	int keyout;
	keyout = H.S[1];
	H.S[1] = H.S[H.heapsize];
	H.heapsize = H.heapsize-1;
	siftdown(H,1);
	return keyout;
}

void removekeys(int n, heap& H, int S[])
{
	int i;
	for (i=n; i>=1; i--)
		{
			S[i] = root(H);
		}
}

void makeheap(int n, heap& H)
{
	int i;
	H.heapsize = n;
	for(i= n/2; i>=1; i--)
		{
			siftdown (H,i);
		}
}


void heapsort(int n, heap& H)
{
	makeheap(n,H);
	removekeys(n,H,H.S);
}
