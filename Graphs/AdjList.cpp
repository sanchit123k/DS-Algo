#include <iostream>
using namespace std;
 //hello
struct node
{
    int data;
    node* next;
};

struct list
{
    node *head; 
};
 
struct Graph
{
    int V;
    list* array;
};
 

//Create A Graph
Graph* create_graph(int V) // v=no. of vertices
{
	Graph* graph = new Graph;
	graph->V=V;
	graph->array= new list[V];
	for (int i = 0; i < V; ++i)
	{
		graph->array[i].head=NULL;   //Iniatialise each list as empty
	}
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	node* temp = new node;
	temp->data = dest;
	temp->next = NULL;
									//Insert at beginning
	temp->next = graph->array[src].head;
	graph->array[src].head=temp;
}

void print_Graph(Graph* graph)
{
	for (int i = 0; i < graph->V ; ++i)
	{
		node* temp = graph->array[i].head;
		cout<<"\nAdjacency list of vertex "<<i<<"\nhead ";
		while(temp!=NULL)
		{
			cout<<"-> "<<temp->data;
			temp=temp->next;
		}
		cout<<endl;
	}
}

int main()
{
	int nodes,source,destn,choice;
	cout<<"Enter number of nodes : ";
	cin>>nodes;
	int max_edges = nodes*(nodes-1);    //Standard Property
	Graph* graph = create_graph(nodes);
	cout<<"1. Directed Graph 2. Undirected Graph\nEnter choice : 	";
	cin>>choice;
	switch(choice)
	{
		case 1:
			for(int i = 0; i < max_edges; i++)   //No more edges than n*(n-1)
   			{
        		cout<<"Enter edge (-1 -1 to exit): ";
        		cin>>source>>destn;
        		if(source==-1 && destn==-1)
        			break;
        		addEdge(graph,source,destn);
    		}
    		break;
    	case 2:
    		for(int i = 0; i < max_edges; i++)  //No more edges than n*(n-1)
   			{
        		cout<<"Enter edge (-1 -1 to exit): ";
        		cin>>source>>destn;
        		if(source==-1 && destn==-1)
        			break;
        		addEdge(graph,source,destn);
        		addEdge(graph,destn,source);
        	}
        	break;
    }
    print_Graph(graph);
 
    return 0;
}