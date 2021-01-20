#include "shidu_0.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXTIMINGS 85

#define DHTPIN 0
shidu_0::shidu_0(QObject *parent) : QObject(parent)
{
    qDebug() << "shidu_0 build!\n";
}


shidu_0& shidu_0::get_shidu()



/*
 *   dht11.c:
 *   Simple test program to test the wiringPi functions
 *   DHT11 test
 */





{

    static shidu_0 single;

    wiringPiSetup();
    int dht11_dat[5] = {0,0,0,0,0};
    uint8_t laststate = HIGH;
    uint8_t counter = 0;
    uint8_t j = 0, i;
    float f; // fahrenheit

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

    // pull pin down for 18 milliseconds
    pinMode(DHTPIN, OUTPUT);
    digitalWrite(DHTPIN, LOW);
    delay(18);
    // then pull it up for 40 microseconds
    digitalWrite(DHTPIN, HIGH);
    delayMicroseconds(40);
    // prepare to read the pin
    pinMode(DHTPIN, INPUT);

    // detect change and read data
    for ( i=0; i< MAXTIMINGS; i++) {
        counter = 0;
        while (digitalRead(DHTPIN) == laststate) {
            counter++;
            delayMicroseconds(1);
            if (counter == 255) {
                break;
            }
        }
        laststate = digitalRead(DHTPIN);

        if (counter == 255) break;

        // ignore first 3 transitions
        if ((i >= 4) && (i%2 == 0)) {
            // shove each bit into the storage bytes
            dht11_dat[j/8] <<= 1;
            if (counter > 16)
                dht11_dat[j/8] |= 1;
            j++;
        }
    }

    // check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
    // print it out if data is good
    if ((j >= 40) &&
            (dht11_dat[4] == ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF)) )
    {
        single.num = 1.0 * dht11_dat[0] + 0.01 * dht11_dat[1];
        f = dht11_dat[2] * 9. / 5. + 32;
        qDebug() << "umidity = " << single.num << "%";

        return single;
    }
    else {
        single.num = 0;
        return single;
    }

}
