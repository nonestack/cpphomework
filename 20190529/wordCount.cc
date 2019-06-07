#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class WordCount{
	public:
		WordCount() = default;
		~WordCount() = default;
		void readFile(const string &);
		void printResult(const string &);
	private:
		map<string, size_t, greater<string> > words;
};

void WordCount::readFile(const string &filename){
	ifstream ifs(filename);
	string s1;
	while(ifs >> s1){
		++words[s1];
	}
	ifs.close();
}

void WordCount::printResult(const string &filename){
	ofstream ofs(filename);
	auto iter = words.begin();
	for(; iter != words.end(); ++iter){
		ofs << iter->first << " : " << iter->second << endl;
	}
	ofs.close();
}

int main(){
	WordCount tc;
	tc.readFile("The_Holy_Bible.txt");
	tc.printResult("Tiancai");
	return 0;
}
