#include <iostream>
using namespace std;

#include "hash_map.h"

int main() {

	hash_map<int, int> map;
	map[57657] = 42;
	map[12] = 1;
	map[768] = 2;
	map[325] = 3;
	map[57657] = 4;
	map[3649] = 5;
	map[98567] = 6;
	map[456] = 7;
	map.print();
	cout << endl;
	map.remove(57657);
	map.print();
	return 0;
}
