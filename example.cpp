

int main()
{

	Graph* graph = new Graph();
	int graphCount = 68;

	for (int i = 0; i < graphCount; i++) {
		GraphNode* crp = new GraphNode;
		graph->addNode(crp);
	}




	vector<int> nodeTable;
	vector<int> edgeTable;


	int nodeNum = 25;
	GraphNode* curNode = graph->findNode(nodeNum);

	bool isVisited = false;
	//for (int i = 0; i < curNode.edges.count()&& endges.getSafe(i);i++)
	for (int i = 0; i < curNode->edges.size(); i++)
	{
		GraphEdge* next = curNode->edges[i];
		GraphNode* next = curNode->edges[i]->getNext(curNode);
		if (next != nullptr)
		{

			if (isVisited == true)
				continue;

		}

	}



}


