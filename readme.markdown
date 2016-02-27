# vending1.ino

a program for the arduino inside Omni Vending Machine #1
(that's the black one, not the brown one)

https://sudoroom.org/wiki/Hack-o-mat

comes with an uploader script make.sh from substack's excellent
non-GUI arduino uploader:

https://github.com/substack/arduino-starter

# to upload vending1.ino to the arduino from commandline:

First install the arduino and avr toolchains:

```
sudo apt-get install arduino python-pip gcc-avr avr-libc binutils-avr avrdude
```

# flash and run

To flash the connected arduino with the program in `vending1.ino`, do:

```
$ ./make.sh
```
