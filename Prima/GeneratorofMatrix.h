#pragma once
#include <iostream>


vector<vector<int>> Generator(int n)
{
	if (n <= 1)
	{
		throw exception("Корявая матрица");
	}
	vector<vector<int>> arr;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(n);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < i; ++k)
		{
			arr[i][k] = arr[k][i];
		}
		for (int k = i; k < n; ++k)
		{
			if (i == k)
				arr[i][k] = 0;
			else
				arr[i][k] = rand() % 9+1;
		}
	}
	return arr;
}

void WriteMatrixtoFile(string txt, vector<vector<int>>& arr)
{
	ofstream file;
	if(!file.is_open())
		file.open(txt);
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int k = 0; k < arr.size(); ++k)
		{
			file << arr[i][k] << " ";
		}
		file << endl;
	}
	file.close();
}