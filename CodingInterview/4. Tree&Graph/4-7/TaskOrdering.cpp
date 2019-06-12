#include <iostream>
#include <iterator>
#include <queue>
#include <list>

template <class T>
std::list<T> ordering(std::list<T> proj, std::list<std::pair<T,T>> relation) {
	int size = proj.size();
	int *depNum = new int[size];
	bool** rel = new bool*[size];
	std::queue<int> taskQueue;
	std::list<T> taskList;
	typename std::list<T>::iterator itr;
	for (int i = 0; i < size; i++) {
		rel[i] = new bool[size];
		depNum[i] = 0;
		for (int j = 0; j < size; j++) {
			rel[i][j] = false;
		}
	}

	for (std::pair<T, T> pair : relation) {
		int first = 0;
		int second = 0;

		itr = proj.begin();
		while (pair.first != *itr) {
			first++;
			itr++;
		}
		itr = proj.begin();
		while (pair.second != *itr) {
			second++;
			itr++;
		}
		
		rel[first][second] = true;
		depNum[second]++;
	}

	for (int i = 0; i < size; i++) {
		if (depNum[i] == 0) taskQueue.push(i);
	}
	while (taskQueue.size() != 0) {
		int next = taskQueue.front();
		taskQueue.pop();
		depNum[next] = -1;
		for (int i = 0; i < size; i++) {
			if (rel[next][i]) {
				depNum[i]--;
				if (depNum[i] == 0) taskQueue.push(i);
			}
		}
		itr = proj.begin();
		while (next != 0) {
			next--;
			itr++;
		}
		taskList.push_back(*itr);
	}
	for (int i = 0; i < size; i++) {
		printf("%d : %d\n", i, depNum[i]);
		try {
			if (depNum[i] != -1) throw std::invalid_argument("circulation");
		}
		catch (std::invalid_argument& e) {
			printf("circulation error");
			exit(0);
		}
	}
	return taskList;
}

int main() {
	std::list<char> project;
	std::list<std::pair<char, char> > relation;

	project.push_back('a');
	project.push_back('b');
	project.push_back('c');
	project.push_back('d');
	project.push_back('e');
	project.push_back('f');

	relation.push_back(std::pair<char,char>('a', 'd'));
	relation.push_back(std::pair<char, char>('f', 'b'));
	relation.push_back(std::pair<char, char>('f', 'a'));
	relation.push_back(std::pair<char, char>('b', 'd'));
	relation.push_back(std::pair<char, char>('d', 'c'));

	project = ordering(project, relation);

	for (char proj : project) {
		printf("%c", proj);
	}
}