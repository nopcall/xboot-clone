#ifndef __LED_TRIGGER_H__
#define __LED_TRIGGER_H__

#include <configs.h>
#include <default.h>
#include <xboot/list.h>
#include <led/led.h>

/*
 * the struct of trigger.
 */
struct trigger
{
	/* the trigger name */
	const char * name;

	/* activate led trigger */
	void (*activate)(struct trigger * trigger);

	/* activate led trigger */
	void (*deactivate)(struct trigger * trigger);

	/* led device */
	struct led * led;

	/* private data */
	void * priv;
};

/*
 * the list of led trigger
 */
struct led_trigger_list
{
	struct trigger * trigger;
	struct list_head entry;
};


x_bool trigger_register(struct trigger * trigger);
x_bool trigger_unregister(struct trigger * trigger);


#endif /* __LED_TRIGGER_H__ */