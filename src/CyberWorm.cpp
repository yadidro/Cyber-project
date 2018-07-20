#include "../include/CyberWorm.h"


CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time):
	cyber_worm_os_(cyber_worm_os),
	cyber_worm_name_(cyber_worm_name),
	cyber_worm_dormancy_time_(cyber_worm_dormancy_time){
}

const std::string CyberWorm::getWormName(){

	return cyber_worm_name_;
}
const std::string CyberWorm::getWormOs(){
	return cyber_worm_os_;
}
const int CyberWorm::getWormDormancyTime(){
	return cyber_worm_dormancy_time_;
}


CyberWorm::CyberWorm(const CyberWorm& other):
		cyber_worm_os_(other.cyber_worm_os_),
		cyber_worm_name_(other.cyber_worm_name_),

	cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_){
}
CyberWorm & CyberWorm::operator=(const CyberWorm& other){
	if (this!=&other){
		*this=CyberWorm(other);
	}
	return *this;

}






