/*
 *   file: main.c
 * author: ShpakovDmitry
 *   date: 2020-08-20
 */

/* GPIO_0 direction set/clear registers; */
#define GPIO_0_DIRSET (*(volatile __UINT32_TYPE__* )0x50000518u)
#define GPIO_0_DIRCLR (*(volatile __UINT32_TYPE__* )0x5000051Cu)

/* GPIO_0 output set/clear registers */
#define GPIO_0_OUTSET (*(volatile __UINT32_TYPE__* )0x50000508u)
#define GPIO_0_OUTCLR (*(volatile __UINT32_TYPE__* )0x5000050Cu)

#define LED_PIN 13

void delay_loop();

int main(void) {
    /* LED1 on DK is at GPIO port 0 and pin 13 */
    /* set this port as output */
    GPIO_0_DIRSET = 1 << LED_PIN;
    
    while (1) {
        GPIO_0_OUTSET = 1 << LED_PIN;
        delay_loop();
        GPIO_0_OUTCLR = 1 << LED_PIN;
        delay_loop();
    }
    
    return 0;
}

void delay_loop() {
    for (volatile __UINT32_TYPE__ i = 0; i < 0x00100000; ++i ) {
        ;
    }
}
