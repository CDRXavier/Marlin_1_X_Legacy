#pragma once
#include "delay.h" //we use that
#include "src/U8glib/utility/u8g.h"
#include "src/U8glib/U8glib.h"
#ifdef __cplusplus
extern "C" {
#warning "rhyttsre"
#endif
//u8g_com_fnptr u8g_com_ssd1306_xustom_fn(u8g_t*, uint8_t , uint8_t , void *);
//uint8_t u8g_dev_ssd1306_xustom_fn(u8g_t *, u8g_dev_t *, uint8_t , void *);
#ifdef __cplusplus
}
#endif
#warning "gf"
//u8g_dev_t u8g_dev_st7565_64128n_2x_VIKI_sw_spi = {u8g_dev_st7565_64128n_2x_VIKI_fn, &u8g_dev_st7565_64128n_2x_VIKI_pb, &u8g_com_null_fn};



/*extern*///u8g_dev_t u8g_dev_ssd1306_xustom_hw_spi = {u8g_dev_ssd1306_xustom_fn, u8g_com_ssd1306_xustom_fn};


















//#ifndef N1306SPIWrapper
//#define N1306SPIWrapper

//#ifdef __cplusplus
//extern "C" {
//#warning "rhyttsre"
//#endif
//uint8_t u8g_com_ssd1306_xustom_fn(u8g_t*, uint8_t, uint8_t, void *);
//#ifdef __cplusplus
//}
//#endif

/*
  #define ST7565_WRITE_BYTE(a)                 { SPDR = a; while (!TEST(SPSR, SPIF)); U8G_DELAY(); }
  #define ST7560_WriteSequence(count, pointer) { uint8_t *ptr = pointer; for (uint8_t i = 0; i <  count; i++) {SPDR = *ptr++; while (!TEST(SPSR, SPIF));} U8G_DELAY(); }

  #if DOGM_SPI_DELAY_US > 0
  #define U8G_DELAY() DELAY_US(DOGM_SPI_DELAY_US)
  #else
  #define U8G_DELAY() u8g_10MicroDelay()
  #endif

  #define ST7565_CS()   do{ WRITE(ST7565_CS_PIN, HIGH); U8G_DELAY(); }while(0)
  #define ST7565_NCS()      WRITE(ST7565_CS_PIN, LOW)
  #define ST7565_A0()   do{ WRITE(ST7565_A0_PIN, HIGH); U8G_DELAY(); }while(0)
  #define ST7565_NA0()      WRITE(ST7565_A0_PIN, LOW)

  #define ST7565_ADC_REVERSE(N)    ST7565_WRITE_BYTE(0xA0 | ((N) & 0x1))
  #define ST7565_BIAS_MODE(N)      ST7565_WRITE_BYTE(0xA2 | ((N) & 0x1))
  #define ST7565_ALL_PIX(N)        ST7565_WRITE_BYTE(0xA4 | ((N) & 0x1))
  #define ST7565_INVERTED(N)       ST7565_WRITE_BYTE(0xA6 | ((N) & 0x1))
  #define ST7565_ON(N)             ST7565_WRITE_BYTE(0xAE | ((N) & 0x1))
  #define ST7565_OUT_MODE(N)       ST7565_WRITE_BYTE(0xC0 | ((N) & 0x1) << 3)
  #define ST7565_POWER_CONTROL(N)  ST7565_WRITE_BYTE(0x28 | (N))
  #define ST7565_V0_RATIO(N)       ST7565_WRITE_BYTE(0x10 | ((N) & 0x7)) // Specific to Displaytech 64128N? (ST7565 is 0x20 | N)
  #define ST7565_CONTRAST(N)   do{ ST7565_WRITE_BYTE(0x81); ST7565_WRITE_BYTE(N); }while(0)

  #define ST7565_COLUMN_ADR(N) do{ ST7565_WRITE_BYTE(0x10 | (((N) >> 4) & 0xF)); ST7565_WRITE_BYTE((N) & 0xF); }while(0)
  #define ST7565_PAGE_ADR(N)       ST7565_WRITE_BYTE(0xB0 | (N))
  #define ST7565_START_LINE(N)     ST7565_WRITE_BYTE(0x40 | (N))
  #define ST7565_SLEEP_MODE()      ST7565_WRITE_BYTE(0xAC)
  #define ST7565_NOOP()            ST7565_WRITE_BYTE(0xE3)

  uint8_t u8g_dev_st7565_64128n_2x_VIKI_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg) {
  switch (msg) {

    case U8G_DEV_MSG_INIT:
    case U8G_DEV_MSG_STOP: break;
    case U8G_DEV_MSG_PAGE_NEXT:
    case U8G_DEV_MSG_CONTRAST:
    case U8G_DEV_MSG_SLEEP_ON:
    case U8G_DEV_MSG_SLEEP_OFF:
  } return u8g_dev_pb16v1_base_fn(u8g, dev, msg, arg);

  }

*/




//taken from SD2Card.cpp
//spiInit(uint8_t spiRate)
//SD card want this
//SPCR = _BV(SPE) | _BV(MSTR) | (spiRate >> 1); // enable SPI, master mode, MODE0, MSB first
//SPSR = spiRate & 1 || spiRate == 6 ? 0 : _BV(SPI2X); // double speed → 8 MHz on 16 MHz AVR



//static uint8_t spiRec() {
//    SPDR = 0xFF;
//    while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//    return SPDR;
//  }
//
//  /** SPI read data - only one call so force inline */
//  static inline __attribute__((always_inline))
//  void spiRead(uint8_t* buf, uint16_t nbyte) {
//    if (nbyte-- == 0) return;
//    SPDR = 0xFF;
//    for (uint16_t i = 0; i < nbyte; i++) {
//      while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//      buf[i] = SPDR;
//      SPDR = 0xFF;
//    }
//    while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//    buf[nbyte] = SPDR;
//  }
//
//  /** SPI send a byte */
//  static void spiSend(uint8_t b) {
//    SPDR = b;
//    while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//  }
//
//  /** SPI send block - only one call so force inline */
//  static inline __attribute__((always_inline))
//  void spiSendBlock(uint8_t token, const uint8_t* buf) {
//    SPDR = token;
//    for (uint16_t i = 0; i < 512; i += 2) {
//      while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//      SPDR = buf[i];
//      while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//      SPDR = buf[i + 1];
//    }
//    while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
//  }


//screen want this
//SPCR = _BV(SPE) | _BV(MSTR);   // MODE0, MSB-first, SPR1:SPR0 = 00
//SPSR = _BV(SPI2X);             // 8 MHz

//fast IO
//READ(IO)
//WRITE(IO, HIGH)


//digitalWrite(chipSelectPin_, HIGH);
//bool sd_active = !(PINB & _BV(PB0))
//OUT_WRITE(SDPOWER, HIGH);

//spiSendBlock
//while (!TEST(SPSR, SPIF)) { /*//*/ Intentionally left empty /*//*/ }
//      SPDR = buf[i];

// no interrupts during byte receive - about 8 us
//    cli();

#define OLED_DC LCD_PINS_RS    // 70 //dc
//#define LCD_PINS_ENABLE// 71 //cs
#define OLED_RESET LCD_PINS_D4 //72 //reset




#define XSD1306_WRITE_BYTE(a)                 { SPDR = a; while (!TEST(SPSR, SPIF)); U8G_DELAY(); }
#define XSD1306_WriteSequence(count, pointer) { uint8_t *ptr = pointer; for (uint8_t i = 0; i <  count; i++) {SPDR = *ptr++; while (!TEST(SPSR, SPIF));} U8G_DELAY(); }

#define SSD1306_MODE_COMMAND WRITE(OLED_DC, LOW) ///< Command mode
#define SSD1306_MODE_DATA WRITE(OLED_DC, HIGH)  ///< Data mode

//extern u8g_dev_t u8g_dev_ssd1306_xustom_hw_spi;

//U8G_PB_DEV(u8g_dev_ssd1306_xustom_hw_spi, 128, 64, 8, u8g_dev_ssd1306_xustom_fn, u8g_com_ssd1306_xustom_fn);

///////////////////////
//
//  Global Variables
//
///////////////////////

uint8_t u8g_ssd1306_xustom_buf[128] U8G_NOCOMMON;
//uint8_t u8g_ssd1306_xustom_buf[1 * 8] U8G_NOCOMMON;
uint8_t page_ind;     // 0..7
//uint8_t page_df[8];

  static inline __attribute__((always_inline))
  void sendDispBuffer(const uint8_t* buf, uint16_t len) {
    //SPDR = token;
    while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
    for (uint16_t i = 0; i < len; i += 2) {
      SPDR = buf[i];
      while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
      SPDR = buf[i + 1];
      while (!TEST(SPSR, SPIF)) { /* Intentionally left empty */ }
    }
  }



static const uint8_t ssd1306_init_seq[26] PROGMEM = {
  0xAE,       //SSD1306_DISPLAYOFF
  0xD5, 0x80, //SSD1306_SETDISPLAYCLOCKDIV, ratio 0x80
  0xA8, 0x3F/*3f = HEIGHT(64) - 1*/,   //SSD1306_SETMULTIPLEX, multiplex ratio
  0xD3, 0x00, //SSD1306_SETDISPLAYOFFSET, no offset
  0x40/*0x40 | 0x0*/,       //SSD1306_SETSTARTLINE | line #0
  0x8D, 0x14, //SSD1306_CHARGEPUMP, enable
  0x20, 0x02, // SSD1306_MEMORYMODE, 0x02 for manual page addressing//0x0 act like ks0108
  0xA1/*0xA0 | 0x1*/,       //SSD1306_SEGREMAP | 0x1 //0xA0
  0xC8,       //SSD1306_COMSCANDEC C8 (normal)//0xC0
  0xDA, 0x12, //SSD1306_SETCOMPINS, 0x12
  0x81, 0x26, //SSD1306_SETCONTRAST, 0xCF
  0xD9, 0x11, //SSD1306_SETPRECHARGE, 0xF1
  //you can play around with this a bit. Second bit (0x8) is the charge-up
  //time for capacitor. First bit is capacitor discharge to OLED time.
  0xDB, 0x10, //SSD1306_SETVCOMDETECT, 0x40
  0x2E,       //SSD1306_DEACTIVATE_SCROLL
  0xA6,       //SSD1306_NORMALDISPLAY
  0xA4,       //SSD1306_DISPLAYALLON_RESUME
  0xAF        //SSD1306_DISPLAYON
};


//#ifdef __cplusplus
//extern "C" {
//#warning "rhyttsre"
//#endif
//uint8_t u8g_com_ssd1306_xustom_fn(u8g_t*, uint8_t, uint8_t, void *);

uint8_t u8g_com_ssd1306_xustom_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr) {
  //u8g_t *u8gptr = (u8g_t*)u8g;
  switch (msg) {
    case U8G_COM_MSG_INIT:
      break;
    case U8G_COM_MSG_STOP:
      break;
    case U8G_COM_MSG_RESET:
      // optional: toggle reset pin
      break;
    //case U8G_COM_MSG_ADDRESS:
    //{ // D/C (A0) line: arg_val == 0 => command, 1 => data
    //if (arg_val) WRITE(DOGLCD_A0, HIGH);
    //else
    //WRITE(DOGLCD_A0, LOW);
    //}
    //break;
    case U8G_COM_MSG_CHIP_SELECT:
      //      digitalWrite(SSD1306_CS, arg_val ? LOW : HIGH);
      break;
    case U8G_COM_MSG_ADDRESS:
      //  WRITE(SSD1306_DC, arg_val ? HIGH : LOW);
      break;

    //case U8G_COM_MSG_SET_DC:
    //    digitalWrite(SSD1306_DC, arg_val ? HIGH : LOW);
    //break;

    case U8G_COM_MSG_WRITE_BYTE:
      //    if (digitalRead(SSD1306_DC) == LOW)
      //      ssd1306_sendCommand(arg_val);
      //    else
      //      ssd1306_sendData(&arg_val, 1);
      break;

    case U8G_COM_MSG_WRITE_SEQ:
      //    ssd1306_sendData((uint8_t*)arg_ptr, arg_val);
      break;

    //case U8G_COM_MSG_WRITE_BYTE:
    // send one byte over HW SPI
    //spiSend((uint8_t)arg_val);
    //break;
    //case U8G_COM_MSG_WRITE_SEQ: {
    //uint8_t *ptr = (uint8_t *)arg_ptr;
    //while (arg_val--) {
    //spiSend(*ptr++);
    //}
    //} break;
    case U8G_COM_MSG_WRITE_SEQ_P: {
        //uint8_t *ptr = (uint8_t *)arg_ptr;
        //while (arg_val--) {
        //spiSend(pgm_read_byte(ptr++));
        //}
        break;
      }
    default:
      break;
  }
  WRITE(BEEPER_PIN, LOW);
  return 1;
}

uint8_t u8g_dev_ssd1306_xustom_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg) {
  WRITE(BEEPER_PIN, HIGH);// delayMicroseconds(300); WRITE(BEEPER_PIN, LOW); //delayMicroseconds(100);
  switch (msg) {
    case U8G_DEV_MSG_INIT:
    //OLED INIT MUST RUN. Regardless of SD state.
      //"No cost too great."
      //if (!READ(SDSS)) return -1;
      //set SPI mode
      //SPE: enable SPI. MSTR: master mode
      //WRITE(BEEPER_PIN, HIGH); delayMicroseconds(200); WRITE(BEEPER_PIN, LOW);
  //WRITE(BEEPER_PIN, HIGH); delayMicroseconds(50); WRITE(BEEPER_PIN, LOW); delayMicroseconds(50);

SET_OUTPUT(OLED_DC);
SET_OUTPUT(LCD_PINS_ENABLE); // CS
SET_OUTPUT(OLED_RESET);

      
      WRITE(OLED_RESET, HIGH);
      DELAY_US(5);          // VDD goes high at start, pause for 5 us
      WRITE(OLED_RESET, LOW);  // Bring reset low
      DELAY_US(15);            // Wait 15 us
      WRITE(OLED_RESET, HIGH); // Bring out of reset

      //SPI BEGIN
      SPCR = _BV(SPE) | _BV(MSTR);   // MODE0, MSB-first, SPR1:SPR0 = 00
      SPSR = _BV(SPI2X);             // 8 MHz

      WRITE(LCD_PINS_ENABLE, LOW);
      
      SSD1306_MODE_COMMAND;

      for (uint8_t i = 0; i < 26/*sizeof(ssd1306_init_seq)*/; i++) {
        SPDR = pgm_read_byte(&ssd1306_init_seq[i]);
        while (!TEST(SPSR, SPIF)) {}
      }
      WRITE(LCD_PINS_ENABLE, HIGH);
      //  SPI.endTransaction();
      WRITE(BEEPER_PIN, LOW);
      return 1;
      
      //
      //END U8G_DEV_MSG_INIT

//case U8G_DEV_MSG_PAGE_FIRST:
 // U8glib is starting a new full-screen redraw
 // You can clear dirty flags here if you want
 
// u8g_pb_Clear((u8g_pb_t *)dev->dev_mem); // THIS is the missing piece
// return 1;
    
    case U8G_DEV_MSG_PAGE_NEXT:
    //u8g->current page return a _u8g_box_t
    //typedef struct _u8g_box_t {
    //uint8_t x0, y0, x1, y1;
    //} u8g_box_t;
    // Compute page index: y0 = 0,8,16,...56 → page = 0..7
    page_ind = u8g->current_page.y0 >> 3;// y divided by 2^3(8) is the page number.
    //uint8_t *src = (uint8_t *)arg;         // U8glib's 128-byte page buffer
    //uint8_t *dst = &framebuffer[page * 128];
    //memcpy(&u8g_ssd1306_xustom_buf[page * 128], (uint8_t*)arg, 128);
    //memcpy(dst, src, 128);                 // copy the whole page
    //page_df[page] = true;               // mark it dirty
    
    // Pointer to U8glib’s 128-byte page buffer
    //uint8_t *src = (uint8_t*)arg;

    SPCR = _BV(SPE) | _BV(MSTR);   // MODE0, MSB-first, SPR1:SPR0 = 00
    SPSR = _BV(SPI2X);             // 8 MHz

    WRITE(LCD_PINS_ENABLE, LOW);

    SSD1306_MODE_COMMAND;
    // Set SSD1306 page and column
    SPDR = (0xB0 | page_ind); //page addressing mode, page indice
    while (!TEST(SPSR, SPIF)) {}
    //column 2 offset? col = 2 when in page addressing; internal 2 bit for 2"display shift".
    SPDR = 0x02;          // Lower column = 0, 0x00 | (col & 0x0F)
    while (!TEST(SPSR, SPIF)) {}
    SPDR = 0x10;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    while (!TEST(SPSR, SPIF)) {}
//SPI.transfer(0x22); //SSD_1306_PAGEADDR
//  SPI.transfer(0);   // Page start address
//  SPI.transfer(0xFF);   // Page end (not really, but works here)
//  SPI.transfer(0x21);//SSD1306_COLUMNADDR
//  SPI.transfer(0); // Column start address
//  SPI.transfer(WIDTH - 1); // Column end address

    //SPDR = 0x22;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    //while (!TEST(SPSR, SPIF)) {WRITE(BEEPER_PIN, !READ(BEEPER_PIN));}
    //SPDR = 0x00;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    //while (!TEST(SPSR, SPIF)) {WRITE(BEEPER_PIN, !READ(BEEPER_PIN));}
    //SPDR = 0xFF;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    //while (!TEST(SPSR, SPIF)) {WRITE(BEEPER_PIN, !READ(BEEPER_PIN));}
    //SPDR = 0x21;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    //while (!TEST(SPSR, SPIF)) {WRITE(BEEPER_PIN, !READ(BEEPER_PIN));}
    //SPDR = 0x00;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    //while (!TEST(SPSR, SPIF)) {WRITE(BEEPER_PIN, !READ(BEEPER_PIN));}
    //SPDR = 0x3F;          // Upper column = 0, 0x10 | ((col >> 4) & 0x0F)
    //while (!TEST(SPSR, SPIF)) {WRITE(BEEPER_PIN, !READ(BEEPER_PIN));}





    
    SSD1306_MODE_DATA;
    // Write the 128 bytes directly
    //u8g_pb_t *pb = (u8g_pb_t*)dev->dev_mem;
    //uint8_t *pixels = pb->buf;
    //for (uint8_t i = 0; i < ((u8g_pb_t*)dev->dev_mem)->width; i++) {
      //SPDR = 0xA0; // light only page 0
      //while (!(SPSR & _BV(SPIF))){};
    //}
    
    sendDispBuffer((const uint8_t*)((u8g_pb_t*)dev->dev_mem)->buf, 128);
    
    
    
    
    WRITE(LCD_PINS_ENABLE, HIGH);
    WRITE(BEEPER_PIN, LOW);
    //return 1;
    break;
//
//END U8G_DEV_MSG_PAGE_NEXT
/*
case U8G_DEV_MSG_GET_PAGE_BOX:
// U8glib asks for the page dimensions
u8g_box_t *box = (u8g_box_t *)arg;
box->x0 = 0;
box->y0 = u8g->current_page.y0;
box->x1 = 127;
box->y1 = u8g->current_page.y1;
return 1;
*/
//
//END U8G_DEV_MSG_GET_PAGE_BOX

    case U8G_DEV_MSG_CONTRAST:
      //ssd1306_sendCommand(0x81);
      //ssd1306_sendCommand(*(uint8_t*)arg);
      return 1;

    case U8G_DEV_MSG_SLEEP_ON:
      //ssd1306_sendCommand(0xAE);
      return 1;

    case U8G_DEV_MSG_SLEEP_OFF:
      //ssd1306_sendCommand(0xAF);
      return 1;
  }

  // everything else (PAGE_NEXT, drawing) handled by u8glib
  return u8g_dev_pb8v1_base_fn(u8g, dev, msg, arg);
}

//#ifdef __cplusplus
//}
//#endif




u8g_pb_t u8g_ssd1306_xustom_pb = {
    { 8, 64, 0, 0, 0 },
    128,
    u8g_ssd1306_xustom_buf
};

u8g_dev_t u8g_dev_ssd1306_xustom_hw_spi = {
    u8g_dev_ssd1306_xustom_fn,
    &u8g_ssd1306_xustom_pb,
    &u8g_com_null_fn
    //u8g_com_ssd1306_xustom_fn //com class
};


class U8GLIB_SSD1306_XUSTOM : public U8GLIB {
  public:
  U8GLIB_SSD1306_XUSTOM(uint8_t dummy)
      : U8GLIB(&u8g_dev_ssd1306_xustom_hw_spi)
    {}
    //U8GLIB_SSD1306_XUSTOM(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE)
    //  : U8GLIB(&u8g_dev_ssd1306_xustom_hw_spi, cs, a0, reset)
    //{}
    //U8GLIB_SSD1306_XUSTOM()//com class constructor
    //  : U8GLIB(&u8g_dev_ssd1306_xustom_hw_spi, (u8g_com_fnptr)u8g_com_ssd1306_xustom_fn)
    //{}
    U8GLIB_SSD1306_XUSTOM(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE)
      : U8GLIB(&u8g_dev_ssd1306_xustom_hw_spi/*, u8g_com_ssd1306_xustom_fn*/)
    {}
};


//these 3 are Old style. DO NOT USE!

//page buffer
//u8g_pb_t u8g_dev_st7565_dogm128_sw_spi_pb = { ... };
//bus .. thing
//u8g_dev_t u8g_dev_st7565_dogm128_sw_spi = {
//  u8g_dev_st7565_dogm128_fn,
//  u8g_com_hw_spi_fn
//};

//u8g_pb_t u8g_dev_ssd1306_xustom_hw_spi_pb = {{8, 64, 0, 0, 0}, 128, u8g_dev_ssd1306_xustom_hw_spi_buf};

//u8g_dev_t u8g_dev_ssd1306_xustom_hw_spi = {
//  u8g_dev_ssd1306_xustom_fn,     // your device function
//  &u8g_dev_ssd1306_xustom_hw_spi_pb,      // existing display info
//  u8g_com_ssd1306_xustom_fn      // your COM backend
//};

//this is garbage

//U8G_PB_DEV(name, width, height, page_height, dev_fn, com_fn)

//new layout
//U8G_PB_DEV(u8g_dev_ssd1306_128x64_hw_spi,
//           WIDTH, HEIGHT, PAGE_HEIGHT,
//           u8g_dev_ssd1306_128x64_fn,
//           U8G_COM_HW_SPI);



//typedef struct _u8g_dev_t {
//  u8g_dev_fnptr u8g_dev_ssd1306_xustom_fn;
//  u8g_com_fnptr u8g_com_ssd1306_xustom_fn;
//} u8g_dev_t;

//class U8GLIB_SSD1306_XUSTOM : public U8GLIB {
//  public:
//    U8GLIB_SSD1306_XUSTOM(uint8_t cs, uint8_t a0, uint8_t reset = U8G_PIN_NONE)
//      : U8GLIB(&u8g_dev_ssd1306_xustom_hw_spi, cs, a0, reset) //8 pages, lines up perfectly
//    {
//     }
//};
//#endif
