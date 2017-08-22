//pins
#define AudPinL A0 //used with analogRead mode only for left audio channel
#define AudPinR A2 //used with analogRead mode only for right audio channel

// consts
#define AmpMax (1024 / 2)
#define MicSamples (1024*2) 
#define VolumeGainFactorBits 0

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Wire.h>

//Update these with values suitable for your network

byte mac[] = {0xAA, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 18, 38);
IPAddress server(192, 168, 18, 183);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0; i<length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

EthernetClient ethClient;
PubSubClient client(ethClient);

char msg[50];
unsigned char frequencyH=0; //PLL 1st byte
unsigned char frequencyL=0; //PLL 2nd byte
unsigned int frequencyB; //PLL in decimal
double freq_available=0; //FM ferquency
int ALPin = 0; //Set the analog pin for audio left channel
int ARPin = 2; //Set the analog pin for audio right channel
int AGPin = 1; //Set the analog pin for ground audio
unsigned long measuretime;

void reconnect() {
  //Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
  }
}



void setup() {
  pinMode(MicPin, INPUT); //relevant for digital pins. not relevant for analog. however, don't put into digital OUTPUT mode if going to read analog values. 
  // serial
  Serial.begin(9600);
  while (!Serial); //wait until Serial is ready
  Serial.println("Starting aircheck");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  MeasureVolume();
  
}

void MeasureVolume() {
  long soundVolAvg = 0, soundVolMax = 0, soundVolRMS = 0, t0 = millis();
  for (int i = 0; i < MicSamples; i++) {
    int k = 
  }
}

