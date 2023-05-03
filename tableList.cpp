#include "table.cpp"

class tableList{
	private:
		vector<table*> tables;
		table errorTable = table("error");	//Used to return errors for functions that return tables

	public:
		tableList(){};
		
		int getColumnPosition(int tablePos, string name);
		int getTablePosition(string name);
		table getTable(string name);
		table getTable(int pos);
		vector<table*> getAllTables();
		bool removeTable(string tableName);
		table* getTablePointer(string name);
		void addTable(table *newTable);
		int size();
		void makeForeign(vector<tuple<string, string>> keys, string caller);
		vector<vector<string>> getDependants(string tableName);
		int getColumnType(string tableName, string columnName);
		int getColumnPosition(string tableName, string columnName);
};

int tableList::getColumnPosition(int tablePos, string name){
	for(int i = 0; i < tables[tablePos]->columns.size(); i++){
		if(name == get<0>(tables[tablePos]->columns[i]))
			return i;
	}
	return -1;
}

int tableList::getColumnPosition(string tableName, string columnName){
	return getColumnPosition(getTablePosition(tableName), columnName);
}

int tableList::getColumnType(string tableName, string columnName){
	int tablePos = getTablePosition(tableName);
	if(-1 == tablePos)
		return -1;

	int columnPos = getColumnPosition(tablePos, columnName);
	if(-1 == columnPos)
		return -1;

	return get<1>(tables[tablePos]->columns[columnPos]);
}



vector<vector<string>> tableList::getDependants(string tableName){
	int tablePos = getTablePosition(tableName);
	if(-1 != tablePos){
		return tables[tablePos]->dependants;
	}
	return {};
}

void tableList::makeForeign(vector<tuple<string, string>> keys, string caller){
	for(int i = 0; i < keys.size(); i++){		//Loops through keys
		string table = get<0>(keys[i]);
		string column = get<1>(keys[i]);
		int tablePos = getTablePosition(table);
		if(-1 == tablePos)
			return;
		bool tableFound = false;
		for(int j = 0; j < tables[tablePos]->dependants.size(); j++){	//Loops through the chosen table's dependant tables
			if(0 < tables[tablePos]->dependants[j].size() && tables[tablePos]->dependants[j][0] == table){
				tableFound = true;
				bool columnFound = false;
				for(int k = 0; k < tables[tablePos]->dependants[j].size(); k++){	//Loops through the dependant columns in the selected dependant  table
					if(column == tables[tablePos]->dependants[j][k]; k++){
						columnFound = true;
						break;
					}
				}
				if(false == columnFound){
					tables[tablePos]->dependants[j].push_back({column});		//Append column to dependants
				}
				break;
			}
		}
		if(false == tableFound){
			tables[tablePos]->dependants.push_back({table, column});		//Append table and column to dependants
		}
	}
}

int tableList::size(){
	return tables.size();
}

table* tableList::getTablePointer(string name){
	int pos = getTablePosition(name);
	if(-1 != pos)
		return tables[pos];
	else
		return nullptr;
}

void tableList::addTable(table *newTable){
	tables.push_back(newTable);
}

table tableList::getTable(string name){
	return getTable(getTablePosition(name));
}

int tableList::getTablePosition(string name){
	for(int i = 0; i < tables.size(); i++){
		if(name == tables[i]->name)
			return i;
	}
	return -1;
}

table tableList::getTable(int pos){
	if(tables.size() > pos)
		return *tables[pos];
	return errorTable;
}

vector<table*> tableList::getAllTables(){
	return tables;
}

bool tableList::removeTable(string tableName){
	int tmpPos = getTablePosition(tableName);
    if(-1 != tmpPos){
        for(int i = 0; i < tables[tmpPos]->entries.size(); ++i){
            delete tables[tmpPos]->entries[i];
        }
        delete tables[tmpPos];// if this does not work use delete[]
        tables.erase(tables.begin() + tmpPos);
        return true;
    }
	return false;
}
