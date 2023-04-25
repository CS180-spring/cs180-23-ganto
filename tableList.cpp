#include "table.cpp"

class tableList{
	private:
		vector<table*> tables;
		table errorTable = table("error");	//Used to return errors for functions that return tables
		int getTablePosition(string name);
		int getColumnPosition(int tablePos, string name);
	public:
		tableList(){};
		
		table getTable(string name);
		table getTable(int pos);
		vector<table*> getAllTables();
		bool removeTable(string tableName);
		table* getTablePointer(string name);
		void addTable(table *newTable);
		int getColumnType(string tableName, string columnName);
};

table* tableList::getTablePointer(string name){
	return tables[getTablePosition(name)];
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

int tableList::getColumnPosition(int tablePos, string name){
    for(int i = 0; i < tables[tablePos]->columns.size(); i++){
        if(name == get<0>(tables[tablePos]->columns[i]))
            return i;
    }
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
