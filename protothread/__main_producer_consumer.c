//#include "hw_gpio.h"
//#include "hw_watchdog.h"
//#include "hw_clk.h"
//
//
//#include "protothread/pt.h"
//
//#include "protothread/pt-sem.h"
//
//
//typedef int ITEM;
//
//#define BUFFER_SIZE             5
//
//ITEM buffer[BUFFER_SIZE];
//
//struct pt_sem mutex, full, empty; /* Semaphores are useless, but needed for footprint comparison */
//
//int item_count, producer_index, consumer_index = 0;
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
//PT_THREAD(producer1(struct pt *pt))
//{
//
//  PT_BEGIN(pt);
//
//  ITEM item = 1;
//
//  while(1){
//          PT_SEM_WAIT(pt, &full);
//
//          PT_SEM_WAIT(pt, &mutex);
//
//          insert_item(item);
//
//          PT_SEM_SIGNAL(pt, &mutex);
//
//          PT_SEM_SIGNAL(pt, &empty);
//
//          PT_WAIT_UNTIL(pt, item_count != BUFFER_SIZE );
//  }
//
//  PT_END(pt);
//}
//
//PT_THREAD(producer2(struct pt *pt))
//{
//
//  PT_BEGIN(pt);
//
//  ITEM item = 1;
//
//  while(1){
//          PT_SEM_WAIT(pt, &full);
//
//          PT_SEM_WAIT(pt, &mutex);
//
//          insert_item(item);
//
//          PT_SEM_SIGNAL(pt, &mutex);
//
//          PT_SEM_SIGNAL(pt, &empty);
//
//          PT_WAIT_UNTIL(pt, item_count != BUFFER_SIZE );
//  }
//
//  PT_END(pt);
//}
//
//PT_THREAD(producer3(struct pt *pt))
//{
//
//  PT_BEGIN(pt);
//
//  ITEM item = 1;
//
//  while(1){
//          PT_SEM_WAIT(pt, &full);
//
//          PT_SEM_WAIT(pt, &mutex);
//
//          insert_item(item);
//
//          PT_SEM_SIGNAL(pt, &mutex);
//
//          PT_SEM_SIGNAL(pt, &empty);
//
//          PT_WAIT_UNTIL(pt, item_count != BUFFER_SIZE );
//  }
//
//  PT_END(pt);
//}
//
//PT_THREAD(consumer1(struct pt *pt))
//{
//
//  PT_BEGIN(pt);
//
//  while(1){
//
//          PT_SEM_WAIT(pt, &empty);
//
//          PT_SEM_WAIT(pt, &mutex);
//
//          remove_item();
//
//          PT_SEM_SIGNAL(pt, &mutex);
//
//          PT_SEM_SIGNAL(pt, &full);
//
//          PT_WAIT_UNTIL(pt, item_count != 0 );
//  }
//
//  PT_END(pt);
//}
//
//PT_THREAD(consumer2(struct pt *pt))
//{
//
//  PT_BEGIN(pt);
//
//  while(1){
//
//          PT_SEM_WAIT(pt, &empty);
//
//          PT_SEM_WAIT(pt, &mutex);
//
//          remove_item();
//
//          PT_SEM_SIGNAL(pt, &mutex);
//
//          PT_SEM_SIGNAL(pt, &full);
//
//          PT_WAIT_UNTIL(pt, item_count != 0 );
//  }
//
//  PT_END(pt);
//}
//
//PT_THREAD(consumer3(struct pt *pt))
//{
//
//  PT_BEGIN(pt);
//
//  while(1){
//
//          PT_SEM_WAIT(pt, &empty);
//
//          PT_SEM_WAIT(pt, &mutex);
//
//          remove_item();
//
//          PT_SEM_SIGNAL(pt, &mutex);
//
//          PT_SEM_SIGNAL(pt, &full);
//
//          PT_WAIT_UNTIL(pt, item_count != 0 );
//  }
//
//  PT_END(pt);
//}
//
//
//
//struct pt pt_producer1, pt_producer2, pt_producer3;
//struct pt pt_consumer1, pt_consumer2, pt_consumer3;
//
//int main( void )
//{
//        PT_SEM_INIT(&empty, 0);
//        PT_SEM_INIT(&full, BUFFER_SIZE);
//        PT_SEM_INIT(&mutex, 1);
//
//        PT_INIT(&pt_producer1);
//        PT_INIT(&pt_consumer1);
//        PT_INIT(&pt_producer2);
//        PT_INIT(&pt_consumer2);
//        PT_INIT(&pt_producer3);
//        PT_INIT(&pt_consumer3);
//
//        for (;;) {
//                producer1(&pt_producer1);
//                consumer1(&pt_consumer1);
//                producer2(&pt_producer2);
//                consumer2(&pt_consumer2);
//                producer3(&pt_producer3);
//                consumer3(&pt_consumer3);
//        }
//        while(1);
//
//}
//
//
