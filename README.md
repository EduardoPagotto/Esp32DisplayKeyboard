# Esp32DisplayKeyboard
Project of keyboard and display firmware build with FreeRTOS and PlataformIO

<br>

## Hardware
Usind EP32 DevKit V1 30 pinouts
![ESP32](docs/ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs.png)

<br>

### GPIO used connections with matrix keyboad
gpio|col|dir
---|---|---
16 | 0 | IN
17 | 1 | IN
18 | 2 | IN
19 | 3 | IN

gpio|lin|dir
---|---|---
21 | 0 | OUT
22 | 1 | OUT
23 | 2 | OUT
25 | 3 | OUT

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


