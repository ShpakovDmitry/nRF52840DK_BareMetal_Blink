### GPIO
To toggle LED on/off firstly we need to configure corresponding GPIO as output.
It is done by writing logical one to `A` field into corresponding
`PIN_CFN[n]` register. To drive pin high or low `OUTSET` or `OUTCLR` registers
are used. nRF52840 has two GPIO ports `P0` and `P1` with corresponding
base addresses `0x5000000` and `0x50000300` respectively. Register `PIN_CFN[n]`
offset could be derived as `0x700 + (n x 0x4 )`. Registers `OUTSET` and `OUTCLR`
offsets are `0x508` and `0x50C` respectively.
![instances](images/instances.png)
![registers\_1](images/registers_1.png)
![registers\_2](images/registers_2.png)

Searching in DK hardware schematics file we can see that leds are connected to
`P0.[13-16]` pins.
![gpio mapping](images/gpio_mapping.png)

Also it could be seen that leds are active low, meaning that when GPIO output
is low then led is turned ON. This is so called sink mode. In source mode action
is opposite.
![leds](images/leds.png)

To blink led1 `P0.13` should be used. Also for blink there is some sort of delay
routine is needed. For simplicity `for` loop is used.
```c
#include <stdint.h>

#define BASE 0x50000000
#define OUTSET (*((uint32_t *) (BASE + 0x508)))
#define OUTCLR (*((uint32_t *) (BASE + 0x50C)))
#define PIN_CNF(pin) (*((uint32_t *) (BASE + 0x700 + pin * 0x4)))

#define LOOP_COUNT 1000000

int main(void) {
	unsigned int LED1 = 13;
	
	PIN_CFN(LED1) = 1
	
	while (1) {
		OUTSET = (1 << LED1);
		for (int i = 0; i < LOOP_COUNT; i++) {
			;
		}
		OUTCLR = (1 << LED1);
		for (int i = 0; i < LOOP_COUNT; i++) {
			;
		}
	}
}
```

---

> All information and images are taken from [NordicSemiconductors](https://infocenter.nordicsemi.com) site.
> Any copyright belongs to NordicSemiconductors©