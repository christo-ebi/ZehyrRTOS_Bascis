#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

static const struct device *dev = DEVICE_DT_GET(DT_ALIAS(dth11tmp));

int main(void)
{
	int ret;

	if (!dev) {
		printf("No device found!\n");
	}

	if (!device_is_ready(dev)) {
		printf("Device %s is not ready\n", dev->name);
	}

	struct sensor_value Temp;
    struct sensor_value Humidity;

	while(1) {

		ret = sensor_sample_fetch(dev);

		if(!ret)
		{
			ret = sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &Temp);

			if(!ret)
			{
				printk("Temperature: %d.%06d\n", Temp.val1, Temp.val2);
			}
			else
			{
				printk("Error Getting Temperature: %d\n", ret);
			}

			ret = sensor_channel_get(dev, SENSOR_CHAN_HUMIDITY, &Humidity);

			if(!ret)
			{
				printk("Humidity: %d.%06d\n", Humidity.val1, Humidity.val2);
			}
			else
			{
				printk("Error Getting Pressure: %d\n", ret);
			}

		}
		else
		{
			printf("Device fetching sensor sample: %d \n", ret);
		}

		//Note:Polling at a higher rate than 1250 ms in STM32 causes errors.
		k_msleep(1250);
	}
	return 0;
}