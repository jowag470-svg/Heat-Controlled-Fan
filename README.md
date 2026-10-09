# Heat Controlled Fan

This is a breadboard circuit utilizing a UNO R3, thermistor, L293D, and power supply. It was made to be an automated 
cooling system for my room, and will turn on if the temperature is ever 80 degrees fahrenheit or above.

<img width="2880" height="2160" alt="Circuit" src="https://github.com/user-attachments/assets/7d9a3c4a-cbba-4c97-8ea8-661e756ff067" />

## How it works

The thermistor is paired with a 10k resistor to divide the voltage that the A2 pin reads. The program converts its readings 
into degrees fahrenheit. The L239D motor is used to activate the fan, as the UNO R3 is not strong enough on its own.

## Parts

- UNO R3

- 830x Tie-Point Breadboard

- L293D IC

- Fan Blade and 3-6v Motor

- 8 M-M Wires

- Power Supply Module

- 9V1A Adapter

- Thermistor

- 10k Resistor

## Wiring

<img width="724" height="301" alt="image" src="https://github.com/user-attachments/assets/7ddd8a24-cd59-4c32-ba54-12ed184ee7e3" />

## Problems I Ran Into

- Thermistor was reading a couple degrees too high so I added an offset of -3 degrees in the conversion

- Fan was constantly switching on and off due to minor temperature change so I added 3 degrees of hysteresis, making the requirement to turn the fan off 3 degrees lower for a smoother switch

## Potential Improvements
- Add lcd screen to display temperature

- smaller build for portability
