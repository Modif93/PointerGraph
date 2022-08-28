#include <iostream>
#include <vector>
using namespace std;

#include "Graph.h"

//////////////////////////
// GraphEdge Source
//////////////////////////

GraphEdge::GraphEdge(GraphNode* from, GraphNode* to, int trailNum)
{
	this->from = from;
	this->to = to;
	this->trailNum = trailNum;
	this->edgeId = trailNum;
}

GraphEdge::GraphEdge(int trailNum)
{
	from = nullptr;
	to = nullptr;
	this->trailNum = trailNum;
	edgeId = -1;
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

GraphNode::GraphNode()
{
	this->nodeId = -1;
	for (int i = 0; i < MAX_EDGE; i++)
	{
		edges[i] = nullptr;
	}
}

GraphNode::GraphNode(int nodeId)
{
	this->nodeId = nodeId;
	for (int i = 0; i < MAX_EDGE; i++)
	{
		edges[i] = nullptr;
	}
}

GraphEdge* GraphNode::findEdge(int edgeId)
{
	for (int i = 0; i < MAX_EDGE;i++) {
		if (edges[i] == nullptr) return nullptr;


		if (edges[i]->edgeId == edgeId) return edges[i];
	}
	return nullptr;
}


int GraphNode::addEdge(GraphEdge* edge)
{
	if (this == nullptr) return 1;
	//already inserted
	for(int i=0;i< MAX_EDGE;i++)
	{
		if (edges[i] != nullptr)
		{
			if (edges[i]->edgeId == edge->edgeId)
				return 1;
		}
	}
	
	
	//reached max
	if (edgeCnt == MAX_EDGE) return 1;
	edges[edgeCnt] = edge;
	edgeCnt++;

	return 0;
}


//////////////////////////
// Graph Source
//////////////////////////

void Graph::addNode(GraphNode* node)
{
	nodeList.push_back(node);
	nodeCnt++;
}

GraphNode* Graph::findNode(int nodeId)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList[i]->nodeId == nodeId)
			return nodeList[i];
	}
	return nullptr;
}



GraphEdge* Graph::findGraphEdge(int edgeId)
{
	for (auto i : edgeList)
	{
		if (i->edgeId == edgeId) return i;
	}
	return nullptr;
}

int Graph::addEdge(GraphEdge* edge)
{
	if (edge == nullptr)return 1;
	if (findGraphEdge(edge->edgeId) != nullptr) return 2;


	edge->from->addEdge(edge);
	edge->to->addEdge(edge);
	edgeCnt++;
	

	return 0;
}

bool Graph::isReachable(GraphNode* from, GraphNode* to)
{
	checkId = to->nodeId;
	fromId = from->nodeId;
	cout << "route from "<< from->nodeId <<" to " << checkId << endl;
	

	
	for (int i = 0; i < MAX_EDGE; i++)
		routes[i] = new TotalRoute;

	//do dfs
	bool reachable = dfs(from);
	if (reachable)
	{
		cout << "route : n"<< fromId;
		for (auto& rr : routes[totalRouteIndex]->route) {
			if (rr.nodeId == fromId) continue;
			printf("-(%d)->n%d", rr.edgeId, rr.nodeId);
		}
		cout << endl;
	}
		


	reachable = found;

	found = false;
	visited.clear();

	for (int i = 0; i < MAX_EDGE; i++)
		delete(routes[i]);

	return reachable;
}


bool Graph::dfs(GraphNode* from) {
	if (from == nullptr) return false;
	if (found == true) return found;
	
	//printf("n%d", from->nodeId);

	visited.push_back(from->nodeId);
	

	if (checkId == from->nodeId)
	{
		found = true;
		
		return found;
	}

	for (int i = 0; i < from->edgeCnt; i++) {
		if (found == true) break;
		GraphEdge* edge = from->edges[i];
		if (edge == nullptr) break;
		GraphNode* next = edge->getNext(from);
		if (next == nullptr) continue;
		

		if (fromId == from->nodeId)
		{
			totalRouteIndex = i;
		}

		bool isVisited = false;

		for (auto& vis : visited) {
			if (vis == next->nodeId) {
				isVisited = true; //if visited, skip
				break;
			}
		}

		//recursive
		if (isVisited == false)
		{
			GraphRoute trroute;
			trroute.nodeId = edge->getNext(from)->nodeId;
			trroute.edgeId = edge->edgeId;
			routes[totalRouteIndex]->route.push_back(trroute);
			//printf("->e%d->", edge->trailNum);
			if (dfs(edge->getNext(from)) == true)
			{
				printf(" found!\n");
			}
			else
			{
				if (from->nodeId == fromId)
				{
					
				}
			}
				
		}
		else return false;
	}
	
}
