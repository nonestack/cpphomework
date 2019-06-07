#include "TextQuery.h"

using namespace std;


void TextQuery::readFile(const string &filename){
	ifstream ifs(filename);
	int count = 0;
	string s1, tmp;
	while(getline(ifs, s1)){
		_pFileContent->push_back(s1);
		istringstream iss(s1);
		while(iss >> tmp){
			auto &line = _wordLines[tmp];
			if(!line){
				line.reset(new set<int>);
			}
			_wordLines[tmp]->insert(count);
		}
		++count;
	}
	ifs.close();
}


QueryResult TextQuery::query(const string &word) const{
	static shared_ptr<set<int> > tmp(new set<int>);
	auto lines = _wordLines.find(word);
	if(lines == _wordLines.end()){
		return QueryResult(word, _pFileContent, tmp);
	}
	return QueryResult(word, _pFileContent, lines->second);
#if 0
	auto lines = _wordLines.find(word)->second;
	cout << word << " occurs " << lines->size() << " times." << endl;
	auto iter = lines->begin();
	for(; iter != lines->end(); ++iter){
		cout << "(line " << *iter << ") " << (*_pFileContent)[*iter - 1] << endl; //下标对应行数减1
	}
#endif
}

void print(QueryResult &res){
	cout << res._word << " occurs " << res._pLines->size() << " times." << endl;
	auto iter = res._pLines->begin();
	//cout << (*res._pFileContent)[*iter - 1] << endl;
	//int i = 0;
	//for(; m != res._pLines->end(); ++m){
	//	cout << *m << endl;
	//}
	//for(i = 0; i < res._pFileContent->size(); ++i){
	//	cout << i << " : " << (*res._pFileContent)[i] << endl;
	//}
	for(; iter != res._pLines->end(); ++iter){
		cout << "(line " << *iter + 1 << ") " << (*res._pFileContent)[*iter] << endl; //下标对应行数减1
		//cout << "ok" << endl;
	}
}
