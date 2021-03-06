#ifndef __REALVIEW_REG_WDG_H__
#define __REALVIEW_REG_WDG_H__

#include <xboot.h>

#define REALVIEW_WDG_LOAD		(0x10010000 + 0x000)
#define REALVIEW_WDG_VALUE		(0x10010000 + 0x004)
#define REALVIEW_WDG_CTRL		(0x10010000 + 0x008)
#define REALVIEW_WDG_ICLR		(0x10010000 + 0x00c)
#define REALVIEW_WDG_RIS		(0x10010000 + 0x010)
#define REALVIEW_WDG_MIS		(0x10010000 + 0x014)
#define REALVIEW_WDG_LOCK		(0x10010000 + 0xc00)
#define REALVIEW_WDG_ITCR		(0x10010000 + 0xf00)
#define REALVIEW_WDG_ITOP		(0x10010000 + 0xf04)


#endif /* __REALVIEW_REG_WDG_H__ */
