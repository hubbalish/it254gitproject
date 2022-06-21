// This #include statement was automatically added by the Particle IDE.
#include <Grove-Ultrasonic-Ranger.h>
#include "application.h"


//Define pins
#define ALARM D4
Ultrasonic ultrasonic(D2);


long RangeInCentimeters;  //defining variables
int sounds(String command);
int Beeps[] = {1000,0,1000,0,1000,0,1000,2000};  
int BeepsTimes[] = {5,5,5,5,5,5,5,5 };


void setup()
{
    pinMode(ALARM, OUTPUT);
    Particle.function("Tripped", sounds);
    
}


void loop()
{
	RangeInCentimeters = ultrasonic.MeasureInCentimeters();    //Defines the variable
    if(RangeInCentimeters<80) {                     //If someone walks within a doorway width of the ultrasonic, will publish to a google sheet.
        Particle.publish("Trip_Time", Time.timeStr());
        delay(1000);
    }
}

int sounds(String command){
    if(command == "Tripped"){
        for (int thisNote = 0; thisNote < 8; thisNote++) {  
            int noteDuration = 1000/BeepsTimes[thisNote];  
            tone(ALARM, Beeps[thisNote], noteDuration);  
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);                        
            noTone(ALARM);                                
        }
    return 1;
    }
    else return -1;
}