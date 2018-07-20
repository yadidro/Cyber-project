
#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <iostream>
#include <string>
#include <map>
#include "../include/CyberPC.h"
using namespace std;
#include "../boost/property_tree/ptree.hpp"
#include "../boost/property_tree/xml_parser.hpp"
#include "..boost/foreach.hpp"
#include "../include/CyberPC.h"
#include "../include/CyberDNS.h"
using namespace std;

class CyberPC; //Forward declaration

class CyberDNS
{
private:
    std::map<const std::string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and pointers

 
public:
    CyberDNS();
	void AddPC(CyberPC & cyber_pc_);
	CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;	
	std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.
	void BuildNetwork(const string &filename);									// All access to PC objects should use this function
	~CyberDNS();
	CyberDNS& operator=(const CyberDNS& other);// Do not store pointers elsewhere!
};



#endif

