#include <iostream>
#include <vector>
using namespace std;

#include "Graph.h"

//////////////////////////
//GraphEdge Source
//////////////////////////

GraphEdge::GraphEdge(int trailNum)
{
	from = nullptr;
	to = nullptr;
	this->trailNum = trailNum;
	edgeNum = -1;
}

GraphNode* GraphEdge::getNext(GraphNode* from)
{
	if (this->from == from)
	{
		return this->to;
	}
	else if (this->to == from)
	{
		return this->from;
	}
	else return nullptr;
}


//////////////////////////
// GraphNode Source
//////////////////////////

GraphEdge* GraphNode::findEdge(int edgeNum)
{

}


int GraphNode::addEdge(GraphEdge* edge)
{

	if (findEdge(edge->edgeNum) != nullptr) return 1;
	
	
	edges.push_back(edge);

	return 0;
}


//////////////////////////
// Graph Source
//////////////////////////

void Graph::addNode(GraphNode* node)
{
	node->nodeNum = nodeCnt;
	nodeList.push_back(node);
	nodeCnt++;
}

GraphNode* Graph::findNode(int nodeNum)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList[i]->nodeNum == nodeNum)
			return nodeList[i];
	}
	return nullptr;
}

GraphEdge* Graph::findEdge(GraphEdge* edge)
{

}

GraphEdge* Graph::findEdge(int edgeNum)
{

}

int Graph::addEdge(GraphEdge* edge)
{
	if (findEdge(edge) != nullptr) return 1;

	edge->edgeNum = edgeCnt;
	edge->from->addEdge(edge);
	edge->to->addEdge(edge);
	
	edgeCnt++;

}

