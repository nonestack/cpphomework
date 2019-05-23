#ifndef __PARSERSS_H__
#define __PARSERSS_H__


#include <string>
#include <vector>


struct RssItem{
	std::string title;
	std::string link;
	std::string description;
	std::string content;
};

class RssReader{
	public:
		RssReader(const char *);

		void parseRss();
		int  selectXML(const char *);
		void dump(const std::string &filename);
	private:
		std::vector<RssItem> _rss;
};


#endif
