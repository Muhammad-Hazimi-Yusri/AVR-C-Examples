# AVR-C-Examples
 My personal testing, experiments and examples of AVR-GCC, mostly C codes for quick revision and snippets

These codes are written with Il Matto bare metal programming using USBasp in mind, not Arduino so no C++, avoided g++ but one that uses it will have compiler config, CC at Makefile clearly written for it.

Makefile is written for Atmel644p AVR MCU, change according

code is not perfect, might be buggy and not up to standards.

Use https://scoop.sh/ to easily install avr-gcc, WinGnu for Make automation, and avrdude without needing to deal with weird versioning and PATH problem. Use PuTTy for UART Serial connection

Install https://zadig.akeo.ie/ if having USBasp connection issue, primarily when flashing .hex file to the chip
