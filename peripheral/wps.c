/*************************************************************************
	> File Name: peripheral/wps.c
	> Author: 
	> Mail: 
	> Created Time: 2015年04月11日 星期六 15时52分12秒
 ************************************************************************/

#include <wps.h>
#define WPSKEY (*(unsigned long*)0x1e000600) // GPIO#18
#define WPSDATA (*(unsigned long *)0x1e000620) 

void init_wps(void)
{
    WPSKEY &=(~(1<<18));//GPIO#18
}
int readwps(void)//按下输出0,未按下输出1
{
    return (WPSDATA & (1<<18));
}

