

#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7);
char msg;
char call;

void bao_chay();
//check commited
int count = 0;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  pinMode(3 ,INPUT);
  
}

void loop()
{  
//  Serial.print("test\n");
  
//  Serial.println(digitalRead(3));
  if (digitalRead(3) == 0 && count == 0){
    SendMessage();
    delay(5000);
    MakeCall();
    count = 1;
    Serial.print("He THong Bao Chay\n");
  }else if (digitalRead(3) == 1){
    count = 0;
  }
//  Serial.print(count);
  delay(1000);
}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+84355136883\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Dang Phat Hien Chay");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

/*void ReceiveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (mySerial.available()>0)
  {
    msg=mySerial.read();
    Serial.print(msg);
  }
}
*/
void MakeCall()
{
  mySerial.println("ATD+84355136883;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}

/*
void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}

void ReceiveCall()
{
  mySerial.println("ATA");
  delay(1000);
  {
    call=mySerial.read();
    Serial.print(call);
  }
}

void RedialCall()
{
  mySerial.println("ATDL");
  Serial.println("Redialing");
  delay(1000);
}*/
