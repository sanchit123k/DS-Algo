#include<iostream>
using namespace std;

void clearMatrix(int adjM[15][15], int nodes)
{
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			adjM[i][j]=0;
		}
	}
}

void addEgde(int adjM[15][15], int source, int destn, int nodes)
{
	if(source<1 || destn<1 || source>nodes || destn>nodes)
		cout<<"\nInvalid Edge.";
	adjM[source][destn]=1;
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

void Warshall(int adjM[][15], int nodes)
{
	int R[15][15];
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			R[i][j] = adjM[i][j];
		}
	}

	for(int k =1; k <= nodes; ++k)
	{
		for (int i = 1; i <= nodes; ++i)
		{
			for (int j = 0; j <= nodes; ++j)
			{
				R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
			}
		}
		cout<<"\nMatrix R("<<k<<") = \n";
		displayAdjMatrix(R,nodes);
	}
}



int main()
{
	int nodes,source,destn;
	cout<<"Note - Warshall's Algo is for only Directed graph. Assume nodes 1..n\n";
	cout<<"Enter number of nodes : ";
	cin>>nodes;
	int max_edges = nodes*(nodes-1);
	int adjM[15][15];
	clearMatrix(adjM,nodes);
	for (int i = 0; i < max_edges; ++i)
	{
		cout<<"Enter edge (-1 -1 to exit) : ";
		cin>>source>>destn;
		if(source ==-1 && destn == -1)
			break;
		addEgde(adjM,source,destn,nodes);

	}
	displayAdjMatrix(adjM, nodes);
	Warshall(adjM,nodes);

}

