/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-04     bkk          first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <bsp.h>


int main(void)
{
	bsp_Init();
    for(;;)
    {
        rt_thread_mdelay(500);
		bsp_LedToggle(1);		
    }
    return RT_EOK;
}
