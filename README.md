# ESP32 Door Magnetic Contact Switch

## Components
- **ESP32**: The microcontroller used for this project.
- **Magnetic Contact Switch**: Detects the door's open or closed state.
- **SMTP**: Protocol used to send email notifications.

## Summary
This personal project aims to utilize an ESP32, a magnetic contact switch, and the SMTP/WiFi capabilities of the ESP32. 
An email notification will be sent if the door remains open for a specified number of seconds without being closed.

## Circuit Diagram
<img width="391" alt="Screenshot 2024-12-01 at 23 05 54" src="https://github.com/user-attachments/assets/e8b61ef0-07d2-4b44-8c2c-587fb8ebad1b">


## Troubleshooting/Additional Notes
- **Security**: Obtaining an app password for your email address is necessary to bypass the security measures that email providers use.
- **Pull-Up/Down Resistor**: Used to remove floating and ensure I/O pin is in High/Low state.



