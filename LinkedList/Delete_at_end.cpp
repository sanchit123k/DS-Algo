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

node* Delete_At_End(node* head)
{
	if(head==NULL) //Check for empty list
	{
		cout<<"No element to Delete.\n";
		return head;
	}
	if(head->next==NULL) //If only one node present
	{
		cout<<"Item Deleted is : "<<head->data<<endl;
		free(head);
		return NULL;
	}
	node* temp = head;
	node* prev=NULL;
	while(temp->next!=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next=NULL;
	cout<<"Item Deleted is : "<<temp->data<<endl;
	delete(temp);
	return head;
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
		cout<<"1. Insert At Beginning \n2. Delete At End \n3. Press -99999 to exit\n\n";
		cin>>item;
		switch(item)
		{
			case -99999:
				cout<<"Final ";
				print(head);
				exit(0);
				break;
			case 1:
				cout<<"Enter item to insert :\n";
				cin>>item;
				head = Insert_At_Beginning(item, head);
				print(head);
				break;
			case 2:
				
				head = Delete_At_End(head);
				print(head);
				break;
			default:
				cout<<"Invalid response\nEnter again :\n";
				break;
		}
	}
}