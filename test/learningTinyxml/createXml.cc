#include "tinyxml2.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

using namespace tinyxml2;

int createXML(const char *xmlPath){
	XMLDocument doc;
	if(doc.LoadFile(xmlPath) != 3){
		cout << "file has been existed!" << endl;
		return 0;
	}

	XMLDeclaration *declaration = doc.NewDeclaration();
	doc.InsertFirstChild(declaration);

	XMLElement *root = doc.NewElement("XMLUSER");
	doc.InsertEndChild(root);

	XMLElement *userNode = doc.NewElement("User");
	//add attribute
	userNode->SetAttribute("Name", "Tony");
	userNode->SetAttribute("Password", "123456");
	root->InsertEndChild(userNode);

	return doc.SaveFile(xmlPath);
}

int main(int argc, char *argv[]){
	createXML("./hello.xml");
	return 0;
}
