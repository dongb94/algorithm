//
// Created by Donggeon Byeon on 2024-10-15.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// back tracking
void backtrack(const vector<int>& load, vector<int>& currentTruckWeigths, int M, int index, int& answer, int currentTruckNum)
{
	if( currentTruckNum >= answer) return;
	if(index == load.size())
	{
		answer = std::min(answer, currentTruckNum);
		return;
	}
	if(load[index] > M)
	{
		answer = -1;
		return;
	}

	for(int i = 0; i < currentTruckWeigths.size(); i++)
	{
		if(currentTruckWeigths[i] + load[index] <= M)
		{
			currentTruckWeigths[i] += load[index];
			cout << "[" << currentTruckWeigths[i] << "," << load[index] << "]" <<endl;
			backtrack(load, currentTruckWeigths, M, index + 1, answer, currentTruckNum);
			currentTruckWeigths[i] -= load[index];
		}
	}

	currentTruckWeigths.push_back(load[index]);
	cout << "[new ," << load[index] << "]" <<endl;
	backtrack(load, currentTruckWeigths, M, index + 1, answer, currentTruckNum + 1);
	currentTruckWeigths.pop_back();
}

int solution(int M, vector<int> load) {
	int answer = load.size();

	vector<int> truck;
	backtrack(load, truck, M, 0, answer, 0);

	return answer;
}