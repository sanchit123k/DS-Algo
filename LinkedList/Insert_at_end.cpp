#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* Insert_At_End(int data, node* head)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;

	if(head == NULL) //If list is empty
	{
		head = temp;
		return temp; // Return new node as 1st node
	}

	node* temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;

	temp1->next = temp;
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
	int item;
	node* head;
	head = NULL;
	for(;;)
	{
		cout<<"Enter an item to insert at end or press -99999 to exit\n";
		cin>>item;
		switch(item)
		{
			case -99999:
				cout<<"Final ";
				print(head);
				exit(0);
				break;
			default:
				head = Insert_At_End(item, head);
				print(head);
				break;

		}

	}
	
}