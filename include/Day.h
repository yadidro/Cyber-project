#ifndef DAY_H
#define DAY_H


#include "../include/CyberDNS.h"
#include "../include/CyberExpert.h"
#include "../include/CyberDNS.h"
#include "../include/CyberWorm.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Day{


public:

	Day(CyberDNS* server,vector<CyberExpert*> cyberExperts);
	void everyDay(CyberDNS* server,vector<CyberExpert*> cyberExperts);

private:
	Day();//empty constructor
   CyberDNS* server_;
   vector<CyberExpert*>  CyberExpert_;
};
#endif
