#include "tableList.cpp"
tableList tables = tableList();

bool addTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos, vector<int> requiredPos);



bool addTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos){
	vector<int> tmp;
	return addTable(tableName, columns, keyPos, tmp);
}

bool addTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos, vector<int> requiredPos){
	table tmp = tables.getTable(tableName);
	if("errorTable" != tmp.name);	//Name already in use
		return false;
	table newTable = table(tableName);
	newTable.columns = columns;		//Checking for column name re-use here would be expensive O(n!)

	if(0 == keyPos.size())
		return false;		//At least one key is mandatory
	for(int i = 0; i < keyPos.size(); i++){
		if(0 > keyPos[i] || columns.size() <= keyPos[i])		//Check key column(s) point to actual columns
			return false;
	}
	newTable.keys = keyPos;

	for(int i = 0; i < requiredPos.size(); i++){
		if(0 > requiredPos[i] || columns.size() <= requiredPos[i])		//Check required column(s) point to actual columns
			return false;
	}

	return true;
}

//bool apiRemoveTable(string table){
//	return removeTable(table);
//}

tuple<vector<string>, vector<vector<int>>> apiReadTable(string tableName, vector<string> columns){
	// Get the table object
	table t = tables.getTable(tableName);

	// Check if the table exists
	if (t.name == "errorTable") {
	    return {};  // Return an empty vector if the table does not exist
	}
	vector<int> tmpInt;
	vector<string> tmpString;
	tmpString.push_back(t.name);
	for(int i = 0; i < t.columns.size(); i++){
		tmpString.push_back(get<0>(t.columns[i]));
		tmpInt.push_back(get<1>(t.columns[i]));
	}
	vector<vector<int>> comboInt;
	comboInt.push_back(tmpInt);
	comboInt.push_back(t.keys);
	comboInt.push_back(t.required);

	return {tmpString, comboInt};
}

bool apiAddColumn(string tableName, vector<string> columnNames){
	table tempTable = tables.getTable(tableName);
	if (tempTable.name == "error") {
	    return false;
	}
	for(int i=0; i<columnNames.size(); i++){
		tuple<string, int> data;
		get<0>(data) = columnNames[i];
		//get<1>(data) = 0.0;
		tempTable.columns.push_back(data);
	}
	return true;
}

bool apiRemoveColumn(string tableName, vector<string> columnNames){
	table tempTable = tables.getTable(tableName);
	if (tempTable.name == "error") {
	    return false;
	}
	int index = -1;
	for(int i=0; i<columnNames.size(); i++){
		if(get<0>(tempTable.columns[i]) == columnNames[i]){
			tempTable.columns.erase(tempTable.columns.begin() + i);
			return true;
		}
	}
	if(index == -1){
		return false;
	}
	// I think I'm supposed to erase it from other vectors as well but I'm not sure which ones
	return false;
}

bool apiRenameColumn(string tableName, string columnName, string newName){
	table tempTable = tables.getTable(tableName);
	if (tempTable.name == "error") {
	    return false;
	}
	for(int i=0; i<tempTable.columns.size(); i++){
		if(get<0>(tempTable.columns[i]) == columnName){
			get<0>(tempTable.columns[i]) = newName;
			return true;
		}
	}
	return false;
}

bool apiSetRequired(string tableName, string columnName, bool required){
	table tempTable = tables.getTable(tableName);
	if (tempTable.name == "error") {
	    return false;
	}
	for(int i=0; i<tempTable.columns.size(); i++){
		if(get<0>(tempTable.columns[i]) == columnName){
			tempTable.required[i] = required;
			return true;
		}
	}
	return false;
}
