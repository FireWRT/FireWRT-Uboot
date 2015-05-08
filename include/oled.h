#ifndef __OLED_H
#define __OLED_H			  	 
#define  u8 unsigned char 
#define  u32 unsigned int 
#define OLED_CMD  0	
#define OLED_DATA 1
#define OLED_MODE 0

/*
*OLED_CS = PAD_G2_RXD0     GPIO#28
*OLED_RST = PAD_G2_RXD1    GPIO#29
*OLED_DC = PAD_G2_RXD2     GPIO#30
*OLED_SCL = PAD_G2_RXD3    GPIO#31
*OLED_SDIN = PAD_G2_RXDV   GPIO#32
* */
/*
*1.先设置RGMII2 GPIO MODE
* */
#define GPIO_MODE_REG 0x1E000060
#define SET_RGMII2_MODE (1<<15)  //写1就为GPIO模式

/*
* 0:GPIO input mode
* 1:GPIO output mode
*/
#define GPIO_CTRL_0_REG 0x1E000600 // (GPIO#0--GPIO#31)
#define GPIO_CTRL_1_REG 0x1E000604 // (GPIO#32-GPIO#63)

#define GPIO_DATA_0_REG 0x1E000620
#define GPIO_DATA_1_REG 0x1E000624

#define SET_REG_VALUE(x) (*(volatile unsigned int *)x)
void OLED_Init_Gpio(void);
void OLED_Set_Data(int gpionum,int v);

#define OLED_CS_Clr()  OLED_Set_Data(28,0) //OLED_CS=0
#define OLED_CS_Set()  OLED_Set_Data(28,1) //OLED_CS=1

#define OLED_RST_Clr() OLED_Set_Data(29,0) //OLED_RST=0
#define OLED_RST_Set() OLED_Set_Data(29,1) //OLED_RST=1

#define OLED_DC_Clr() OLED_Set_Data(30,0) //OLED_DC=0
#define OLED_DC_Set() OLED_Set_Data(30,1) //OLED_DC=1

#define OLED_SCLK_Clr() OLED_Set_Data(31,0) //OLED_SCL=0
#define OLED_SCLK_Set() OLED_Set_Data(31,1) //OLED_SCL=1

#define OLED_SDIN_Clr() OLED_Set_Data(32,0) //OLED_SDIN=0
#define OLED_SDIN_Set() OLED_Set_Data(32,1)//OLED_SDIN=1


#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  

void delay_ms(unsigned int ms);
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_Clear_page(u8 page);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);
void OLED_ShowString(u8 x,u8 y, u8 *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
#endif  



