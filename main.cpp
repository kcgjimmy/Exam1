#include "mbed.h"
#include "stm32l475e_iot01_accelero.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
//InterruptIn btnRecord(BUTTON1);
//EventQueue queue(32 * EVENTS_EVENT_SIZE);
//Thread t;

int16_t pDataXYZ[3] = {0};
//int idR[32] = {0};
//int indexR = 0;

/*
void record(void) {
   BSP_ACCELERO_AccGetXYZ(pDataXYZ);
   printf("%d, %d, %d\n", pDataXYZ[0], pDataXYZ[1], pDataXYZ[2]);
}

void startRecord(void) {
   printf("---start---\n");
   idR[indexR++] = queue.call_every(1ms, record);
   indexR = indexR % 32;
}

void stopRecord(void) {
   printf("---stop---\n");
   for (auto &i : idR)
      queue.cancel(i);
}*/

int main() {
    ThisThread::sleep_for(1s);
    printf("uLCD printing...\n");
    uLCD.printf("\nHello uLCD World\n");
    ThisThread::sleep_for(1s);

    printf("Done.\n");
    printf("Start accelerometer init\n");
    BSP_ACCELERO_Init();
    ThisThread::sleep_for(1s);
    while(1) {
        BSP_ACCELERO_AccGetXYZ(pDataXYZ);
        //printf("%d, %d, %d\n", pDataXYZ[0], pDataXYZ[1], pDataXYZ[2]);
        
        uLCD.locate(1, 2);
        uLCD.printf("X:%d     ", pDataXYZ[0]);
        uLCD.locate(1, 3);
        uLCD.printf("Y:%d     ", pDataXYZ[1]);
        uLCD.locate(1, 4);
        uLCD.printf("Z:%d     ", pDataXYZ[2]);
    }
   /*
   t.start(callback(&queue, &EventQueue::dispatch_forever));
   btnRecord.fall(queue.event(startRecord));
   btnRecord.rise(queue.event(stopRecord));*/
}
