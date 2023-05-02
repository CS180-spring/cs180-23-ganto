#include "tableList.cpp"
class api{
	private:
	tableList tables;

	public:
api(){
	tables = tableList();
}


bool addTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos){
	vector<int> tmp;
	return addTable(tableName, columns, keyPos, tmp);
}

bool addTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos, vector<int> requiredPos){
	table tmp = tables.getTable(tableName);
	if("error" != tmp.name)	//Name already in use
		return false;
		
	table *newTable = new table(tableName);
	newTable->columns = columns;		//Checking for column name re-use here would be expensive O(n!)

	if(0 == keyPos.size())
		return false;		//At least one key is mandatory
	for(int i = 0; i < keyPos.size(); i++){
		if(0 > keyPos[i] || columns.size() <= keyPos[i])		//Check key column(s) point to actual columns
			return false;
	}
	newTable->keys = keyPos;
	for(int i = 0; i < requiredPos.size(); i++){
		if(0 > requiredPos[i] || columns.size() <= requiredPos[i])		//Check required column(s) point to actual columns
			return false;
	}

	tables.addTable(newTable);

	return true;
}

bool apiRemoveTable(string table){
	return tables.removeTable(table);
}

tuple<vector<string>, vector<vector<int>>> apiReadTable(string tableName, vector<string> columns){
	// Get the table object
	table t = tables.getTable(tableName);
	// Check if the table exists
	if (t.name == "error") {
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

bool apiAddColumn(string tableName, vector<tuple<string, int>> columnNames){
	table* tempTable = tables.getTablePointer(tableName);
	if (tempTable->name == "error") {
	    return false;
	}
	for(int i=0; i<columnNames.size(); i++){
		//Error handling needed here
		tempTable->columns.push_back(columnNames[i]);
	}
	return true;
}

bool apiRemoveColumn(string tableName, vector<string> columnNames){
	table* tempTable = tables.getTablePointer(tableName);
	if (tempTable->name == "error") {
	    return false;
	}
	int index = -1;
	for(int i=0; i<columnNames.size(); i++){
		if(get<0>(tempTable->columns[i]) == columnNames[i]){
			tempTable->columns.erase(tempTable->columns.begin() + i);
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
	table* tempTable = tables.getTablePointer(tableName);
	if (tempTable->name == "error") {
	    return false;
	}
	for(int i=0; i<tempTable->columns.size(); i++){
		if(get<0>(tempTable->columns[i]) == columnName){
			get<0>(tempTable->columns[i]) = newName;
			return true;
		}
	}
	return false;
}

bool apiSetRequired(string tableName, string columnName, bool required){
	table* tempTable = tables.getTablePointer(tableName);
	if (tempTable->name == "error") {
	    return false;
	}
	for(int i=0; i<tempTable->columns.size(); i++){
		if(get<0>(tempTable->columns[i]) == columnName){
			tempTable->required[i] = required;
			return true;
		}
	}
	return false;
}
bool apiAddEntry(string tableName, vector<variant<string, double>> row) {
    table* tempTable = tables.getTablePointer(tableName);
    if (tempTable->name == "error") {
        return false;
    }
    // Check for duplicate or null key values
    for (int i = 0; i < tempTable->entries.size(); ++i) {
        const auto& entry = tempTable->entries[i];
        bool duplicate = true;
        for (int j = 0; j < tempTable->keys.size(); ++j) {
            const int keyPos = tempTable->keys[j];
            if (entry->at(keyPos) != row[keyPos]) {
                duplicate = false;
                break;
            }
            if (row[keyPos].index() == 0 && get<string>(row[keyPos]).empty()) {
                return false;  // Null key value
            }
        }
        if (duplicate) {
            return false;  // Duplicate key value
        }
    }
    // Check for null values in required columns
    for (int i = 0; i < tempTable->required.size(); ++i) {
        const int requiredPos = tempTable->required[i];
        if (row[requiredPos].index() == 0 && get<string>(row[requiredPos]).empty()) {
            return false;  // Null required value
        }
    }
    // Add the new entry
    tempTable->entries.push_back(new vector<variant<string, double>>(row));
    return true;
}

};