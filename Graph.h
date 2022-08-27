#pragma once
#include <iostream>
#include <vector>

class GraphNode;
class GraphEdge;

class GraphNode {
	// Method Section
public:
	std::vector<GraphEdge*>edges;
	int nodeNum;
	int nodeID;
	GraphEdge* findEdge(int edgeNum);
	//TrailPoint* point;
	int addEdge(GraphEdge* edge);
protected:
private:

	//Data & Interface Section
public:
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
	int edgeNum;
	int trailNum;

protected:
private:
};


class Graph {
public:
	std::vector<GraphEdge*> edgeList;
	std::vector<GraphNode*> nodeList;
	int edgeCnt = 0;
	int nodeCnt = 0;
	void addNode(GraphNode* node);
	GraphNode* findNode(int nodeNum);

	GraphEdge* findEdge(GraphEdge* edge);
	GraphEdge* findEdge(int edgeNum);


	int addEdge(GraphEdge* edge);

};

