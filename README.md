# arduniocalculator
this is an Arduino calculator that uses the Arduino mega 2560 r3
This is my project on making a calculor with arundio 


HOW TO MAKE :

Component's needed:

1. Jumper wire or hookup wires: Jumper wire's are wires that have pins on the end and usually they are messy. Hookup wires are wires that you cut and strip and they are more clean though.
I recommend to use jumper wires because it is easier to connect them unlike hookup wires.

2. Ardunio mega 2560 R3: This is another arudnio board that I recommend using becuase it has more pins and it can hold more memory.

3. 16x2 8-bit LCD Display: This is a specific type of display that has 2 line's with 16 digit's where you can insert most characters.

4. Resistors: A resistor is a peice of metal that takes some of the current and reduces it in the process it makes heat. For this project you will need a 1K Ω and one 220 Ω.

8. Breadboard: A breadboard is a small board where you can connect pins or sensors to.

9. Downloading wire: A wire that is used to connect to your computer on one end and other to arundio board through USB.


Steps: 

1.Connect the pins of the 4x4 keypad to pins 9-2 using jumper wires.

2. Using the breadbaord, connect the 5v of the ardunio directly with a jumper wire to the plus (red) side of the power rails.

3. Connect ground the same way to the minus (blue) side of the power rials.

4. Connect the LCD to the breadboard at any place you want

5. Connect pins VSS, RW, and K to the minus (blue) power rail.

6. Connect VDD directly to the plus (red) power rail.

7. Connect V0 with the 1K Ω resistor to the minus  (blue) power rail.

8. Connect RS to pin 22.

9. Connect the pins E to D7 to pins 23 - 31 in the layout below.

Pin on LCD          Pin on Ardunio

E                   23
D0                  24
D1                  25
D2                  26
D3                  27
D4                  28
D5                  29
D6                  30
D7                  31


10. Connect A with the 220 Ω resistor to the plus  (red) power rail.

11. Connect K to minus  (blue) power rail.

12. Download ardunio IDE from https://www.arduino.cc/en/software

13. Open the arudnio IDE and then click controle + o. or open a file using the file bar.

14. Download the file on the github page called ardunio_clalcultor.ino

15. Open it on arudnio IDE.

16. Plug in the USB to the device you are using and plug the other end into the arundio.

17. Click the checkmark in the left corner that will verfy and download the code after it is all downloded and everything is woring the LCD should say "Calc Ready".

Bonus: Download the pdf because that is the key for the calculator. You can use it to know which buttons do what.


Bye and thank you
