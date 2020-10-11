#include "lcd.h"


void lcd_data(word data)
{
    if(data & 1) 
        D4 = 1;
    else
        D4 = 0;
    if(data & 2)
        D5 = 1;
    else
        D5 = 0;
    if(data & 4)
        D6 = 1;
    else
        D6 = 0;
    if(data & 8) 
        D7 = 1;
    else
        D7 = 0;
}

void lcd_cmd(word cmd)
{
    RS = 0;
    
    lcd_data(cmd);
    // Send The EN Clock Signal
    EN  = 1;         
    __delay_us(lcd_delay);
    EN  = 0;    
}
void lcd_init()
{
    lcd_port_d = 0x00;
    lcd_port = 0x00;
  // Initialization sequence from data sheet 
  lcd_data(0x00);
  __delay_ms(30);
  __delay_us(lcd_delay); 
  lcd_cmd(0x03);
  __delay_ms(5);
  lcd_cmd(0x03);
  __delay_us(150);
  lcd_cmd(0x03); 
  lcd_cmd(0x02);
  lcd_cmd(0x02);
  lcd_cmd(0x08);
  lcd_cmd(0x00);
  lcd_cmd(0x0C);
  lcd_cmd(0x00);
  lcd_cmd(0x06);
}

word get_high(word myword)
{
    word high4;
    high4 = myword & 0xf0 ;
    high4 = high4 >> 4  ;
    return high4 ;
}
word get_low(word myword)
{
    word low4 ;
    low4 = myword & 0x0f ;
    return low4 ;
}
void lcd_send_char(char mychar)
{
    RS = 1;
    lcd_data(get_high(mychar));  
   EN = 1;
   __delay_us(lcd_delay); 
   EN = 0;
   __delay_us(lcd_delay); 
   lcd_data(get_low(mychar)); 
   EN = 1;
   __delay_us(lcd_delay); 
   EN = 0;
   __delay_us(lcd_delay); 
}
void lcd_send_string(char* str)
{
    int i=0;
    while (str[i]!='\0')
    {
        lcd_send_char(str[i]);
        i++;
    }
}
void lcd_clear()
{
    lcd_cmd(0);
    lcd_cmd(1);
} 

void lcd_set_cursor(word raw,word col)
{
    word instruction ;
    if(raw == 1)
    {
      instruction  = 0x80 + col - 1; //0x80 is used to move the cursor
      
      lcd_cmd(get_high(instruction));
      lcd_cmd(get_low(instruction));
    }
    if(raw == 2)
    {
      instruction  = 0xC0 + col - 1;
      lcd_cmd(get_high(instruction));
      lcd_cmd(get_low(instruction));
    }
}

void lcd_shift_right()
{
    lcd_cmd(0x01);
    lcd_cmd(0x08);
}
void lcd_shift_left()
{
    lcd_cmd(0x01);
    lcd_cmd(0x0c);
}