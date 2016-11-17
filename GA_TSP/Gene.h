#pragma once
#include <vector>
#include "Graph.h"

class Gene
{
public:
	static double minFitness;
	static vector<int> TSPpath;
	int *geneSequence;			// 基因序列
	static int num;				// 基因数量
	static int bitNum;			// 序列长度
	double fitness;				// 适用性
	double posibility;			// 选择的概率
	static double upBond;		// 适用性函数上界
	static double lowBond;		// 适用性函数下界
	
	Gene(void);
	~Gene(void);

	// 随机生成初始化基因序列
	void init();

	//变异
	void variation(); 
	//从某节点开始交换基因序列，复制到新的副本
	static void swapGene(const Gene &gene0, const Gene &gene1, Gene &gene2, Gene &gene3);
	
	 //计算基因适用性
	void fitnessFunction(const Graph &graph);
	//随机选择交换
	static void randSwap(Gene *&gene, const Graph &graph);
	//随机选择交换序列
	static void randSelect(Gene *gene,int &oder0 ,int &oder1);

	//函数功能为产生n个0-1的随机数
	static void get_rand(double &x, double &y);
};

