# Esp32DisplayKeyboard
Project of keyboard and display firmware build with FreeRTOS and PlataformIO

<br>

## Hardware

Keypad 4x4

![KEYPAD_4X4](docs/keypad.png)

### GPIO used connections with matrix keyboad
gpio|col|dir
---|----|---
16 | X1 | IN
17 | X2 | IN
18 | X3 | IN * 13
19 | X4 | IN

gpio|lin|dir
---|----|---
21 | Y1 | OUT
22 | Y2 | OUT
23 | Y3 | OUT * 12
25 | Y4 | OUT

<br>

Nokia LCD5110

![Nokia5110](docs/Nokia-5110-LCD.jpg)

### GPIO Nokia 5110
gpio           |LCD
---------------|---
02             |RST
15             |CE
04             |DC
23  (VSPI_MOSI)|DIN
18  (VSPI_CLK) |CLK
VCC            |VCC
BL             |3.3V (220R)
GND            |GND

<BR>

EP32 DevKit V1 30 pinouts

![ESP32](docs/ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs.png)

<br>

<b>obs:</b> <i>Directory (/hardware) has kicad files</i>
![kicad](docs/esp32kd.png)

<br>

### Develop Environment
```bash
# Extençoes uteis: 
# code --list-extensions | xargs -L 1 echo code --install-extension
code --install-extension ms-vscode.cpptools
code --install-extension PKief.material-icon-theme
code --install-extension platformio.platformio-ide
code --install-extension QiaoJie.binary-viewer
code --install-extension xaver.clang-format

# Liberacao da porta /dev/ttyACM0 no ubuntu para usuario (logout necessario)
sudo usermod -a -G tty $USER
sudo usermod -a -G dialout $USER
```

<br>

## Optional

```bash
# Simulador de Uno/pic
apt install simulide

# Acesso a serial
sudo apt install minicom

# Serial: /dev/ttyACM0 
# speed: 9600 baund 
# parity: none 
# bits: 7
minicom -s
```

<br>

## References:
- https://www.embarcados.com.br/arduino-vscode-platformio/
- https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
- https://www.fernandok.com/2018/03/esp32-detalhes-internos-e-pinagem.html
- https://www.electronicshub.org/esp32-nokia-5110-lcd/


