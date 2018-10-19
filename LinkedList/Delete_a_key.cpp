#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* Insert_at_end(int data, node* head)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;

	if(head==NULL)
	{
		head=temp;
		return head;
	}

	node* temp1 = head;
	while(temp1->next != NULL)
		temp1 = temp1->next;

	temp1->next = temp;
	return head;
}

node* Delete_a_key(int key, node* head)
{
	node* temp;
	temp=head;
	if(head == NULL)
	{
		cout<<"\nThe List is already empty.\n";
		return head;
	}
	if(head!=NULL && temp->data==key) //If 1st element itself is equal to key
	{
		head = temp->next;
		cout<<"\nThe key deleted is "<<temp->data<<endl;
		delete(temp);
		return head;
	}
	node* prev = NULL;
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		cout<<"\nThe Key "<<key<<" is not found.\n";
		return head;
	}
	prev->next=temp->next;
	cout<<"\nThe key deleted is "<<temp->data<<endl;
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
	head = NULL; //signifies list is empty
	int choice,item;
	for(;;)
	{
		cout<<"1. Insert At End\n2. Delete A Key\n 3. Press -99999 to  Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter data to Insert : ";
				cin>>item;
				head = Insert_at_end(item,head);
				print(head);
				break;

			case 2:
				cout<<"Enter Key to Delete From List : ";
				cin>>item;
				head = Delete_a_key(item,head);
				print(head);
				break;

			case -99999:
				cout<<"The Final ";
				print(head);
				exit(0);
				break;

			default:
				cout<<"Invalid choice : \n";
				break;

		}
	}
}