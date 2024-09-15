***For this example we will completely use the device tree to reference the GPIO device/pheripheral and the GPIO Pin Number.***

 Before proceeding with the tutorial please read the [device tree explainer](https://github.com/christo-ebi/ZehyrRTOS_Bascis/blob/main/Docs/DeviceTree.md).

 For STM32F108C8T6 (Blue Pill -AKA Min DEV BOARD BLUE) Dev Board the Device Tree is located at : `zephyrproject/zephyr/boards/others/stm32_min_dev/` folder.

 First we define a overlay file (it is standard practice to place the overide file insdie the boards folder with a .overlay extension) to extend/override the device tree with our custom node.

 Here we have defined the following:
 
- leds node within the root node.
- `compatibale` key is used to match with the device tree bindings (Provides information on the contents of the node.)  Here we use the pre defined gpio-leds bindings.
- gpio-leds binding: It is located at : /zephyrproject/zephyr/dts/bindings/led/gpio-leds.yaml
- The gpios is a property with phandle array (a list of phandles and 32-bit cells (usually specifiers)) type. Which is ued to define the pheripheral and pin number and the default state if the pin.
- A phandle is typeof a which is like a pointer to another node. Here in the gpios phandle-array the `&gpioc` is a phandle to node gpioc.


```
/   {
        leds {
            compatible = "gpio-leds";
            blinking_led: blinking_led {
                gpios = <&gpioc 13 GPIO_ACTIVE_HIGH>;
            };
        };
    };
```

First we define the `struct gpio_dt_spec' which will contain the gpio pin information. This can be initialized by the information from the device tree
using the "	GPIO_DT_SPEC_GET(node_id, prop)"

The node_id is a value that uniquely identifies that node. 
The prop is the property name in lowercase and underscore (From the device tree node). Here we have defined the gpio device , pin number and default state.

Next we can check if the device is ready using the `device_is_ready` API. Note here we are passing the led_dev.port as an argument. As the port is a `struct device` pointer type.

gpio_pin_configure_dt API is used to configure the pin as an output.
gpio_pin_toggle_dt API is ued to toggle the pin state.
k_msleep() suspends the thread for the time specified.

Note: Here all the API's ending with `_dt` take the device tree struct (In our case `struct gpio_dt_spec` as an argument.)

