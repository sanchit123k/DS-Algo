#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;


struct node
{
	char key[30];
	//int value;
	node* next;
};

node* CreateNode(char* key)//, int value)
{
	node* newNode = new node;
	strcpy(newNode->key, key);
	//newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

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

node* InsertNode(node* head, char* key)
{
	if(head==NULL)
	{
		head = CreateNode(key);
		return head;
	}

	node* temp = CreateNode(key);
	node* cur = head;
	while(cur->next!=NULL)
		cur = cur->next;
	cur->next = temp;
	return head;
}

void display(node* HashTable[], int bucketsize)			 //To display the contents of Hash Table
{
	for (int i = 0; i < bucketsize; i++) 
    {
		node *temp = HashTable[i];
		if (temp == NULL)
			cout<<"Index "<<i<<" has 0 elements \n";
		else 
    	{
			cout<<"Index "<<i<<" has elements ";
			while(temp != NULL)
        	{
				cout<<" -> "<<temp->key;
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	cout<<endl;
}

void SearchKey(node* HashTable[], char* key, int bucketsize)
{
	int hashvalue = HashFuntion(key,bucketsize);
	cout<<"Hashvalue = "<<hashvalue<<endl;
	node* temp = HashTable[hashvalue];
	if(temp==NULL)
	{
		cout<<"Empty cell. Search Unsuccessful. \n";
		return ;
	}
	while(temp!=NULL)
	{
		if(!strcmp(temp->key, key))			// strcmp function returns 0 if both strings are equal
		{
			cout<<"Item found at index "<<hashvalue<<" \n";
			return;
		}
		temp = temp->next;
	}
	cout<<"Search Unsuccessful. Item not at index "<<hashvalue<<endl;
	return;
}

int main()
{
	int bucketsize;
	cout<<"Enter bucketsize : ";
	cin>>bucketsize;
	node* HashTable[bucketsize];		// Create a hashtable of size = bucketsize

	for (int i = 0; i < bucketsize; ++i)  // Initialise all node pointers to NULL
	{
		HashTable[i]=NULL;
	}

	char key[30], Exit[5]="EXIT";
	cout<<"Enter the item to be inserted (EXIT to exit) : \n";
	cin>>key;
	while(strcmp(key,Exit))					// strcmp function returns 0 if both strings are equal
	{
		int hashvalue = HashFuntion(key,bucketsize);
		HashTable[hashvalue] = InsertNode(HashTable[hashvalue], key);
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

Index 0 has elements  -> TO
Index 1 has elements  -> A -> YOU -> BRANCH -> OUT
Index 2 has elements  -> LIKE -> FIRST -> PLACE -> THEN
Index 3 has elements  -> TREE -> FIND -> GROW
Index 4 has elements  -> AND

*/