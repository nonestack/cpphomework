#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>

using namespace std;

class QueryResult{
	friend void print(QueryResult &);
	public:
		QueryResult(string str, shared_ptr<vector<string> > content, shared_ptr<set<int> > lines)
		:_word(str)
		,_pFileContent(content)
		,_pLines(lines)
		{
			//cout << "QueryResult(string, shared_ptr<vector<string> >, shared_ptr<set<int> >)" << endl;
		}
		shared_ptr<set<int> > getLines(){
			return _pLines;
		}
	private:
		string _word;
		shared_ptr<vector<string> > _pFileContent;
		shared_ptr<set<int> > _pLines;
};



#endif
