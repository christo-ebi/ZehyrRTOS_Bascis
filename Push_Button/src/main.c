#include<zephyr/kernel.h>
#include<zephyr/device.h>
#include<zephyr/drivers/gpio.h>

static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_ALIAS(sw0),gpios);

static struct gpio_callback button_cb_info;


void button_press_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());
}

int main()
{
	if(!device_is_ready(button.port))
	{
		printk("device_is_ready \n");
		return 0;
	}

	int ret;

	ret = gpio_pin_configure_dt(&button,GPIO_INPUT);

	if(ret !=0)
	{
		printk("gpio_pin_configure_dt \n");
		return 0;
	}

	ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);

	if(ret !=0)
	{
		printk("gpio_pin_interrupt_configure_dt \n");
		return 0;
	}

	gpio_init_callback(&button_cb_info, button_press_cb, BIT(button.pin));

	gpio_add_callback(button.port, &button_cb_info);

	while(true){
		printk("Inside Loop\n");
		k_msleep(1000);
	}

	return 0;
}
