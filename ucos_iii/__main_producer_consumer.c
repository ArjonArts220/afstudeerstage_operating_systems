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
//#include "resmgmt.h"
//#include "hw_cpm.h"
//#include "hw_gpio.h"
//#include "hw_watchdog.h"
//#include "sys_clock_mgr.h"
//#include "sys_power_mgr.h"
//
//
//#include "ucos_iii/Source/os.h"
//
//
//typedef int ITEM;
//
//#define BUFFER_SIZE             5
//
//OS_SEM  sem_empty, sem_full;
//OS_MUTEX mutex;
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
//#define  APP_CFG_TASK_START_STK_SIZE                     250u
//#define  APP_CFG_TASK_START_PRIO                           2u
//#define  APP_CFG_TASK_START_STK_SIZE_PCT_FULL             90u
//#define  APP_CFG_TASK_START_STK_SIZE_LIMIT       (APP_CFG_TASK_START_STK_SIZE * (100u - APP_CFG_TASK_START_STK_SIZE_PCT_FULL))   / 100u
//
////.long   OS_CPU_PendSVHandler          /* PendSV Handler */
////.long   OS_CPU_SysTickHandler         /* SysTick Handler */
//
//OS_TCB  producer1TCB;
//OS_TCB  producer2TCB;
//OS_TCB  producer3TCB;
//OS_TCB  consumer1TCB;
//OS_TCB  consumer2TCB;
//OS_TCB  consumer3TCB;
//
//int main( void ) {
//        OS_ERR os_err;
//
//        CPU_STK producer1_stack_size[APP_CFG_TASK_START_STK_SIZE];
//        CPU_STK consumer1_stack_size[APP_CFG_TASK_START_STK_SIZE];
//        CPU_STK producer2_stack_size[APP_CFG_TASK_START_STK_SIZE];
//        CPU_STK consumer2_stack_size[APP_CFG_TASK_START_STK_SIZE];
//        CPU_STK producer3_stack_size[APP_CFG_TASK_START_STK_SIZE];
//        CPU_STK consumer3_stack_size[APP_CFG_TASK_START_STK_SIZE];
//        SysTick_Config(100000);
//
//        CPU_Init();
//
//        OSInit(&os_err);
//        OSMutexCreate(&mutex, "My Semaphore", &os_err);
//        OSSemCreate(&sem_empty, "My Semaphore", (OS_SEM_CTR)BUFFER_SIZE, &os_err);
//        OSSemCreate(&sem_full, "My Semaphore", (OS_SEM_CTR)0, &os_err);
//
//        OSTaskCreate(   (OS_TCB      *) &producer1TCB,
//                        (CPU_CHAR    *) "vLEDTask1",
//                        (OS_TASK_PTR) producer,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) producer1_stack_size,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//
//        OSTaskCreate(   (OS_TCB      *) &producer2TCB,
//                        (CPU_CHAR    *) "vLEDTask1",
//                        (OS_TASK_PTR) producer,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) producer2_stack_size,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//
//        OSTaskCreate(   (OS_TCB      *) &producer3TCB,
//                        (CPU_CHAR    *) "vLEDTask1",
//                        (OS_TASK_PTR) producer,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) producer3_stack_size,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//
//        OSTaskCreate(   (OS_TCB      *) &consumer1TCB,
//                        (CPU_CHAR    *) "vLEDTask2",
//                        (OS_TASK_PTR) consumer,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) consumer1_stack_size,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//        OSTaskCreate(   (OS_TCB      *) &consumer2TCB,
//                        (CPU_CHAR    *) "vLEDTask2",
//                        (OS_TASK_PTR) consumer,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) consumer2_stack_size,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//        OSTaskCreate(   (OS_TCB      *) &consumer3TCB,
//                        (CPU_CHAR    *) "vLEDTask2",
//                        (OS_TASK_PTR) consumer,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) consumer3_stack_size,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//
//        OSStart(&os_err);
//
//        while (1);
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
//void producer(void *pdata){
//        ITEM item;
//        OS_ERR  err;
//        CPU_TS  ts;
//
//        while(1) {
//                item = 1;
//
//                OSSemPend(&sem_empty, 20, OS_OPT_PEND_BLOCKING, &ts, &err);
//
//                OSMutexPend(&mutex, 20, OS_OPT_PEND_BLOCKING, &ts, &err);
//
//                insert_item(item);
//
//                OSMutexPost(&mutex, OS_OPT_POST_1, &err);
//
//                OSSemPost(&sem_full, OS_OPT_POST_1, &err);
//
//                //OSTimeDly(10);
//        }
//}
//
//void consumer(void *pdata){
//        OS_ERR  err;
//        CPU_TS  ts;
//        while(1) {
//                OSSemPend(&sem_full, 20, OS_OPT_PEND_BLOCKING, &ts, &err);
//
//                OSMutexPend(&mutex, 20, OS_OPT_PEND_BLOCKING, &ts, &err);
//
//                remove_item();
//
//                OSMutexPost(&mutex, OS_OPT_POST_1, &err);
//
//                OSSemPost(&sem_empty, OS_OPT_POST_1, &err);
//
//                //OSTimeDly(10);
//        }
//}
