

/* 
 * File:  lcd_header
 * Author: Asem Moustafa Badr
 * Comments: 
 * Revision history: 
 */


#ifndef XC_HEADER_lcd_H
#define	XC_HEADER_lcd_H
#include <xc.h>
#define _XTAL_FREQ 4000000


#define lcd_delay 500
#define lcd_port_d TRISB 
#define lcd_port PORTB 
#define RS RB5
#define EN RB4
#define D4 RB0
#define D5 RB1
#define D6 RB2
#define D7 RB3

typedef unsigned char word ;
/**************************/

void lcd_init();
void lcd_clear();
void lcd_set_cursor(word raw,word col);
void lcd_data(word data);
void lcd_cmd(word cmd);
void lcd_data(word data);
void lcd_send_char(char);
void lcd_send_string(char*);
word get_high(word);
word get_low(word);
void lcd_shift_right();
void lcd_shift_left();
#endif	

