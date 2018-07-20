
#include "../include/Day.h"

Day::Day(CyberDNS* server,vector<CyberExpert*> cyberExperts){
	server_=server;
	CyberExpert_=cyberExperts;

}



void Day::everyDay(CyberDNS* server,vector<CyberExpert*> cyberExperts){
		server_ = server;
		CyberExpert_ = cyberExperts;

	vector<string> cyberPcList = server->GetCyberPCList();

	vector<string>::iterator itPc = cyberPcList.begin();


	for (vector<CyberExpert*>::iterator itExpert = cyberExperts.begin();itExpert != cyberExperts.end(); ++itExpert) {
		if (((*itExpert)->getWorkingTime()) > 0 || ((*itExpert)->getRestConstTime()==0)) {
			int efficiency = (*itExpert)->getEfficiency();

			while (efficiency > 0) {
				if (itPc == cyberPcList.end()) {

					itPc = cyberPcList.begin();
				}



				(*itExpert)->Clean(server_->GetCyberPC(*itPc));
				itPc=itPc+1;
				efficiency--;

			}
			itPc=itPc+1;
			(*itExpert)->set_cyber_work_time();
		}
		else{

			(*itExpert)->Set_cyber_rest_time();
		}
	}

	for (vector<string>::iterator it = cyberPcList.begin();it != cyberPcList.end(); ++it) {
		 (server->GetCyberPC(*it)).Run(*server);

	}

	for (vector<string>::iterator it = cyberPcList.begin();	it != cyberPcList.end(); ++it) {
		(server->GetCyberPC(*it)).setTimeToInfect();
	}
}





