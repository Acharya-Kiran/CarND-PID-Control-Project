#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}


void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	
	PID::p_error = 0.0;
	PID::i_error = 0.0;
	PID::d_error = 0.0;
	
}

void PID::UpdateError(double cte) {
	PID::d_error = cte - p_error;
	PID::p_error = cte;
	PID::i_error += cte;
	
}

double PID::TotalError() {
	double total_error;
	total_error = -1*PID::Kp*PID::p_error - PID::Kd*PID::d_error - PID::Ki*PID::i_error;
	return total_error;
}

