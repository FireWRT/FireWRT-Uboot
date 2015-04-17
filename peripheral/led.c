/*************************************************************************
	> File Name: led.c
	> Author: 
	> Mail: 
	> Created Time: 2015年04月11日 星期六 15时22分19秒
 ************************************************************************/
#include <led.h>

#define POWERLEDADDR (*(volatile unsigned int *)0x1e000600)//GPIO#22
#define SETPOWERLED  (*(volatile unsigned int *)0x1e000630)

void init_power_led(void)
{
    //GPIO#22
    POWERLEDADDR |=(1<<22);//设置为输出
}
void control_power_led(int flag)//写0熄灭 写1点亮
{
    unsigned long tmp = 1<<22;
    if(flag == 1){
        SETPOWERLED |= tmp;
    }
    else
        SETPOWERLED &= (~tmp);
}


