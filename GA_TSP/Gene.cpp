#include "StdAfx.h"
#include "Gene.h"
#include "Graph.h"
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <iostream>


const double PI = 3.1415926;
using namespace std;

int Gene::num; 
int Gene::bitNum;

double Gene::minFitness = 9999;
vector<int> Gene::TSPpath;

Gene::Gene(void)
{
	geneSequence = new int[Gene::bitNum];
}


Gene::~Gene(void)
{
	delete[] geneSequence;
}

void Gene::init()
{
	for(int i = 0; i < Gene::bitNum; i++)
	{	
		geneSequence[i] = rand()%Gene::bitNum;
		for (int j = 0; j < i; j++)
		{
			if (geneSequence[i] == geneSequence[j])
			{
				i--;
				break;
			}
		}
	}
}

void Gene::swapGene(const Gene &gene0, const Gene &gene1, Gene &gene2, Gene &gene3)
{
	int pos = rand()%Gene::bitNum;
	for (int i = 0; i < pos; i++ )
	{
		gene2.geneSequence[i] = gene0.geneSequence[i];
		gene3.geneSequence[i] = gene1.geneSequence[i];
	}

	for (int i = pos; i < Gene::bitNum; i++ )
	{
		gene2.geneSequence[i] = gene1.geneSequence[i];
		gene3.geneSequence[i] = gene0.geneSequence[i];
	}
}

void Gene::variation()
{
	int pos = rand()%Gene::bitNum;
	geneSequence[pos] = rand()%(Gene::bitNum - pos);
}

void Gene::fitnessFunction(const Graph &graph)
{
	fitness = 0;
	for (int i = 1; i < Gene::bitNum; i++)
	{
		fitness += graph.weight[ geneSequence[i - 1] ][ geneSequence[i] ];
	}
	//cout << "fitness = " << fitness << endl;
}

void Gene::randSwap(Gene *&gene, const Graph &graph)
{

	double sumFitness = 0;
	//Gene::minFitness = 9999;
	for (int i = 0 ; i < Gene::num; i++)
	{
		sumFitness += gene[i].fitness;

	}
	
	double sumPosibility = 0;
	for (int i = 0; i < Gene::num; i++)
	{
		gene[i].posibility =1 - (double)gene[i].fitness/(double)sumFitness;
		sumPosibility += gene[i].posibility;
	}

	for (int i = 0; i < Gene::num; i++)
	{
		gene[i].posibility = (double)gene[i].posibility/(double)sumPosibility;
	}

	Gene *newGene = new Gene[Gene::num];


	for (int i = 0; i < Gene::num; i = i + 2)
	{
		int order0, order1;
		
		Gene::randSelect(gene , order0, order1);		
		Gene::swapGene(gene[order0], gene[order1], newGene[i], newGene[i + 1]);
	}


	delete[] gene;
	gene = newGene;
}

void Gene::randSelect(Gene *gene, int &order0 ,int &order1)
{
	double randNum0, randNum1;
	get_rand(randNum0, randNum1);

	//cout << "randNum0 = " << randNum0 << " " << "randNum1 = " << randNum1 << endl;
	for (int i = 0; i < Gene::num; i++)
	{
		if (randNum0 < gene[i].posibility)
		{
			order0 = i;
			break;
		}
		else
		{
			randNum0 = randNum0 - gene[i].posibility;
		}
	}

	for (int i = 0; i <Gene::num; i++)
	{
		if (randNum1 < gene[i].posibility)
		{
			order1 = i;
			break;
		}
		else
		{
			randNum1 = randNum1 - gene[i].posibility;
		}
	}

	//cout << "oder0 = " << order0 << " " << "order1 = " << order1 << endl; 
}

void Gene::get_rand(double &x, double &y)
{
	int N = 999;
	x = rand()%(N+1)/(float)(N+1);         //生成0-1间的随机数
	y = rand()%(N+1)/(float)(N+1);         //生成0-1间的随机数
}