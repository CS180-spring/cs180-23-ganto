#include <variant>
#include <vector>
#include <string>
#include <tuple>

using namespace std;



class table{
	public:
		string name;						//Table name
		vector<tuple<string, int>> columns;	//0 is string, 1 is double
		vector<int> keys;					//tracks key column pos(s)
		vector<int> required;				//tracks required column pos(s)

		vector<tuple<int, int>> indexes;	//stores position of entries sorted for a column tuple<column, position>

		vector<vector<variant<string, double>*>> entries;	//Stores actual data, pointer allows non-contiguous data storage

		table(string name){this->name = name;};
};