#include "table.cpp"
#include <fstream>
#include "json/single_include\nlohmann\json.hpp"

using json = nlohmann::json;

class tableList{
	private:
		vector<table*> tables;
		table errorTable = table("error");	//Used to return errors for functions that return tables

	public:
		tableList(){};
		
		bool loadTables(string filename);
		bool writeTables(string filename);
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
		bool addForeignKey(string tableName, string columnName);
		bool removeForeignKey(string tableName, string columnName);
		int isForeign(table* workingTable, string columnName);
};

bool tableList::loadTables(string filename){
	ifstream i(filename);
	json all;
	i >> all;
	for(int i = 0; i < all.size(); i++){
		string name = all[i][0];
		if(nullptr != getTablePointer(name)){
			return false;
		}
		table *tbl = new table(name);

		name = all[i][0];
		for(int j = 0; j < all[i][1].size(); j++){	//columns
			tbl->columns.push_back(all[i][1][j]);
		}
		for(int j = 0; j < all[i][2].size(); j++){	//keys
			tbl->keys.push_back(all[i][2][j]);
		}
		for(int j = 0; j < all[i][3].size(); j++){	//required
			tbl->required.push_back(all[i][3][j]);
		}
		for(int j = 0; j < all[i][4].size(); j++){	//foreign
			tbl->foreign.push_back(all[i][4][j]);
		}
		for(int j = 0; j < all[i][5].size(); j++){	//indexes
			vector<int> tmp;
			for(int k = 0; k < (all[i][5][j][1]).size(); k++){
				tmp.push_back(all[i][5][j][1][k]);
			}
			tbl->indexes.push_back({all[i][5][j][0], tmp});
		}
		tbl->entries = {};
		for(int j = 0; j < all[i][6].size(); j++){	//entries
			vector<variant<string, double>> *entry = new vector<variant<string, double>>();
			for(int k = 0; k < all[i][6][j].size(); k++){		//entry columns
				if(0 == get<1>(tbl->columns[k])){
					string tmp = all[i][6][j][k];
					entry->push_back(tmp);
				}
				else if(1 == get<1>(tbl->columns[k])){
					double tmp = all[i][6][j][k];
					entry->push_back(tmp);
				}
			}
			tbl->entries.push_back(entry);

		}
		addTable(tbl);
	}
	return true;
}

bool tableList::writeTables(string filename){
	json all;

	for(int i = 0; i < tables.size(); i++){
		json tbl;
		tbl.push_back(tables[i]->name);
		tbl.push_back(tables[i]->columns);
		tbl.push_back(tables[i]->keys);
		tbl.push_back(tables[i]->required);
		tbl.push_back(tables[i]->foreign);
		tbl.push_back(tables[i]->indexes);
		json entries;
		for(int j = 0; j < tables[i]->entries.size(); j++){		//entry rows
			json entry;
			bool run = true;
			for(int k = 0; k < tables[i]->entries[j]->size(); k++){		//entry columns
				if(0 == get<1>(tables[i]->columns[k])){
					entry.push_back(get<string>(tables[i]->entries[j]->at(k)));
				}
				else if(1 == get<1>(tables[i]->columns[k])){
					entry.push_back(get<double>(tables[i]->entries[j]->at(k)));
				}
			}
			entries.push_back(entry);
		}
		tbl.push_back(entries);

		all.push_back(tbl);
	}
	ofstream o(filename);
	o << setw(3) << all << endl;
	return true;
}

int tableList::isForeign(table* workingTable, string columnName){
	for(int i = 0; i < workingTable->foreign.size(); i++){
		if(columnName == get<0>(workingTable->foreign[i]))
			return i;
	}
	return -1;
}

bool tableList::addForeignKey(string tableName, string columnName){
	table* t = getTablePointer(tableName);
	if(nullptr == t)
		return false;

	int pos = isForeign(t, columnName);
	if(-1 != pos){
		t->foreign[pos] = {columnName, get<1>(t->foreign[pos]) + 1};	//Increment the columnUsed counter by 1
	}
	else{
		t->foreign.push_back({columnName, 1});
	}
	return true;
}

bool tableList::removeForeignKey(string tableName, string columnName){
	table* t = getTablePointer(tableName);
	if(nullptr == t)
		return false;
	
	int pos = isForeign(t, columnName);
	if(-1 != pos){
		int size = get<1>(t->foreign[pos]);
		if(1 == size){
			t->foreign.erase(t->foreign.begin() + pos);
		}
		else{
			t->foreign[pos] = {columnName, pos - 1};
		}
	}
	return true;
}

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
		if(0 != tables[tmpPos]->foreign.size())		//Check if table is used for foreign keys
			return false;
		for(int i = 0; i < tables[tmpPos]->keys.size(); i++){
			if("" != get<0>(tables[tmpPos]->keys[i])){
				removeForeignKey(get<0>(tables[tmpPos]->keys[i]), get<1>(tables[tmpPos]->keys[i]));
			}
		}
        for(int i = 0; i < tables[tmpPos]->entries.size(); ++i){
            delete tables[tmpPos]->entries[i];
        }
        delete tables[tmpPos];// if this does not work use delete[]
        tables.erase(tables.begin() + tmpPos);
        return true;
    }
	return false;
}
