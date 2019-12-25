/*
 Authors: Samantha Casler & Philip Cesani
 
 Program will create a randomly generated array of a number of elements
 that the user enters and display the first 20 values of that array.
 Then the program will use recursion and sequentially search the array for some
 value. The program will then use selection, insertion and 3 pivot values for quick
 sort and compare the time it takes for each as well as how many comparisons were
 done to get to that value.

 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void copyArray (char [], char [], int);
void swap(char&, char&);
void printIntro ();// function to print the intro to the program
void displayElems (char [], int);
void sequentialSearch(char[], int, int, char, int&);
void selectionSort(char [], int, int&);
void insertionSort(char [], int, int&);
void quickSortMidd(char [], int, int, int&);
void quickSortFirst(char [], int, int, int&);
void quickSortEnd(char [], int, int, int&);
int partitionEnd (char [], int, int);
int partitionFirst(char [],int,int);

int main ()
{
    srand(time(0));
    int n;// an integer to hold the size of the array given by the user

    printIntro();// function to print the intro to the program
    cout << "Enter the size of the array : ";
    cin >> n;

    if (n < 0 || cin.fail()) // verify that the size is valid
    {
        cout << " *** Error - Invalid input - Size must be > 0 ***\n\n";

        cout << "Benchmark Algorithm Implemented by : Samantha, Casler and Philip, Cesani\n";
        cout << "24 / 4 / 2019\n";
        return 0;
    }

    char charArray [n]; // creating a character array of the users given size
    char charArrayCopy[n]; // creating a  second character array of the users given size

    for (int i = 0; i < n; i++)
    {
        charArray [i] = (rand ()%126) + 33; // populating the character array with random characters between 33 and 126
    }

    cout << "\nArray elements are : ";
    displayElems(charArray, n);
    copyArray (charArray, charArrayCopy, n);

    int count = 0; //Counts number of swaps, calls, comparisons, etc.
    clock_t startSearch, endSearch, startSelection, endSelection,
    startInsertion, endInsertion, startMidd, endMidd,
    startFirst, endFirst, startLast, endLast; // Hold the time it takes a function to start
    float endSearch2, endSelection2, endInsertion2, endMidd2,
    endFirst2, endLast2; // Hold the time it takes a function to stop


    cout << endl << endl;

    //Sequential Search
    cout << "Sequential Search\n\n";
    cout << "Searching for 80\n\n";
    startSearch = clock();
    sequentialSearch(charArray, 0, n-1, 80, count);
    endSearch = clock();
    endSearch2 = float (endSearch)/CLOCKS_PER_SEC;
    cout << "Start Time  : " << startSearch << endl;
    cout << "End Time  : " << endSearch << endl;
    cout << "Actual CPU Clock time : " << endSearch2 << " seconds";
    cout << "\nTotal Number of Comparisons : " << count << endl;
    cout << "Array elements : ";
    displayElems(charArray, n);
    count = 0;

    //Selection Sort
    cout << endl << endl;
    cout << "Selection Sort : \n\n";
    startSelection = clock();
    selectionSort(charArray, n, count);
    endSelection = clock();
    endSelection2 = float (endSelection)/CLOCKS_PER_SEC;
    cout << "Start Time  : " << startSelection << endl;
    cout << "End Time  : " << endSelection << endl;
    cout << "Actual CPU Clock time : " << endSelection2 << " seconds";
    cout << "\nTotal Number of Swaps : " << count << endl;
    cout << "Sorted elements : ";
    displayElems(charArray, n);
    copyArray (charArrayCopy, charArray, n);
    count = 0;

    //Insertion Sort
    cout << endl << endl;
    cout << "Insertion Sort : \n\n";
    startInsertion = clock();
    insertionSort(charArray, n, count);
    endInsertion = clock();
    endInsertion2 = float (endInsertion)/CLOCKS_PER_SEC;
    cout << "Start Time  : " << startInsertion << endl;
    cout << "End Time  : " << endInsertion << endl;
    cout << "Actual CPU Clock time : " << endInsertion2 << " seconds";
    cout << "\nTotal Number of Comparisons : " << count << endl;
    cout << "Sorted elements : ";
    displayElems(charArray, n);
    copyArray (charArrayCopy, charArray, n);
    count = 0;

    //Quick Sort - Middle
    cout << endl << endl;
    cout << "Quick Sort - Next to the middle element as pivot: \n\n";
    startMidd = clock();
    quickSortMidd(charArray, 0, n-1, count);
    endMidd = clock();
    endMidd2 = float (endMidd)/CLOCKS_PER_SEC;
    cout << "Start Time  : " << startMidd << endl;
    cout << "End Time  : " << endMidd << endl;
    cout << "Actual CPU Clock time : " << endMidd2 << " seconds" <<  endl;
    cout << "Total Number of Recursive Calls : " << count << endl;
    cout << "Sorted Elements: " ;
    displayElems(charArray, n);
    copyArray (charArrayCopy, charArray, n);
    count = 0;

    //Quick Sort - First
    cout << endl << endl;
    cout << "Quick Sort - First element as pivot: \n\n";
    startFirst = clock();
    quickSortFirst(charArray, 0, n-1, count);
    endFirst = clock();
    endFirst2 = float (endFirst)/CLOCKS_PER_SEC;
    cout << "Start Time  : " << startFirst << endl;
    cout << "End Time  : " << endFirst << endl;
    cout << "Actual CPU Clock time : " << endFirst2 << " seconds" << endl;
    cout << "Total Number of Recursive Calls : " << count << endl;
    cout << "Sorted Elements: " ;
    displayElems(charArray, n);
    copyArray (charArrayCopy, charArray, n);
    count = 0;

    //Quick Sort - Last
    cout << endl << endl;
    cout << "Quick Sort - last element as pivot: \n\n";
    startLast = clock();
    quickSortEnd(charArray, 0, n-1, count);
    endLast = clock();
    endLast2 = float (endLast)/CLOCKS_PER_SEC;
    cout << "Start Time  : " << startLast << endl;
    cout << "End Time  : " << endLast << endl;
    cout << "Actual CPU Clock time : " << endLast2 << " seconds" << endl;
    cout << "Total Number of Recursive Calls : " << count << endl;
    cout << "Sorted Elements: " ;
    displayElems(charArray, n);
    copyArray (charArrayCopy, charArray, n);
    count = 0;


    cout << "\n\nBenchmark Algorithm Implemented by : Samantha, Casler and Philip, Cesani\n";
    cout << "24 / 4 / 2019\n";

    return 0;
}

void printIntro()// function to print the intro to the program
{
    cout << "Searching / Sorting Benchmark\n\n";
    cout << "Using a random number generator, we are creating an array of n\n";
    cout << "elements of type char then performing the following :\n\n";
    cout << "1. Displaying the first 20 numbers.\n\n";
    cout << "2. Using recursion, Searching for an element in the array using\n";
    cout << "sequential search and at the end displaying number of comparisons\n";
    cout << "it makes.\n\n";
    cout << "3. Sort the original array using Selection Sort and at the end\n";
    cout << "display the number of swaps it makes.\n\n";
    cout << "4. Sorting the array using insertion Sort and at the end\n";
    cout << "displaying the number of comparisons it makes.\n\n";
    cout << "5. Sorting the array using Quick Sort and at the end displaying\n";
    cout << "the number of recursion calls it makes. Using the next to the\n";
    cout << "middle value as a pivot value.\n\n";
    cout << "6. Sorting the same array using Quick Sort and at the end\n";
    cout << "displaying the number of recursion calls it makes. Using the\n";
    cout << "first value as a pivot value.\n\n";
    cout << "7. Sorting the same array using Quick Sort and at the end\n";
    cout << "displaying the number of recursion calls it makes. Using the\n";
    cout << "last value as a pivot value.\n\n";
    cout << "8. For each of the preceding steps ( 2 thru 7 ), calculating and\n";
    cout << "printing the CPU time before each step starts and after each\n";
    cout << "completed step then calculating actual CPU time for the\n";
    cout << "completion of each step.\n\n\n";
}

//Char copy array
void copyArray (char arr[], char copyArr[], int n){

    for(int i = 0; i < n; i++){
        copyArr[i] = arr[i];
    }
}

//Char swap function
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

//Displays the elements of the array
void displayElems(char c [], int SIZE)
{
    const int MAX_OUTPUT = 20;  // sets the max output to 20 so no more than 20 elements are output

    //Goes through the array until it hits the max output allowed, 20 elements
    for (int i = 0; i < SIZE; i++)
    {
        if (i < MAX_OUTPUT)
            cout << c[i] << " ";
        else
            break;
    }
}

//Recursive sequential search
void sequentialSearch(char arr[], int first, int last, char x, int &count)
{

    if (arr[first] == x){
        count++;
        cout << "80 was found." << endl;
    }
    else if (first == last){
        count++;
        cout << "80 was not found." << endl;
    }
    else{
        count++;
        sequentialSearch(arr, first + 1, last, x, count);
    }
}

//Selection Sort Function
void selectionSort(char arr[], int n, int &count)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        count++;
        swap(arr[min_idx], arr[i]);
    }
}

//Insertions sort function
void insertionSort(char arr[], int n, int &count)
{
    int i, j;
    char key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key) {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Quick sort using the middle element as the pivot
void quickSortMidd(char arr[], int left, int right, int &count)
{

    int i = left, j = right;
    char tmp;
    int pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j){
        count++;
        quickSortMidd(arr, left, j, count);
    }
    if (i < right){
        count++;
        quickSortMidd(arr, i, right, count);
    }
}

//Generates the partition of the array using the last element as the pivot
int partitionEnd (char arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Generates the partition of the array using the first element as the pivot
int partitionFirst(char arr[],int low,int high)
{
    int j,temp,i=low+1;

    for(j = low+1; j < high;j++)
    {
        //swap values if a[j]<=a[r](i.e. pivot)
        if(arr[j]<=arr[low])
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
    }
    //place pivot at its position by swapping
    temp=arr[i-1];
    arr[i-1]=arr[low];
    arr[low]=temp;
    return i;
}

//Quick sort using ending element as the pivot
void quickSortEnd(char arr[], int low, int high, int &count)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partitionEnd(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        count++;
        quickSortEnd(arr, low, pi - 1, count);
        count++;
        quickSortEnd(arr, pi + 1, high, count);
    }
}

//Quick sort using first element pivot
void quickSortFirst(char arr[], int low, int high, int &count)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partitionFirst(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        count++;
        quickSortEnd(arr, low, pi - 1, count);
        count++;
        quickSortEnd(arr, pi + 1, high, count);
    }
}

