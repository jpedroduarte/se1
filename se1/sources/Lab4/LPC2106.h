#ifndef LPC2106_h
#define LPC2106_h

#define GPIO_base 0xE0028000 
#define GPIO (*((GPIO_DSC *)GPIO_base))

#define LPC2106_BASE_TC0 ( *( (LPC210X_TC *) 0xE0004000) )
#define LPC2106_BASE_TC1 ( *( (LPC210X_TC *) 0xE0008000) )

#endif
