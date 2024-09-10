## This project is a simple code to demonstrate toggling of an LED without using device tree (will be explained in a later chapter) and hardcoding the Pin No.

To use any of the Zephyr API's a pointer to the device struct must be created for each device (In this case gpioc).
> `static const struct device *led_dev = DEVICE_DT_GET(DT_NODELABEL(gpioc));`.
**Note: here we have used some Device Tree related macros for simpllicity but for this example lets ignore this line and focus on the led pin number.**

- The `device_is_ready(led_dev)` API takes in a pointer to the `struct device` and returns true if the peripheral/device is ready.

- The `gpio_pin_configure(led_dev,13,GPIO_OUTPUT_ACTIVE)` API takes in a pointer to the `struct device`, the pin number and the value/macro to define if the pin is output/input etc.

- The `gpio_pin_set_raw(led_dev,13,1)` API takes in a pointer to the `struct device`, the pin number and the value to set the pin (ie. 1 for ture/high).

- The `k_msleep(1000)` puts the current thread to sleep. Thus only toggling the LED every 1000 ms.

## Issues with this approach:

- Hardcoding the value pin number 13 will lead to portablity issues. 
- Every time we port the software to a new board/hardware the source code needs to be modified.

Building the project:

`repo git clone https://github.com/christo-ebi/ZehyrRTOS_Bascis.git`

`cd /ZehyrRTOS_Bascis/Blinky`

`west build`
