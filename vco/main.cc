#define F_CPU 9600000UL // 9.6 Mhz
#include <avr/io.h>
#include <util/delay.h>

void out1( unsigned char value ) {
  // set pwm output pin 1
  OCR0A = value;
}

void out2( unsigned char value ) {
  // set pwm output pin 2
  OCR0B = value;
}

int read1() {
  return 0;
}

int main(void) {

  DDRB = 1 + 2;
  TCCR0A = (1<<COM0A1) | (0<<COM0A0) | (1<<COM0B1) | (0<<COM0B0) | (1<<WGM01) | (1<<WGM00);
  TCCR0B = (0<<WGM02) | (0<<CS02) | (0<<CS01) | (1<<CS00);
  OCR0A = 0x80;
  OCR0B = 255;
 
  // toggle portB pin 0
  //DDRB = 1;
  //PORTB = 1;

  unsigned char value = 0;
  for( ;; ) {
    // read sample
    // read parameters
    //_delay_ms( 500 );
    //out1( 255);
    //_delay_ms(500);
    //out1(0);
    _delay_ms(4);
    value = value + 1;
    out1( value );
    out2( 255 - value );
  }

}
