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

  // configure pwm on pins 5 and 6 ( AIN0 and AIN1 )
  DDRB = 1 + 2;
  TCCR0A = (1<<COM0A1) | (0<<COM0A0) | (1<<COM0B1) | (0<<COM0B0) | (1<<WGM01) | (1<<WGM00);
  TCCR0B = (0<<WGM02) | (0<<CS02) | (0<<CS01) | (1<<CS00);
  OCR0A = 0x80;
  OCR0B = 255;
 
  // configure analog input on pin 2 ( ADC3 )
  DIDR0 = ( 1 << ADC3D );
  ADMUX = ( 0 << REFS0 ) | ( 1 << ADLAR ) | ( 1 << MUX1 ) | ( 1 << MUX0 );
  ADCSRB = 0;
  ADCSRA = ( 1 << ADEN ) | ( 1 << ADSC ) | ( 1 << ADATE ) | ( 0 << ADIF ) | ( 0 << ADIE ) | ( 1 << ADPS2 ) |( 0 << ADPS1 ) | ( 1 << ADPS0 );

  unsigned char value = 0;
  for( ;; ) {
    // read sample
    // read parameters
    //_delay_ms( 500 );
    //out1( 255);
    //_delay_ms(500);
    //out1(0);
    unsigned int readval = ADC >> 12;
    readval += 1;
    while( readval ) {
      _delay_ms(100);
      out1( 255 );
      _delay_ms(100);
      out1(0);
      readval--;
    }
    _delay_ms(400);
  }

}
