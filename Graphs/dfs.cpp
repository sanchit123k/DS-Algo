#include<iostream>
using namespace std;

void ClearAdjMatrix(int adjM[][15], int nodes)
{
	for (int i = 0; i < nodes; ++i)
	{
		for (int j = 0; j < nodes; ++j)
		{
			adjM[i][j] = 0;
		}
	}
}

void addEdge(int adjM[][15], int source, int destn, int nodes)
{
	if(source>=nodes||destn>=nodes||source<0||destn<0)
		cout<<"Invalid edge. Enter again. \n";
	adjM[source][destn]=1;
}

void dfs(int adjM[][15], int nodes, int visited[], int startingV)
{
	printf("-> %d ", startingV);           // print the visited the vertex
	visited[startingV] = 1;				   // mark the visited vertex as "visited"

	for (int i = 0; i < nodes; ++i)
	{
		if(adjM[startingV][i]==1 && visited[i]!=1)    // Check if there exists an UNVISITED vertex adjacent to current vertex being visited
		{
			dfs(adjM, nodes, visited, i);			  // Recursively call dfs & pass the unvisited vertex 
													  // adjacent to current vertex being visited
		}
	}
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
	int nodes,choice,source,destn;
	printf("Enter no. of vertices : ");
	scanf("%d", &nodes);
	int adjM[15][15];
	int max_edges = nodes*(nodes-1);
	ClearAdjMatrix(adjM, nodes);
	printf("\n1. Directed Graph  2.Undirected Graph \nEnter choice : ");
	scanf("%d", &choice);
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

	//--------------------------------

	int visited[nodes] = {0};
	int startingV;
	printf("Enter starting vertex : ");
	scanf("%d", &startingV);
	dfs(adjM,nodes,visited,startingV);
}