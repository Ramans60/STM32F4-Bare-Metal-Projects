## STM32F401CCU6 – Recovering from "Device Not Found" Issue (Mass Erase Method)

### ⚠️ Problem Description

When flashing the STM32F401CCU6 using ST-LINK and STM32CubeProgrammer, the device fails to connect, and the following error appears:

```
ST-LINK error (DEV_CONNECT_ERR)
```

This indicates the target MCU is not responding to the programmer due to a locked flash, unstable firmware, or incorrect configuration.

This usually occurs when the firmware gets stuck, or memory is locked/protected. It can often be solved using a combination of forced erase, reset button timing, and flashing firmware again.

---

### 🎯 Goal

Erase the flash memory and restore access to the STM32F401CCU6 for successful programming and debugging.

---

### 🧰 Requirements

* ST-LINK V2 or V3
* STM32\_Programmer\_CLI (latest version)
* Working USB cable
* STM32F401CCU6 board with access to RESET and BOOT0 pins
* Terminal (Ubuntu/Linux or Windows CMD)

---

### 🛠️ Step-by-Step Solution

Below are practical commands to recover the STM32F401CCU6 when "Device Not Found" occurs.

#### 🔁 1. **Mass Erase (Under Reset Mode)**

```bash
STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -e all
```

✅ Performs a full erase of flash memory. Required if device is locked.

> 💡 *Press and hold the RESET button, run the command, then release RESET to allow the erase to proceed.*

📋 **Sample Output:**

```
Mass erase ...
Mass erase successfully achieved
```

---

#### 🔍 2. **Display Option Bytes**

```bash
STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -ob displ
```

🧠 Shows RDP, write protections, and boot options.

📋 **Sample Output (Partial):**

```
RDP          : 0xAA (Level 0, no protection)
WRP0         : 0x1 (Write protection not active)
BOR_LEV      : 0x3 (BOR OFF reset threshold level from 1.80 to 2.10 V)
```

---

#### 💾 3. **Flash .bin File to STM32F401**

```bash
STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -d blink.bin 0x08000000 -v -rst
```

Use this if your firmware is in binary format.

❗ *If you see:* `Error: File does not exist: blink.bin`, place the file in the current directory or give the full path.

---

#### 💾 4. **Flash .hex File (Alternative)**

```bash
STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -w your_firmware.hex -v -rst
```

Use this if your firmware is in Intel HEX format.

❗ *If you see:* `Error: File does not exist: your_firmware.hex`, double-check the filename and location.

---

#### 🔎 5. **Find Your Firmware Files (.bin or .hex)**

```bash
find . -name "*.bin"
find . -name "*.hex"
```

Useful to locate your compiled firmware.

---

#### 🐌 6. **Lower SWD Frequency (For Stable Flashing)**

```bash
STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst freq=1000 -e all
```

Reduce SWD speed to \~1 MHz for more reliable flashing.

✅ This worked successfully as shown in terminal output:

```
SWD freq    : 950 KHz
Mass erase successfully achieved
```

---

### ❌ Deprecated or Unavailable Options

```bash
STM32_Programmer_CLI -c port=SWD reset=HWrst mode=UR --connect-delay=100
```

⚠️ Not supported in CLI v2.19. Use stable power and hold RESET manually instead.

---

### ✅ Extra Recovery Tips

* Use **mode=UR** (Under Reset) when the device fails to respond.
* **Important:** For some commands, you **must press and hold the RESET button**, run the command, and then **release RESET** to allow access.
* Keep **BOOT0 = GND** to boot from main flash after programming.
* Use a reliable 3.3V power source and a good USB cable.
* Remove read protection if necessary:

```bash
STM32_Programmer_CLI -c port=SWD -ob RDP=AA
```

---

### 📌 Summary

This "Mass Erase Recovery Method" helps fix the "Device Not Found" error on STM32F401CCU6 by erasing the flash, resetting the MCU, and flashing firmware again. Commands must sometimes be run with the RESET button pressed, especially when the chip is locked or bricked.

✅ Confirmed working and tested on STM32F401CCU6 board. All screenshots and logs are real.

---

### 🔗 References

* [STM32CubeProgrammer CLI User Manual](https://www.st.com/resource/en/user_manual/um2237-stm32cubeprogrammer-software-description-stmicroelectronics.pdf)
* [STM32F401CC Datasheet](https://www.st.com/resource/en/datasheet/stm32f401cc.pdf)
* [ST-LINK Firmware Upgrade](https://www.st.com/en/development-tools/stsw-link007.html)


![Screenshot from 2025-07-01 18-48-17](https://github.com/user-attachments/assets/6ca390ac-2760-4bd3-9404-6c467ccac5ae)
![Screenshot from 2025-07-01 18-50-22](https://github.com/user-attachments/assets/5c7ec9b1-6219-45a8-9f90-761ea29efdf9)
![Screenshot from 2025-06-26 09-21-53](https://github.com/user-attachments/assets/de2d9b03-791a-4e31-8368-1a1a67262c5d)
![Screenshot from 2025-07-02 09-22-15](https://github.com/user-attachments/assets/5b43bc5b-4daa-4d5b-a981-cbdc92cd7617)
![Screenshot from 2025-07-02 09-23-22](https://github.com/user-attachments/assets/3aa0ecd1-dbb9-428e-9eb9-bbc84534cc22)
![Screenshot from 2025-07-02 09-24-29](https://github.com/user-attachments/assets/f2f73905-7865-4a96-a75f-4463fbde7a9e)




