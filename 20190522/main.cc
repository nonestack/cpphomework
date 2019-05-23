#include "parseRss.h"

#include <iostream>

using std::cout;
using std::endl;

int main(){
	cout << "0" << endl;
	RssReader rss1("myRss.xml");
	cout << "1" << endl;
	rss1.parseRss();
	cout << "2" << endl;
	rss1.dump("world.txt");
	cout << "3" << endl;
	return 0;
}
