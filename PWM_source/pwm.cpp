		#include "pwm.hpp"

		void PWM_CTRL(data16 LoadValCnt,
					  data16 *LoadValCnt_r,
					  wire EN,
					  wire *EN_r,
					  wire Rst,
					  wire *Rst_r
					  ){
		#pragma HLS INTERFACE ap_none port=LoadValCnt_r
		#pragma HLS INTERFACE ap_none port=Rst_r
		#pragma HLS INTERFACE ap_none port=EN_r
		#pragma HLS INTERFACE s_axilite port=Rst bundle=CTRL
		#pragma HLS INTERFACE s_axilite port=EN bundle=CTRL
		#pragma HLS INTERFACE s_axilite port=LoadValCnt bundle=CTRL
		#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

			*LoadValCnt_r = LoadValCnt;
			*EN_r = EN;
			*Rst_r = Rst;
		};

		void PWM(data16 LoadValCnt,
				 wire EN,
				 wire Rst,
				 wire* OutPWM
				 ){
		#pragma HLS INTERFACE ap_none port=OutPWM
		#pragma HLS INTERFACE ap_ctrl_none port=return

		static data16 counter = 0;

		*OutPWM = (counter < LoadValCnt) ? 1 : 0;

		if(!Rst & EN){
				counter++;
			}
			else{
				counter = 0;
			}
		};


