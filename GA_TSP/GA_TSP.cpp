// GA_TSP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Graph.h"
#include "Gene.h"
#include "Grefenstette.h"
#include <ctime>
#include <cstdlib>

using namespace std;

const int iterTimes = 100;			// ��������
int _tmain(int argc, _TCHAR* argv[])
{
	srand(static_cast<unsigned short>(time(0)));
	Graph graph;
	graph.readGraph(".\\st70.tsp");
	Gene::num = 8;
	Gene::bitNum = graph.nodeNum;
	
	Gene *geneArray = new Gene[Gene::num];
	for (int i = 0; i < Gene::num; i++)
	{
		geneArray[i].init();
	}

	for (int i = 0; i < iterTimes; i++)
	{	
		for (int j = 0; j < Gene::num; j++)
		{
			geneArray[j].fitnessFunction(graph);
			if (geneArray[j].fitness < Gene::minFitness)
			{
				Gene::minFitness = geneArray[j].fitness;
				Gene::TSPpath.clear();
				for (int k = 0; k < Gene::bitNum; k++)
				{
					Gene::TSPpath.push_back(geneArray[j].geneSequence[k]);
				}
			}
			Grefenstette::coding(geneArray[j].geneSequence, Gene::bitNum);
		}

		cout << endl;
		cout << "�� " << i << " �ε����Ľ��Ϊ��" << endl;
		cout <<  "Gene::minFitness = " << Gene::minFitness  << endl;

		Gene::randSwap(geneArray, graph);

		for (int j = 0; j < Gene::num; j++)
		{
			geneArray[j].variation();
		}

		for (int j = 0; j < Gene::num; j++)
		{
			Grefenstette::Decoding(geneArray[j].geneSequence, Gene::bitNum);

		}


		//for (int j = 0; j < Gene::num; j++)
		//{
		//	for (int k = 0; k < Gene::bitNum; k++)
		//	{
		//		cout << geneArray[j].geneSequence[k] << " ";
		//	}
		//	cout << endl;
		//}

	}

	// ������Ž��
	cout << endl;
	cout << "���� " << iterTimes << " �ε����Ž��Ϊ��" << endl;
	cout <<  "Gene::minFitness = " << Gene::minFitness  << endl;
	cout << "TSP��·Ϊ��" << endl;

	for (int i = 0; i < Gene::TSPpath.size(); i++)
	{
		cout << Gene::TSPpath[i] << " ";
	}
	cout << endl;

	return 0;
}

