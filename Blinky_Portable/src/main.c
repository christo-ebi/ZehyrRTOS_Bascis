#include<zephyr/kernel.h>
#include<zephyr/device.h>
#include<zephyr/drivers/gpio.h>

static const struct gpio_dt_spec led_dev = GPIO_DT_SPEC_GET(DT_NODELABEL(blinking_led),gpios);

int main()
{
	if(!device_is_ready(led_dev.port))
	{
		return 0;
	}

	int ret;
	
	//ret = gpio_pin_configure(led_dev.port,led_dev.pin,led_dev.dt_flags);
	//Better Way.

	ret = gpio_pin_configure_dt(&led_dev,GPIO_OUTPUT_ACTIVE);

	if(ret !=0)
	{
		return 0;
	}

	while(true){

		//ret = gpio_pin_set_raw(led_dev.port,led_dev.pin,1);

		//Better Way.
		ret = gpio_pin_toggle_dt(&led_dev);

		if(ret !=0)
		{
			return 0;
		}

		k_msleep(1000);

	}
	return 0;
}
