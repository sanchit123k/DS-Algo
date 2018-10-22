// Heap Sort Using HeapBottomUp.cpp in ascending Order.
// Time Complexity - O(nlogn)

#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeapify(int arr[], int n, int i)		// A function to heapify the array.  // i = root index of the subtree
{
	int parentvalue = arr[i];
	//cout<<"ParentValue = "<<parentvalue<<"\n";
	int leftchildIndex = 2*i + 1;
	int rightchildIndex= 2*i + 2;
	int largerchild = leftchildIndex;

	while(leftchildIndex < n)		//while leftchild exists
	{
		if(leftchildIndex < n-1    &&  arr[rightchildIndex] > arr[leftchildIndex]  )		// if rightchild exists, find the larger child
		{
			largerchild = rightchildIndex;
		}
		//cout<<"largerchildIndex = "<<largerchild<<"\n";

		if(parentvalue >= arr[largerchild])		// Break if parent value is already greater than larger  child value.
			break;

		if(parentvalue < arr[largerchild])
		{
			arr[i] = arr[largerchild];				// swap parent node value and 
			arr[largerchild] = parentvalue;			// larger child node value
			/*
			for (int i = 0; i < n; i++)
			{
				cout<<"->"<<arr[i];
			}
			cout<<endl;
			*/
			MaxHeapify(arr,n,largerchild);			// recursively call MaxHeapify, passing largerchild Index(which is now a new parent)

		}

		return;
	} 
}


void Build_MaxHeap(int arr[], int n)
{
	for(int i = (n-2)/2; i >= 0; i--)			// non leaf node starts from (n-2)/2 and ends at 0 
	{
		MaxHeapify(arr, n, i);					// call MaxHeapify to heapify the subtree
		//cout<<"-------------\n";
	}
}


void HeapSort(int arr[], int n)
{
	for (int i = n-1; i > 0; --i)
	{
		swap(&arr[0],&arr[i]);
		Build_MaxHeap(arr,i);
		for (int j = 0; j < n; j++)
		{
			cout<<"->"<<arr[j];
		}
		cout<<endl;
	}

}



using namespace std;

int main()
{
	int n;
	cout<<"Enter array/heap size : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements : ";
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	Build_MaxHeap(arr,n);			// Stage 1
	cout<<"Stage 1 : \n";
	for (int i = 0; i < n; i++)
	{
		cout<<"->"<<arr[i];
	}

	cout<<"\nStage 2 : \n";
	HeapSort(arr,n); 				// Stage 2

	cout<<"\nSorted Array : \n";
	for (int i = 0; i < n; i++)
	{
		cout<<"->"<<arr[i];
	}

	return 0;
}