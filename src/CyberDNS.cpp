#include "../include/CyberDNS.h"

CyberDNS::CyberDNS() {
}

void CyberDNS::AddPC(CyberPC & cyber_pc_) {
	cyber_DNS_.insert(
			pair<const string, CyberPC&>(cyber_pc_.getName(), cyber_pc_));
}

CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const {
	return cyber_DNS_.find(cyber_pc_name)->second;
}
vector<string> CyberDNS::GetCyberPCList() {
	vector<string> pcList;
	for (map<const string, CyberPC &>::iterator it = cyber_DNS_.begin();
			it != cyber_DNS_.end(); ++it) {
		pcList.push_back(it->first);
	}
	reverse(pcList.begin(), pcList.end());
	return pcList;
}
void CyberDNS::BuildNetwork(const string &filename) {
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(filename, pt);
	BOOST_FOREACH(ptree::value_type &curEvent, pt) {
		if (curEvent.first == "computer") {
			string computerName = curEvent.second.get<string>("name");
			string computerOs = curEvent.second.get<string>("os");
			CyberPC* newPC = new CyberPC(computerOs, computerName);
			cout << "Adding to server: " << computerName << endl;
			AddPC(*newPC);
			cout << computerName << " connected to server" << endl;
		}
		if (curEvent.first == "wire") {
			string FirstPc = curEvent.second.get<string>("pointA");
			string SecondPc = curEvent.second.get<string>("pointB");
			cout << "Connecting " << FirstPc << " to " << SecondPc << endl;
			GetCyberPC(FirstPc).AddConnection(SecondPc);
			GetCyberPC(SecondPc).AddConnection(FirstPc);
			cout << "    " << FirstPc << " now connected to " << SecondPc
					<< endl;
			cout << "    " << SecondPc << " now connected to " << FirstPc
					<< endl;
		}
	}
}

CyberDNS& CyberDNS::operator=(const CyberDNS& other) // copy assignment
		{
	if (this != &other) { // self-assignment check expected
		for (map<const string, CyberPC &>::iterator it = cyber_DNS_.begin();
				it != cyber_DNS_.end(); ++it) {
			AddPC(it->second);
		}
	}
	return *this;
}

CyberDNS::~CyberDNS() {

	for (map<const string, CyberPC &>::iterator it = cyber_DNS_.begin();
			it != cyber_DNS_.end(); ++it) {
		delete &(it->second);
	}
	cyber_DNS_.clear();
}

