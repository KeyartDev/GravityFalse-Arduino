#include "MusicLib.h"

MusicLib::MusicLib() {}

MusicLib::MusicLib(int bpm) {
    this->BPM = BPM;   
}

void MusicLib::setBPM(int BPM) {
    this->BPM = BPM;
}

void MusicLib::setSheet(float customSheet[][]) {
    this->sheet = customSheet;
}

void MusicLib::playTone(float v, long t, bool withPoint) {
    t = withPoint ? t+t/2 : t;
    const long T = 1000000 / v;
    long d = T/2;
    int count = t / T;
    Serial.println("V: " + String(v) + "   |   point: " + String(withPoint) + "   |   length: " + String(t));
    for (int i=0;i<count;i++) {
        digitalWrite(port, HIGH);
        delayMicroseconds(d);
        digitalWrite(port, LOW);
        delayMicroseconds(d);
    }
    delay(10);
}

void MusicLib::playEmpty(float v, long t, bool withPoint) {
    t = withPoint ? t+t/2 : t;
    const long T = 1000000 / v;
    long d = T/2;
    int count = t / T;
    Serial.println("V: " + String(v) + "   |   point: " + String(withPoint) + "   |   length: " + String(t));
    for (int i=0;i<count;i++) {
        digitalWrite(13, HIGH);
        delayMicroseconds(d);
        digitalWrite(13, LOW);
        delayMicroseconds(d);
    }||
    Serial.println("----------------DELAY: " + String(T*count) + "----------------");
    delay(10);
}

void MusicLib::play() {
    if (BPM == 0) {
        Serial.println("Set BPM before playing!");
        return;
    }

    for (int i=0;i<sheet.length;i++) {
        if (sheet[i][0] != PAUSE_EIGHT && sheet[i][0] != PAUSE_FOUR && sheet[i][0] != PAUSE_HALF && sheet[i][0] != PAUSE_TAKT) {
            playTone(sheet[i][0], sheet[i][1], sheet[i][2]);
        } else {
            playEmpty(DO, sheet[i][1], false);
        }
    }
}
