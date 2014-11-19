#ifndef GPIO_H
#define GPIO_H

extern void GPIO_config(unsigned int dir, unsigned int mask, unsigned int initvalue);

extern void GPIO_output(unsigned int value, unsigned int mask);

extern unsigned int GPIO_input();

#endif
