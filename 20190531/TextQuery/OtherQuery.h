#ifndef __OTHERQUERY_H__
#define __OTHERQUERY_H__

#include "QueryBase.h"

#include <string>
#include <algorithm>

using namespace std;

class WordQuery : public QueryBase{
	friend class Query;
	private:
		WordQuery(const string &word)
		:_word(word)
		{
		}
		virtual QueryResult eval(const TextQuery &text) const{
			return text.query(_word);
		}
		virtual string rep() const{
			return _word;
		}
	private:
		string _word;
};

/*********************************************************************************************/
class Query{
	friend Query operator~(const Query &);
	friend Query operator&(const Query &, const Query &);
	friend Query operator|(const Query &, const Query &);
	public:
		Query(const string &word)
		:_pWord(new WordQuery(word))
		{
		}
		QueryResult eval(const TextQuery &text) const{
			return _pWord->eval(text);
		}
		string rep() const{
			return _pWord->rep();
		}
	private:
		Query(shared_ptr<QueryBase> ptr)
		:_pWord(ptr)
		{
		}
	private:
		shared_ptr<QueryBase> _pWord; 
};
/*********************************************************************************************/
class NotQuery : public QueryBase{
	//friend class Query;
	friend Query operator~(const Query &);
	private:
		NotQuery(const Query &q)
		:_query(q)
		{
		}
		virtual QueryResult eval(const TextQuery &) const;
		virtual string rep() const{
			return "~" + _query.rep();
		}
	private:
		Query _query;
		
};

QueryResult NotQuery::eval(const TextQuery &text) const{
	auto norm = _query.eval(text).getLines();
	shared_ptr<set<int> > res(new set<int>);
	size_t lines = text.getContent()->size();
	int i;
	auto beg = norm->begin(), end = norm->end();
	for(i = 0; i < lines; ++i){
		//cout << "ok" << endl;
		if(beg == end || *beg != i){
			res->insert(i);
		}
		else if(beg != end){
			++beg;
		}
	}
	//auto iter = res->begin();
	//for(; iter != res->end(); ++iter){
	//	cout  << *iter << endl;
	//}
	return QueryResult(rep(), text.getContent(), res);
}

Query operator~(const Query &q){
	return shared_ptr<QueryBase>(new NotQuery(q));
}
/*********************************************************************************************/
class BinaryQuery : public QueryBase{
	protected:
		BinaryQuery(const Query &lq, const Query &rq, const string s)
		:_lhs(lq), _rhs(rq), _op(s)
		{
		}
		virtual QueryResult eval(const TextQuery &) const = 0;
		virtual string rep() const{
			return "(" + _lhs.rep() + _op + _rhs.rep() + ")";
		}
	protected:
		Query _lhs;
		Query _rhs;
		string _op;
};
/*********************************************************************************************/
class AndQuery : public BinaryQuery{
	friend Query operator&(const Query &, const Query &);
	private:
		AndQuery(const Query &lq, const Query &rq)
		:BinaryQuery(lq, rq, "&")
		{
		}
		virtual QueryResult eval(const TextQuery &) const;
};

Query operator&(const Query &lq, const Query &rq){
	return shared_ptr<QueryBase>(new AndQuery(lq, rq));
}

QueryResult AndQuery::eval(const TextQuery &text) const{
	shared_ptr<set<int> > tmp(new set<int>);
	auto left = _lhs.eval(text).getLines();
	auto right = _rhs.eval(text).getLines();
	set_intersection(left->begin(), left->end(),
					 right->begin(), right->end(),
					 inserter(*tmp, tmp->begin()));
	return QueryResult(rep(), text.getContent(), tmp);
}
/*********************************************************************************************/
class OrQuery : public BinaryQuery{
	friend Query operator|(const Query &, const Query &);
	private:
		OrQuery(const Query &lq, const Query &rq)
		:BinaryQuery(lq, rq, "|")
		{
		}
		virtual QueryResult eval(const TextQuery &) const;
};

QueryResult OrQuery::eval(const TextQuery &text) const{
	auto left = _lhs.eval(text).getLines();
	auto right = _rhs.eval(text).getLines();

	shared_ptr<set<int> > tmp = make_shared<set<int>>();
	tmp->insert(left->begin(), left->end());
	tmp->insert(right->begin(), right->end());
	return QueryResult(rep(), text.getContent(), tmp);
}

Query operator|(const Query &lq, const Query &rq){
	return shared_ptr<QueryBase>(new OrQuery(lq, rq));
}
/*********************************************************************************************/


#endif
