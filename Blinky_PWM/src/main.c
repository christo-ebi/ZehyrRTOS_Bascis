#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>

static const struct pwm_dt_spec pwm_led = PWM_DT_SPEC_GET(DT_NODELABEL(pwm_led1));

#define PERIOD PWM_MSEC(500U)
#define PULSE PERIOD / 4U

int main(void)
{
	int ret;

	printk("PWM-based blinky\n");

	if (!pwm_is_ready_dt(&pwm_led)) {
		printk("Error: PWM device %s is not ready\n", pwm_led.dev->name);
		return 0;
	}
	
	ret = pwm_set_dt(&pwm_led, PERIOD, PULSE);

	if (ret) {
		printk("Error %d: failed to set pulse width\n", ret);
		return 0;
	}

	while (1) {
		printk("Inside Loop\n");
		k_sleep(K_SECONDS(1U));
	}
	return 0;
}