#include<iostream>
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



void Kruskals(int adjM[15][15], int nodes)
{
	
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
    Kruskals(adjM,nodes);
        		
}