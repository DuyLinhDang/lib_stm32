#include "test.h"
#include "pic.h"
//========================variable==========================//
u16 ColorTab[5]={RED,GREEN,BLUE,YELLOW,BRED};//定义颜色数组
//=====================end of variable======================//

//const unsigned char gImage_ptit[3208] = { /*0X00,0X10,0X28,0X00,0X28,0X00,0X01,0X1B*/
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDA,0XF6,0X2C,0XE3,0X64,0XD9,
//0X64,0XD9,0XAA,0XE2,0X95,0XF5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X07,0XE2,0X00,0XD0,0X44,0XD9,0XC6,0XE1,
//0X40,0XD8,0X40,0XD8,0X20,0XD8,0X89,0XE2,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XDB,0XF6,0X00,0XD0,0X50,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0X71,0XEC,0X40,0XD8,0X20,0XD8,0X38,0XF6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XF3,0XEC,0XC6,0XD9,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X34,0XED,0X00,0XD8,0X6C,0XE3,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XEF,0XE3,0X0F,0XE4,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X64,0XD9,0X07,0XE2,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X2C,0XE3,
//0X59,0XF6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XB2,0XEC,0X44,0XD9,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XB2,0XEC,0XF7,0XF5,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X58,0XF6,0XC6,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XFF,0X27,0XE2,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9A,0XF6,0XA9,0XE2,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X44,0XD9,0XDF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X59,0XF6,0X0F,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X96,0XF5,0XAA,0XE2,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X55,0XF5,0X38,0XF6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XD0,0X7D,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XEF,0XEB,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF3,0XEC,0X44,0XD9,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0X99,0XF7,0XFF,0XFF,0XD3,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X40,0XD8,0XD2,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFB,0XFF,0XB0,0XDE,0XFF,0XFF,0X17,0XF6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X18,0XF6,0X00,0XD8,0X5D,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XA4,0XDE,0X3A,0XEF,0X9E,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X6D,0XEB,0X20,0XD8,0XFF,0XFF,0X2B,0XE3,0XC2,0XD8,0XA1,0XD8,
//0X85,0XD9,0X9E,0XFF,0X20,0XD0,0X03,0XD9,0X03,0XD9,0X00,0XD8,0X5A,0XEF,0X20,0XD6,
//0X80,0XDE,0X86,0XD6,0X37,0XF6,0X00,0XD0,0XA1,0XD8,0X20,0XD8,0X60,0XD0,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X02,0XD9,0XE6,0XE1,0XFF,0XFF,0X48,0XE2,0X71,0XEC,0XFF,0XFF,
//0X2C,0XE3,0X07,0XE2,0XFF,0XFF,0XEF,0XEB,0XAD,0XEB,0XFF,0XFF,0XFF,0XFF,0X20,0XD6,
//0X60,0XD6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X28,0XE2,0X18,0XF6,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X00,0XD8,0X0B,0XE3,0XFF,0XFF,0X68,0XE2,0XEF,0XEB,0X9E,0XFF,
//0X89,0XE2,0X48,0XE2,0XFF,0XFF,0X30,0XEC,0XEE,0XEB,0XFF,0XFF,0XA6,0XDE,0X57,0XE6,
//0XCE,0XE6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X27,0XE2,0XD7,0XF5,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0X58,0XF6,0X00,0XD8,0XEF,0XEB,0XFF,0XFF,0XAA,0XE2,0X03,0XD9,0X85,0XE1,
//0X89,0XE2,0XDF,0XFF,0XFF,0XFF,0X2F,0XEC,0XCE,0XEB,0XFF,0XFF,0XFF,0XFF,0X72,0XEC,
//0X04,0XD9,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X27,0XE2,0XD7,0XF5,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XD3,0XEC,0X20,0XD8,0X2F,0XEC,0XFF,0XFF,0X68,0XE2,0XD2,0XEC,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X2F,0XEC,0XCE,0XEB,0XFF,0XFF,0XF3,0XEC,0X4C,0XE3,
//0X20,0XD8,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X27,0XE2,0XD7,0XF5,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0X30,0XEC,0X40,0XD8,0X6D,0XE3,0XFF,0XFF,0XE6,0XD9,0X30,0XEC,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XAE,0XEB,0XCE,0XEB,0X9E,0XFF,0X00,0XD8,0X8D,0XE3,
//0X00,0XD0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XA5,0XD9,0X96,0XF5,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0X30,0XEC,0X60,0XD8,0X48,0XE2,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X5D,0XFF,0X40,0XD8,0X40,0XD8,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0X13,0XED,0X80,0XD8,0X40,0XD8,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X59,0XF6,0X20,0XD8,0X00,0XD8,0XBA,0XF6,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XBE,0XFF,0X00,0XD8,0X81,0XD8,0XB2,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X30,0XEC,0X00,0XD8,0X00,0XD8,0X79,0XF6,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0X30,0XEC,0X20,0XD8,0X00,0XD8,0X38,0XF6,0XFF,0XFF,0XFF,0XFF,
//0X5D,0XFF,0X85,0XD9,0X00,0XD8,0X03,0XD9,0X9D,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X91,0XEC,0X50,0XEC,0XCE,0XE3,0X96,0XF5,0X69,0XE2,
//0X00,0XD8,0X00,0XD8,0X71,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X6D,0XEB,0X23,0XD9,0X81,0XD8,0XE6,0XE1,
//0XB2,0XEC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0X59,0XF6,0XD2,0XEC,0XF3,0XEC,0X13,0XED,0X75,0XF5,0XB6,0XF5,0XD6,0XF5,0XB6,0XF5,
//0X75,0XF5,0X13,0XED,0XF3,0XEC,0X34,0XED,0X34,0XED,0XF3,0XEC,0X13,0XED,0X13,0XED,
//0XF3,0XEC,0X13,0XED,0X13,0XED,0X13,0XED,0X13,0XED,0X13,0XED,0XB2,0XEC,0X5D,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0X13,0XED,0X48,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,
//0X89,0XE2,0X89,0XE2,0X68,0XE2,0X13,0XED,0X2C,0XE3,0X89,0XE2,0X89,0XE2,0X89,0XE2,
//0X89,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,0X89,0XE2,0X27,0XE2,0XDB,0XFE,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0X54,0XED,0XCA,0XE2,0X0B,0XE3,0X2B,0XE3,0X2C,0XE3,0X2C,0XE3,0X4C,0XE3,0X4C,0XE3,
//0X6D,0XE3,0X8D,0XEB,0X6D,0XEB,0X8D,0XE3,0XC6,0XD9,0XAD,0XEB,0X6D,0XEB,0X6D,0XEB,
//0X4C,0XE3,0X4C,0XE3,0X2C,0XE3,0X2B,0XE3,0X2B,0XE3,0X0B,0XE3,0X89,0XE2,0XFB,0XFE,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9E,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
//};




void Text_Center(u16 x1, u16 y1, u16 x2, u16 y2, u16 fc, u16 bc, u8 *str, u8 size,u8 mode){
	int Width_x = x2-x1;
	int length_text = strlen((const char *)str);
	int Width_text = length_text*8;
	int X_text = (Width_x - Width_text)/2;
	int Y_text = ((y2-y1)-13)/2;
	Show_Str(X_text+x1,Y_text+y1,fc, bc, str, size, mode);
}


/*											Ham hien thi 4 truong thong tin																					*/
void interface(){
	LCD_direction(1);
	//GUI TFT9341
	LCD_Fill(0,0,lcddev.width-1,lcddev.height-1,WHITE);
	LCD_DrawFillRectangle(0,45,lcddev.width-1,lcddev.height-20);
	LCD_Fill(0,45,lcddev.width-1,45,GRAYBLUE);
	LCD_Fill(0,lcddev.height-20,lcddev.width-1,lcddev.height-20,GRAYBLUE);

	LCD_ShowString(100,50,24,"STUDENT ID CARD",0);
	Show_Str(100,10,BLACK,WHITE,"Posts & Telecommunications ",16,0);
	Show_Str(115,25,BLACK,WHITE,"Institute of Technology ",16,0);
	
	Show_Str(100,85,GRAYBLUE,LIGHTGRAY,"Name:",16,0);
	Show_Str(100,105,GRAYBLUE,LIGHTGRAY,"DoB:",16,0);
	Show_Str(100,125,GRAYBLUE,LIGHTGRAY,"ADD:",16,0);
	Show_Str(100,145,GRAYBLUE,LIGHTGRAY,"Class:",16,0);
	Show_Str(100,165,GRAYBLUE,LIGHTGRAY,"Valid:",16,0);
	Show_Str(14,162,GRAYBLUE,LIGHTGRAY,"ID NO",16,0);
	
//	Gui_Drawbmp16(25,0,gImage_ptit);

	
}

void Interface_Waiting(){
	LCD_direction(1);
	//GUI TFT9341
	LCD_Fill(0,0,lcddev.width-1,lcddev.height-1,WHITE);
	LCD_DrawFillRectangle(0,45,lcddev.width-1,lcddev.height-20);
	LCD_Fill(0,45,lcddev.width-1,45,GRAYBLUE);
	LCD_Fill(0,lcddev.height-20,lcddev.width-1,lcddev.height-20,GRAYBLUE);

	Show_Str(110,100,RED,WHITE,"WELCOME TO LAB",48,0);
	Show_Str(50,130,RED,WHITE,"Quang Bien Va Nhung Thang De",36,0);
	Show_Str(100,10,BLACK,WHITE,"Posts & Telecommunications ",16,0);
	Show_Str(115,25,BLACK,WHITE,"Institute of Technology ",16,0);
//	Gui_Drawbmp16(25,0,gImage_ptit);
	
}

/**************************************************************************************/

void clear_text(u16 x1, u16 y1, u16 x2, u16 y2, u8 *str, u8 size,u8 mode){

	int Width_x = x2-x1;
	int length_text = strlen((const char *)str);
	int Width_text = length_text*8;
	int X_text = (Width_x - Width_text)/2;
	int Y_text = ((y2-y1)-13)/2;
	Show_Str(X_text+x1,Y_text+y1,WHITE, WHITE, str, size, mode);

}

void LCD_Clear_TIME(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd,u16 Color)
{
  unsigned int i,m;  
	LCD_SetWindows(xStar,yStar,xEnd,yEnd);   
	LCD_CS_CLR;
	LCD_RS_SET;
	for(i=0;i<yEnd;i++)
	{
    for(m=0;m<xEnd;m++)
    {	
			Lcd_WriteData_16Bit(Color);
		}
	}
	 LCD_CS_SET;
}

