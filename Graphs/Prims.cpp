#include<iostream>
#include<stdbool.h>
#include<limits.h> 
using namespace std;

void InitializeMatrix(int adjM[15][15], int nodes)
{
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			adjM[i][j]=-1;
			if(i==j)
				adjM[i][j]=0;
		}
	}
}

void addEgde(int adjM[15][15], int source, int destn, int weight, int nodes)
{
	if(source<1 || destn<1 || source>nodes || destn>nodes)
		cout<<"\nInvalid Edge.";
	adjM[source][destn]=weight;
}

void display(int adjM[][15], int nodes)
{
	cout<<"The Adjacency Matrix is : \n";
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			cout<<adjM[i][j]<<" ";
		}
		cout<<endl;
	}
}

int minKey(int key[], bool mstset[], int nodes) 
{ 
	int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= nodes; i++)
	{
    	if(mstset[i] == false && key[i] < min) 
        	min = key[i], min_index = i; 
    }
	return min_index; 
}

int displayPrims(int adjM[15][15], int nodes, int* parent, int source)
{
	cout<<"Edge          Weight\n";
	for (int i = 1; i <= nodes; ++i)
	{
		if(i == source)
			continue;
		cout<<parent[i]<<" - "<<i<<"	       "<<adjM[parent[i]][i]<<endl;
	}
}

void Prims(int adjM[15][15], int nodes, int source)
{
    bool mstset[nodes+1];				// Represents set of vertices included/not included in MST 
    int key[nodes+1]; 			        // Key values used to pick minimum weight edge
    int parent[nodes+1];				// Array to store constructed MST/Find parent of nodes in mstset

    for (int i = 1; i <= nodes; ++i)	// Initialize all keys = INF and mstset is empty
    {
    	key[i] = INT_MAX;
    	mstset[i] = false;
    }

    key[source] = 0;					// Mark starting vertex's key = 0 so that it is 1st included in mstset
    parent[source] = -1;				// Starting node has no parent i.e. it the root of MST

    for (int i = 1; i <= nodes; ++i)	// mstset will have 'nodes' vertices
    {
    	int u = minKey(key,mstset,nodes);		// Pick the minimum key vertex from the set of vertices not yet included in MST
        mstset[u] = true;				// Add the picked vertex to the MST Set

        for (int j = 1; j <= nodes; ++j)// Update the key values of adjacent vertices to u which are not in mstset
        {
        	if(adjM[u][j] < key[j]  &&  mstset[j] == false && adjM[u][j] > 1)
        	{
        		key[j] = adjM[u][j];
        		parent[j] = u;			// Update the parent
        	}
        }

    }

    displayPrims(adjM,nodes,parent,source);
}


int main()
{
	int nodes,source,destn,weight;
	cout<<"--------------PRIMS ALGO WORKS FOR UNDIRECTED CONNECTED WEIGHTED GRAPH. Assume nodes 1..n---------------\n";
	cout<<"Enter number of nodes : ";
	cin>>nodes;
	int max_edges = nodes*(nodes-1);    //Standard Property
	int adjM[15][15];
	InitializeMatrix(adjM,nodes);		    //Initialise All cells according to weight
    for(int i = 0; i < max_edges/2; i++)  //No more edges than n*(n-1)/2
   {	
		cout<<"Enter edge and weight(-1 -1 -1 to exit) : ";
		cin>>source>>destn>>weight;
		if(source ==-1 && destn == -1 && weight == -1)
			break;
		addEgde(adjM,source,destn,weight,nodes);
		addEgde(adjM,destn,source,weight,nodes);
	}
    display(adjM,nodes);
    cout<<"Enter Starting Vertex : ";
    cin>>source;
    Prims(adjM,nodes,source);
        		
}



/*

5

1 2 10
1 3 20
2 3 30
2 4 5
3 4 15
3 5 6
4 5 8


--------------PRIMS ALGO WORKS FOR UNDIRECTED CONNECTED WEIGHTED GRAPH. Assume nodes 1..n---------------
Enter number of nodes : 5
Enter edge and weight(-1 -1 -1 to exit) : 1 2 10
Enter edge and weight(-1 -1 -1 to exit) : 1 3 20
Enter edge and weight(-1 -1 -1 to exit) : 2 3 30
Enter edge and weight(-1 -1 -1 to exit) : 2 4 5
Enter edge and weight(-1 -1 -1 to exit) : 3 4 15
Enter edge and weight(-1 -1 -1 to exit) : 3 5 6
Enter edge and weight(-1 -1 -1 to exit) : 4 5 8
Enter edge and weight(-1 -1 -1 to exit) : -1 -1 -1
The Adjacency Matrix is : 
0 10 20 -1 -1 
10 0 30 5 -1 
20 30 0 15 6 
-1 5 15 0 8 
-1 -1 6 8 0 
Enter Starting Vertex : 1
Edge          Weight
1 - 2	       10
5 - 3	       6
2 - 4	       5
4 - 5	       8




//--------------------------------------------------------------------------------------------------------------




GFG

--------------PRIMS ALGO WORKS FOR UNDIRECTED CONNECTED WEIGHTED GRAPH. Assume nodes 1..n---------------
Enter number of nodes : 5
Enter edge and weight(-1 -1 -1 to exit) : 1 2 2
Enter edge and weight(-1 -1 -1 to exit) : 1 4 6
Enter edge and weight(-1 -1 -1 to exit) : 2 4 8
Enter edge and weight(-1 -1 -1 to exit) : 4 5 9
Enter edge and weight(-1 -1 -1 to exit) : 2 5 5
Enter edge and weight(-1 -1 -1 to exit) : 2 3 3
Enter edge and weight(-1 -1 -1 to exit) : 3 5 7
Enter edge and weight(-1 -1 -1 to exit) : -1 -1 -1
The Adjacency Matrix is : 
0 2 -1 6 -1 
2 0 3 8 5 
-1 3 0 -1 7 
6 8 -1 0 9 
-1 5 7 9 0 
Enter Starting Vertex : 1
Edge          Weight
1 - 2	       2
2 - 3	       3
1 - 4	       6
2 - 5	       5

*/
