#include <iostream>
#include <vector>
#include <random>
#include "Graph.h"
#include <ctime>
using namespace std;


int main()
{
	clock_t curtime = clock();
	random_device rd;
	minstd_rand engine(rd());
	std::uniform_int_distribution<> distr(0, MAX_NODES-1);

	
	vector<int> nodeTable;
	vector<int> edgeTable;
	Graph* graph = new Graph();

	for (int i = 0; i < MAX_NODES; i++)
	{
		graph->addNode(new GraphNode(i));
	}
	
	for (int i = 0; i < MAX_EDGES; i++)
	{
		GraphNode* from = graph->findNode(distr(engine));
		GraphNode* to = graph->findNode(distr(engine));


		if (from != to)
		{
			GraphEdge* edge = new GraphEdge(from, to, i);
			graph->addEdge(edge);
		}
	}

	int trials = 25;

	for (int i = 0; i < trials; i++)
	{
		int nodeNum = distr(engine);
		int toNodeNum = distr(engine);
		if (nodeNum == toNodeNum) continue;


		GraphNode* curNode = graph->findNode(nodeNum);
		GraphNode* toNode = graph->findNode(toNodeNum);



		//for (int i = 0; i < curNode.edges.count()&& endges.getSafe(i);i++)

		if (graph->isReachable(curNode, toNode))
		{
			cout << "reachable!" << endl;
		}
		else
		{
			cout << "not reachable!" << endl;

		}
	}

	/*for (int i = 0; i < curNode->edges.size(); i++)
	{
		GraphEdge* next = curNode->edges[i];
		GraphNode* next = curNode->edges[i]->getNext(curNode);
		if (next != nullptr)
		{

			if (isVisited == true)
				continue;

		}

	}*/


	clock_t elapsed = clock();


	cout << "elapsed " << elapsed - curtime << "ms for " << trials <<" trials" << endl;

}


