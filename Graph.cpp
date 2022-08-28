#pragma once
#include <iostream>
#include <vector>
#pragma once

#define MAX_EDGE 6
#define MAX_NODES 5242
#define MAX_EDGES 48880

class GraphNode;
class GraphEdge;





typedef struct GraphRoute {
	int edgeId;
	int nodeId;
};
typedef struct TotalRoute {
	std::vector<GraphRoute> route;
};

class GraphNode {
	// Method Section
public:
	GraphNode();
	GraphNode(int nodeId);
	int addEdge(GraphEdge* edge);
	
	GraphEdge* findEdge(int edgeNum);
	
	

	

protected:
private:

	//Data & Interface Section
public:
	//TrailPoint* point;
	GraphEdge* edges[MAX_EDGE];
	int nodeId;
	int edgeCnt = 0;
protected:
private:
};


class GraphEdge {
	// Method Section
public:
	GraphEdge(GraphNode* from, GraphNode* to, int trailNum);
	GraphEdge(int trailNum);
	GraphNode* getNext(GraphNode* from);
protected:
private:

	//Data & Interface Section
public:
	GraphNode* from;
	GraphNode* to;
	int edgeId;
	int trailNum;

protected:
private:
};


class Graph {
	// Method Section
public:
	std::vector<GraphEdge*> edgeList;
	std::vector<GraphNode*> nodeList;
	int edgeCnt = 0;
	int nodeCnt = 0;
	void addNode(GraphNode* node);
	GraphNode* findNode(int nodeId);


	GraphEdge* findGraphEdge(int edgeId);


	int addEdge(GraphEdge* edge);
	bool isReachable(GraphNode* from, GraphNode* to);
	bool dfs(GraphNode* from);
protected:
private:
	//Data & Interface Section
public:
	std::vector<int> visited;
	TotalRoute* routes[MAX_EDGE];
	int checkId, fromId, totalRouteIndex;
	bool found = false;
protected:
private:
};

