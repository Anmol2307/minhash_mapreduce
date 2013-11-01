#ifndef MINHASH_H
#define MINHASH_H

#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<map>
using namespace std;

class minhash {

private:
	map <string, int> words;
	vector<int> myvector;
	vector<int> min;
	int pointer;

public:
	minhash();
	void map_words (string filename);
	void map_files(int n) ;
	void print_map ();
	void shuffle_array();
	void find_min (int n);
	void compute_min (int n);
};


#endif
