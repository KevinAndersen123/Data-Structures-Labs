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
	std::cout << "Visiting: " << t_node->m_data.m_cityName << std::endl;
}

int main()
{
	// Create a graph with capacity for 25 nodes.
	// Templates parameters are NodeType (std::string), ArcType (int)
	Graph<NodeData, int> myGraph(6);
	std::map<std::string, int> cityMap;
	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	// Create each node, and assign a name (nodeLabel) from the text file
	myfile.open("nodes.txt");
	while (myfile >> nodeData.m_cityName)
	{
		myGraph.addNode(nodeData, nodeIndex);
		cityMap[nodeData.m_cityName] = nodeIndex;
		nodeIndex++;
	}
	myfile.close();

	// Wire up the graph by creating arcs between nodes.
	myfile.open("arcs.txt");
	std::string from, to;
	int weight;
	while (myfile >> from >> to >> weight)
	{
		myGraph.addArc(cityMap[from], cityMap[to], weight);
	}
	myfile.close();
	std::vector<Node*> m_path;
	myGraph.ucs(myGraph.m_nodes[cityMap["Caldor"]], myGraph.m_nodes[cityMap["Faldor"]], visit, m_path);
	system("pause");
}