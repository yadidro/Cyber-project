#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string.h>
#include <vector>
#include "../include/CyberWorm.h"
#include "../include/CyberDNS.h"
#include "../include/CyberPC.h"
#include <string.h>
#include <vector>
using namespace std;


class CyberDNS; // Forward decleration

class CyberPC
{

private:
    const std::string cyber_pc_os_;
    const std::string cyber_pc_name_;
    std::vector<std::string> cyber_pc_connections_;
    CyberWorm * cyber_worm_ = NULL;
    int cyber_pc_time_to_infect_;
    CyberPC(); // Prevent the use of an empty constructor
 
public:


    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);// Only use this constructor
    const std::string getName();
	void AddConnection(std::string  second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active	
	void Disinfect();
	void setTimeToInfect();
	CyberPC & operator=(const CyberPC& other);

	~CyberPC();
};
#endif
