#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* Insert_At_Position(int data, node* head,int n)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;

	if(n==1)
	{
		temp->next=head;
		head = temp;//this statement not required
		return temp;
	}
	node*temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
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
	int item,n;
	node* head;
	head = NULL;
	for(;;)
	{
		cout<<"Enter an item to insert and its position at end or press -99999 to exit\n";
		cin>>item>>n;
		switch(item)
		{
			case -99999:
				cout<<"Final ";
				print(head);
				exit(0);
				break;
			default:
				head = Insert_At_Position(item, head,n);
				print(head);
				break;

		}

	}
	
}