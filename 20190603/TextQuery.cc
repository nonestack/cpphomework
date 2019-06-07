#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>


using namespace std;

class TextQuery{
	public:
		TextQuery() = default;
		~TextQuery() = default;
		void readFile(const string &);
		void query(const string &);
	private:
		vector<string> _lineNum;
		map<string, set<int> > _wordLines;
};

void TextQuery::readFile(const string &filename){
	ifstream ifs(filename);
	int count = 0;
	string s1, tmp;
	while(getline(ifs, s1)){
		++count;
		_lineNum.push_back(s1);
		istringstream iss(s1);
		while(iss >> tmp){
			_wordLines[tmp].insert(count);
		}
	}
	ifs.close();
}


void TextQuery::query(const string &word){
	auto lines = _wordLines.find(word)->second;
	cout << word << " occurs " << lines.size() << " times." << endl;
	auto iter = lines.begin();
	for(; iter != lines.end(); ++iter){
		cout << "(line " << *iter << ") " << _lineNum[*iter - 1] << endl; //下标对应行数减1
	}
}

int main(){
	TextQuery *haha = new TextQuery();
	unique_ptr<TextQuery> hehe(haha);
	hehe->readFile("china_daily.txt");
	hehe->query("overseas");
	return 0;
}
