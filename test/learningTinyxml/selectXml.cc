#include "tinyxml2.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

using namespace tinyxml2;

int selectXML(const char *xmlPath){
	ofstream os;
	os.open("world.txt");
	XMLDocument doc;
	if(doc.LoadFile(xmlPath) != 0){
		cout << "load xml file failed" << endl;
		return false;
	}
	XMLElement *root = doc.RootElement();

//	if(root == NULL){
//		cout << "root bad" << endl;
//	}
	XMLElement *global = root->FirstChildElement("channel");
	XMLElement *userNode = global->FirstChildElement("item");
	if(userNode == NULL){
		cout << "I'm bad" << endl;
	}
	while(userNode != NULL){
		os << userNode->FirstChildElement("title")->GetText() << endl;
		os << userNode->FirstChildElement("link")->GetText() << endl;
		os << userNode->FirstChildElement("description")->GetText() << endl;
		//os << userNode->FirstChildElement("context")->GetText() << endl;
		userNode = userNode->NextSiblingElement();
	}
	os.close();
	return 0;
}

int main(){
	selectXML("myRss.xml");
	cout << "I'm end" << endl;
	return 0;
}
