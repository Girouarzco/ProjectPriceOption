#pragma once
#include <vector>
#include <iostream>
template <class T>
class BinaryTree
{
public : 
	void setDepth(int N)
	{
		this->depth = N;
		_tree.resize(depth + 1);
		for (int i = 0; i <= depth; i++)
		{
			_tree[i].resize(i + 1);
		}
	}
	void SetNode(int n, int i, T x)
	{
		_tree[n][i] = x;
	}
	T GetNode(int n, int i) const
	{
		return _tree[n][i];
	}
	void Display() const
	{
		for (int i = 0; i <= depth; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				std::cout << (double)GetNode(i, j) << " ";
			}
			std::cout << "\n" ;
		}
	}
private : 
	int depth;
	std::vector<std::vector<T>> _tree;
};

