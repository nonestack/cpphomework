#include "Mylogger.h"

int main(){
	Mylogger *log = Mylogger::getInstance();
	log->warn("Hello");
	log->info("Hello World");
	log->debug("Hello");
	log->error("Hello hhhh");
	Mylogger::destory();
	return 0;
}
