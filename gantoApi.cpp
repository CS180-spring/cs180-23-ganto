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

bool apiUpdateEntry(string table, string columns, double newData) {
    table* t = tables.getTablePointer(table);

    if (t->name == "error") {
        return false;
    }
    
    if(getColumnType(table, columns) == 1){
        for (int i = 0; i < tables[tablePos]->columns[columnPos].size(); i++) {
            columns[columnPos][i] = newData;
        }
        return true;
    }    

    return false;
}

bool apiUpdateEntry(string table, string columns, string newData) {
    table* t = tables.getTablePointer(table);

    if (t->name == "error") {
        return false;
    }
    
    if(getColumnType(table, columns) == 0){
        for (int i = 0; i < tables[tablePos]->columns[columnPos].size(); i++) {
            columns[columnPos][i] = newData;
        }
        return true;
    }    

    return false;
}
	
bool apiUpdateEntry(string table, string column, int operation, double compareWith, double newData) {
    table* t = tables.getTablePointer(table);

    if (t->name == "error") {
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

    if(getColumnType(table, column) != 1){
        return false;
    }

    for (int i = 0; i < t->columns.size(); i++) {
        double currentValue = get<double>(t->columns[i][columnPos]);
        bool cond = false;
        switch (operation) {
            case 0:  
                cond = currentValue == compareWith;
                break;
            case 1:  
                cond = currentValue > compareWith;
                break;
            case 2:  
                cond = currentValue >= compareWith;
                break;
            case 3:  
                cond = currentValue < compareWith;
                break;
            case 4:  
                cond = currentValue <= compareWith;
                break;
            default:
                return false;  
        }
        if (cond) {
            t->columns[i][columnPos] = newData;
        }
    }
    return true;
}

bool apiUpdateEntry(string table, string column, int operation, string compareWith, string newData) {
    table* t = tables.getTablePointer(table);

    if (t->name == "error") {
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

    if(getColumnType(table, column) != 0){
        return false;
    }

    for (int i = 0; i < t->columns.size(); i++) {
        double currentValue = get<double>(t->columns[i][columnPos]);
        bool cond = false;
        switch (operation) {
            case 0:  
                cond = currentValue == compareWith;
                break;
            case 1:  
                cond = currentValue > compareWith;
                break;
            case 2:  
                cond = currentValue >= compareWith;
                break;
            case 3:  
                cond = currentValue < compareWith;
                break;
            case 4:  
                cond = currentValue <= compareWith;
                break;
            default:
                return false;  
        }
        if (cond) {
            t->columns[i][columnPos] = newData;
        }
    }
    return true;
}
	
};
