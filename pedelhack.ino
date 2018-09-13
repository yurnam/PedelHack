
/*
 *PedelHack by YurNam 
 *Halbiert die Frequenz des Tachosignals bei einem E-Bike sodass die 25Kmh-Grenze überschritten werden kann
 *
*/




const int OutputCoilPin = 2;                                           // Pin an dem Die Spule angeschlossen wird
int x = 1;                                                            //  Der Zählervariable x wird der Wert 1 zugewiesen
void setup() {                                                       //
  pinMode(OutputCoilPin, OUTPUT);                                   //    Setze OutputCoilPin auf Output
  Serial.begin(9600);                                              //
}                                                                 //
void loop(){                                                     //
  int InputCoilValue = analogRead(A0);                          //       Überwache die Spannung am Pin A0 und weise den Wert der Variable InputCoilValue zu. Je nachdem Welche Spule als Sensor benutzt wird muss InputCoilValue danach angepasst werden
  if (InputCoilValue >= 1){                                    //        Wenn InputCoilValue grösser als 1 ist dann sollst du :   
    Serial.println("Signal wurde Empfangen");                 //
    x++;                                                     //          x um 1 erhöhen.
    if (x%4 == 0){                                          //           und  wenn x geteilt durch 4  keinen Rest ergibt dann:    
      digitalWrite(OutputCoilPin, HIGH);                   //            Sende ein Signal an den Tacho.   2 = 25 KM/h  4 = 50 KM/h  6 = ?   8 = 100KM/h ?         
      Serial.println("Tachosignal wurde gesendet");       //
      delay(9);                                          //              Delays :  Ein Delay von 100ms ergibt auf dem Display eine Max. Geschwindigkeit von ca. 40 KM/h  (80 als tatsächliche Geschwindigkeit) 
      digitalWrite(OutputCoilPin, LOW);                 //             
    }   
    
    if (x%2 != 0){
      Serial.println("Tachosignal wurde nicht gesendet");
    }
  
  }                            // Damit wir nicht irgendwann einen sinnlos hohen Wert bei x haben, soll die Variable bei 1025 wieder auf 1 gesetzt werden.
   if (x > 1024){             // Wenn x größer als 1024 dann:                                
    x = 1;                   // Setze x wieder auf 1
    } 
delay(1);
}



// 
// 
