#include "StdAfx.h"
#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

void Graph::readGraph(const string &path)
{
	fstream fileInput(path);
	if (!fileInput)
	{
		cerr << "open " + path + " error!" << endl;
		abort();
	}
	int nodeNum, arcNum;
	fileInput >> nodeNum >> arcNum;
	this->nodeNum = nodeNum;
	this->arcNum = arcNum;

	weight = new double*[nodeNum];
	for (int i = 0; i < nodeNum; i++)
	{
		weight[i] = new double[nodeNum];
	}

	for (int i = 0; i < nodeNum; i++)
	{
		for (int j = 0; i < nodeNum; i++)
		{
			weight[i][j] = 99999;
		}
	}

	int head, tail;
	double weight;
	for (int i = 0; i < arcNum; i++)
	{
		fileInput >> head >> tail >> weight;
		this->weight[head][tail] = weight;
	}
}