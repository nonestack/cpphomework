#ifndef __MYLOGGER_H__
#define __MYLOGGER_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <sstream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Mylogger{
	public:
		static Mylogger *getInstance();
		static void destory();
		void warn(const char *);
		void error(const char *);
		void debug(const char *);
		void info(const char *);
	private:
		Mylogger();
		~Mylogger();
	private:
		static Mylogger *_pInstance;
		log4cpp::RollingFileAppender *_myFileAppender;
		log4cpp::OstreamAppender *_myOutAppender;
		log4cpp::PatternLayout *_myPattern1;
		log4cpp::PatternLayout *_myPattern2;
		log4cpp::Category &_myRoot;
};

#endif
