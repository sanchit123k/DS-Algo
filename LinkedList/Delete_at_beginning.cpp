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

node* Delete_At_Beginning(node* head)
{
	if(head==NULL) //Check for empty list
	{
		cout<<"Empty List : Cannot Delete\n";
		return head;
	}
	node* temp;
	temp=head;
	head=temp->next;
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
	int item;
	node* head;
	head = NULL;
	for(;;)
	{
		cout<<"1. Insert At End \n2. Delete At Beginning \n3. Press -99999 to exit\n\n";
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
				
				head = Delete_At_Beginning(head);
				print(head);
				break;
			default:
				cout<<"Invalid response\nEnter again :\n";
				break;



		}

	}
	
}