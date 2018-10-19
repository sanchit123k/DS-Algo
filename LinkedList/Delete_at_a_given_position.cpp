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
		head = temp; //not required to write this statement
		return temp;
	}

	node* temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;

	temp1->next = temp;
	return head;

}

node* Delete_At_A_Given_Position(int n,node* head)
{
	
	node* temp=head;
	if(n==1)
	{
		head=temp->next;
		cout<<"Item Deleted is : "<<temp->data<<endl;
		delete(temp);
		return head;
	}
	for(int i=0;i<n-2;i++)
	{
		temp=temp->next;
	}

	node* temp2 = temp->next; // temp2 points to the nth node to be deleted
	temp->next=temp2->next;
	cout<<"Item Deleted is : "<<temp2->data<<endl;
	delete(temp2);
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
		cout<<"1. Insert At End \n2. Delete At Nth Position \n3. Press -99999 to exit\n\n";
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
				head = Insert_At_End(item, head);
				print(head);
				break;
			case 2:
				cout<<"Enter Position to Delete : \n";
				cin>>n;
				head = Delete_At_A_Given_Position(n,head);
				print(head);
				break;
			default:
				cout<<"Invalid response\nEnter again :\n";
				break;

		}

	}
	
}