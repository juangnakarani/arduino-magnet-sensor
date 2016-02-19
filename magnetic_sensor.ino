//
// Mambaca sensor magnet digital
//
int led1 = 13 ;// define LED Interface
int digitalPin = 3; // define the Reed sensor interfaces
int pinValue;// define numeric variables val
int count=0;//value jumlah berapa kali sensor mendeteksi magnet
int led2 = 4;//led indikator saat sudah berapa kali
boolean isOneRound = false;
void setup ()
{
  Serial.begin(9600);  // open the serial port at 9600 bps:    
  pinMode(led1, OUTPUT) ;// define LED as output interface
  pinMode(digitalPin, INPUT) ;// output interface as defined Reed sensor
  pinMode(led2, OUTPUT);
}
void loop ()
{
  pinValue = digitalRead (digitalPin) ;// digital interface akan dimasukkan pada pin #3
  if (pinValue == HIGH) // ketika sensor magnet mendeteksi magnet
  {
    digitalWrite (led1, HIGH);
    if(isOneRound == false){
      digitalWrite (led2, LOW);
      count++;
      Serial.println(count);
      isOneRound = true;
      if(count == 10){
        digitalWrite (led2, HIGH);
        count = 0;
      }
    }
  }
  else
  {
    digitalWrite (led1, LOW);
    isOneRound = false;
  }
}
