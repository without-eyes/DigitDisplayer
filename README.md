# 7-Segment Display with Brightness Control

This Arduino project controls a 7-segment display to show numbers (0–9) and allows the brightness to be adjusted using buttons.

## Components
- Arduino Uno (or compatible)
- 7-segment display
- 3 push buttons
- Resistors
- Breadboard and jumper wires

## Circuit
- **7-segment pins**: Connect to Arduino pins as per the `pins[]` array.
- **Buttons**: Three buttons connected to pins `10`, `11`, and `12` for increasing, decreasing the displayed number, and adjusting brightness.
- **PWM Pin**: Connected to pin `5` for brightness control via PWM.

## Pin Connections
- **Increase Button**: Pin 10
- **Decrease Button**: Pin 11
- **Brightness Button**: Pin 12
- **PWM Brightness Control**: Pin 5
- **7-Segment Display**: Pins `{7, 6, 4, 3, 2, 8, 9}`

## How it Works
- **Number Display**: Use the increase and decrease buttons to change the number on the display (0–9).
- **Brightness Control**: Use the brightness button to adjust the display brightness up or down, with a smooth transition.
- **Debouncing**: The code ensures buttons are debounced using the isButtonsPressed flag and a small delay.

## License
This project is open-source and available under the [MIT License](LICENSE).
