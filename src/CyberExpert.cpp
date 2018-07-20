#include "../include/CyberExpert.h"




CyberExpert::CyberExpert(std::string cyber_expert_name, int cyber_expert_work_time,
		int cyber_expert_rest_time, int cyber_expert_efficiency):
		cyber_expert_name_(cyber_expert_name),
		cyber_expert_work_time_(cyber_expert_work_time),
		cyber_expert_rest_time_(cyber_expert_rest_time),
		cyber_expert_efficiency_(cyber_expert_efficiency){
        count_work_time=cyber_expert_work_time;
		count_rest_time=cyber_expert_rest_time;

}
void CyberExpert::Clean(CyberPC & cyber_pc){
	cout<<"    "<<cyber_expert_name_<<" examining "<<cyber_pc.getName()<<endl;
	cyber_pc.Disinfect();
}



void CyberExpert::Set_cyber_rest_time(){
	if(cyber_expert_rest_time_==count_rest_time)
		cout<<"    "<<cyber_expert_name_<<" is back to work"<<endl;
	if (count_work_time> 1) {

		count_rest_time=count_rest_time-1;
	}
	else{
		count_rest_time= cyber_expert_rest_time_;
		count_work_time= cyber_expert_work_time_;

	}
}
int CyberExpert::getRestConstTime(){
  return cyber_expert_rest_time_;
}






void CyberExpert::set_cyber_work_time(){
	if(count_work_time== 1){
			cout<<"	"<<cyber_expert_name_<<" is taking a break"<<endl;
	}
	if (count_work_time > 0) {

		count_work_time--;
	}
}

int CyberExpert::getEfficiency(){
	return cyber_expert_efficiency_;
}
int CyberExpert::getWorkingTime(){
	return count_work_time;
}
int CyberExpert::getRestTime(){
	return count_rest_time;
}
CyberExpert::CyberExpert(const CyberExpert &other):
	cyber_expert_name_(other.cyber_expert_name_),
	cyber_expert_work_time_(other.cyber_expert_work_time_),
	cyber_expert_rest_time_(other.cyber_expert_rest_time_),
	cyber_expert_efficiency_(other.cyber_expert_efficiency_){
	count_rest_time=other.count_rest_time;
	count_work_time=other.count_work_time;
}



