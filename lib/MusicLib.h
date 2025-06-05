#define REP for(int x=0;x<2;x++)

class MusicLib {
public:
    MusicLib(int bpm);
    MusicLib();

    void setBPM(int BPM);
    void setSheet(float customSheet[][]);
    void play();
    

    const float LAD = 220.00;
    const float SIDB = 233.08;
    const float SID = 246.96;
    const float DO = 261.63;
    const float DOS = 277.18;
    const float RE = 293.66;
    const float RES = 311.13;
    const float MI = 329.63;
    const float FA = 349.23;
    const float FAS = 369.99;
    const float SOL = 392.00;
    const float SOLS = 415.30;
    const float LA = 440.00;
    const float SIB = 466.16;
    const float SI = 493.88;
    const float DOUP = 523.25;
    const float DOUPS = 554.36;
    const float REUP = 587.32;
    const float REUPS = 622.26;
    const float MIUP = 659.26;
    const float FAUP = 698.46;
    const float FAUPS = 739.98;
    const float SOLUP = 784.00;
    const float SOLUPS = 830.60;
    const float LAUP = 880.00;
    const float SIUPB = 932.32;
    const float SIUP = 987.75;
    const float DOUU = 1046.50;
    const float DOUUS = 1108.70;
    const float REUU = 1174.60;
    const float REUUS = 1244.50;

    const long MINUTE = 60000000;
    const long double TAKT = (MINUTE/BPM)*4;
    const long HALF = TAKT/2;
    const long FOUR = TAKT/4;
    const long EIGHT = TAKT/8;
    const long SIXTEEN = TAKT/16;
    const long PAUSE_TAKT = TAKT;
    const long PAUSE_HALF = HALF;
    const long PAUSE_FOUR = FOUR;
    const long PAUSE_EIGHT = EIGHT;
private:
    int BPM = 0;
    float sheet[10000][3];

    void playTone(float v, long t, bool withPoint, int port=2);
    void playEmpty(float v, long t, bool withPoint, int port=2);

    int port = 2;
};
