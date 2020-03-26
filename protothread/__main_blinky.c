//#include "hw_gpio.h"
//#include "hw_watchdog.h"
//#include "hw_clk.h"
//
//
//#include "protothread/pt.h"
//
//struct pt pt_struct;
//
//PT_THREAD(example(struct pt *pt)) {
//
//        PT_BEGIN(pt);
//
//        while(1) {
//                /* Turn LED on */
//                hw_gpio_set_active(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//                hw_clk_delay_usec(1000000);
//                /* Turn LED off */
//                hw_gpio_set_inactive(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//                hw_clk_delay_usec(1000000);
//        }
//        PT_END(pt);
//}
//
//int main( void )
//{
//        /* Watchdog is enabled by ROM based bootloader */
//        hw_watchdog_freeze();
//
//        /* Configure GPIO used to drive LED D9 on DA14695 Daughter Board */
//        hw_gpio_set_pin_function(HW_GPIO_PORT_1, HW_GPIO_PIN_1, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
//        hw_gpio_pad_latch_enable(HW_GPIO_PORT_1, HW_GPIO_PIN_1);
//
//        for (;;) {
//                example(&pt_struct);
//        }
//        while(1);
//
//}
//
//
