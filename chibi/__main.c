//#include "hw_gpio.h"
//#include "hw_watchdog.h"
//#include "hw_clk.h"
//
//#include "chibi/ch.h"
//
//Thread tcb_test;
//Mutex mutex_test;
//Semaphore semaphore_test;
//VirtualTimer virtual_timer_test;
//CondVar conditional_variable_test;
//GenericQueue message_queue_test;
//Mailbox mailbox_test;
//EventListener event_flag_test;
//
//
//static WORKING_AREA(waThread1, 128);
//static msg_t Thread1(void *p)
//{
//        /* Watchdog is enabled by ROM based bootloader */
//        hw_watchdog_freeze();
//
//        /* Configure GPIO used to drive LED D9 on DA14695 Daughter Board */
//        hw_gpio_set_pin_function(HW_GPIO_PORT_1, HW_GPIO_PIN_1, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
//        hw_gpio_pad_latch_enable(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//
//        /* Blink LED */
//        while (1) {
//            /* Turn LED on */
//            hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            /* Turn LED off */
//            hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            chThdSleepMilliseconds(10);
//        }
//        chThdExit(0);
//        return 0;
//}
//
//static WORKING_AREA(waThread2, 128);
//static msg_t Thread2(void *p)
//{
//        /* Watchdog is enabled by ROM based bootloader */
//        hw_watchdog_freeze();
//
//        /* Configure GPIO used to drive LED D9 on DA14695 Daughter Board */
//        hw_gpio_set_pin_function(HW_GPIO_PORT_1, HW_GPIO_PIN_1, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
//        hw_gpio_pad_latch_enable(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//
//        /* Blink LED */
//        while (1) {
//            /* Turn LED on */
//            hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            /* Turn LED off */
//            hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//            hw_clk_delay_usec(1000000);
//            chThdSleepMilliseconds(10);
//        }
//        chThdExit(0);
//        return 0;
//}
//
//static VirtualTimer led_vt;
//
//static void led_cb(void *arg) {
//        chVTSet(&led_vt, MS2ST(500), led_cb, NULL);
//}
//
//int main( void )
//{
//        chSysInit();
//
//        SysTick_Config(100000);
//
//        chVTSet(&led_vt, MS2ST(500), led_cb, NULL);
//
//        chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
//
//        chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);
//
//        while(1){
//                chThdSleepMilliseconds(10);
//        }
//}
