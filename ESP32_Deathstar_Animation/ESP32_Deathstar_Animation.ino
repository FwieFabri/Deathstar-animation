int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;
int buttonState1 = 0;
int lastButtonState1 = 0;
int Knopf1 = 0;
int Knopf2 = 0;
int Schuss = 0;
int Ton = 0;
unsigned long AlteZeit = 0;
int Betrieb = 0;
int D0 = 13;
int D1 = 14;
int D2 = 15;
int D3 = 16;
int D4 = 17;
int D5 = 18;
int D6 = 19;
int D7 = 21;
int D8 = 22;

void setup() {
              pinMode(23, INPUT);
              pinMode(25, INPUT);
              pinMode(D0, OUTPUT);//led filament 1 to 9
              pinMode(D1, OUTPUT);
              pinMode(D2, OUTPUT);
              pinMode(D3, OUTPUT);
              pinMode(D4, OUTPUT);
              pinMode(D5, OUTPUT);
              pinMode(D6, OUTPUT);
              pinMode(D7, OUTPUT);
              pinMode(D8, OUTPUT);
              pinMode(26, OUTPUT);//trigger on Sound module
              pinMode(27, OUTPUT);
              Serial.begin(9600);

              digitalWrite(26, LOW);
              digitalWrite(26, HIGH);

 
             }

void loop() {

              
              
              unsigned long Zeit = millis();

              buttonState = Knopf1;
              
              buttonState1 = Knopf2;

              if (digitalRead(23) == HIGH) {
                                            Knopf1 = 1;
                                           } else {
                                                   Knopf1 = 0;
                                                  }
            
              if (digitalRead(25) == HIGH) {
                                            Knopf2 = 1;
                                           } else {
                                                   Knopf2 = 0;
                                                  }
                                                  
if (buttonState != lastButtonState) {
                                       if (buttonState == 1) {
                                                               buttonPushCounter += 1;
                                                               if (buttonPushCounter % 2 != 0) {
                                                                                                Serial.println("Alles An");
                                                                                               }
                                                               if (buttonPushCounter % 2 == 0) {
                                                                                                Serial.println("Alles Aus");
                                                                                               }  
                                                              }
                                       delay(5); // Wait for 5 millisecond(s)
                                       lastButtonState = buttonState;
                                       }
  
  
  
  if (Schuss == 0) {
                    if (buttonPushCounter % 2 != 0) {
                                                    digitalWrite(D0, HIGH);
                                                    digitalWrite(D1, HIGH);
                                                    digitalWrite(D2, HIGH);
                                                    digitalWrite(D3, HIGH);
                                                    digitalWrite(D4, HIGH);
                                                    digitalWrite(D5, HIGH);
                                                    digitalWrite(D6, HIGH);
                                                    digitalWrite(D7, HIGH);
                                                    digitalWrite(D8, HIGH);
                                                    digitalWrite(27, HIGH);
                                                    } else {
                                                            digitalWrite(D0, LOW);
                                                            digitalWrite(D1, LOW);
                                                            digitalWrite(D2, LOW);
                                                            digitalWrite(D3, LOW);
                                                            digitalWrite(D4, LOW);
                                                            digitalWrite(D5, LOW);
                                                            digitalWrite(D6, LOW);
                                                            digitalWrite(D7, LOW);
                                                            digitalWrite(D8, LOW);
                                                            digitalWrite(27, LOW);
                                                           }
                    }

if (buttonState1 != lastButtonState1) {
                                       if ((buttonState1 == 1) && (Betrieb == 0)) {
                                                               AlteZeit = Zeit;
                                                               Schuss = 1;
                                                               Serial.println("Schuss");
                                                               } 
                                      }

delay(10); // Wait for 5 millisecond(s)

if(Schuss == 1){
                digitalWrite(27, LOW);
                Betrieb = 1;
                if( (Zeit - AlteZeit) >= 1 && (Zeit - AlteZeit) <= 100){
                                                                            digitalWrite(26, LOW);
                                                                            Serial.println("Ton");
                                                                           } else{
                                                                                  digitalWrite(26, HIGH);
                                                                                 }
                
                if( (Zeit - AlteZeit) >= 5933 && (Zeit - AlteZeit) <= 7367){
                                                                            digitalWrite(D0, HIGH);
                                                                           } else{
                                                                                  digitalWrite(D0, LOW);
                                                                                 }
                if((Zeit - AlteZeit) >= 6033 && (Zeit - AlteZeit) <= 7367){ 
                                                                           digitalWrite(D1, HIGH);
                                                                          } else{
                                                                                 digitalWrite(D1, LOW);
                                                                                }
                if((Zeit - AlteZeit) >= 6100 && (Zeit - AlteZeit) <= 7367){
                                                                           digitalWrite(D2, HIGH);
                                                                          } else{
                                                                                 digitalWrite(D2, LOW);
                                                                                }
                if((Zeit - AlteZeit) >= 6233 && (Zeit - AlteZeit) <= 7367){
                                                                           digitalWrite(D3, HIGH);
                                                                          } else{
                                                                                 digitalWrite(D3, LOW);
                                                                                }
                if((Zeit - AlteZeit) >= 6366 && (Zeit - AlteZeit) <= 7367){ 
                                                                           digitalWrite(D4, HIGH);
                                                                          } else{
                                                                                 digitalWrite(D4, LOW);
                                                                                }
                if((Zeit - AlteZeit) >= 6533 && (Zeit - AlteZeit) <= 7367){
                                                                           digitalWrite(D5, HIGH);
                                                                          } else{
                                                                                 digitalWrite(D5, LOW);
                                                                                } 
                if((Zeit - AlteZeit) >= 6700 && (Zeit - AlteZeit) <= 7367){ 
                                                                           digitalWrite(D6, HIGH);
                                                                          } else{
                                                                                 digitalWrite(D6, LOW);
                                                                                }
                if((Zeit - AlteZeit) >= 6867 && (Zeit - AlteZeit) <= 7367){ 
                                                                           digitalWrite(D7, HIGH);  
                                                                          } else{
                                                                                 digitalWrite(D7, LOW);
                                                                                }
                if((Zeit - AlteZeit) >= 6867 && (Zeit - AlteZeit) <= 8367){ 
                                                                           digitalWrite(D8, HIGH);
                                                                           Serial.println("BOOOMM!!!");
                                                                          } else{
                                                                                 digitalWrite(D8, LOW);
                                                                                }
                if(Zeit - AlteZeit >= 16000){
                                            buttonPushCounter = 2;
                                            Betrieb = 0;
                                            Schuss = 0;
                                           }
                
                
                }
                
}                  
