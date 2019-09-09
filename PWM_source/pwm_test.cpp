#include "pwm.hpp"

int PWM_test(){

	wire OutPWM;
	wire Rst = 0;
	wire Rst_r;
	wire EN = 1;
	wire EN_r;
	data16 LoadValCnt = 10;
	data16 LoadValCnt_r;
	int res = 0;

	PWM_CTRL(LoadValCnt, &LoadValCnt_r, EN, &EN_r, Rst, &Rst_r);

	for (int i = 0; i <= LoadValCnt; i++){

		PWM(LoadValCnt_r, EN_r, Rst_r, &OutPWM);

		if((i == (LoadValCnt - 1)) & (OutPWM == 1)) res++;
		if((i == LoadValCnt) & (OutPWM == 0)) res--;
		}

	if(res == 0){
		std::cout << "**********Test PASS**********"<< std::endl;
		return 0;
	}
	else{
		std::cout << "**********Test FAIL**********"<< std::endl;
		return 1;
	}
};


int main(){

	return PWM_test();

}



