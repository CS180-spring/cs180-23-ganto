#include <variant>
#include <vector>
#include <string>
#include <tuple>

using namespace std;



class table{
	public:
		string name;						//Table name
		vector<tuple<string, int>> columns;	//0 is string, 1 is double
		vector<tuple<string, string>> keys;	//tracks key column pos(s)
		vector<string> required;				//tracks required column name
		vector<tuple<string, int>> foreign;		//Tracks the columns used as foreign keys by other tables {columnName, # of tables using the column}

		vector<tuple<int, int>> indexes;	//stores position of entries sorted for a column tuple<column, position>

		vector<vector<variant<string, double>>*> entries;	//Stores actual data, pointer allows non-contiguous data storage

		table(string name){this->name = name;};
};