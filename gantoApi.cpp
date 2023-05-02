#include "tableList.cpp"
class api{
	private:
	tableList tables;
	vector<int> getAcceptedEntries(table workingTable, vector<tuple<string, int, variant<string, double>>> conditions);
	bool compare(variant<string, double> left, int op, variant<string, double> right);	
	bool keyUsed(table* workingTable, int columnPos, variant<string, double> data);

	public:
	api(){ tables = tableList(); }

	//Table Functions
		//Add Table
	bool apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int>keyPos);
	bool apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int>keyPos, vector<int> requiredPos);
	bool apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int> localKeys, vector<tuple<string, string>> foreignPos);
	bool apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int> localKeys, vector<tuple<string, string>> foreignPos, vector<int> requiredPos);
		//Remove Table
	bool apiRemoveTable(string tableName);
		//Read Table
	tuple<vector<string>, vector<vector<int>>> apiReadTable(string tableName, vector<string> columns);
		//Update Table
	bool apiAddColumn(string tableName, vector<tuple<string, int>> columnNames);
	bool apiRemoveColumn(string tableName, vector<string> columnNames);
	bool apiRenameColumn(string tableName, string columnName, string newName);
	bool apiSetRequired(string tableName, string columnName, bool required);

	//Entry Functions
		//Add Entry
	bool apiAddEntry(string tableName, vector<variant<string, double>> columns);
		//Remove Entry
	bool apiRemoveEntry(string tableName, vector<tuple<string, int, variant<string, double>>> conditions);	//Delete all entries from table where conditions == true
	bool apiRemoveEntry(string tableName, string column, vector<tuple<string, int, variant<string, double>>> conditions);	//Make columns nullptr for all entries where conditions == true
		//Update Entry
	bool apiUpdateEntry(string tableName, string column, double newData);		//Changes value of column to newData for all entries
	bool apiUpdateEntry(string tableName, string column, string newData);
	bool apiUpdateEntry(string tableName, string column, vector<tuple<string, int, variant<string, double>>> conditions, double newData);	//Changes value of column to newData for all entries where if(column[entry] operation compareWith)
	bool apiUpdateEntry(string tableName, string column, vector<tuple<string, int, variant<string, double>>> conditions, string newData);
		//Read Entry
	vector<vector<variant<string, double>>> apiReadEntry(string table, vector<string> displayColumns);
	vector<vector<variant<string, double>>> apiReadEntry(string table, vector<string> displayColumns, vector<tuple<string, int, variant<string, double>>> conditions);

};

bool api::keyUsed(table* workingTable, int columnPos, variant<string, double> data){
	int type = get<1>(workingTable->columns[columnPos]);
	string stringData;
	double doubleData;
	if(0 == type){
		stringData = get<string>(data);
	}
	else if(1 == type){
		doubleData = get<double>(data);
	}

	for(int i = 0; i < workingTable->entries.size(); i++){
		switch(type){
			case 0:
				if(stringData == get<string>(workingTable->entries[i]->at(columnPos)))
					return true;
				break;
			case 1:
				if(doubleData == get<double>(workingTable->entries[i]->at(columnPos)))
					return true;
				break;
		}
	}

	return false;
}

bool api::apiAddEntry(string tableName, vector<variant<string, double>> columns){
	table* t = tables.getTablePointer(tableName);
	if(nullptr == t)
		return false;
	vector<variant<string, double>> *entry = new vector<variant<string, double>>();
	bool valid = true;
	for(int i = 0; i < columns.size(); i++){
		variant<string, double> colVal;
		if(holds_alternative<string>(columns[i])){
			if(0 != get<1>(t->columns[i]))
				return false;
			colVal = get<string>(columns[i]);
		}
		else if(holds_alternative<double>(columns[i])){
			if(1 != get<1>(t->columns[i]))
				return false;
			colVal = get<double>(columns[i]);
		}
		if(false == keyUsed(t, i, colVal)){
			entry->push_back(colVal);
		}
		else{
			valid = false;
			break;
		}
	}
	if(true == valid){
		t->entries.push_back(entry);
		return true;
	}
	else{
		delete entry;
		return false;
	}
}


bool api::apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos){
	vector<int> tmp;
	return apiAddTable(tableName, columns, keyPos, tmp);
}

bool api::apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int> keyPos, vector<int> requiredPos){
	if(0 == keyPos.size())
		return false;		//At least one key is mandatory
	return apiAddTable(tableName, columns, keyPos, {}, requiredPos);

}

bool api::apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int> localKeys, vector<tuple<string, string>> foreignPos){
	return apiAddTable(tableName, columns, localKeys, foreignPos, {});
}

bool api::apiAddTable(string tableName, vector<tuple<string, int>> columns, vector<int> localKeys, vector<tuple<string, string>> foreignPos, vector<int> requiredPos){
	table tmp = tables.getTable(tableName);
	if("error" != tmp.name)	//Name already in use
		return false;

	int end = tables.size();
	/*
	for(int i = 0; i < foreignPos.size(); i++){
		if( get<0>(foreignPos[i]) || end < get<0>(foreignPos[i]))
			return false;
		if(0 < get<1>(foreignPos[i]) || get<1>(foreignPos[i]) > tables.getTable(get<0>(foreignPos[i])).columns.size())
			return false;
	}
	*/


	for(int i = 0; i < localKeys.size(); i++){
		if(0 > localKeys[i] || columns.size() <= localKeys[i])		//Check key column(s) point to actual columns
			return false;
	}

	for(int i = 0; i < requiredPos.size(); i++){
		if(0 > requiredPos[i] || columns.size() <= requiredPos[i])		//Check required column(s) point to actual columns
			return false;
	}
	for(int i = 0; i < columns.size(); i++){						//Check for repeated column names O(n!) runtime
		for(int j = 0; j < i; j++){
			if(columns[i] == columns[j])
				return false;
		}
	}

	table *newTable = new table(tableName);
	newTable->columns = columns;
	vector<tuple<string, string>> tmpKeys;
	for(int i = 0; i < localKeys.size(); i++){
		tmpKeys.push_back({"", get<0>(columns[localKeys[i]])});
	}
	newTable->keys = tmpKeys;

	tables.addTable(newTable);
	tables.makeForeign(foreignPos, tableName);	//Marks columns as having dependants

	return true;
}

bool api::apiRemoveTable(string table){
	return tables.removeTable(table);
}

tuple<vector<string>, vector<vector<int>>> api::apiReadTable(string tableName, vector<string> columns){
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
	//comboInt.push_back(t.keys);
	//comboInt.push_back(t.required);

	return {tmpString, comboInt};
}

bool api::apiAddColumn(string tableName, vector<tuple<string, int>> columnNames){
	table* tempTable = tables.getTablePointer(tableName);
	if (nullptr == tempTable) {
	    return false;
	}
	for(int i=0; i<columnNames.size(); i++){
		//Error handling needed here
		tempTable->columns.push_back(columnNames[i]);
	}
	return true;
}

bool api::apiRemoveColumn(string tableName, vector<string> columnNames){
	table* tempTable = tables.getTablePointer(tableName);
	if (nullptr == tempTable) {
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

bool api::apiRenameColumn(string tableName, string columnName, string newName){
	table* tempTable = tables.getTablePointer(tableName);
	if (nullptr == tempTable) {
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

bool api::apiSetRequired(string tableName, string columnName, bool required){
	table* tempTable = tables.getTablePointer(tableName);
	if (nullptr == tempTable) {
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

bool api::compare(variant<string, double> left, int op, variant<string, double> right){		//Assumes types are the same, check before calling
	    switch (op) {
            case 0:  
                return left == right;
            case 1:  
                return left > right;
            case 2:  
                return left >= right;
            case 3:  
                return left < right;
            case 4:  
                return left <= right;
            default:
                return false;  
        }
}



vector<int> api::getAcceptedEntries(table workingTable, vector<tuple<string, int, variant<string, double>>> conditions){
	vector<int> accepted;
	for(int i = 0; i < workingTable.entries.size(); i++){
		accepted.push_back(i);
	}

	if(0 == conditions.size()){		//no conditions means apply change to all entries
		return accepted;
	}

	string columnName = "";
	int colPos = 0;
	for(int i = 0; i < accepted.size(); i++){
		int entry = accepted[i];
		for(int j = 0; j < conditions.size(); j++){
			if(columnName == get<0>(conditions[j])){
				columnName = get<0>(conditions[j]);
				colPos = tables.getColumnPosition(workingTable.name, columnName);	//Could improve performance by making new getColumn[.]s that takes tables
			}
			int operation = get<1>(conditions[j]);
			variant<string, double> compareWith = get<2>(conditions[j]);
			int type = get<1>(workingTable.columns[colPos]);
			switch(type){
				case 0:
					if(false == holds_alternative<string>(compareWith))
						return {};
					if(false == compare(get<string>(workingTable.entries[entry]->at(colPos)), operation, get<string>(compareWith))){
						accepted.erase(accepted.begin() + i);
						i--;
					}
					break;
				case 1:
					if(false == holds_alternative<double>(compareWith))
						return {};
					if(false == compare(get<double>(workingTable.entries[entry]->at(colPos)), operation, get<double>(compareWith))){
						accepted.erase(accepted.begin() + i);
						i--;
					}
					break;
				default:
					return {};
			}
		}
	}
	return accepted;
}

bool api::apiUpdateEntry(string tableName, string column, double newData) {
    return apiUpdateEntry(tableName, column, {}, newData);
}

bool api::apiUpdateEntry(string tableName, string column, string newData) {
    return apiUpdateEntry(tableName, column, {}, newData);
}

bool api::apiUpdateEntry(string tableName, string column, vector<tuple<string, int, variant<string, double>>> conditions, double newData) {
    table* t = tables.getTablePointer(tableName);

    if (nullptr == t) {
        return false;
    }

    int columnPos = -1;
    for (int i = 0; i < t->columns.size(); i++) {
        if (get<0>(t->columns[i]) == column) {
            columnPos = i;
            break;
        }
    }

    if (columnPos == -1) {
        return false;  
    }

    if(tables.getColumnType(tableName, column) != 1){
        return false;
    }

	for(int i = 0; i < t->keys.size(); i++){
		if(column == get<1>(t->keys[i])){
			if(true == keyUsed(t, columnPos, newData)){		//Check for duplicate key value
				return false;
			}
			break;
		}
	}

	vector<int> accepted = getAcceptedEntries(*t, conditions);
	for(int i = 0; i < accepted.size(); i++){
		t->entries[accepted[i]]->at(columnPos) = newData;
	}

    return true;
}

bool api::apiUpdateEntry(string tableName, string column, vector<tuple<string, int, variant<string, double>>> conditions, string newData){
    table* t = tables.getTablePointer(tableName);
	
    if (nullptr == t) {
        return false;
    }

    int columnPos = -1;
    for (int i = 0; i < t->columns.size(); i++) {
        if (get<0>(t->columns[i]) == column) {
            columnPos = i;
            break;
        }
    }

    if (columnPos == -1) {
        return false;  
    }

    if(tables.getColumnType(tableName, column) != 0){
        return false;
    }

	for(int i = 0; i < t->keys.size(); i++){
		if(column == get<1>(t->keys[i])){
			if(true == keyUsed(t, columnPos, newData)){		//Check for duplicate key value
				return false;
			}
			break;
		}
	}
	
	vector<int> accepted = getAcceptedEntries(*t, conditions);
	for(int i = 0; i < accepted.size(); i++){
		t->entries[accepted[i]]->at(columnPos) = newData;
	}

    return true;
}