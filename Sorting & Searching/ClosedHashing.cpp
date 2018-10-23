#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

struct slot
{
	char key[30];
};

int HashFuntion(char* key, int bucketsize)
{
	int len = strlen(key) - 1;
	int index = len;
	int hashvalue = 0;
	while(index>=0)
	{
		hashvalue = hashvalue + (int(key[index]) - 64);
		index--;
	}
	hashvalue = hashvalue % bucketsize;
	return hashvalue;
}

void InsertKey(slot* HashTable[], char* key, int bucketsize)
{
	int hashvalue = HashFuntion(key,bucketsize);
	cout<<"Hashvalue = "<<hashvalue<<endl;
	if(HashTable[hashvalue]==NULL){
		struct slot* newSlot=new struct slot;
		strcpy(newSlot->key,key);
		HashTable[hashvalue]=newSlot;
		return;
	}
	int i = hashvalue;
	i = (i+1)%bucketsize;
	while(i!=hashvalue)
	{
		if(HashTable[i]==NULL){
		struct slot* newSlot=new struct slot;
		strcpy(newSlot->key,key);
		HashTable[i]=newSlot;
		return;
		}		
		i = (i+1)%bucketsize;
	}
	cout<<"HashTable Full. Do Rehashing... \n";
}

void display(slot* HashTable[], int bucketsize)
{
	for (int i = 0; i < bucketsize; ++i)
	{
		if(HashTable[i]==NULL){cout<<"empty ";continue;}
		cout<<" "<<HashTable[i]->key<<" ";
	}
	cout<<endl<<endl;
}

void SearchKey(slot* HashTable[], char* key, int bucketsize)
{
	int hashvalue = HashFuntion(key,bucketsize);
	cout<<"Hashvalue = "<<hashvalue<<endl;
	if(!strcmp(HashTable[hashvalue]->key,key))
	{
		cout<<"Search Successful at index "<<hashvalue<<" in first comparision .."<<endl;
		return;
	}
	int i = hashvalue;
	i = (i+1)%bucketsize;
	while(HashTable[i]!=NULL)
	{
		if(!strcmp(HashTable[i]->key,key))
		{
			cout<<"Search Successful at index "<<i<<endl;
			return;
		}
		if(i==hashvalue)
		{
			break;
		}
		i = (i+1)%bucketsize;
	}
	cout<<"Search Unsuccessful. Item not found "<<endl;
	return;
}

int main()
{
	int bucketsize;
	cout<<"Enter bucketsize : ";
	cin>>bucketsize;

	slot* HashTable[bucketsize];		// Define an array(in which each cell can hold char[30]) of bucketsize size
	//char Null[30] = "NULL";
	
	for (int i = 0; i < bucketsize; ++i)
	{
		HashTable[i]=NULL;
	}
	

	char key[30]; 
	char Exit[30]="EXIT";
	cout<<"Enter the item to be inserted (EXIT to exit) : \n";
	cin>>key;
	while(strcmp(key,Exit))					// strcmp function returns 0 if both strings are equal
	{
		InsertKey(HashTable,key,bucketsize);
		display(HashTable, bucketsize);
		cin>>key;
	}
	cout<<"Enter item to search : ";
	cin>>key;
	SearchKey(HashTable,key,bucketsize);


	return 0;
}


/*

INPUT

LIKE 
A 
TREE 
YOU 
FIRST 
FIND 
PLACE 
TO 
GROW 
AND 
THEN 
BRANCH 
OUT
EXIT


OUTPUT

empty  A  YOU  TREE  FIND  TO  GROW  LIKE  PLACE  AND  THEN  BRANCH  FIRST  OUT empty 

Enter item to search : TO
Hashvalue = 5
Search Successful at index 5in first comparision ..


*/