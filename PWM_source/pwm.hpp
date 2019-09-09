#include <ap_int.h>
#include <stdio.h>

typedef ap_uint<1>  wire;
typedef ap_uint<16> data16;

void PWM(data16 LoadValCnt, wire EN, wire Rst, wire* OutPWM);

void PWM_CTRL(data16 LoadValCnt, data16 *LoadValCnt_r, wire EN, wire *EN_r, wire Rst, wire *Rst_r);

int PWM_test();


