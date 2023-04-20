#include "table.cpp"

class tableList{
	private:
		vector<table*> tables;
		table errorTable = table("error");	//Used to return errors for functions that return tables
		int getTablePosition(string name);

	public:
		tableList(){};
		
		table getTable(string name);
		table getTable(int pos);
		vector<table*> getAllTables();
		bool removeTable(string tableName);
};

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
