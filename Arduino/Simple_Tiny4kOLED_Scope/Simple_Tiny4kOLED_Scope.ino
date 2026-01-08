/*


  ╔══════════════════════════════════╗
  ║           ╰──USB──╯              ║
  ║                                  ║
  ║         [Teensy 4.0]             ║
  ║      ARM Cortex-M7 600MHz        ║
  ║                                  ║
 ─╢GND                            VIN╟─
╳─╢RX1  CRX2   -0                 GND╟──⎡⎤──────┬──────┐
╳─╢TX1  CTX2   -1                 3V3╟──┤│──────│──────┼───┐
 ─╢     OUT2   -2  23- MCLK1 CRX1  A9╟──┤│────┐ │      │   │
 ─╢     LRCLK2 -3  22-       CTX1  A8╟──⎣⎦──┐ │ │      │   │
 ─╢     BCLK2  -4  21- BCLK1  RXS  A7╟─╳    │ │ │      │   │
 ─╢     IN2    -5  20-        TXS  A6╟─╳    │ │ │      │   │
 ─╢     OUT1D  -6  19-  SCL0       A5╟──⎡⎤──│─│─│──────┼───┼───┐
╳─╢RX2  OUT1A  -7  18-  SDA0       A4╟──⎣⎦──│─│─│──────┼───┼───┼───┐
╳─╢TX2  IN1    -8  17-  SDA1  TX4  A3╟─╳    │ │ │      │   │   │   │
 ─╢     OUT1C  -9  16-  SCL1  RX4  A2╟─╳    │ │ │  ╔═══╧═══╧═══╧═══╧═══╗
╳─╢MQSR CS     -10 15-        RX3  A1╟─╳    │ │ │  ║  GND VCC SCL SDA  ║
 ─╢MOSI CTX1   -11 14-        TX3  A0╟─╳    │ │ │  ║                   ║
╳─╢MISO MQSL   -12 13- CRX1   SCK LED╟─     │ │ │  ║┌─────────────────┐║
  ║                                  ║      │ │ │  ║│                 │║
  ╚══════════════════════════════════╝      │ │ │  ║│    [SSD1306]    │║
                  ┌─────────────────────────┘ │ │  ║│  64 x 32 OLED   │║
                  │ ╷     ╷                   │ │  ║│                 │║
                  └•⎺•─┬─•⎺•──────────────────┘ │  ║└─────────────────┘║
                       └────────────────────────┘  ╚═══════════════════╝


*/


#define OLEDSCOPE_DEBUG
//#define OLEDSCOPE_WIPER
#define SCOPE_PIN          A9
#define TINY4KOLED_WIDTH   64
#define TINY4KOLED_HEIGHT  32
//#define TINY4KOLED_MOD   r

#include "OLEDscope_v1.h"
OLEDscope scope;
uint8_t  x=0;
uint8_t  cnt=0;
uint32_t i2c_speed=0;


#ifdef OLEDSCOPE_DEBUG
          #include "zxpix_font.h"
          #define FONTZXPIX (&TinyOLEDFontzxpix)
          const DCfont *currentFont = FONTZXPIX;
#endif

void setup()
{

  
#ifdef OLEDSCOPE_DEBUG
          oled.setFont(currentFont);
#endif

    pinMode(SCOPE_PIN, INPUT);
    #ifdef LED_PIN
    pinMode(LED_PIN,OUTPUT);
    #endif
    //oled.begin(TINY4KOLED_WIDTH, TINY4KOLED_HEIGHT, sizeof(tiny4koled_init_64x32r), tiny4koled_init_64x32r);
    oled.begin(TINY4KOLED_WIDTH, TINY4KOLED_HEIGHT, sizeof(TINY4KOLED_INI), TINY4KOLED_INI);

    
    //Wire.setClock(100000);   // 100000 = 100 kHz, 400000 = 400 kHz (common fast-mode), 1000000 = 1MHz (ultra-fast)
    //Wire.setClock(400000);
    Wire.setClock(1000000);

    scope.begin();
    scope.debug();
}

void loop()
{
    if(cnt>63)
    {
      i2c_speed+=100;
      //Wire.setClock(i2c_speed);
      cnt=0;
    }
    cnt++;
    
    uint8_t y = analogRead(SCOPE_PIN) >> 2;
    //uint8_t y = digitalRead(SCOPE_PIN)?255:0;
    //uint8_t y = (1+sin(x/(2.5*3.14))) * 127;
    //uint8_t y = 20 * (64-x);
    //uint8_t y = x%10<5?(22*4):i;      // range 0-255

    scope.update(y);
    #ifdef LED_PIN
    if(y > 128)
         digitalWrite(LED_PIN,HIGH);
    else digitalWrite(LED_PIN,LOW);
    #endif

    x = x<TINY4KOLED_WIDTH-1?x+1:0;
}
