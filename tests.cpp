#include "gantoApi.cpp"
#include <iostream>
#include <stdio.h>
#include <assert.h>
api t = api();
bool integrationTest = false;	//Use this to turn on/off integration tests

void addTableTest(){
	cout << "Add Table Tests" << endl;
	vector<tuple<string, int>> columns = {{"name", 0}, {"age", 1}, {"location", 0}};
	vector<int> keys = {0};
	vector<int> requiredPos;
	cout << "\tBasic Test:\t\t";
	if(true == t.apiAddTable("test", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tValidTable:\t\t";
	if(true == t.apiAddTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tInvalidTable:\t\t";
	if(false == t.apiAddTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
	
	
	columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
	cout << "\tDuplicateTable:\t\t";
	if(false == t.apiAddTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tKeyIsForeign:\t\t";
	if(true == t.apiAddTable("Foreign", {{"name", 0}, {"birthPlace", 0}}, {}, {make_tuple("People", "name")}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
}

void updateTableTest(){
	cout << "Update Table Tests" << endl;
	vector<tuple<string, int>> columns = {{"time", 1}, {"distance", 1}, {"personality", 0}};
	vector<int> keys = {0};
	vector<int> requiredPos;
	cout << "\tAdd Column Test:\t";
	if(true == t.apiAddColumn("test", columns))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	/*
	cout << "\tColumnUsedAsForeignKey:\t\t";
	if(false == t.apiAddTable("People", columns, keys))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
	*/
}

void deleteTableTest(){
	cout << "Delete Table Tests" << endl;
	t.apiAddTable("DeleteTable", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	t.apiAddTable("ForeignTable", {{"String", 0}, {"Third Thing", 0}}, {}, {{"DeleteTable", "Third Thing"}});
	
	cout << "\tTableUsedAsForeignKey:\t";
	if(false == t.apiRemoveTable("DeleteTable"))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;


	cout << "\tTableWithForeignKey\t";
	if(true == t.apiRemoveTable("ForeignTable") && true == t.apiReadTable("ForeignTable", {}).empty())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tForeignTableRemoved:\t";
	if(true == t.apiRemoveTable("DeleteTable"))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
	
}

void readTableTest(){
	cout << "Read Table Tests" << endl;

	t.apiAddTable("ReadTable", {{"name", 0}, {"age", 1}, {"location", 0}}, {0});
	vector<tuple<string, int, string, bool, bool>> returned;

	cout << "\tValidTwoColumns:\t";
	returned = t.apiReadTable("ReadTable", {"name", "location"});
	bool success = true;
	if(true == returned.empty())
		success = false;
	else if(get<0>(returned[0]) != "name"){
		success = false;
	}
	else if(get<1>(returned[0]) != 0){
		success = false;
	}
	else if(get<2>(returned[0]) != ""){
		success = false;
	}
	else if(get<3>(returned[0]) != true){
		success = false;
	}
	else if(get<4>(returned[0]) != true){
		success = false;
	}
	else if(get<0>(returned[1]) != "location"){
		success = false;
	}
	else if(get<1>(returned[1]) != 0){
		success = false;
	}
	else if(get<2>(returned[1]) != ""){
		success = false;
	}
	else if(get<3>(returned[1]) != false){
		success = false;
	}
	else if(get<4>(returned[1]) != false){
		success = false;
	}
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tTableDoesNotExist:\t";
	if(true == t.apiReadTable("nonexistentTable", {"column1", "column2"}).empty())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tColumnsDoNotExist:\t";
	if(true == t.apiReadTable("ReadTable", {"nonexistentColumn"}).empty())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

}


void addEntryTest(){
	t.apiAddTable("AddEntry", {{"String", 0}, {"Double", 1}}, {0});
	cout << "Add Entry Tests" << endl;
	cout << "\tValidEntry:\t\t";
	if(true == t.apiAddEntry("AddEntry", {{"Valid", 1.0}}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tDuplicateKeyValue:\t";
	if(false == t.apiAddEntry("AddEntry", {{"Valid", 2.0}}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

/*		nullptr doesn't work with variants?
	cout << "\tNullKeyValue:\t\t";
	if(false == t.apiAddEntry("AddEntry", {nullptr, 3.0}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	t.apiSetRequired("AddEntry", "Double", true);
	cout << "\tNullRequiredValue:\t\t";
	if(false == t.apiAddEntry("AddEntry", {"AlsoValid", nullptr}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
*/

}

void updateEntryTest(){
	t.apiAddTable("UpdateEntry", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> returned;
	vector<vector<variant<string, double>>> entries;
	entries.push_back({{"entry1", 10.0, "#1"}});
	entries.push_back({{"entry2", 20.0, "#2"}});
	entries.push_back({{"entry3", 10.3, "#3"}});
	entries.push_back({{"entry4", 14.0, "#4"}});
	entries.push_back({{"entry5", 55.0, "#5"}});
	entries.push_back({{"entry6", 66.6, "#6"}});
	for(int i = 0; i < entries.size(); i++){
		t.apiAddEntry("UpdateEntry", entries[i]);
	}



	cout << "update Entry Tests" << endl;

	cout << "\tNoConditions(string):\t";
	if(true == t.apiUpdateEntry("UpdateEntry", "String", "joe"))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tOneCondition:\t\t";
	if(true == t.apiUpdateEntry("UpdateEntry", "String", {{"Third Thing", 0, "#2"}}, "bob"))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tDuplicateKeyValue:\t";
	if(false == t.apiUpdateEntry("UpdateEntry", "Double", 10))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	/*
	cout << "\tNullKeyValue:\t\t";
	if(true == t.apiUpdateEntry("UpdateEntry", "Double", nullptr))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
	*/

	cout << "\tMultipleConditions:\t";
	if(true == t.apiUpdateEntry("UpdateEntry", "String", {{"Double", 1, 10.0}, {"String", 0, "joe"}}, "zoe"))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
}

void deleteEntryTest(){
	t.apiAddTable("DeleteEntry", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> returned;
	vector<vector<variant<string, double>>> entries;
	entries.push_back({{"entry1", 10.0, "#1"}});
	entries.push_back({{"entry2", 20.0, "#2"}});
	entries.push_back({{"entry3", 10.3, "#3"}});
	entries.push_back({{"entry4", 14.0, "#4"}});
	entries.push_back({{"entry5", 55.0, "#5"}});
	entries.push_back({{"entry6", 66.6, "#6"}});
	for(int i = 0; i < entries.size(); i++){
		t.apiAddEntry("DeleteEntry", entries[i]);
	}



	cout << "delete Entry Tests" << endl;

	cout << "\tValidDeleteWholeEntry:\t";
	if(true == t.apiRemoveEntry("DeleteEntry", {{"Third Thing", 0, "#1"}}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;


	cout << "\tValidDeleteAll:\t\t";
	if(true == t.apiRemoveEntry("DeleteEntry", "String", {}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tDeleteKeyValue:\t\t";
	if(false == t.apiRemoveEntry("DeleteEntry", "Double", {}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;


	cout << "\tEntryDoesNotExist:\t";
	if(false == t.apiRemoveEntry("DeleteEntry", "Not a real column", {}))
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;


	//Integration tests
	if(false == integrationTest)
		return;
	cout << "\tDeletedEntry:\t" << endl;
	returned = t.apiReadEntry("DeleteEntry", {"String"});
	if(nullptr == &get<0>(returned[0][0]))	//Deleted column elements return nullptr. I think this allows for that check?
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

}


void readEntryTest(){
	t.apiAddTable("ReadEntry", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> returned;
	vector<vector<variant<string, double>>> entries;
	entries.push_back({{"entry1", 10.0, "#1"}});
	entries.push_back({{"entry2", 20.0, "#2"}});
	entries.push_back({{"entry3", 10.3, "#3"}});
	entries.push_back({{"entry4", 14.0, "#4"}});
	entries.push_back({{"entry5", 55.0, "#5"}});
	entries.push_back({{"entry6", 66.6, "#6"}});
	for(int i = 0; i < entries.size(); i++){
		t.apiAddEntry("ReadEntry", entries[i]);
	}



	cout << "Read Entry Tests" << endl;
	
	cout << "\tNoCondition:\t\t";
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"});
	bool success = true;
	for(int i = 0; i < entries.size(); i++){
		if(get<0>(entries[i][0]) != get<0>(returned[i][0])){
			success = false;
			break;
		}
		else if(get<1>(entries[i][1]) != get<1>(returned[i][1])){
			success = false;
			break;
		}
		else if(get<0>(entries[i][2]) != get<0>(returned[i][2])){
			success = false;
			break;
		}
	}
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tOneCondition:\t\t";
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"}, {{"Double", 1, 10.0}});
	for(int i = 1; i < entries.size(); i++){
		if(get<0>(entries[i][0]) != get<0>(returned[i-1][0])){
			success = false;
			break;
		}
		else if(get<1>(entries[i][1]) != get<1>(returned[i-1][1])){
			success = false;
			break;
		}
		else if(get<0>(entries[i][2]) != get<0>(returned[i-1][2])){
			success = false;
			break;
		}
	}
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tMultipleConditions:\t";
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"}, {{"Double", 1, 10.0}, {"String", 0, "entry3"}});
	if(get<0>(entries[2][0]) != get<0>(returned[0][0])){
		success = false;
	}
	else if(get<1>(entries[2][1]) != get<1>(returned[0][1])){
		success = false;
	}
	else if(get<0>(entries[2][2]) != get<0>(returned[0][2])){
		success = false;
	}

	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tNoResults:\t\t";
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"}, {{"Double", 3, 10.0}, {"String", 0, "entry3"}});
	if(0 == returned.size())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
		
	cout << "\tInvalidOperator:\t";
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"}, {{"String", 3, "entry1"}});
	if(0 == returned.size())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tWrongType:\t\t";
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"}, {{"Double", 3, "entry1"}});
	if(0 == returned.size())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

}

void apiAddIndexTest(){
	t.apiAddTable("IndexTest", {{"name", 0}, {"age", 1}, {"location", 0}}, {0});
	vector<vector<variant<string, double>>> entries;
	entries.push_back({{"entry1", 10.0, "#1"}});
    	entries.push_back({{"entry2", 20.0, "#2"}});
    	entries.push_back({{"entry3", 10.3, "#3"}});
    	entries.push_back({{"entry4", 14.0, "#4"}});
    	entries.push_back({{"entry5", 55.0, "#5"}});
    	entries.push_back({{"entry6", 66.6, "#6"}});
    	for(int i = 0; i < entries.size(); i++){
        	t.apiAddEntry("IndexTest", entries[i]);
    	}
	
	cout << "Add Index Text" << endl;
	
	cout << "\tBasic Test:\t\t";
	if (true == t.apiAddIndex("IndexTest", "location"))
    		cout << "Success" << endl;
	else
    		cout << "Failed" << endl;
	cout << "\tInvalidTable:\t\t";
	if (false == t.apiAddIndex("NonExistentTable", "location"))
    		cout << "Success" << endl;
	else
    		cout << "Failed" << endl;

	cout << "\tInvalidColumn:\t\t";
	if (false == t.apiAddIndex("IndexTest", "nonExistentColumn"))
    		cout << "Success" << endl;
	else
    		cout << "Failed" << endl;

	cout << "\tDuplicateIndex:\t\t";
	if (false == t.apiAddIndex("IndexTest", "location"))
    		cout << "Success" << endl;
	else
    		cout << "Failed" << endl;
}



void writeTablesTest(){
	//t.apiSaveToFile();
	t.apiLoadFile("tmpName.json");
	cout << "\tNoCondition:\t\t";
	vector<vector<variant<string, double>>> returned;
	vector<vector<variant<string, double>>> entries;
	entries.push_back({{"entry1", 10.0, "#1"}});
	entries.push_back({{"entry2", 20.0, "#2"}});
	entries.push_back({{"entry3", 10.3, "#3"}});
	entries.push_back({{"entry4", 14.0, "#4"}});
	entries.push_back({{"entry5", 55.0, "#5"}});
	entries.push_back({{"entry6", 66.6, "#6"}});
	returned = t.apiReadEntry("ReadEntry", {"String", "Double", "Third Thing"});
	bool success = true;
	for(int i = 0; i < entries.size(); i++){
		if(get<0>(entries[i][0]) != get<0>(returned[i][0])){
			success = false;
			break;
		}
		else if(get<1>(entries[i][1]) != get<1>(returned[i][1])){
			success = false;
			break;
		}
		else if(get<0>(entries[i][2]) != get<0>(returned[i][2])){
			success = false;
			break;
		}
	}
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
}

void largeTableTest(){
	t.apiLoadFile("LargeTable.json");
	vector<vector<variant<string, double>>> returned;

	returned = t.apiReadEntry("LargeTable", {"Number"}, {{"Number", 1, 50.0}});
	cout << returned.size();
}

void readMultipleEntryTest(){
	t.apiAddTable("ReadMultEntries", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> returned;
	vector<vector<variant<string, double>>> entries;
	entries.push_back({{"entry1", 10.0, "#1"}});
	entries.push_back({{"entry2", 20.0, "#2"}});
	entries.push_back({{"entry3", 10.3, "#3"}});
	entries.push_back({{"entry4", 14.0, "#4"}});
	entries.push_back({{"entry5", 55.0, "#5"}});
	entries.push_back({{"entry6", 66.6, "#6"}});
	for(int i = 0; i < entries.size(); i++){
		t.apiAddEntry("ReadMultEntries", entries[i]);
	}

	t.apiAddTable("ReadMultEntries_2", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> entries_2;
	entries_2.push_back({{"entry7", 200.0, "#1"}});
	entries_2.push_back({{"entry8", 253.8, "#2"}});
	entries_2.push_back({{"entry9", 473.09, "#3"}});
	entries_2.push_back({{"entry10", 300.02, "#4"}});
	entries_2.push_back({{"entry11", 6.7, "#5"}});
	entries_2.push_back({{"entry12", 78.2, "#6"}});
	for(int i = 0; i < entries_2.size(); i++){
		t.apiAddEntry("ReadMultEntries_2", entries_2[i]);
	}

	cout << "Read Multiple Entry Tests" << endl;
	
	cout << "\tNoCondition:\t\t";
	returned = t.apiReadEntry({"ReadMultEntries", "ReadMultEntries_2"}, {{"String", "Double", "Third Thing"},{"String", "Double", "Third Thing"}});
	bool success = true;
	for(int i = 0; i < entries.size(); i++){
		if(get<0>(entries[i][0]) != get<0>(returned[i][0])){
			success = false;
			break;
		}
		else if(get<1>(entries[i][1]) != get<1>(returned[i][1])){
			success = false;
			break;
		}
		else if(get<0>(entries[i][2]) != get<0>(returned[i][2])){
			success = false;
			break;
		}
	}
	for(int i = 0; i < entries_2.size(); i++){
		if(get<0>(entries_2[i][0]) != get<0>(returned[i+entries.size()][0])){
			success = false;
			break;
		}
		else if(get<1>(entries_2[i][1]) != get<1>(returned[i+entries.size()][1])){
			success = false;
			break;
		}
		else if(get<0>(entries_2[i][2]) != get<0>(returned[i+entries.size()][2])){
			success = false;
			break;
		}
	}
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tOneCondition:\t\t";
	vector<vector<string>> displayColumns = {{"String", "Double", "Third Thing"}, {"String", "Double", "Third Thing"}};
    vector<vector<tuple<string, int, variant<string, double>>>> conditions = {{{"String", 0, "entry1"}}, {{"Double", 1, 10.0}}};
    returned = t.apiReadEntry({"ReadMultEntries", "ReadMultEntries_2"}, displayColumns, conditions);
	if(get<string>(entries[0][0]) != get<string>(returned[0][0])){
		success = false;
	}
	if(get<string>(entries_2[0][0]) != get<string>(returned[1][0])){
		success = false; 
	}
	if(get<double>(entries_2[0][1]) != get<double>(returned[1][1])){
		success = false; 
	}
	if(get<string>(entries_2[0][2]) != get<string>(returned[1][2])){
		success = false; 
	}
	if(get<string>(entries_2[1][0]) != get<string>(returned[2][0])){
		success = false;
	}
	if(get<double>(entries_2[1][1]) != get<double>(returned[2][1])){
		success = false; 
	}
	if(get<string>(entries_2[1][2]) != get<string>(returned[2][2])){
		success = false; 
	}
	//4th
	if(get<string>(entries_2[2][0]) != get<string>(returned[3][0])){
		success = false;
	}
	if(get<double>(entries_2[2][1]) != get<double>(returned[3][1])){
		success = false; 
	}
	if(get<string>(entries_2[2][2]) != get<string>(returned[3][2])){
		success = false; 
	}
	if(get<string>(entries_2[3][0]) != get<string>(returned[4][0])){
		success = false;
	}
	if(get<double>(entries_2[3][1]) != get<double>(returned[4][1])){
		success = false; 
	}
	if(get<string>(entries_2[3][2]) != get<string>(returned[4][2])){
		success = false; 
	}
	if(get<string>(entries_2[5][0]) != get<string>(returned[5][0])){
		success = false;
	}
	if(get<double>(entries_2[5][1]) != get<double>(returned[5][1])){
		success = false; 
	}
	if(get<string>(entries_2[5][2]) != get<string>(returned[5][2])){
		success = false; 
	}
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tMultipleConditions:\t";
	returned = t.apiReadEntry({"ReadMultEntries","ReadMultEntries_2"}, {{"String", "Double", "Third Thing"},{"String", "Double", "Third Thing"}}, {{{"Double", 1, 10.0}, {"String", 0, "entry3"}}, {{"Double", 1, 15.2}, {"String", 0, "entry8"}}});
	if(get<string>(entries[2][0]) != get<string>(returned[0][0])){
		success = false;
	}
	else if(get<double>(entries[2][1]) != get<double>(returned[0][1])){
		success = false;
	}
	else if(get<string>(entries[2][2]) != get<string>(returned[0][2])){
		success = false;
	}
	if(get<string>(entries_2[1][0]) != get<string>(returned[1][0])){
		success = false;
	}
	else if(get<double>(entries_2[1][1]) != get<double>(returned[1][1])){
		success = false;
	}
	else if(get<string>(entries_2[1][2]) != get<string>(returned[1][2])){
		success = false;
	} 
	if(true == success)
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tNoResults:\t\t";
	returned = t.apiReadEntry({"ReadMultEntries","ReadMultEntries_2"}, {{"String", "Double", "Third Thing"},{"String", "Double", "Third Thing"}}, {{{"Double", 0, 9.0}, {"String", 0, "entry3"}}, {{"Double", 0, 15.2}, {"String", 0, "entry8"}}});
	if(0 == returned.size())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;
		
	cout << "\tInvalidOperator:\t";
	returned = t.apiReadEntry({"ReadMultEntries", "ReadMultEntries_2"}, {{"String", "Double", "Third Thing"}, {"String", "Double", "Third Thing"}}, {{{"String", 9, "entry1"}}, {{"String", 9, "entry7"}}});
	if(0 == returned.size())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

	cout << "\tWrongType:\t\t";
	returned = t.apiReadEntry({"ReadMultEntries", "ReadMultEntries_2"}, {{"String", "Double", "Third Thing"}, {"String", "Double", "Third Thing"}}, {{{"Double", 3, "entry1"}}, {{"Double", 3, "entry8"}}});
	if(0 == returned.size())
		cout << "Success" << endl;
	else
		cout << "Failed" << endl;

}

void joinTest(){
	t.apiAddTable("JoinTest1", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	tuple<vector<string>, vector<vector<variant<string, double>>>> returned;
	vector<vector<variant<string, double>>> entries1;
	entries1.push_back({{"entry1", 10.0, "#1"}});
	entries1.push_back({{"entry2", 20.0, "#"}});
	entries1.push_back({{"entry3", 10.3, "#3"}});
	entries1.push_back({{"entry4", 14.0, "#4"}});
	entries1.push_back({{"entry5", 55.0, "#5"}});
	entries1.push_back({{"entry6", 66.6, "#6"}});
	for(int i = 0; i < entries1.size(); i++){
		t.apiAddEntry("JoinTest1", entries1[i]);
	}

	t.apiAddTable("JoinTest2", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> entries2;
	entries2.push_back({{"entry7", 200.0, "#1"}});
	entries2.push_back({{"entry8", 253.8, "#2"}});
	entries2.push_back({{"entry9", 473.09, "#3"}});
	entries2.push_back({{"entry10", 300.02, "#4"}});
	entries2.push_back({{"entry11", 6.7, "#9"}});
	entries2.push_back({{"entry12", 78.2, "#6"}});
	for(int i = 0; i < entries2.size(); i++){
		t.apiAddEntry("JoinTest2", entries2[i]);
	}

	t.apiAddTable("JoinTest3", {{"String", 0}, {"Double", 1}, {"Third Thing", 0}}, {1});
	vector<vector<variant<string, double>>> entries3;
	entries3.push_back({{"entry13", 200.0, "#1"}});
	entries3.push_back({{"entry14", 253.8, "#2"}});
	entries3.push_back({{"entry15", 473.09, "#3"}});
	entries3.push_back({{"entry16", 300.02, "#4"}});
	entries3.push_back({{"entry17", 6.7, "#5"}});
	entries3.push_back({{"entry18", 78.2, "#6"}});
	for(int i = 0; i < entries3.size(); i++){
		t.apiAddEntry("JoinTest3", entries3[i]);
	}

	vector<tuple<string, vector<string>, vector<tuple<string, int, variant<string, double>>>>> columns = {{"JoinTest1", {"String", "Double"}, {{"String", 0, "entry1"}, {"Double", 0, 10.0}}},{"JoinTest2", {"String", "Third Thing"}, {{"Double", 3, 300.0}, {"Double", 1, 10.0}}}};
	vector<tuple<tuple<string, string>, tuple<string, string>>> join = {{{"JoinTest1", "Third Thing"}, {"JoinTest2", "Third Thing"}}, {{"JoinTest1", "Third Thing"}, {"JoinTest3", "Third Thing"}}};
    returned = t.apiJoinEntry(columns, join);
}


//Comment out here if a test you aren't working on is throwing errors
int main(){

	//addTableTest();
	//updateTableTest();
	//deleteTableTest();
	//readTableTest();
	//addEntryTest();
	//updateEntryTest();
	//deleteEntryTest();
	//readEntryTest();
	//apiAddIndexTest();
  	//writeTablesTest();
  	//largeTableTest();
	//readMultipleEntryTest();
	joinTest();

	return 0;
}
