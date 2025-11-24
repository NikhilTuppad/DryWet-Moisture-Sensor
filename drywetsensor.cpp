int moistureValue;
float moisture_percentage;
void setup()
{
 pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(5, OUTPUT);
 Serial.begin(9600);
 }
void loop()
{
moistureValue = analogRead(A0);
 moisture_percentage = ((moistureValue/539.00)*100);
 if ( moisture_percentage>0 && moisture_percentage<25 )
 { digitalWrite(7,HIGH);
 digitalWrite(6,LOW);
 digitalWrite(5,LOW);
 }
 if ( moisture_percentage>25 && moisture_percentage<80 )
 { digitalWrite(7,LOW);
 digitalWrite(6,HIGH);
 digitalWrite(5,LOW);
 }
 if ( moisture_percentage>80 && moisture_percentage<100 )
 { digitalWrite(7,LOW);
 digitalWrite(6,LOW);
 digitalWrite(5,HIGH);
 }
 Serial.print("\nMoisture Value : ");
 Serial.print(moisture_percentage);
 Serial.print("%");
 delay(1000);
}