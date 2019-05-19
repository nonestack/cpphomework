#include "Mylogger.h"

Mylogger *Mylogger::_pInstance = NULL;

//init function about appender, layout and category of log4cpp
Mylogger::Mylogger()
:_myFileAppender(new log4cpp::RollingFileAppender("myFileAppender", "file.log", 10 * 1024 * 1024, 3))
,_myOutAppender(new log4cpp::OstreamAppender("myOutAppender", &cout))
,_myPattern1(new log4cpp::PatternLayout())
,_myPattern2(new log4cpp::PatternLayout())
,_myRoot(log4cpp::Category::getRoot().getInstance("RootName"))
{
	_myPattern1->setConversionPattern("%d:[%p] %c %x :%m %n");
	_myPattern2->setConversionPattern("%d:[%p] %c %x :%m %n");

	_myFileAppender->setLayout(_myPattern1);
	_myOutAppender->setLayout(_myPattern2);

	_myRoot.addAppender(_myFileAppender);
	_myRoot.addAppender(_myOutAppender);
	_myRoot.setPriority(log4cpp::Priority::DEBUG);
	cout << "Mylogger()" << endl;
}


Mylogger::~Mylogger(){
	log4cpp::Category::shutdown();
	cout << "~Mylogger()" << endl;
}

//singleton mode
Mylogger *Mylogger::getInstance(){
	if(_pInstance == NULL){
		_pInstance = new Mylogger();
	}
	return _pInstance;
}

void Mylogger::destory(){
	if(_pInstance != NULL){
		delete _pInstance;
	}
}

//function of member
void Mylogger::warn(const char *msg){
	stringstream oss;
	oss << msg << "    file:" << __FILE__ << "    line:" << __LINE__ << "    function :"<< __FUNCTION__;
	string s1 = oss.str();
	_myRoot.warn(s1);
}

void Mylogger::debug(const char *msg){
	stringstream oss;
	oss << msg << "    file:" << __FILE__ << "    line:" << __LINE__ << "    function :"<< __FUNCTION__;
	string s1 = oss.str();
	_myRoot.debug(s1);
}

void Mylogger::error(const char *msg){
	stringstream oss;
	oss << msg << "    file:" << __FILE__ << "    line:" << __LINE__ << "     function :"<< __FUNCTION__;
	string s1 = oss.str();
	_myRoot.error(s1);
}

void Mylogger::info(const char *msg){
	stringstream oss;
	oss << msg << "    file:" << __FILE__ << "    line:" << __LINE__ << "     function :"<< __FUNCTION__;
	string s1 = oss.str();
	_myRoot.info(s1);
}
