

/*

  PedelHack V2 by YurNam

*/


int laststate = 1;        // Variablen für die Flankensteuerung
int state = 1;
volatile int i = 0;
const int tachopin = 4;   // Pin der zum Tacho führt
const int reedpin = 2;    // Pin der zum Reedschalter (Sensor) führt
const int red = 1;

const int v = 350;  // 350 ms ~ 25 KM / h je nach Radgröße



int m = 1;          // Variable für den Modus  1 = Normal (< 25 Kmh) 2 = Speedmodus (> 25Kmh)

volatile long int lasttime = 0;   // Die Variablen für die Zeit initialisieren
volatile long int time = 0;
volatile int newtime;



void setup(){
                                  // Pins Initialisieren
                    
  pinMode(tachopin, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(reedpin, INPUT);

  int b = 0; 
  while(b < 20){           // Kurz blinken
  digitalWrite(red, HIGH);  
  delay(50);
  digitalWrite(red, LOW);
  delay(50); 
  b++;
  }
  
}


void tacho(int a){                  // Diese Funktion berechnet die Geschwindigkeit und sendet das Tachosignal

 
  newtime = time - lasttime;        // Zeit zwischen den Impulsen messen
  lasttime = time;
  time = millis();

  if (newtime < v) {m = 2;}     // Wenn Zeit zwischen den Impulsen länger als definiert, Modus auf 2 setzen
  else {m = 1;}                   // sonst Modus 1
 
  if (m == 1){digitalWrite(red, LOW);}  //  Wenn der Modus umschaltet die Rote LED (Pin 1 am Digispark) einschalten

  if(a % m == 0)                      // m wird hier direkt fürs rechnen benutzt   wenn Modus 1 ergibt die Modulorechnung immer 0, im 2. Modus nur jedes 2. mal
  {
  digitalWrite(tachopin, HIGH);
  delay(20);                            // Einen kurzen Impuls an den Tacho senden
  digitalWrite(tachopin, LOW);
  }
}


void loop(){
  state = digitalRead(reedpin);
  if (laststate == 1 && state == 0)   // Bei Fallender Flanke zählen
  {
    laststate = 0;
    tacho(i);                       // Die Zählervariable an tacho() weitergeben
    i++;
  }

  if (laststate == 0 && state == 1){laststate = 1;}  // Flankensteuerung zurücksetzen
  if (1 > 1023){i = 0;}                              // Sinnlos hohen Zählerwert vermeiden


}
