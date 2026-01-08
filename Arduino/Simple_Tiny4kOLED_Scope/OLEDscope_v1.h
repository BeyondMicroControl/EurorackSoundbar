//TINY4KOLED

#ifndef TINY4KOLED_WIDTH
#define TINY4KOLED_WIDTH  128
#endif
#ifndef TINY4KOLED_HEIGHT
#define TINY4KOLED_HEIGHT 64
#endif
#ifndef TINY4KOLED_MOD
#define TINY4KOLED_MOD
#endif
#if TINY4KOLED_HEIGHT == 64
#define TINY4KOLED_DIV 2
#endif
#if TINY4KOLED_HEIGHT == 48
#define TINY4KOLED_DIV 3
#endif
#if TINY4KOLED_HEIGHT == 32
#define TINY4KOLED_DIV 4
#endif
#if TINY4KOLED_HEIGHT == 16
#define TINY4KOLED_DIV 5
#endif

#define TINY4KOLED_PAGES (TINY4KOLED_HEIGHT >> 3)

#define PASTE(a,b) a##b
#define CONCAT(a,b) PASTE(a,b)
#define MAKE_NAME(s1, s2, s3, s4, s5) CONCAT(CONCAT(CONCAT(CONCAT(s1, s2), s3), s4), s5)
#define TINY4KOLED_INI MAKE_NAME(tiny4koled_init_,TINY4KOLED_WIDTH,x,TINY4KOLED_HEIGHT,TINY4KOLED_MOD)


#include <Tiny4kOLED.h>

class OLEDscope
{
  public:
    OLEDscope() :  x(0), y0(0) {}

    void begin()
    {
        oled.enableChargePump();
        oled.clear();
        oled.on();
    }

    void debug(uint8_t val = 0)
    {
        #ifdef OLEDSCOPE_DEBUG

        #define STRINGIFY(x) #x
        #define TOSTRING(x) STRINGIFY(x)

        switch(val)
        {
            case 0:
                oled.setCursor(0, 0);
                oled.print("TINY4KOLED_INI=");
                oled.println(TOSTRING(TINY4KOLED_INI));
                oled.print("TINY4KOLED_DIV=");
                oled.println(TOSTRING(TINY4KOLED_DIV));
                oled.print("TINY4KOLED_PAGES=");
                oled.println(PAGES);
                delay(8000);
                break;
            default:
                oled.setCursor(0, 0);
                oled.print(val);
                break;
        }
        #endif
    }

    int update(uint8_t byte_value)      // value range = 0-255
    {
        uint8_t y1 =(TINY4KOLED_HEIGHT-1) - (byte_value >> TINY4KOLED_DIV);   // pixel position of y1
        if((x&1)==1) debug(y1);
        vline(x, y0, y1);
        x++; y0 = y1; if(x == TINY4KOLED_WIDTH) x = 0;
        return byte_value;
    }

  private:
    uint8_t x, y0;
    const uint8_t PAGES = TINY4KOLED_PAGES;

    void strip(uint8_t x0, uint8_t y0, uint8_t byte)
    {
        oled.setCursor(x0, y0);
        oled.startData();
        if(x0 & 1) oled.sendData(byte); else oled.sendData(byte);
        #ifdef OLEDSCOPE_WIPER
        if(x0 & 1) oled.sendData(0b10101010); else oled.sendData(0b01010101);
        #endif
        oled.endData();
    }

    void stripe(uint8_t x_pix, uint8_t *buf)
    {
        switch (PAGES)
        {
            case  8: strip(x_pix, 7, buf[7]);
            case  7: strip(x_pix, 6, buf[6]);
            case  6: strip(x_pix, 5, buf[5]);
            case  5: strip(x_pix, 4, buf[4]);
            case  4: strip(x_pix, 3, buf[3]);
            case  3: strip(x_pix, 2, buf[2]);
            case  2: strip(x_pix, 1, buf[1]);
            case  1: strip(x_pix, 0, buf[0]);
            case  0: break;
        }
    }

    inline void vline(uint8_t x_pix, uint8_t y0_pix, uint8_t y1_pix)
    {
        uint8_t buf[TINY4KOLED_PAGES] = {0};
        if(y1_pix < y0_pix) { uint8_t t = y1_pix; y1_pix = y0_pix; y0_pix = t; }
        uint8_t byte0 = y0_pix >> 3, byte1 = y1_pix >> 3;
        uint8_t bit0  = y0_pix & 7,  bit1  = y1_pix & 7;

        if (byte0 == byte1)
        {
            buf[byte0] = ((uint8_t)0xFF >> (7 - bit1)) & ((uint8_t)0xFF << bit0);
            stripe(x_pix, buf);
            return;
        }

        buf[byte0] = (uint8_t)0xFF << bit0;
        buf[byte1] |= (uint8_t)0xFF >> (7 - bit1);
        switch (byte1 - byte0 - 1)
        {
            case  8: buf[byte0+ 8] = 0xFF;
            case  7: buf[byte0+ 7] = 0xFF;
            case  6: buf[byte0+ 6] = 0xFF;
            case  5: buf[byte0+ 5] = 0xFF;
            case  4: buf[byte0+ 4] = 0xFF;
            case  3: buf[byte0+ 3] = 0xFF;
            case  2: buf[byte0+ 2] = 0xFF;
            case  1: buf[byte0+ 1] = 0xFF;
            case  0: break;
        }
        stripe(x_pix, buf);
    }
};
