#pragma once
#include <vector>
#include "Graph.h"

class Gene
{
public:
	static double minFitness;
	static vector<int> TSPpath;
	int *geneSequence;			// ��������
	static int num;				// ��������
	static int bitNum;			// ���г���
	double fitness;				// ������
	double posibility;			// ѡ��ĸ���
	static double upBond;		// �����Ժ����Ͻ�
	static double lowBond;		// �����Ժ����½�
	
	Gene(void);
	~Gene(void);

	// ������ɳ�ʼ����������
	void init();

	//����
	void variation(); 
	//��ĳ�ڵ㿪ʼ�����������У����Ƶ��µĸ���
	static void swapGene(const Gene &gene0, const Gene &gene1, Gene &gene2, Gene &gene3);
	
	 //�������������
	void fitnessFunction(const Graph &graph);
	//���ѡ�񽻻�
	static void randSwap(Gene *&gene, const Graph &graph);
	//���ѡ�񽻻�����
	static void randSelect(Gene *gene,int &oder0 ,int &oder1);

	//��������Ϊ����n��0-1�������
	static void get_rand(double &x, double &y);
};

