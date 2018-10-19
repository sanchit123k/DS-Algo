#include<iostream>
using namespace std;

void ClearAdjMatrix(int adjM[][15], int nodes)
{
	for (int i = 0; i < nodes; ++i)
	{
		for (int j = 0; j < nodes; ++j)
		{
			adjM[i][j]=0;
		}
	}
}

void addEdge(int adjM[][15], int source, int destn, int nodes)
{
	if(source>=nodes||destn>=nodes||source<0||destn<0)
		cout<<"Invalid edge. Enter again. \n";
	adjM[source][destn]=1;
}

void display(int adjM[][15], int nodes)
{
	cout<<"The Adjacency Matrix is : \n";
	for (int i = 0; i < nodes; ++i)
	{
		for (int j = 0; j < nodes; ++j)
		{
			cout<<adjM[i][j]<<" ";
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
	int adjM[15][15];
	ClearAdjMatrix(adjM,nodes);		    //Initialise All cells to 0
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
        		addEdge(adjM,source,destn,nodes);
    		}
    		break;
    	case 2:
    		for(int i = 0; i < max_edges; i++)  //No more edges than n*(n-1)
   			{
        		cout<<"Enter edge (-1 -1 to exit): ";
        		cin>>source>>destn;
        		if(source==-1 && destn==-1)
        			break;
        		addEdge(adjM,source,destn,nodes);
        		addEdge(adjM,destn,source,nodes);
        	}
        	break;
    }
    display(adjM,nodes);
        		
}