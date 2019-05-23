#include "parseRss.h"

#include "tinyxml2.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <fstream>

using namespace tinyxml2;

using std::cout;
using std::endl;
using std::string;

RssReader::RssReader(const char *xmlPath){
	if(selectXML(xmlPath) == false){
		cout << "RssReader() error!!!" << endl;
	}
	cout << "RssReader()" << endl;
}

int RssReader::selectXML(const char *xmlPath){
	XMLDocument doc;
	if(doc.LoadFile(xmlPath) != 0){
		cout << "load xml dile failed" << endl;
		return false;
	}
	XMLElement *root = doc.RootElement();

	if(root == NULL){
		cout << "root bad" << endl;
		return false;
	}

	XMLElement *globalNode = root->FirstChildElement("channel");
	XMLElement *userNode = globalNode->FirstChildElement("item");
	//read information
	RssItem rtmp;
	while(userNode != NULL){
		rtmp.title = userNode->FirstChildElement("title")->GetText();
		rtmp.link = userNode->FirstChildElement("link")->GetText();
		rtmp.description = userNode->FirstChildElement("description")->GetText();
		
		rtmp.content = userNode->FirstChildElement("content:encoded")->GetText();
		this->_rss.push_back(rtmp);
		userNode = userNode->NextSiblingElement();
	}
	return true;
}

void RssReader::parseRss(){
	std::regex brackets("<.*?>");
	string tmpContent;
	std::ostringstream modifyContent;
	std::vector<RssItem>::iterator iter = _rss.begin();
	for(; iter != _rss.end(); ++iter){
		modifyContent << std::regex_replace(iter->content, brackets, "");
		tmpContent = modifyContent.str();
		iter->content = tmpContent;
	}
}

void RssReader::dump(const string &filename){
	std::ofstream os;
	os.open(filename);
	os << "<doc>" << endl; 
	int count = 0;
	std::vector<RssItem>::iterator iter = _rss.begin();
	for(; iter != _rss.end(); ++iter){
		os << "\t" <<  "<docid>" << ++count << "</docid>" << endl;
		os << "\t" <<  "<title>" << iter->title << "</title>" << endl;
		os << "\t" <<  "<link>" << iter->link << "</link>" << endl;
		os << "\t" <<  "<description>" << iter->description << "</description>" << endl;
		os << "\t" <<  "<content>" << iter->content << "</content>";
	}
	os << "</doc>"; 
	os.close();
}
