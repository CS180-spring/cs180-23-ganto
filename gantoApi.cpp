#include "tableList.cpp"
tableList tables = tableList();

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

bool apiRemoveTable(string table){
    return removeTable(table);
}

vector<vector<int>> apiReadTable(string table, vector<string> columns){
	// Get the table object
	table t = tables.getTable(table);

	// Check if the table exists
	if (t.name == "error") {
	    return {};  // Return an empty vector if the table does not exist
	}

	// Create a vector of column positions to retrieve
	vector<int> columnPositions;
    	for (string col : columns) {
    	    for (int i = 0; i < t.columns.size(); i++) {
	        if (col == get<0>(t.columns[i])) {
	            columnPositions.push_back(i);
	            break;
	        }
	    }
	}

	// Read the specified columns from the table and store the values in a vector of vectors
	vector<vector<int>> result;
	for (vector<variant<string, double>>* entry : t.entries) {
	    vector<int> row;
	    for (int pos : columnPositions) {
	       // Check if the value is an integer and add it to the row vector
	       if (holds_alternative<int>(entry->at(pos))) {
    	           row.push_back(get<int>(entry->at(pos)));
     	       }
    	    }
	    result.push_back(row);
	}

	return result;
}

//testing git branch