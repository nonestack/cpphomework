#include "TextQuery.h"
#include "QueryBase.h"
#include "OtherQuery.h"

int test0(){
	TextQuery haha;
	haha.readFile("china_daily.txt");
	Query q = ~Query("overseas");// & Query("who");
	QueryResult &&res = q.eval(haha);
	print(res);
	//QueryResult &&res = haha.query("overseas");
	//print(res);
	return 0;
}

int main(){
	test0();
	return 0;
}
