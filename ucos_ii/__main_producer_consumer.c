///**
// ****************************************************************************************
// *
// * @file main.c
// *
// * @brief Bare Metal (no OS) Blinky Example Application
// *
// * Copyright (c) 2020 Dialog Semiconductor. All rights reserved.
// *
// * This software ("Software") is owned by Dialog Semiconductor. By using this Software
// * you agree that Dialog Semiconductor retains all intellectual property and proprietary
// * rights in and to this Software and any use, reproduction, disclosure or distribution
// * of the Software without express written permission or a license agreement from Dialog
// * Semiconductor is strictly prohibited. This Software is solely for use on or in
// * conjunction with Dialog Semiconductor products.
// *
// * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES OR AS
// * REQUIRED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. EXCEPT AS OTHERWISE PROVIDED
// * IN A LICENSE AGREEMENT BETWEEN THE PARTIES OR BY LAW, IN NO EVENT SHALL DIALOG
// * SEMICONDUCTOR BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR
// * CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
// * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
// * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE SOFTWARE.
// *
// ****************************************************************************************
// */
//
//
//#include "resmgmt.h"
//#include "hw_cpm.h"
//#include "hw_gpio.h"
//#include "hw_watchdog.h"
//#include "sys_clock_mgr.h"
//#include "sys_power_mgr.h"
//
//#include "ucos_ii/ucos_ii.h"
//
//typedef int ITEM;
//
//#define BUFFER_SIZE             5
//
//OS_EVENT *mutex, *sem_empty, *sem_full;
//
//int item_count, producer_index, consumer_index = 0;
//
//ITEM buffer[BUFFER_SIZE];
//
//void insert_item(ITEM item);
//void remove_item();
//
//void producer(void *pdata);
//void consumer(void *pdata);
//
//int main( void ) {
//
//        SysTick_Config(100000);
//
//        INT8U err;
//
//        OS_STK producer1_stack_size[250];
//        OS_STK consumer1_stack_size[250];
//        OS_STK producer2_stack_size[250];
//        OS_STK consumer2_stack_size[250];
//        OS_STK producer3_stack_size[250];
//        OS_STK consumer3_stack_size[250];
//
//        OSInit();
//
//        mutex = OSMutexCreate(1, &err);
//        sem_full = OSSemCreate(0);
//        sem_empty = OSSemCreate(BUFFER_SIZE);
//
//        OSTaskCreate(producer, NULL, &producer1_stack_size[250-1], 2);
//        OSTaskCreate(consumer, NULL, &consumer1_stack_size[250-1], 3);
//        OSTaskCreate(producer, NULL, &producer2_stack_size[250-1], 4);
//        OSTaskCreate(consumer, NULL, &consumer2_stack_size[250-1], 5);
//        OSTaskCreate(producer, NULL, &producer3_stack_size[250-1], 6);
//        OSTaskCreate(consumer, NULL, &consumer3_stack_size[250-1], 7);
//
//        OSStart();
//
//        /* Blink LED */
//        while (1);
//}
//
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
//void producer(void *pdata){
//        ITEM item;
//        INT8U err;
//
//        while(1) {
//                item = 1;
//
//                OSSemPend(sem_empty, 0, &err);
//
//                OSMutexPend(mutex, 0, &err);
//
//                insert_item(item);
//
//                OSMutexPost(mutex);
//
//                OSSemPost(sem_full);
//
//                //OSTimeDly(10);
//        }
//}
//
//void consumer(void *pdata){
//        INT8U err;
//        while(1) {
//                OSSemPend(sem_full, 0, &err);
//
//                OSMutexPend(mutex, 0, &err);
//
//                remove_item();
//
//                OSMutexPost(mutex);
//
//                OSSemPost(sem_empty);
//
//                //OSTimeDly(10);
//        }
//}
