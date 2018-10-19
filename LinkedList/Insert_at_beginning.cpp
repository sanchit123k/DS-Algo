#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};


node *Insert_At_Beginning(int data, node* head)
{
	node* temp = new node;
	temp->data = data;
	temp->next = head;
	head=temp;

	return temp;
}

void print(node* head)
{
	node* temp = head;
	cout<<"Linked list :";
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp = temp->next;

	}
	cout<<endl;
}

int main()
{
	node* head;
	int item;
	head = NULL;
	for(;;)
	{
		cout<<"Insert a key to Insert at Beginning or -99999 to exit : \n";
		cin>>item;
		switch(item)
		{
			case -99999:
				cout<<"Final ";
				print(head);
				exit(0);
				break;
			default:
				head = Insert_At_Beginning(item, head);
				print(head);
				break;

		}
	}
}