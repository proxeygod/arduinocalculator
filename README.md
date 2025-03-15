# arduniocalculator
this is an Arduino calculator that uses the Arduino mega 2560 r3
This is my project on making a calculor with arundio 


HOW TO MAKE :

Component's needed:

1. Jumper wires/hookup wires
(Jumper wire's are wires that have pins on the end usually they are messy.Hookup wires are wires that you cut sna strip they are more cleen thought.)
I say to use jumper wires it is a mess but the beadboard connections dont end it in my oppinon.


2. Ardunio mega 2560 R3
(This is another arudnio board I am using this becuase it has more pins it can hold more code)


3. 16x2 8-bit LCD Display
(This is a spefic type fo display that I am using right now.It has 2 line's with 16 digit's whrer you cna pace most carecters.)

4.resistors
you will need 2 risistors one 1K Ω and one 220 Ω risistor.

5.breadboard
(a breadboard is a mall area that you can connect pins or sensors to)

6.Donloding wire
(ot donlode the code to the arundio throught usb)


Steps:first bring all the componets together

1.Connect the pins of the 4x4 keypad to pins 9-2 using jumper wires


2. get a breadbaord and connect the 5v of the ardunio directly with a jumper wire to the plus (red) side of the power rails.
Then also connect ground the same way to The minus (blue) sid eof the power rials.

3.connect the LCD to the breadboard at any plce you want

4.connect pins VSS, RW, and K to the minus (blue) power rail.

5.Connect VDD directly to the plus  (red) power rail.

6.Connect V0 with the 1K Ω resistor to the minus  (blue) power rail.

7.Connect RS to pin 22

8.Connect the pins E to D7 to pins 23 - 31 in the layout below



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



9. Connect A with the 220 Ω resistor to the plus  (red) power rail
10. Lastely connect K to minus  (blue) power rail.



11.Downldoe ardunio IDE From https://www.arduino.cc/en/software

12.Open the arudnio IDE and then click controle + o. or open a file using the file bar.

13.Downldoe the file on the github page called ardunio_clalcultor.ino

14.Open it on arudnio IDE

15.Plug in the usb to the devide you are using and plug the other end into the arundio.

16.The last step is to click the checkmark in the left corner that will verfy and download the code after it is all downloded and everything is woring the LCD should say "Calc Ready"

17.A bonus step si to downlode the pdf beucase that is the key for the calculator.You can use it to knwo wat buttons do what.


By and thank you
