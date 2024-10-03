First we need to enable the PWM driver in the prj.conf file (kConfig).
`CONFIG_PWM=y` --> Enables the generic pwm drivers.
`CONFIG_PWM_STM32=y` --> Specific config for STM32 Microcontrollers.

Next is to add a device overlay to add pwm node.

1. In stm32 the timers acts as pwm controller. Lets use timer1 for this example.
  In the final device tree under /build/zephyr/zephyr.dts

By default the prescaler is 0 and the timer1 is enabled.
![image](https://github.com/user-attachments/assets/3e441d8f-c575-43cf-8522-cbbc4e8587bb)

The timer1 is fed by a 8Mhz Clock to timer1.
The prescaler can be used to divide the clock to an approporiate value.

`pwm_set_dt(&pwm_led, PERIOD, PULSE);` takes three parameters device tree struct , period and pulse.

Creates a PWM of Pulse: 125 ms with period of 500ms.
![image](https://github.com/user-attachments/assets/a0d19506-575f-426d-b785-1db873e05fa7)
