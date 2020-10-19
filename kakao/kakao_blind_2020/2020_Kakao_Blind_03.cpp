#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	
	//자바 1 파이선 2 cpp 3
	//frontend 1 backend 2
	//junior 1 senior 2
	//pizza 1 chicken 2

	list<vector<int>> DB;

	for (int i = 0; i < info.size(); i++) {
		//추출
		vector<int> vec;
		
		istringstream ss(info[i]);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' '))
		{
			if (!stringBuffer.compare("java")) {
				vec.push_back(1);
			}
			else if (!stringBuffer.compare("python")) {
				vec.push_back(2);
			}
			else if (!stringBuffer.compare("cpp")) {
				vec.push_back(3);
			}
			
			else if (!stringBuffer.compare("frontend")) {
				vec.push_back(1);
			}
			else if (!stringBuffer.compare("backend")) {
				vec.push_back(2);
			}

			else if (!stringBuffer.compare("junior")) {
				vec.push_back(1);
			}
			else if (!stringBuffer.compare("senior")) {
				vec.push_back(2);
			}

			else if (!stringBuffer.compare("pizza")) {
				vec.push_back(1);
			}
			else if (!stringBuffer.compare("chicken")) {
				vec.push_back(2);
			}

			else {
				vec.push_back(atoi(stringBuffer.c_str()));
			}
		}

		DB.push_back(vec);
	}

	for (int i = 0; i < query.size(); i++) {
		string quer = query[i];

		list<vector<int>> DBCP = list<vector<int>>(DB);

		istringstream ss(query[i]);
		string buff;

		vector<int> queryV(4,0);
		while (getline(ss, buff, ' '))
		{
			if (!buff.compare("and") || !buff.compare("-")) continue;

			if (!buff.compare("java")) {
				queryV[0] = 1;
			}
			else if (!buff.compare("python")) {
				queryV[0] = 2;
			}
			else if (!buff.compare("cpp")) {
				queryV[0] = 3;
			}

			else if (!buff.compare("frontend")) {
				queryV[1] = 1;
			}
			else if (!buff.compare("backend")) {
				queryV[1] = 2;
			}

			else if (!buff.compare("junior")) {
				queryV[2] = 1;
			}
			else if (!buff.compare("senior")) {
				queryV[2] = 2;
			}

			else if (!buff.compare("pizza")) {
				queryV[3] = 1;
			}
			else if (!buff.compare("chicken")) {
				queryV[3] = 2;
			}

			else {
				queryV[4] = atoi(buff.c_str());
			}
		}

		list<vector<int>>::iterator iter = DBCP.begin();

		while (iter != DBCP.end()) {

			if (queryV[0] != 0 && (*iter)[0] != queryV[0]) {
				iter = DBCP.erase(iter);
			}
			else if (queryV[1] != 0 && (*iter)[1] != queryV[1]) {
				iter = DBCP.erase(iter);
			}
			else if (queryV[2] != 0 && (*iter)[2] != queryV[2]) {
				iter = DBCP.erase(iter);
			}
			else if (queryV[3] != 0 && (*iter)[3] != queryV[3]) {
				iter = DBCP.erase(iter);
			}
			else if ((*iter)[4] < queryV[4]) {
				iter = DBCP.erase(iter);
			}
			else {
				iter++;
			}
		}

		answer.push_back(DBCP.size());
	}

	return answer;
}