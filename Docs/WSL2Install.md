## WSL Installation Guide:

Installation Instruction for WSL Windowns 11: (https://learn.microsoft.com/en-us/windows/wsl/install)

Follow the same instructions given in the Documentation (Ubuntu): (https://docs.zephyrproject.org/latest/develop/getting_started/index.html)

To connect USB debuggers to WSL (Eg St-link).

- List all USB devices and get the bus-id: ` usbipd list `
![image](https://github.com/user-attachments/assets/dd7d0418-83c7-43fa-b21f-b0a17dbeb835)

    Here STM32 STLink is the USB device to be attached to the WSL.

- Share the STM32 STLink device: ` usbipd bind --busid {bus-id} `

    ![image](https://github.com/user-attachments/assets/92fa3090-15ee-4030-8c96-7b9871452b5e)

- Start the WSL Distro.

    ![image](https://github.com/user-attachments/assets/a1a4f48c-2904-4484-b37f-e5c9e8890ce3)

- Attach device: ` usbipd attach --wsl --busid {bus-id} `

    ![image](https://github.com/user-attachments/assets/13d0bef8-c448-404d-bd18-60ce56760d4e)

- Verify if device is detected by the linux distro: ` lsusb `

    ![image](https://github.com/user-attachments/assets/6d1da53b-e7bc-4756-9ad5-833b13427812)





