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
//OS_MUTEX mutex_test;
//OS_SEM  sem_test;
//OS_TCB  tcb_test;
//OS_FLAG_GRP  event_flag_test;
//OS_Q   message_queue_test;
//OS_TMR  timer_test;
//
//#define OS_UCOS_III
//
//#define  APP_CFG_TASK_START_STK_SIZE                     250u
//#define  APP_CFG_TASK_START_PRIO                           2u
//#define  APP_CFG_TASK_START_STK_SIZE_PCT_FULL             90u
//#define  APP_CFG_TASK_START_STK_SIZE_LIMIT       (APP_CFG_TASK_START_STK_SIZE * (100u - APP_CFG_TASK_START_STK_SIZE_PCT_FULL))   / 100u
//
//static OS_TCB  vLEDTask1TCB;
//static CPU_STK vLEDTask1Stk[APP_CFG_TASK_START_STK_SIZE];
//
//static OS_TCB  vLEDTask2TCB;
//static CPU_STK vLEDTask2Stk[APP_CFG_TASK_START_STK_SIZE];
//
//static void vLEDTask1(void *p_arg)
//{
//        while(1)
//        {
//                /* Turn LED on */
//                hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//                hw_clk_delay_usec(1000000);
//                /* Turn LED off */
//                hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//                hw_clk_delay_usec(1000000);
//        }
//}
//
//static void vLEDTask2(void *p_arg)
//{
//        while(1) {
//                /* Turn LED on */
//                hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//                hw_clk_delay_usec(1000000);
//                /* Turn LED off */
//                hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//                hw_clk_delay_usec(1000000);
//        }
//}
//
////.long   OS_CPU_PendSVHandler          /* PendSV Handler */
////.long   OS_CPU_SysTickHandler         /* SysTick Handler */
//
//int main( void ) {
//        /* Watchdog is enabled by ROM based bootloader */
//        hw_watchdog_freeze();
//
//        /* Configure GPIO used to drive LED D9 on DA14695 Daughter Board */
//        hw_gpio_set_pin_function(HW_GPIO_PORT_1, HW_GPIO_PIN_1, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
//        hw_gpio_pad_latch_enable(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//
//        OS_ERR os_err;
//
//        SysTick_Config(100000);
//
//        CPU_Init();
//
//        OSInit(&os_err);
//
//        OSTaskCreate(   (OS_TCB      *) &vLEDTask1TCB,
//                        (CPU_CHAR    *) "vLEDTask1",
//                        (OS_TASK_PTR) vLEDTask1,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) vLEDTask1Stk,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE_LIMIT,
//                        (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
//                        (OS_MSG_QTY) 0u,
//                        (OS_TICK) 20u,
//                        (void        *) 0,
//                        (OS_OPT) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
//                        (OS_ERR      *) &os_err);
//
//        OSTaskCreate(   (OS_TCB      *) &vLEDTask2TCB,
//                        (CPU_CHAR    *) "vLEDTask2",
//                        (OS_TASK_PTR) vLEDTask2,
//                        (void        *) 0,
//                        (OS_PRIO) APP_CFG_TASK_START_PRIO,
//                        (CPU_STK     *) vLEDTask2Stk,
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
