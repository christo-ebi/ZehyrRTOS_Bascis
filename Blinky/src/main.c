#include<zephyr/kernel.h>
#include<zephyr/device.h>
#include<zephyr/drivers/gpio.h>

static const struct device *led_dev = DEVICE_DT_GET(DT_NODELABEL(gpioc));

int main()
{
	if(!device_is_ready(led_dev))
	{
		return 0;
	}

	int ret;
	ret = gpio_pin_configure(led_dev,13,GPIO_OUTPUT_ACTIVE);

	if(ret !=0)
	{
		return 0;
	}

	while(true){

		ret = gpio_pin_set_raw(led_dev,13,1);
		if(ret !=0)
		{
			return 0;
		}

		k_msleep(1000);

		ret = gpio_pin_set_raw(led_dev,13,0);
		if(ret !=0)
		{
			return 0;
		}

		k_msleep(1000);

	}
	return 0;
}
