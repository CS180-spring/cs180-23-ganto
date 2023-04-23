#include "gantoApi.cpp"
#include <iostream>
api t = api();

void addTableTest(){
	cout << "Add Table Tests" << endl;
	vector<tuple<string, int>> columns = {{"name", 0}, {"age", 1}, {"location", 0}};
	vector<int> keys = {0};
	vector<int> requiredPos;
	cout << "\tBasic Test: ";
	if(true == t.addTable("test", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tValidTable: ";
	if(true == t.addTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tInvalidTable: ";
	if(false == t.addTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
	
	
	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tDuplicateTable: ";
	if(false == t.addTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
}

void updateTableTest(){
	cout << "Update Table Tests" << endl;
	vector<tuple<string, int>> columns = {{"time", 1}, {"distance", 1}, {"personality", 0}};
	vector<int> keys = {0};
	vector<int> requiredPos;
	cout << "\tAdd Column Test: ";
	if(true == t.apiAddColumn("test", columns))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
}

void deleteTableTest(){
	cout << "Delete Table Tests" << endl;
	vector<tuple<string, int>> columns = {{"name", 0}, {"age", 1}, {"location", 0}};
	vector<int> keys = {0};
	vector<int> requiredPos;
	cout << "\tBasic Test: ";
	if(true == t.apiRemoveTable("test"))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
}

void readTableTest(){
	cout << "Read Table Tests" << endl;

	vector<tuple<string, int>> columns = {{"name", 0}, {"age", 1}, {"location", 0}};
	vector<int> keys = {0};
	vector<int> requiredPos;
	t.addTable("test", columns, keys);

	vector<string> columnChoice = {"column1", "column2"};
	cout << "\tTableDoesNotExist: ";
	if(get<0>(t.apiReadTable("nonexistentTable", columnChoice)).empty() && get<1>(t.apiReadTable("nonexistentTable", columnChoice)).empty())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tColuimnsDoNotExist: ";
	if(false == t.addTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

}




int main(){
	addTableTest();
	updateTableTest();
	deleteTableTest();
	readTableTest();
	return 0;
}