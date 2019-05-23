#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <fstream>

int main(){
	//std::string url("<link>http://www.w3school.com.cn/xml</link>");
	std::regex brackets("<.*?>");
	std::ifstream is;
	is.open("test.xml");
	std::string s;
	while(is >> s){
		//std::cout << s << std::endl;
		std::cout << std::regex_replace(s, brackets, "") << "\n";
	}
	//std::cout << std::regex_replace(url, brackets, "") << "\n";
	is.close();
	return 0;
}
