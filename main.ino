#define BPM 166

#define DO 261.63
#define DOS 277.18
#define RE 293.66
#define RES 311.13
#define MI 329.63
#define FA 349.23
#define FAS 369.99
#define SOL 392.00
#define SOLS 415.30
#define LA 440.00
#define SIB 466.16
#define SI 493.88
#define DOUP 523.25
#define DOUPS 554.36
#define REUP 587.32
#define REUPS 622.26
#define MIUP 659.26
#define FAUP 698.46
#define FAUPS 739.98
#define SOLUP 784.00
#define SOLUPS 830.60
#define LAUP 880.00
#define SIUPB 932.32
#define SIUP 987.75

#define REP for(int x=0;x<2;x++) 


const long MINUTE = 60000000;
const long double TAKT = (MINUTE/BPM)*4;
const long HALF = TAKT/2;
const long FOUR = TAKT/4;
const long EIGHT = TAKT/8;
const long SIXTEEN = TAKT/16;

#define FOUR_PAUSE delayMicroseconds(FOUR);

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  
}

void playTone(float v, long t, bool withPoint, int port=2) {
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

void playEmpty(float v, long t, bool withPoint, int port=2) {
  t = withPoint ? t+t/2 : t;
  const long T = 1000000 / v;
  long d = T/2;
  int count = t / T;
  Serial.println("V: " + String(v) + "   |   point: " + String(withPoint) + "   |   length: " + String(t));
  for (int i=0;i<count;i++) {
    digitalWrite(4, HIGH);
    delayMicroseconds(d);
    digitalWrite(4, LOW);
    delayMicroseconds(d);
  }
  Serial.println("----------------DELAY: " + String(T*count) + "----------------");
  delay(10);
}

void loop() {
  Serial.println("---------------------BEGIN---------------------");
  //PRE
  playTone(FAUP, EIGHT, false);
  playTone(REUP, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(REUP, EIGHT, false);
  playTone(FAUP, EIGHT, false);
  playTone(REUP, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(REUP, EIGHT, false);

  playTone(FAUP, EIGHT, false);
  playTone(DOUP, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(DOUP, EIGHT, false);
  playTone(FAUP, EIGHT, false);
  playTone(DOUP, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(DOUP, EIGHT, false);

  playTone(FAUP, EIGHT, false);
  playTone(DOUPS, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(DOUPS, EIGHT, false);
  playTone(FAUP, EIGHT, false);
  playTone(DOUPS, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(DOUPS, EIGHT, false);

  playTone(FAUP, EIGHT, false);
  playTone(DOUPS, EIGHT, false);
  playTone(LA, EIGHT, false);
  playTone(DOUPS, EIGHT, false);

  playTone(MIUP, EIGHT, false);
  playTone(DOUPS, EIGHT, false);
  playTone(LAUP, FOUR, false);

  //FIRST
  playTone(RE, HALF, true);
  playTone(MI, FOUR, false);
  
  playTone(FA, TAKT, false);
  
  playTone(LA, FOUR, true);
  playTone(SOL, FOUR, true);
  playTone(LA, FOUR, false);
  
  playTone(DO, TAKT, false);
  
  playTone(RE, HALF, true);
  playTone(MI, FOUR, false);
  //SECOND
  playTone(FA, HALF, false);
  playTone(MI, HALF, false);
  
  playTone(SOL, HALF, false);
  playTone(LA, HALF, false);
  
  playTone(SOL, HALF, false);
  playTone(FA, HALF, false);

  playEmpty(RE, FOUR, false);
  playTone(FA, FOUR, false);
  playTone(FA, FOUR, false);
  playTone(FA, FOUR, false);
  //THIRD
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(SOL, FOUR, false);
  playTone(FA, FOUR, false);

  playEmpty(RE, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);

  playTone(SOL, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(SOL, FOUR, false);
  playTone(FA, FOUR, false);

  playEmpty(RE, FOUR, false);
  playTone(FA, FOUR, false);
  playTone(FA, FOUR, false);
  playTone(FA, FOUR, false);
  //FOURTH
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(SOL, FOUR, false);
  playTone(FA, FOUR, false);

  playEmpty(RE, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);

  playEmpty(RE, FOUR, false);
  playTone(DOUPS, FOUR, false);
  playTone(DOUPS, FOUR, false);
  playTone(DOUPS, FOUR, false);

  playEmpty(RE, FOUR, false);
  playTone(FA, FOUR, false);
  playTone(FA, FOUR, false);
  playTone(FA, FOUR, false);
  //FITH
  playTone(LA, FOUR, false);
  playTone(LA, FOUR, false);
  playTone(SOL, FOUR, false);
  playTone(FA, FOUR, false);

  playEmpty(RE, FOUR, false);
  playTone(SIB, FOUR, false);
  playTone(SIB, FOUR, false);
  playTone(SIB, FOUR, false);

  playTone(SOL, HALF, false);
  playTone(DOUP, HALF, false);

  playTone(LA, HALF, false);
  playTone(DOUPS, HALF, false);

  playTone(REUP, TAKT, false);

  Serial.println("----------------------END----------------------");
  delay(5000);
}
