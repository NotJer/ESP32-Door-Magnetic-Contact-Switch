#include <WiFi.h>
#include <ESP32_MailClient.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

const int switchPin = 4; // GPIO pin connected to the magnetic switch
unsigned long doorOpenTime = 0;
bool doorOpen = false;

SMTPData smtpData;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT_PULLUP);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == LOW) { // Door is open
    if (!doorOpen) {
      doorOpen = true;
      doorOpenTime = millis();
    } else if (millis() - doorOpenTime > 20000) { // Door open for more than 20 seconds
      sendEmailNotification();
      doorOpen = false; // Reset the flag to avoid multiple emails
    }
  } else { // Door is closed
    doorOpen = false;
  }
}

void sendEmailNotification() {
  smtpData.setLogin("smtp_server", 465, "email", "app_password");
  smtpData.setSender("ESP32", "email");
  smtpData.setPriority("High");
  smtpData.setSubject("Door Open Alert");
  smtpData.setMessage("The door has been open for more than 20 seconds, please close the door.", false);
  smtpData.addRecipient("email");

  if (!MailClient.sendMail(smtpData)) {
    Serial.println("Error sending email: " + MailClient.smtpErrorReason());
  }

  smtpData.empty(); // Clear all data
}
