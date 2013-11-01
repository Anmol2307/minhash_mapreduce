#include <iostream>
#include <cstring>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include "minhash.h"

using namespace std;


minhash::minhash (){
	pointer = 1;
}

void minhash::map_words (string filename) {
	ifstream infile;
	//int imax = numeric_limits<int>::max();
	string str;
	char str1[1000];
	infile.open(filename.c_str());
	
	char* token;

	while(getline(infile,str)){
		strcpy(str1,str.c_str());
		token = strtok(str1," ,\t;:.[]{}()=-_");
		while (token != NULL) {
			if (words.find(token) == words.end()){
				words[token] = pointer++;
			}
			token = strtok(NULL," ,\t;:.[]{}()=-_");
		}
	}	
	infile.close();
}

void minhash::map_files(int n) {
	for (int i =1; i <= n;i++) {
		string str1 = to_string(i) + ".txt";
		map_words(str1);
	}
}

void minhash::print_map () {
	map<string,int>::iterator it;
	//cout<<"here"<<endl;
	for(it = words.begin(); it!= words.end(); it++){
		
		cout<<it->first<<" maps to "<<it->second<<endl;
	}
}

int myrandom (int i) { return std::rand()%i;}

void minhash::shuffle_array () {
	//vector<int> myvector;
	srand ( unsigned ( time(0) ) );
	for (int i = 1;i < pointer;i++) {
		myvector.push_back(i);
	}
	random_shuffle ( myvector.begin(), myvector.end());

	cout << "myvector contains:";
	for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
			cout << ' ' << *it;
	cout << '\n';	
}


void minhash::find_min (int n) {
	
	for (int i = 1; i <= n; i++) {
		int minval = 10000;
		ifstream infile;
		string str;
		char str1[1000];
		string filename = to_string(i) + ".txt";
		infile.open(filename.c_str());
		string value;
		char* token;

		while(getline(infile,str)){
			strcpy(str1,str.c_str());
			token = strtok(str1," ,\t;:.[]{}()=-_");
			while (token != NULL) {
				if (myvector[words[token]-1] < minval){
					minval = myvector[words[token]-1];
					value = token;
				}
				token = strtok(NULL," ,\t;:.[]{}()=-_");
			}
		}
		cout<< value << " "<<minval<<endl;
		min.push_back(minval);	
		infile.close();
	}
	cout<<"min contains ";
	for (int i =0; i < min.size(); i++) {
		cout<<min[i]<<" ";	
	}
	cout<<endl;
}

/*
void minhash::compute_similar(int n) {
	
	int count = 1000;
	int t =1;
	while (count--) {
		ofstream outfile;
		outfile.open("out"+ to_string(t) + ".txt");
		find_min(n);
		for (int i=0;i<min.size();i++) {
			outfile<<min[i]<<" "<<(i+1)<<endl; 
		}
		t++;
	}
}

*/
