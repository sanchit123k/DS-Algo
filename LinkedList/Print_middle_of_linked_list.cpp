#include<iostream>
using namespace std;
//M3 -Initialize mid element as head and initialize a counter as 0. 
//Traverse the list from head, while traversing increment the counter and change mid to mid->next whenever the counter is odd. 
//So the mid will move only half of the total length of the list. 
//PS:Not coded here. Check : https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
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

node* MiddleM1(node* head) //Traverse the whole linked list and count the no. of nodes. 
                           //Now traverse the list again till count/2 and return the node at count/2.
{
	node* temp=head;
	int count=0;
	if(head==NULL)
	{
		cout<<"\nEmpty List";
		return head;
	}
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	int n=(count/2)+1; // Doesn't matters if count is odd or even since if(count==even) we print 2nd middle element
	temp=head;
	for (int i = 0; i < n-1; i++)// Go to the nth node. by moving ahead (n-1) times
	{
		temp=temp->next;
	}
	cout<<temp->data;
	return head;
}

node* MiddleM2(node* head) //Traverse linked list using two pointers. Move one pointer by one and other pointer by two. 
                           //When the fast pointer reaches end slow pointer will reach middle of the linked list.

{
	node* fast_ptr=head, *slow_ptr=head;
	if(head==NULL)
	{
		cout<<"\nEmpty List";
		return head;
	}
	while(fast_ptr!=NULL && fast_ptr->next!=NULL) //Both conditions are necessary since skipping 2 nodes may result to both
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
	}

	cout<<slow_ptr->data;
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
		cout<<"1.Insert At End\n2.Print Middle of the List\n3.Press -99999 to exit\n";
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
				cout<<"\nThe Middle Element of Linked List is : ";
				head = MiddleM1(head);
				cout<<"  ||  ";
				head = MiddleM2(head);
				cout<<endl;
				break;
			default:
				cout<<"Invalid choice :\n";
				break;
		}
	}	
}
/*5->NULL
The middle element is [5]

4->5->NULL
The middle element is [5]

3->4->5->NULL
The middle element is [4]

2->3->4->5->NULL
The middle element is [4]

1->2->3->4->5->NULL
The middle element is [3]
*/