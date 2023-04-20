#include "gantoApi.cpp"
#include <iostream>

void addTableTest(){
	
	vector<tuple<string, int>> columns = {{"name", 0}, {"age", 1}, {"location", 0}};
	vector<int> keypos = {0};
	vector<int> requiredPos;
	cout << addTable("test", columns, keypos) << endl;
}






int main(){
	addTableTest();

	return 0;
}