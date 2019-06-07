#ifndef __QUERYBASE_H__
#define __QUERYBASE_H__

#include "QueryResult.h"
#include "TextQuery.h"
//#include "OtherQuery.h"

#include <string>
#include <memory>

using namespace std;

/*********************************************************************************************/
class Query;

class QueryBase{
	friend class Query;
	protected:
		virtual ~QueryBase() = default;
	private:
		virtual QueryResult eval(const TextQuery &) const = 0;
		virtual string rep() const = 0;
};

/*********************************************************************************************/

#endif
