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

node* SwapPairwise(node* head)
{
	node* temp =head;  //points to 1st node in a pair
	node* check =head; //checks whether the next pair is available or not(to swap)
	node* second = head->next; //points to 2nd node in a pair
	if(head==NULL) //check if list is empty
	{
		cout<<"\nEmpty list\n";
		return head;
	}
	if(head->next==NULL)
	{
		cout<<"\nOnly 1 element in list. No need to swap\n";
		return head;
	}
	head=temp->next; //if more than 1 elememt, it means that aleast 1 pair is available to swap. Point head to 2nd node
					 //(which will become 1st node after swap)
	while(check!=NULL && check->next!=NULL) //check if next pair is a pair or not 
	{
		check=check->next->next; //go to next pair
		second->next=temp; //swap
		temp->next=check; //swap
		if(check!=NULL && check->next!=NULL) //check if next pair is available or not.
 		{
			temp->next=check->next; // MOST IMP STEP - if next pair is available, point the 2nd node of (after swap) current pair
									//to the 2nd node of the next pair(before swap) 
									//as that node will be swapped to become 1st node of next pair
									//and thus a contiuous link from 2nd node of current pair to 1st node of next pair(after swap)
			temp=check; // go to 1st node of next pair 
			second=check->next; // go to 2nd node of next pair
		}
	}
	return head;
}

void print(node* head)
{
	if(head==NULL)
	{
		cout<<"Empty\n";
		return;
	}
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
		cout<<"1.Insert At End\n2.Swap Pairwise\n3.Press -99999 to exit\n";
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
				cout<<"\nSwapped Pairwise : ";
				head = SwapPairwise(head);
				print(head);
				break;
			default:
				cout<<"Invalid choice :\n";
				break;

		}

	}
	
}