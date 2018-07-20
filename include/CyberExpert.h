#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/CyberPC.h"
#include "../include/CyberDNS.h"
using namespace std;

class CyberExpert{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    CyberExpert(); // Prevent the use of an empty constructor
    int count_rest_time;
    int count_work_time;

public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
 	CyberExpert(const CyberExpert &other);
	void Set_cyber_rest_time();
	void set_cyber_work_time();
	int getEfficiency();
	int getWorkingTime();
	int getRestTime();
	CyberExpert & operator=(const CyberExpert& other);
	int getRestConstTime();

};

  






#endif
