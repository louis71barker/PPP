#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

typedef enum {DIRECTGRAPH, UNDIRECTGRAPH} graphType;
#define weightForNonExistingEdge 0 // choose a suitable value for your application

int **createAdjMatrix(graphType type, int numNodes, int numEdges, int edgeList[][3])
{
	// allocate memory for adjacent matrix, 2D matrix allocation
    int i, j;
	int **matrix = (int **)malloc(numNodes*sizeof(int*));
    for(i = 0;i < numNodes;i++)
    {
        matrix[i] =  (int *)malloc(numNodes*sizeof(int));
        for(j=0;j<numNodes;j++)
        {
            matrix[i][j] = weightForNonExistingEdge;
        }
    }

    for (i=0; i < numEdges;i++)
    {
        matrix[edgeList[i][0]][edgeList[i][1]]=edgeList[i][2];
        if (type == UNDIRECTGRAPH)
        {
               matrix[edgeList[i][1]][edgeList[i][0]]=edgeList[i][2];
        }
    }

    return matrix;


}

void printAdjMatrix(int numNodes, int **adjMatrix)
{
    int i, j;
	printf("The adjacent matrix for this graph is\n");
    for(i=0;i<numNodes;i++)
	{
        for(j=0;j<numNodes;j++)
			printf("%3d ", adjMatrix[i][j]);
		printf("\n");
	}
}
void freeAdjMatrix(int numNodes, int **adjMatrix)
{
    int i;
    for(i=0;i<numNodes;i++)
		free(adjMatrix[i]);
	free(adjMatrix);
}

// Task: print out the graph content in the order of breadth first
// stopping condition: queue is empty
// visitFlag used to check if the vertex has been visited already or not, if yes, skip it
void breadthFirstSearch(int numNodes, int **adjMatrix, char *nodeList[], int startNode)
{
    int i;
	bool *visitFlag = (bool *)calloc(numNodes, sizeof(bool));
	int currentNode;
  queue nodeQueue;
  initializeQueue(&nodeQueue);
  addToQueue(&nodeQueue, startNode);
  visitFlag[startNode] = 1;
  printf("start of breath first \n");
  while (!isEmptyQueue(&nodeQueue))
  {
     deleteFromQueue(&nodeQueue, &currentNode);
     for(i=0; i<numNodes; i++)
     {
        if (adjMatrix[currentNode][i] != weightForNonExistingEdge)
        {
            if (visitFlag[i] == 0)
            {
            addToQueue(&nodeQueue, i);
            visitFlag[i] = 1;
            }
         }
      }

      printf("%s \n", nodeList[currentNode]);


  }




}


// Task: print out the graph content in the order of depth first
// stopping condition: stack is empty
// visitFlag used to check if the vertex has been visited already or not, if yes, skip it
void depthFirstSearch(int numNodes, int **adjMatrix, char *nodeList[], int startNode)
{
        int i;
        bool *visitFlag = (bool *)calloc(numNodes, sizeof(bool));
        int currentNode;
        stack nodeStack;
        initializeStack(&nodeStack);
        pushStack(&nodeStack, startNode);
        visitFlag[startNode] = 1;
        printf("Depth first printing started from %s\n", nodeList[startNode]);
        while(!isEmptyStack(&nodeStack))
        {
                popStack(&nodeStack, &currentNode);
                printf(" %s ", nodeList[currentNode]);
                for(i=0;i<numNodes;i++)
                {
                        if(adjMatrix[currentNode][i]!=0) // there is a edge between currentNode to node i
                        {
                                if(visitFlag[i] == 0) // node i has not been visited yet
                                {
                                        pushStack(&nodeStack, i);
                                        visitFlag[i] = 1;
                                }
                        }
                }
        }
        printf("\n");
        free(visitFlag);
}

void selectionSort(int numEdges, int edgeList[][3])
{
    int i, j, v1, v2, minWeight, minIndex;
    for(i=0;i<numEdges-1;i++)
    {
        minWeight = edgeList[i][2];
        minIndex = i;
        for(j=i+1;j<numEdges;j++)
        {
            if(edgeList[j][2]<minWeight)
            {
                minWeight = edgeList[j][2];
                minIndex = j;
            }
        }
        if(minIndex != i) // need to swap
        {
            v1 = edgeList[minIndex][0];
            v2 = edgeList[minIndex][1];
            edgeList[minIndex][2] = edgeList[i][2];
            edgeList[minIndex][0] = edgeList[i][0];
            edgeList[minIndex][1] = edgeList[i][1];
            edgeList[i][0]=v1;
            edgeList[i][1]=v2;
            edgeList[i][2]=minWeight;
        }
    }
}

// minimum spanning tree, Kruskal’s algorithm, didn't use adjacent matrix
void minmumSpanningTree(int numNodes, char *nodeList[], int numEdges, int edgeList[][3])
{
    int i, j, firstFlag, secondFlag, biggerFlag, smallerFlag;
    // sorting the edgeList according to the weight, in increasing order, use buble sort method
    selectionSort(numEdges, edgeList);

    // each node is allocated to a seperate tree, indexed by a number
    int *treeFlag = (int *)malloc(numNodes*sizeof(int));
    for(i=0;i<numNodes;i++)
        treeFlag[i] = i;

    printf("The minimum spanning tree include the following edges:\n");
    // search the edgelist from the shortest first
    for(i=0;i<numEdges;i++)
    {
        firstFlag = treeFlag[edgeList[i][0]];
        secondFlag = treeFlag[edgeList[i][1]];
        biggerFlag = firstFlag<secondFlag?secondFlag:firstFlag;
        smallerFlag = firstFlag>secondFlag?secondFlag:firstFlag;
        if(firstFlag != secondFlag) // this edge won't form a circuit if added
        {
            printf("[%s, %s]", nodeList[edgeList[i][0]], nodeList[edgeList[i][1]]);
            // merge two trees
            for(j=0;j<numNodes;j++)
            {
                if(treeFlag[j]==biggerFlag)
                    treeFlag[j] = smallerFlag;
            }
        }
    }
    printf("\n");
    free(treeFlag);
}

#define INFINITY 10000 // choose a big number, impossible to achieve for a path length
int smallestDistInQSet(int numNodes, int *nodeDist, bool *qSet)
{
    int i, smallestDist, smallestIndex;
    smallestDist = INFINITY;
    smallestIndex = -1;
    for(i=0;i<numNodes;i++)
    {
        if(qSet[i] && nodeDist[i]<smallestDist)
        {
            smallestDist = nodeDist[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

// find the shortest path from the source vertex(1) to the target vertex(9), using Dijkstra algorithm
void shortestPath(int numNodes, int **adjMatrix, char *nodeList[], int startNode, int endNode)
{
    int i, smallestIndex;
    int *nodeDist = (int*)malloc(numNodes*sizeof(int));
    int *prevNode = (int*)malloc(numNodes*sizeof(int));
    bool *qSet = (bool*)malloc(numNodes*sizeof(bool));
    int numInQSet = numNodes;
    for(i=0;i<numNodes;i++)
    {
        nodeDist[i] = INFINITY;
        prevNode[i] = -1;
        qSet[i] = true;
    }
    nodeDist[startNode]=0;
    while(numInQSet>0)
    {
        // find the smallest nodeDist in QSet
        smallestIndex = smallestDistInQSet(numNodes, nodeDist, qSet);
        if(nodeDist[smallestIndex]==INFINITY)
            break; // not all the vertex are accessible from the source vertex
        qSet[smallestIndex]=false; // remove this vertex from Q set
        numInQSet--;
        // recalc the dist for all neighbouring vertex to the node(smallestIndex)
        for(i=0;i<numNodes;i++)
        {
            if(adjMatrix[smallestIndex][i]!=weightForNonExistingEdge) // there is a edge between smallestIndex and i
            {
                if(nodeDist[smallestIndex]+adjMatrix[smallestIndex][i]<nodeDist[i])
                {
                    nodeDist[i] = nodeDist[smallestIndex]+adjMatrix[smallestIndex][i];
                    prevNode[i] = smallestIndex;
                }
            }
        }
    }

    // now all the nodes got their shortest distance to the source vertex
    // we need to print out a path from startNode to endNode, we need to use a stack
    stack pathNodeList;
    initializeStack(&pathNodeList);
    int currentNode = endNode;
    while(currentNode!=startNode)
    {
        pushStack(&pathNodeList, currentNode);
        currentNode = prevNode[currentNode];
    }
    pushStack(&pathNodeList, startNode);
    printf("The shortest path from %s to %s is ", nodeList[startNode], nodeList[endNode]);
    while(!isEmptyStack(&pathNodeList))
    {
        popStack(&pathNodeList, &currentNode);
        printf(" %s ", nodeList[currentNode]);
    }
    printf("\n");
    free(nodeDist);
}

int main()
{
/*
        graphType type = DIRECTGRAPH;
        char *nodeList[] = {"V1", "V2", "V3", "V4", "V5", "V6"};
        int edgeList[][3] = {{0, 1, 1}, {0, 2, 1}, {0, 3, 1}, {1, 3, 1}, {1, 4, 1}, {3, 5, 1}};
*/
	graphType type = UNDIRECTGRAPH;
	char *nodeList[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	int edgeList[][3] = {{0, 1, 5}, {0, 2, 3}, {1, 2, 6}, {1, 3, 7}, {3, 6, 6}, {1, 6, 3}, {2, 5, 2},
		{5, 7, 1}, {2, 7, 11}, {1, 4, 4}, {2, 4, 6}, {4, 6, 8}, {4, 7, 9}, {6, 7, 10},
		{6, 8, 4}, {7, 8, 7}}; // {startNodeIndex, endNodeIndex, EdgeWeight}

	// create the adjacent matrix
	int numNodes = sizeof(nodeList)/sizeof(char*);
	int numEdges = sizeof(edgeList)/sizeof(int)/3;
	int **adjMatrix = createAdjMatrix(type, numNodes, numEdges, edgeList);
	printAdjMatrix(numNodes, adjMatrix);
	
	// breadth first search, start from the node0 "1"
	breadthFirstSearch(numNodes, adjMatrix, nodeList, 0);
		
    // Depth first search, start from the node0 "1"
    depthFirstSearch(numNodes, adjMatrix, nodeList, 0);

    // minimum spanning tree, Kruskal’s algorithm
    minmumSpanningTree(numNodes, nodeList, numEdges, edgeList);

    // find the shortest path from the source vertex 1 (index 0) to the target vertex 9 (index 8), using Dijkstra algorithm
    shortestPath(numNodes, adjMatrix, nodeList, 0, 8);

    freeAdjMatrix(numNodes, adjMatrix);
    return EXIT_SUCCESS;
}
