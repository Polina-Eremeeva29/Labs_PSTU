#pragma once
#include <iostream>
#include <vector>
#include "glut.h"
#include <string>
using namespace std;

extern int maxSize;
extern const int za;
extern int WinW, WinH, R;
template <typename T>
class Graph
{
public:
	Graph();
	~Graph();
	int GetVertPos(const T& vertex);
	bool IsEmpty();
	bool IsFull();
	int GetAmountOfVerts();
	int GetAmountOfEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void InsertVertex(const T& vertex);
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void FillLabels(T& startVertex);
	int Dijsktra(T& startVertex);
	bool AllVisited(bool* visitedVerts);
	void Print();
	void DrawGraph();
	void fillmatrix(int mat[6][6]);
private:
	T adjMatrix[20][20];
	vector<T> vertList;
	vector<int> labelList;
};

extern Graph <int> graph;

template <typename T>
void Graph<T>::fillmatrix(int mat[6][6])
{
	for (int i = 0; i < za; i++)
	{
		for (int j = 0; j < za; j++)
		{
			if (i == j)
			{
				mat[i][j] = 0;
			}
			else
			{
				mat[i][j] = adjMatrix[i][j];
			}
		}
	}
}


template <typename T>
Graph<T>::Graph()
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template <typename T>
Graph<T>::~Graph()
{

}

template <typename T>
int Graph<T>::GetVertPos(const T& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i)
	{
		if (this->vertList[i] == vertex) return i;
	}
	return -1;
}

template <typename T>
bool Graph<T>::IsEmpty()
{
	if (this->vertList.size() != 0) return false;
	else return true;
}

template <typename T>
bool Graph<T>::IsFull()
{
	return (vertList.size() == maxSize);
}

template <typename T>
int Graph<T>::GetAmountOfVerts()
{
	return this->vertList.size();
}

template <typename T>
int Graph<T>::GetAmountOfEdges()
{
	int amount = 0;
	if (!this->IsEmpty())
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->adjMatrix[i][j] == this->adjMatrix[j][i] && this->adjMatrix[i][j] != 0) amount += 1;
			}
		}
		return (amount / 2);
	}
	else return 0;
}

template <typename T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2)
{
	if (!this->IsEmpty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	else return 0;
}

template <typename T>
vector<T> Graph<T>::GetNbrs(const T& vertex)
{
	vector<T> nbrsList;
	int vertPos = this->GetVertPos(vertex);
	if (vertPos != (-1))
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			if (this->adjMatrix[vertPos][i] != 0 && this->adjMatrix[i][vertPos] != 0) nbrsList.push_back(this->vertList[i]);
		}
	}
	return nbrsList;
}

template <typename T>
void Graph<T>::InsertVertex(const T& vertex)
{
	if (!this->IsFull()) this->vertList.push_back(vertex);
	else
	{
		cout << "Граф заполнен. Невохможно добавить новую вершину" << endl;
		return;
	}
}

template <typename T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0 && this->adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << "Ребро между этими вершинами уже есть" << endl;
			return;
		}
		else
		{
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Одной из вершин (или обеих)нет в графе" << endl;
		return;
	}
}

template <typename T>
void Graph<T>::FillLabels(T& startVertex)
{
	for (int i = 0, size = vertList.size(); i < size; ++i)
	{
		labelList.push_back(1000000);

	}
	int pos = GetVertPos(startVertex);
	labelList[pos] = 0;
}

template <typename T>
bool Graph<T>::AllVisited(bool* visitedVerts)
{
	bool flag = true;
	for (int i = 0; i < vertList.size(); ++i)
	{
		if (visitedVerts[i] != true) flag = false;
	}
	return flag;
}

template <typename T>
int Graph<T>::Dijsktra(T& startVertex)
{
	FillLabels(startVertex);
	bool* visitedVerts = new bool[vertList.size()];
	for (int i = 0; i < vertList.size(); ++i)
	{
		visitedVerts[i] = false;
	}

	for (int i = 0; i < vertList.size(); ++i)
	{
		for (int j = 0; j < vertList.size(); ++j)
		{
			if (adjMatrix[i][j] < 0) return -1;
			if (GetVertPos(startVertex) == -1) return -2;
		}
	}

	T curSrc;
	int counter = 0;
	int minLabel = 1000000;
	vector<T>neighbors = GetNbrs(startVertex);
	for (int i = 0; i < neighbors.size(); ++i)
	{
		int startLabel = labelList[GetVertPos(startVertex)];
		int weight = GetWeight(startVertex, neighbors[i]);
		int nIndex = GetVertPos(neighbors[i]);
		int nextLabel = labelList[nIndex];
		if (startLabel + weight < nextLabel) labelList[nIndex] = startLabel + weight;
		if (labelList[nIndex] < minLabel) minLabel = labelList[nIndex];
	}
	for (int i = 0; i < neighbors.size(); ++i)
	{
		if (labelList[GetVertPos(neighbors[i])] != 1000000) counter += 1;
		if (counter == neighbors.size()) visitedVerts[GetVertPos(startVertex)] = true;
	}
	for (int i = 0; i < neighbors.size(); ++i)
	{
		if (labelList[GetVertPos(neighbors[i])] == minLabel) curSrc = neighbors[i];
	}

	while (!AllVisited(visitedVerts))
	{
		neighbors = GetNbrs(curSrc);
		int count = 0;
		int minLabel = 1000000;
		for (int i = 0; i < neighbors.size(); ++i)
		{
			int curLabel = labelList[GetVertPos(curSrc)];
			int weight = GetWeight(curSrc, neighbors[i]);
			int nIndex = GetVertPos(neighbors[i]);
			int nextLabel = labelList[nIndex];
			if (curLabel + weight < nextLabel) labelList[nIndex] = curLabel + weight;
			if (labelList[nIndex] < minLabel && visitedVerts[nIndex] != true) minLabel = labelList[nIndex];
			count += 1;
		}
		if (count == neighbors.size()) visitedVerts[GetVertPos(curSrc)] = true;
		for (int i = 0; i < neighbors.size(); ++i)
		{
			if (labelList[GetVertPos(neighbors[i])] == minLabel && visitedVerts[GetVertPos(neighbors[i])] != true) curSrc = neighbors[i];
		}
	}

	for (int i = 0; i < GetVertPos(startVertex); ++i)
	{
		cout << "Кратчайшее расстояние от вершины:" << startVertex << " "
			<< "До вершины:" << vertList[i] << " " << "равно" << "-" << labelList[GetVertPos(vertList[i])] << endl;
	}
	for (int i = GetVertPos(startVertex) + 1; i < vertList.size(); ++i)
	{
		cout << "Кратчайшее расстояние от вершины:" << startVertex << " "
			<< "До вершины:" << vertList[i] << " " << "равно" << "-" << labelList[GetVertPos(vertList[i])] << endl;
	}
}

template <typename T>
void Graph<T>::Print()
{
	if (!this->IsEmpty())
	{
		cout << "Матрица смежности графа:" << endl;
		cout << " " << " ";
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << " " << this->vertList[i] << " ";
		}
		cout << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else cout << "Граф пуст" << endl;
}



Graph<int> makeGraph();
extern struct vertCoord;
struct vertCoord
{
	int x, y;
};
extern vertCoord vertC[20];
void setCoord(int i, int n);
void drawCircle(int x, int y, int R);
void drawText(int num, int x1, int y1);
void drawVertex(int n);
void drawLine(int text, int x0, int y0, int x1, int y1);
void reshape(int w, int h);
void display();

template <typename T>
void Graph<T>::DrawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; ++i)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}
