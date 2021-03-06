#include "MPU9150.h"

#include "Quaternion.h"

 

Serial debug(USBTX, USBRX);

MPU9150 imu(P0_22, P0_23, P0_0);

 

DigitalOut led(LED3);

char buffer[200];

int main(){
	float xavg=0;float yavg=0;float zavg=0; float w; float wavg =0; float mean =0; float sum_deviation;
	int n =0;
	float data[100];

    debug.baud(9600);

    if(imu.isReady()){

        //debug.printf("MPU9150 is ready\r\n");

    } else {

        //debug.printf("MPU9150 initialisation failure\r\n");

                                                while(true);

    }


    imu.initialiseDMP();


    Timer timer;

    timer.start();


    imu.setFifoReset(true);   

    imu.setDMPEnabled(true);   
   

    Quaternion q1;


    for(int i=0;i<100;i++){

 

        if(imu.getFifoCount() >= 48){

            imu.getFifoBuffer(buffer,  48);

            led = !led;

        }

       

        if(timer.read_ms() > 50){

            timer.reset();

          

           //This is the format of the data in the fifo,

           /* ================================================================================================ *

             | Default MotionApps v4.1 48-byte FIFO packet structure:                                           |

             |                                                                                                  |

             | [QUAT W][      ][QUAT X][      ][QUAT Y][      ][QUAT Z][      ][GYRO X][      ][GYRO Y][      ] |

             |   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  |

             |                                                                                                  |

             | [GYRO Z][      ][MAG X ][MAG Y ][MAG Z ][ACC X ][      ][ACC Y ][      ][ACC Z ][      ][      ] |

             |  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  |

             * ================================================================================================ */

            

           

            /* debug.printf("%d, %d, %d\r\n",  (int32_t)(((int32_t)buffer[34] << 24) + ((int32_t)buffer[35] << 16) + ((int32_t)buffer[36] << 8) + (int32_t)buffer[37]),

                                            (int32_t)(((int32_t)buffer[38] << 24) + ((int32_t)buffer[39] << 16) + ((int32_t)buffer[40] << 8) + (int32_t)buffer[41]),

                                            (int32_t)(((int32_t)buffer[42] << 24) + ((int32_t)buffer[43] << 16) + ((int32_t)buffer[44] << 8) + (int32_t)buffer[45]));

                                               

            debug.printf("%d, %d, %d\r\n",  (int32_t)(((int32_t)buffer[16] << 24) + ((int32_t)buffer[17] << 16) + ((int32_t)buffer[18] << 8) + (int32_t)buffer[19]),

                                            (int32_t)(((int32_t)buffer[20] << 24) + ((int32_t)buffer[21] << 16) + ((int32_t)buffer[22] << 8) + (int32_t)buffer[23]),

                                            (int32_t)(((int32_t)buffer[24] << 24) + ((int32_t)buffer[25] << 16) + ((int32_t)buffer[26] << 8) + (int32_t)buffer[27]));

                                           

            debug.printf("%d, %d, %d\r\n",  (int16_t)(buffer[29] << 8) + buffer[28],

                                            (int16_t)(buffer[31] << 8) + buffer[30],

                                            (int16_t)(buffer[33] << 8) + buffer[32]);

                                            

            debug.printf("%f, %f, %f, %f\r\n",

                (float)((((int32_t)buffer[0] << 24) + ((int32_t)buffer[1] << 16) + ((int32_t)buffer[2] << 8) + buffer[3]))* (1.0 / (1<<30)),

                (float)((((int32_t)buffer[4] << 24) + ((int32_t)buffer[5] << 16) + ((int32_t)buffer[6] << 8) + buffer[7]))* (1.0 / (1<<30)),

                (float)((((int32_t)buffer[8] << 24) + ((int32_t)buffer[9] << 16) + ((int32_t)buffer[10] << 8) + buffer[11]))* (1.0 / (1<<30)),

                (float)((((int32_t)buffer[12] << 24) + ((int32_t)buffer[13] << 16) + ((int32_t)buffer[14] << 8) + buffer[15]))* (1.0 / (1<<30)));

                */

           q1.decode(buffer);

           //debug.printf("%f, %f, %f, %f\r\n", q1.w, q1.v.x, q1.v.y, q1.v.z);



//debug.printf("w data:%f\t", q1.w);

/*xavg = xavg+ q1.v.x;

yavg = yavg+ q1.v.y;

zavg = zavg+ q1.v.z;
*/

//w = (q1.v.x)*(q1.v.x) + (q1.v.y)*(q1.v.y) + (q1.v.z)*(q1.v.z);
//wavg = wavg +w;
n++;

data[n] = q1.v.x;

xavg = xavg + data[n];

debug.printf("X :%f\t", data[n]);

debug.printf("Y axis data:%f\t", q1.v.y);

debug.printf("Z axis data:%f\t", q1.v.z); 
																																								

 

            //TeaPot Demo Packet for MotionFit SDK

           

            /* debug.putc('$'); //packet start

            debug.putc((char)2); //assume packet type constant

            debug.putc((char)0); //count seems unused

            for(int i = 0; i < 16; i++){ //16 bytes for 4 32bit floats

                debug.putc((char)(buffer[i]));

            }

            for(int i = 0; i < 5; i++){ //no idea, padded with 0

                debug.putc((char)0); } */

           

        }  

    }
		
		
mean = xavg/n;

% Activity evaluation using Standard deviation
for(int i=0; i<n;i++)
		{
    sum_deviation+=(data[i]-mean)*(data[i]-mean);		
		}
		
		debug.printf("Standard Dev.:%f\t", sum_deviation );
		
		if((sum_deviation > 0.008) && (sum_deviation < 0.28) )
		debug.printf("Slow Walk");
			else if ( (sum_deviation > 0.28) )
			debug.printf("Fast");
				else
					debug.printf("Idle");


//debug.printf("W axis avg:%f\t", wavg);

//debug.printf("Y axis avg:%f\t", yavg);

//debug.printf("Z axis avg:%f\t", zavg);
	}		
