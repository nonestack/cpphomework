#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::iterator;
using std::vector;

class WordCount{
	public:
		WordCount(const string &);
		int wordCmp(const string &);
		int getCount();
		void addCount();
		string getWord();
		~WordCount();
	private:
		//char *_word;
		string _word;
		int _count;
};

WordCount::WordCount(const string &word)
:_count(1), _word(word){

}

int WordCount::wordCmp(const string &word){
	if(this->_word == word){
		return 1;
	}
	return 0;
}

int WordCount::getCount(){
	return _count;
}

void WordCount::addCount(){
	++this->_count;
}

string WordCount::getWord(){
	return this->_word;
}

WordCount::~WordCount(){
	//printf("~WordCount()\n");
}


class Dictionary{
	public:
		Dictionary();
		void read(const string&);
		void store(const string&);
		static int isMore(WordCount w1, WordCount w2){
			string m1 = w1.getWord();
			string m2 = w2.getWord();
			return m1 < m2;
		}
		void dictSort();
		~Dictionary();
	private:
		vector<WordCount> _dvec;
};

Dictionary::Dictionary(){
	printf("Dictionary()\n");
}

//void Dictionary::isMore(const WordCount &w1, const WordCount &w2){

void Dictionary::dictSort(){
	sort(_dvec.begin(), _dvec.end(), isMore);
}

void Dictionary::read(const string &filename){
	ifstream fin;
	fin.open(filename);
	string s;
	vector<WordCount>::iterator iter;
	while(fin >> s){
		iter = _dvec.begin();
		for(; iter != _dvec.end(); ++iter){
			if((*iter).wordCmp(s) == 1){
				(*iter).addCount();
				break;
			}
		}
		if(iter == _dvec.end()){
			_dvec.push_back(s);
		}
	}	
	fin.close();
}

void Dictionary::store(const string &filename){
	ofstream fout(filename);
	string s;
	vector<WordCount>::iterator iter;
	for(iter = _dvec.begin(); iter != _dvec.end(); ++iter){
		fout << (*iter).getWord() << " : " << (*iter).getCount() << endl;
	}
	fout.close();
}

Dictionary::~Dictionary(){
	printf("~Dictionary()\n");
}

int main(int argc, char *argv[]){
	Dictionary dict;
	dict.read(argv[1]);
	dict.dictSort();
	dict.store(argv[2]);
	return 0;
}
