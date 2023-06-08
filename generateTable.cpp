#include "gantoApi.cpp"
#include <iostream>
api t = api();

int main(){
	srand(time(0));
	t.apiAddTable("LargeTable", {{"Number", 1}, {"String", 0}, {"KeyValue", 1}, {"Other Number", 1}}, {2});
	for(int i = 0; i < 10000; i++){
		t.apiAddEntry("LargeTable", {(double) (rand() % 100), "#" + to_string(rand() % 1000), (double) i, (double) rand()});
		if(0 == i % 1000)	//Helps assure that the program has not frozen
			cout << ".";
	}

	t.apiSaveToFile("LargeTable.json");

	return 0;
}