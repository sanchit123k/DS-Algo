#include<iostream>
using namespace std;
#define MAX 15
int queue[MAX], f=-1, r=-1;

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

void Enqueue(int startingV)
{
	if(r == MAX - 1)
		printf("Queue Overflow\n");
	else 
	{
		if(f == -1)
		{
			f = 0;
		}
		queue[++r] = startingV;
	}
}

int Dequeue()
{
	if(f == -1 || f>r)
		printf("Queue Underflow\n");
	else
	{
		int s = queue[f];
		f++;
		return s;
	}
}

int Empty_queue()
{
	if(f == -1 || f>r)
		return 1;
	else
		return 0;
}

void displayq()
{
    int i;
    if (f== - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = f; i <= r; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
} 

void bfs(int adjM[][15], int nodes, int visited[], int startingV)
{
	visited[startingV] = 2;				   // mark the visited vertex as "waiting" in the queue
	Enqueue(startingV);
	while(!Empty_queue())
	{
		int startingV = Dequeue();
		printf("-> %d ", startingV);       // print the visited the vertex
		visited[startingV] = 1;            // mark the visited vertex as "visited"
		for (int i = 0; i < nodes; ++i)
		{
			if(adjM[startingV][i] == 1 && visited[i]==0)// Check if there exists an UNVISITED vertex adjacent to current vertex being visited
			{
				Enqueue(i);
				visited[i] = 2;    // mark the visited vertex as "waiting" but not recursively call bfs
								   // cause we first have to visit all neighbouring nodes of startingV
			}
			
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
	bfs(adjM,nodes,visited,startingV);
}