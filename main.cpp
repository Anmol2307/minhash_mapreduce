#include "minhash.h"
#include <cstdio>
#include <iostream>

using namespace std;


int main () {
	minhash m;
	m.map_files(2);
	m.print_map();
	m.shuffle_array();
	m.find_min(2);
}