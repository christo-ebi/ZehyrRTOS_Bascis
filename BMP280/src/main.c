#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

static const struct device *dev = DEVICE_DT_GET(DT_ALIAS(sensortmp));

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
    struct sensor_value Pressure;

	while(1) {
		if(!sensor_sample_fetch(dev))
		{

			ret = sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &Pressure);
			
			if(!ret)
			{
				printk("Temperature: %d.%06d\n", Temp.val1, Temp.val2);
			}
			else
			{
				printk("Error Getting Temperature: %d\n", ret);
			}


			/* 
			
			@warning Not supported foe BMP280. Can be uncommented for BME280.

			ret = sensor_channel_get(dev, SENSOR_CHAN_HUMIDITY, &Humidity);

			if(!ret)
			{
				printk("Humidity: %d.%06d\n", Humidity.val1, Humidity.val2);
			}
			else
			{
				printk("Error Getting Humidity: %d\n", ret);
			}

			*/
		
			ret = sensor_channel_get(dev, SENSOR_CHAN_PRESS, &Pressure);
			if(!ret)
			{
				printk("Pressue: %d.%06d\n", Pressure.val1, Pressure.val2);
			}
			else
			{
				printk("Error Getting Pressure: %d\n", ret);
			}

		}

		k_msleep(1000);
	}
	return 0;
}