#define BPM 150

#define LAD 220.00
#define SIDB 233.08
#define SID 246.96
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
#define DOUU 1046.50
#define DOUUS 1108.70
#define REUU 1174.60
#define REUUS 1244.50

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

  playTone(SI, FOUR, false);

  playTone(MIUP, FOUR, true);
  playTone(SOLUP, EIGHT, false);
  playTone(FAUPS, FOUR, false);

  playTone(MIUP, HALF, false);
  playTone(SIUP, FOUR, false);

  playTone(LAUP, HALF, true);

  playTone(FAUPS, HALF, true);

  playTone(MIUP, FOUR, true);
  playTone(SOLUP, EIGHT, false);
  playTone(FAUPS, FOUR, false);

  playTone(REUPS, HALF, false);
  playTone(FAUP, FOUR, false);

  playTone(SI, HALF, true);

  playEmpty(DO, FOUR, false);
  playEmpty(DO, FOUR, false);
  playTone(SI, FOUR, false);

  playTone(MIUP, FOUR, true);
  playTone(SOLUP, EIGHT, false);
  playTone(FAUPS, FOUR, false);

  playTone(MIUP, HALF, false);
  playTone(SIUP, FOUR, false);
  //SECOND
  playTone(REUU, HALF, false);
  playTone(DOUUS, FOUR, false);

  playTone(DOUU, HALF, false);
  playTone(SOLUPS, FOUR, false);

  playTone(DOUU, FOUR, true);
  playTone(SIUP, EIGHT, false);
  playTone(SIUPB, FOUR, false);

  playTone(SIB, HALF, false);
  playTone(SOLUP, FOUR, false);

  playTone(MIUP, HALF, true);

  playEmpty(DO, HALF, false);
  playTone(SOLUP, FOUR, false);

  playTone(SIUP, HALF, false);
  playTone(SOLUP, FOUR, false);

  playTone(SIUP, HALF, false);
  playTone(SOLUP, FOUR, false);

  playTone(DOUU, HALF, false);
  playTone(SIUP, FOUR, false);

  playTone(SIUPB, HALF, false);
  playTone(FAUPS, FOUR, false);

  playTone(SOLUP, FOUR, true);
  playTone(SIUPB, EIGHT, false);
  playTone(SIUPB, FOUR, false);

  Serial.println("----------------------END----------------------");
  delay(5000);
}
