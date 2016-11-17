#pragma once
#include <string>
#include <fstream>

using namespace std;

class Graph
{
public:
	int nodeNum;
	int arcNum;
	double **weight;
	void readGraph(const string &path);
};