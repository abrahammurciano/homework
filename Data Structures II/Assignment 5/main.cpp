#include <iostream>
using namespace std;

#include "hash_map.h"

int main() {

	hash_map<int, int> map;
	map[57657] = 42;
	hash_map<int, int>::iterator i = map.find(57657);
	cout << i->second << endl;

	map.remove(57657);
	if (map.find(57657)) {
		cout << map[57657] << endl;
	} else {
		cout << "Removed correctly" << endl;
	}
	return 0;
}
