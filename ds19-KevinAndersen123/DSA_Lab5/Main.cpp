#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "NodeData.h"
#include "Graph.h"
#include <map>

typedef GraphArc<NodeData, int> Arc;
typedef GraphNode<NodeData, int> Node;
void visit(Node* t_node)
{
	std::cout << "Visiting: " << t_node->m_data.m_name << std::endl;
}

int main()
{
	// Create a graph with capacity for 30 nodes.
	// Templates parameters are NodeType (std::string), ArcType (int)
	Graph<NodeData, int> myGraph(30);
	std::map<std::string, int> myMap;
	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	// Create each node, and assign a name (nodeLabel) from the text file
	myfile.open("nodes.txt");
	while (myfile >> nodeData.m_name >> nodeData.m_xPos >>nodeData.m_yPos)
	{
		myGraph.addNode(nodeData, nodeIndex);
		myMap[nodeData.m_name] = nodeIndex;
		nodeIndex++;
	}
	myfile.close();

	// Wire up the graph by creating arcs between nodes.
	myfile.open("arcs.txt");
	std::string from, to;
	int weight;
	while (myfile >> from >> to >> weight)
	{
		myGraph.addArc(myMap[from], myMap[to], weight);
	}

	myfile.close();
	std::vector<Node*> m_path;
	myGraph.aStar(myGraph.m_nodes[myMap["1"]], myGraph.m_nodes[myMap["d"]], visit, m_path);
	system("pause");
}