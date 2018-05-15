# DIY Fuel Injector Tester
Here you can find an injector tester based on an arduino and a MOSFET.
The tester is based on the description of a Fuel Injector Tester (EM276).
Here is this description :
>The tester can help diagnose injector problems, you can use it to test each injector individually to help identify stuck, leaking or burnt-out conditions. 
>It used 12 volt vehicle battery for power. 
>It has 4 pulse modes, the continuous mode (mode 4) helps to identify good or bad injectors. 
>The mode lock feature ensures test condition uniformity. 
>It can work with any fuel pressure tester. 
>-----------
>Four pulse modes:
>- **Mode 1**: **1** output **pulse**, pulse width about **250 ms** is which.
>- **Mode 2**: **50** output **pulses**, each pulse width is about **7 ms**.
>- **Mode 3**: **100** output **pulses**, every pulse width/pulse rate is about **3.5 ms**.
>- **Mode 4**: Output **impulse continuously** at a speed of **50 pulses per 1450 ms**, pulse width **7 ms**.


# What you need
You need some cheap stuff:
- an arduino platform (no matter the model, you just need a digital pin) 
- a mofset (here I use a IRF520 MOSFET, it cost less than 1 euro on Aliexpress)
- some Alligator Clips (available on aliexpress)
- a breadboard
- a trombone or some cables
- If you test your injectors (modes 1 to 3), you will need a fuel injection pump pressure tester kit (check it on eBay).
- If you want to clean our injector you can use the mode 4 and an ultrasound bath.

I have used this project to check my injector without removing it from my motor.
I use the technical reviews to get the injector pin on my ECM (Engine Management & Emissions).
To get a correct connection I use a needle in the connector of the ECM and an alligator clip. 
![demo][demo]

Here is the schematic of the tester. You can connect the tester directly on the injector (but there are not easy to access). In this case, you don't need to know the "+" and the "-" because an injector is not sensible to it. But **if like me, you use the ECM connector and the ground connector of your car, you need to respect the polarity.**
![Pinout][poinout]

# Configuration
In the arduino program you can change the **sig-pin** variable according to the pin used on our arduino.
You can also change the **mode** variable.

# How to use it to check you injector
First connect your nanometer to your fuel ramp. Then turn 3 times your key in the ignition (without starting the motor) to get a good pressure inside of your injection ramp.
Check the pressure on the nanometer and write it on a piece of paper.
Then disconnect the "+" and "-" of your battery. Disconnect your ECM connector.

Before using this Pulse Tester, use an Ohm meter to test the internal resistance of each injector. Should be 11-18 Ohms, with 14.5 Ohms as ideal. You should have the same resistance for all injectors and it is a good thing to be sure that you use the good pins.
**If one (1) or more injectors test out of spec, there's no sense going any further: the bad injector(s) MUST be replaced.**

Now, connect the arduino to your battery. Once the arduino correctly powered, connect the "v+" to your injector (in the ECM connector) and finish by connecting the v- to the ground of your car (the ground cable disconnect from the battery).
Then restart the arduino by pressing on the reset button. The test least one second and you can hear the injector nose.
Then read the nanometer: the pressure should have dropped, write it and then disconnect the arduino, reconnect the ECM connector then the battery. Go in the car, start the engine (to remove the fuel in the cylinder).
You can now restart the procedure for the other injectors.
At the end you can check if the pressure has dropped of the same value for all of your injector.



# Disclaimer
I have only done this DIY injector tester for my personal usage. You use it at your own risk.

# References 
- [MOSFET documentation](https://en.wikipedia.org/wiki/MOSFET) |  Mosfet on Aliexpress : "IRF520 MOSFET"
- Arduino Nano on Aliexpress : "nano v3.0 ch340"
- Alligator Clips on Aliexpress : "Alligator Clips Double-ended Clips"
- [Pinout - Mosfet ](https://www.pinterest.co.uk/pin/396527942183351203/)
- [Pinout - Arduino Nano](http://www.pighixxx.com/test/pinouts/boards/nano.pdf)
- [Shematics Fuel injection](http://www.924cup.fr/sour/technique/moteur/MS924/hpfp.gif)
- [EM276 Fuel Injector Tester  description](https://www.amazon.com/all-sun-EM276-Fuel-Injector-Tester/dp/B0126MEK3C)



[poinout]: ./images/pinout.png "Pinout"
[demo]: ./images/demo.jpg "Demo"