/*
 * File:   main.c
 * Author: acer
 *
 * Created on October 7, 2020, 11:57 PM
 */


#include <xc.h>
#include "config.h"
#include "lcd.h"


void main(void) {
    lcd_init();
    lcd_clear();
    lcd_set_cursor(1,1); 
    lcd_send_string("   STARKS TEAM");
    
    
    
    
    while(1)
    {
    __delay_ms(500);
    lcd_shift_right();
    __delay_ms(500);
    lcd_shift_left();
    }
    
    return;
}
