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

	if(head == NULL)
	{
		head = temp;
		return temp;
	}

	node* temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;

	temp1->next = temp;
	return head;

}

node* Reverse(node* head)
{
	node *prev,*cur,*next;
	cur=head;
	prev=NULL;
	while(cur!=NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev=cur;
		cur=next;
	}
	head=prev;
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
	int item,choice;
	node* head;
	head = NULL;
	for(;;)
	{
		cout<<"1. Insert At End\n2.Reverse The Linked List\n3.Press -99999 to exit\n";
		cin>>choice;
		switch(choice)
		{
			case -99999:
				cout<<"Final ";
				print(head);
				exit(0);
				break;
			case 1:
				cout<<"Enter a data to Insert :\n";
				cin>>item;
				head = Insert_At_End(item, head);
				print(head);
				break;
			case 2:
				cout<<"\nReversed Linked List is : ";
				head = Reverse(head);
				print(head);
				break;
			default:
				cout<<"Invalid choice :\n";
				break;

		}

	}
	
}