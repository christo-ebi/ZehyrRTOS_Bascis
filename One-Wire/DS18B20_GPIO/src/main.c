#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>

const static struct device *const tempProbeDev = DEVICE_DT_GET_ANY(maxim_ds18b20);;

int TempProbeInit()
{
	if (tempProbeDev == NULL) {
		printk("\nError: no device found.\n");
		return -1;
	}

	if (!device_is_ready(tempProbeDev)) {
		printk("\nError: Device \"%s\" is not ready \n", tempProbeDev->name);
		return -1;
	}

	return 0;
}

void GetTempVal()
{
		int res;
		struct sensor_value temp;

		res = sensor_sample_fetch(tempProbeDev);

		if (res != 0) {
			printk("sample_fetch() failed: %d\n", res);
		}

		res = sensor_channel_get(tempProbeDev, SENSOR_CHAN_AMBIENT_TEMP, &temp);
		if (res != 0) {
			printk("channel_get() failed: %d\n", res);
		}
		printk("Temp: %d.%06d\n", temp.val1, temp.val2);
}


int main(void)
{

	if(TempProbeInit() == -1)
	{
		return -1;
	}

	while (true) {
		GetTempVal();
		k_sleep(K_MSEC(500));
	}

	return 0;
}