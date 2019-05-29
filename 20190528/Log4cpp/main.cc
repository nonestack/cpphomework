#include "Mylogger.h"

static stringstream oss;

void LogInfo(const char *str){
	const char *p = str;
	//cout << "end" << endl;
	oss << p;
	return;
}

template <class T, class... Args>
void LogInfo(const char *str, const T &t, const Args&... args){
	const char *p = str;
	while(*p){
		if(*p == '%'){
			++p;
			if(*p == 'd' || *p == 'u' || *p == 'f' || *p == 's'){
				++p;
				oss << t;
				LogInfo(p, args...);
				break;
			}
			else{ 
				if(*p == 'l'){
					p += 2;
					oss << t;
					LogInfo(p, args...);
					break;
				}

			}
		}
		else{
			oss << *p;
		}
		++p;
		//cout << "hi" << endl;
	}
	string s1 = oss.str();
	Mylogger *log = Mylogger::getInstance();
	//cout << p << t << endl;
	log->warn(s1.c_str());
	//Mylogger::destory();
}

void test() {
	int number = 100;
	const char * pstr = "hello, log4cpp";
	LogInfo("this is an info message. number = %d, str = %s\n", number, pstr);
}

int main(){
	test();
	//log->info("Hello World");
	//log->debug("Hello");
	//log->error("Hello hhhh");
	return 0;
}
