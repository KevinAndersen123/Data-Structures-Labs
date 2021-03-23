#pragma once
#include <string>
struct NodeData
{
	std::string m_name;
	int m_pathCost;
	int m_xPos;
	int m_yPos;
	float m_heuristicVal;
};
