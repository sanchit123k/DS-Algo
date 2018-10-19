#include<iostream>
using namespace std;

void InitializeMatrix(int adjM[15][15], int nodes)
{
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			adjM[i][j]=9999;
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

void displayAdjMatrix(int adjM[15][15], int nodes)
{
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			cout<<adjM[i][j]<<" ";
		}
		cout<<endl;
	}
}

int min(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

void Floyd(int adjM[][15], int nodes)
{
	int D[15][15];
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			D[i][j] = adjM[i][j];
		}
	}

	for(int k =1; k <= nodes; ++k)
	{
		for (int i = 1; i <= nodes; ++i)
		{
			for (int j = 0; j <= nodes; ++j)
			{
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
		cout<<"\nMatrix D("<<k<<") = \n";
		displayAdjMatrix(D,nodes);
	}
}



int main()
{
	int nodes,source,destn,weight,choice;
	cout<<"Note - Warshall's Algo is for Directed/Undirected connected graph. Assume nodes 1..n\n";
	cout<<"Enter number of nodes : ";
	cin>>nodes;
	int max_edges = nodes*(nodes-1);
	int adjM[15][15];
	InitializeMatrix(adjM,nodes);
	cout<<"1. Directed Graph 2. Undirected Graph\nEnter choice : 	";
	cin>>choice;
	switch(choice)
	{
		case 1:
			for (int i = 0; i < max_edges; ++i)
			{	
				cout<<"Enter edge and weight(-1 -1 -1 to exit) : ";
				cin>>source>>destn>>weight;
				if(source ==-1 && destn == -1)
					break;
				addEgde(adjM,source,destn,weight,nodes);
			}
			break;

		case 2:
			for (int i = 0; i < max_edges; ++i)
			{	
				cout<<"Enter edge and weight(-1 -1 to exit) : ";
				cin>>source>>destn>>weight;
				if(source ==-1 && destn == -1)
					break;
				addEgde(adjM,source,destn,weight,nodes);
				addEgde(adjM,destn,source,weight,nodes);
			}
			break;
	}
	displayAdjMatrix(adjM, nodes);
	Floyd(adjM,nodes);

}

