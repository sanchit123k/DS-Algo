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

node* Remove_Duplicates_Sorted(node* head)
{
	node* temp=head;
	node* cur=head;
	while(cur->next!=NULL)  // 
	{
		cur=cur->next;
		while(cur->data==temp->data && cur->next!=NULL)//Dont use cur!=NULL since nw,cur->data is invalid:result in segmentation fault
		{
			node* to_del = cur;
			cur=cur->next;
			temp->next=to_del->next; //Make a new link to next to next element from temp
			delete(to_del);
		}
		if(cur->next==NULL)   //when list end is reached
		{
			if(cur->data==temp->data) // check whether last two elements are same or not
			{
				temp->next=NULL; //Make 2nd last element as last element
				delete(cur); // Delete last element(which is same as 2nd last element)
			}
		}
		temp=temp->next; 
	}
	return head;
}

node* Remove_Duplicates_Sorted_Optimized(node* head)
{
	node* temp = head;
	node* temp1=head;
	while(temp->next!=NULL)
	{
		temp1=temp;
		if(temp->data==temp->next->data)
		{
			temp1=temp->next;
			temp->next=temp1->next;
			delete(temp1);
		}
		else
			temp=temp->next;
	}
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
		cout<<"1.Insert At End(Sort List)\n2.Remove Duplicates from Sorted List\n3.Press -99999 to exit\n";
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
				cout<<"\nThe New ";
				head = Remove_Duplicates_Sorted_Optimized(head);
				print(head);
				cout<<endl;
				break;
			default:
				cout<<"Invalid choice :\n";
				break;
		}
	}	
}