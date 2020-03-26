//#include "hw_gpio.h"
//#include "hw_watchdog.h"
//#include "hw_clk.h"
//
//#include "chibi/ch.h"
//
//typedef int ITEM;
//
//#define BUFFER_SIZE             5
//
//SEMAPHORE_DECL(mutex, 1);
//SEMAPHORE_DECL(sem_full, 0);
//SEMAPHORE_DECL(sem_empty, BUFFER_SIZE);
//
//int item_count, producer_index, consumer_index = 0;
//
//ITEM buffer[BUFFER_SIZE];
//
//void insert_item(ITEM item);
//void remove_item();
//
//msg_t producer(void *p);
//
//msg_t consumer(void *p);
//
//int main( void )
//{
//
//        WORKING_AREA(wa_producer1, 250);
//        WORKING_AREA(wa_producer2, 250);
//        WORKING_AREA(wa_producer3, 250);
//        WORKING_AREA(wa_consumer1, 250);
//        WORKING_AREA(wa_consumer2, 250);
//        WORKING_AREA(wa_consumer3, 250);
//        chSysInit();
//
//        SysTick_Config(100000);
//
//        chThdCreateStatic(wa_producer1, sizeof(wa_producer1), NORMALPRIO, producer, NULL);
//        chThdCreateStatic(wa_producer2, sizeof(wa_producer2), NORMALPRIO, producer, NULL);
//        chThdCreateStatic(wa_producer3, sizeof(wa_producer3), NORMALPRIO, producer, NULL);
//
//        chThdCreateStatic(wa_consumer1, sizeof(wa_consumer1), NORMALPRIO, consumer, NULL);
//        chThdCreateStatic(wa_consumer2, sizeof(wa_consumer2), NORMALPRIO, consumer, NULL);
//        chThdCreateStatic(wa_consumer3, sizeof(wa_consumer3), NORMALPRIO, consumer, NULL);
//
//        while(1);
//}
//
//void insert_item(ITEM item) {
//
//        while (item_count == BUFFER_SIZE);
//
//        buffer[producer_index] = item;
//
//        producer_index++;
//        producer_index = producer_index % BUFFER_SIZE;
//
//        item_count++;
//}
//
//void remove_item() {
//
//        while(item_count == 0);
//
//        buffer[consumer_index] = -1;
//
//        consumer_index++;
//        consumer_index = consumer_index % BUFFER_SIZE;
//
//        item_count--;
//}
//
//msg_t producer(void *p) {
//        ITEM item;
//        while(1) {
//                item = 1;
//
//                chSemWait(&sem_empty);
//
//                chSemWait(&mutex);
//
//                insert_item(item);
//
//                chSemSignal(&mutex);
//
//                chSemSignal(&sem_full);
//
//                chThdSleepMilliseconds(10);
//        }
//        chThdExit(0);
//        return 0;
//}
//
//msg_t consumer(void *p) {
//        while(1) {
//                chSemWait(&sem_full);
//
//                chSemWait(&mutex);
//
//                remove_item();
//
//                chSemSignal(&mutex);
//
//                chSemSignal(&sem_empty);
//
//                chThdSleepMilliseconds(10);
//        }
//        chThdExit(0);
//        return 0;
//}
