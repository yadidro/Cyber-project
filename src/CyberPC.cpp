
#include "../include/CyberPC.h"
#include "../include/CyberWorm.h"



CyberPC::CyberPC(const std::string cyber_pc_os,const std::string cyber_pc_name):
cyber_pc_os_(cyber_pc_os),cyber_pc_name_(cyber_pc_name){
	cyber_pc_time_to_infect_=0;

}
const std::string CyberPC::getName(){

	return cyber_pc_name_;
}

void CyberPC::AddConnection(std::string  second_pc){
	cyber_pc_connections_.push_back(second_pc);
}

void CyberPC::Infect(CyberWorm & worm){// Add a worm to this PC, passing by refernce
	if (worm.getWormOs()==cyber_pc_os_){

			delete cyber_worm_;

			cyber_worm_=new CyberWorm(worm);




		cyber_pc_time_to_infect_=worm.getWormDormancyTime();
		cout<<"          "<<cyber_pc_name_<<" infected by "<<worm.getWormName()<<endl;
	}
	else
		cout<<"          "<<"worm "<<worm.getWormName()<<"is incompatible with "<<cyber_pc_name_<<endl;
}




void CyberPC::Run(const CyberDNS& server){
	if(cyber_pc_time_to_infect_== 0 && cyber_worm_ !=0){

		cout<<"    "<<cyber_pc_name_<<"  infecting..."<<endl;
		for (vector<string>::iterator it = cyber_pc_connections_.begin(); it!= cyber_pc_connections_.end(); ++it){

			(server.GetCyberPC(*it)).Infect(*cyber_worm_);
			(server.GetCyberPC(*it)).cyber_pc_time_to_infect_+=1;

		}
	}


	else if(cyber_pc_time_to_infect_ >0 && cyber_worm_ !=NULL){
		cyber_pc_time_to_infect_--;
		cout<<"    "<<cyber_pc_name_<<": Worm "<<cyber_worm_->getWormName()<<" is dormant"<<endl;
	}

}



void CyberPC::setTimeToInfect(){
	if (cyber_pc_time_to_infect_!=0)
		cyber_pc_time_to_infect_=cyber_pc_time_to_infect_-1;
}










void  CyberPC::Disinfect(){// called by cyber expert, disinfect PC

	if (cyber_worm_!=NULL){
		cout<<"          "<<"worm"<<cyber_worm_->getWormName()<< " successfully removed from "<<cyber_pc_name_<<endl;
		//destructor
		delete (cyber_worm_);

		cyber_worm_=NULL;
	}
}



CyberPC::~CyberPC(){
	delete cyber_worm_;
	cyber_worm_=NULL;
}






CyberPC & CyberPC::operator=(const CyberPC& other){
	if (this!=&other){

		cyber_pc_time_to_infect_=other.cyber_pc_time_to_infect_;
		cyber_pc_connections_=other.cyber_pc_connections_;
		cyber_worm_=new CyberWorm(*(other.cyber_worm_));
	}
	return *this;
}


