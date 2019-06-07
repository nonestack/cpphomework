#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include "QueryResult.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>


class TextQuery{
	public:
		TextQuery()
		:_pFileContent(new vector<string>)
		{
			cout << "TextQuery()" << endl;
		}
		~TextQuery() = default;
		void readFile(const string &);
		QueryResult query(const string &) const;
		shared_ptr<vector<string> > getContent() const{
			return _pFileContent;
		}
		//void print(QueryResult &);
	private:
		shared_ptr<vector<string> > _pFileContent;
		map<string, shared_ptr<set<int> > > _wordLines;
};

void print(QueryResult &);



#endif
