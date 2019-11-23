#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;
int* randomNoGenerator(int size)                        //randomNoGenerator is a function
{                                                       //that generates random numbers
	int* randomNumbers = new int[size];                 //in a range and print the numbers 
	for (int i = 0; i < size; i++)                      //on console and store numbers in a
	{                                                   //dynamially allocated array and returns
		randomNumbers[i] = (rand() % 1000000) + 1;      //the array
	}
	cout << endl;
	return randomNumbers;                              
}
int* insertionSort(int arr[],int startIndex,int endIndex)                                  
{
	int j, key;
	for (startIndex = 1; startIndex < endIndex; startIndex++)            //Inserion Sort is a function 
	{                                                                    //that sorts the numbers in the
		key = arr[startIndex];                                           //array which is passed to this
		j = startIndex - 1;                                              //function.
		while ((key < arr[j]) && (j >= 0))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return arr;
}
void merge(int arr[], int startIndex, int middle, int endIndex)
{
	int i, j, k;                                                          //Merge is a function 
	int size1 = middle - startIndex + 1;                                  //that merges two arrays.
	int size2 = endIndex - middle;                                        
																		  
	int* leftArray = new int[size1];
	int* rightArray = new int[size2];

	for (i = 0; i < size1; i++)
		leftArray[i] = arr[startIndex + i];
	for (j = 0; j < size2; j++)
		rightArray[j] = arr[middle + 1 + j];

	i = 0;
	j = 0;
	k = startIndex;
	while (i < size1 && j < size2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			arr[k] = leftArray[i];
			i++;
		}
		else
		{
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < size1)
	{
		arr[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		arr[k] = rightArray[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int startIndex, int endIndex) 
{
	if (startIndex < endIndex)                                            //Merge Sort is a function 
	{                                                                     //that diveds the elements 
		int middle = startIndex + (endIndex - startIndex) / 2;            //of array according to
		mergeSort(arr, startIndex, middle);                               //indices and call merge 
		mergeSort(arr, middle + 1, endIndex);                             //function
		merge(arr, startIndex, middle, endIndex);
	}
}
void printArray(int* arr, int size)
{
	cout << "The sorted array of randon numbers is: " << endl << endl;
	for (int i = 0; i < size; i++)                                       //printArray is a functon that
	{                                                                    //prints the array which is passed
		cout << arr[i] << " \t";                                         //to this function.
	}
	cout << endl;
}
int main()
{
	clock_t t,t1;
	ofstream ofs;
	ofs.open("sorted.txt", ios::out | ios::trunc);                    //creating and opening file
	if (ofs)
	{
		int size;                                                    //total numbers we want to generate
		cout << "Enter the ammount of numbers you want to generate : " << endl;     
		cin >> size;

		/*Insertion Sort*/

		int* p= randomNoGenerator(size);                             //generating random number array

		t = clock();                                                 //clock starts
		insertionSort(p,1,size);                               
	    t = clock() - t;                                             //clock ends
		
		for (int i = 0; i < size; i++) { ofs << p[i] << endl; }      //saving sorted numbers in file 

		double time_taken = ((double)t) / CLOCKS_PER_SEC;    
		printf("Insertin Sort Algorithm took %f seconds to sort random numbers. \n",time_taken); //printing the total time
		
		/*Merge Sort */
		
		int* q= randomNoGenerator(size);                              //generating random number array

		t1 = clock();                                                 //clock starts
		mergeSort(q, 0, size-1);
		t1 = clock() - t1;                                            //clock ends

		double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;    
		printf("Merge Sort Algorithm took %f seconds to sort random numbers. \n",time_taken1);   /*printing total time*/
	}
	else
	{
		cout << "Error in opening file." << endl;
	}
	ofs.close();                                                      //closing file.
	
	
	return 0;
}