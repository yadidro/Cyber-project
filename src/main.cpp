#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include "../include/CyberDNS.h"
#include <vector>
#include <string>
#include "../include/CyberPC.h"
#include "../include/CyberExpert.h"
#include "../include/Day.h"

using namespace std;


int main(){
	CyberDNS * server = new CyberDNS();
	vector< CyberExpert *>  VecExp;//// new??
	Day * every = new Day(server,VecExp);
	server->BuildNetwork("computers.xml");
	server->BuildNetwork("network.xml");
	//network.xml;


	using boost::property_tree::ptree;
	ptree pt;
	read_xml("events.xml",pt);

	ptree tree;



	int day=0;
	int terminate=0;




	BOOST_FOREACH(ptree::value_type &y, pt){
		cout<<"day "<<day<<":"<<endl;

		if(y.first == "hack"){
			string eventComputer = y.second.get<string>("computer");
			string eventWormName = y.second.get<string>("wormName");
			int eventWormDormancy = y.second.get<int>("wormDormancy");
			string eventWormOs = y.second.get<string>("wormOs");

			cout<<"    "<<"Hack occurred on"<<eventComputer<<endl;
			CyberWorm * newworm=new CyberWorm(eventWormOs,eventWormName,eventWormDormancy);
			server->GetCyberPC(eventComputer).Infect(*newworm);

			delete newworm;
		}

		if(y.first == "clock-in"){
			string expertName = y.second.get<string>("name");
			int expertWorkTime = y.second.get<int>("workTime");
			int expertRestTime = y.second.get<int>("restTime");
			int expertEfficiency = y.second.get<int>("efficiency");
			CyberExpert * exp=new CyberExpert(expertName,expertWorkTime,expertRestTime,expertEfficiency);
			VecExp.push_back(exp);
			cout<<"    "<<"Clock-In: "<<expertName<<" began working"<<endl;

		}

		if (y.first=="termination"){
			int eventEnd=y.second.get<int>("time");
			terminate=eventEnd;

		}

		every->everyDay(server,VecExp);
		day++;

	}

	while(terminate-day>=0){
		cout<<"Day: " <<day<<endl;

		every->everyDay(server,VecExp);


		day++;

	}

	delete(every);
	for (vector<CyberExpert *>::iterator it = VecExp.begin();it !=VecExp.end(); ++it) {
		delete *(it);
	}


	server->~CyberDNS();
	delete(server);
}




