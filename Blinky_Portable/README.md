For this example we will completely use the device tree to refrence the GPIO device/pheripheral and the GPIO Pin Number.

 TO DO: Before proceding with the tutorial please read the device tree explainer.

First we define the `struct gpio_dt_spec' which will contain the gpio pin information. This can be initialized by the information from the device tree
using the "	GPIO_DT_SPEC_GET(node_id, prop)"

The node_id is a value that uniquely identifies that node.
The prop is the property name in lowercase and underscore.
