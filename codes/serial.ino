#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
    Serial.begin(115200);
    while (!Serial);

    Serial.println("Goodnight moon!");

    mySerial.begin(115200);
    mySerial.println("Hello, world?");
}

void loop() {
    int a=mySerial.available();
    if (a>0) {
        for(int i=0;i<a;i++)
            Serial.write(mySerial.read());
    }
    if (Serial.available()) {
        mySerial.write(Serial.read());
    }
}
