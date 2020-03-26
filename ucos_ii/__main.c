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
//#include "ucos_ii.h"
//
//OS_EVENT sem_test;
//OS_TCB tcb_test;
//OS_FLAG_GRP  event_flag_test;
//OS_Q   message_queue_test;
//OS_TMR  timer_test;
//
//void RandomNumberTask(void *pdata){
//
//        /* Blink LED */
//        while (1) {
//            /* Turn LED on */
//            hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            /* Turn LED off */
//            hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//        }
//}
//void RandomNumberTask1(void *pdata){
//
//        /* Blink LED */
//
//            /* Turn LED on */
//            hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            /* Turn LED off */
//            hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//
//            OSTaskDel(OS_PRIO_SELF);
//
//}
//OS_STK Task6Stack[200];
//OS_STK Task5Stack[200];
//
//
//int main( void ) {
//        /* Watchdog is enabled by ROM based bootloader */
//        hw_watchdog_freeze();
//
//        /* Configure GPIO used to drive LED D9 on DA14695 Daughter Board */
//        hw_gpio_set_pin_function(HW_GPIO_PORT_1, HW_GPIO_PIN_1, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
//        hw_gpio_pad_latch_enable(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//
//        SysTick_Config(100000);
//
//        OSInit();
//
//        OSTaskCreate(RandomNumberTask,  NULL, &Task6Stack[200-1], 6);
//        OSTaskCreate(RandomNumberTask1, NULL, &Task5Stack[200-1], 5);
//
//        OSStart();
//
//        /* Blink LED */
//        while (1) {
//            /* Turn LED on */
//            hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            /* Turn LED off */
//            hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//
//
//        }
//}
