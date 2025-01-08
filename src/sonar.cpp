#include "sonar.h"

unsigned long time = 0;

//gets the distance from the ultra sonic sensor
int Sonar::getSonar(){
    int timeToRecord = 0;
    int distance = 0;
    digitalWrite(_TriggerPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(_TriggerPin, HIGH); //sends power to the sensor
    delayMicroseconds(10);      
    digitalWrite(_TriggerPin, LOW);  //sets back to low
    timeToRecord = pulseIn(_EchoPin, HIGH, 30000); //will return how long it took the sensor to recive a wave
    //if 0 then error occurd
    if(timeToRecord==0){
        //Serial.println("Error getting distance");
        return 0;
    }else{
        distance = (timeToRecord * 0.0343) / 2; //distance = time*speed of sound per milisecond / 2 (travels to object and back) 
    }
    return distance;
} 

int oldDistance = 1;
int Sonar::getDistance() {
    if(millis() > time){
        // Define the maximum number of attempts to obtain valid readings
        const int MAX_ATTEMPTS = 5;
    
        // Define the acceptable variance between two distance readings
        const int MAX_VARIANCE = 5;  // More flexible variance threshold

        // Loop to attempt readings up to the maximum number of attempts
        for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
            // Measure the distance twice
            int distance1 = getSonar(); 
            int distance2 = getSonar(); 

            // Check if both readings are valid and within the acceptable variance
            if (distance1 > 0 && distance2 > 0 && abs(distance1 - distance2) <= MAX_VARIANCE) {
                // If readings are valid and consistent, print success and return 1
                //Serial.println("Correct");
                int avgDistance = (distance1 + distance2) / 2;
                time = millis() + 250;
                oldDistance = avgDistance;
                return avgDistance;  // Valid and consistent readings
            }
            time = millis() + 250;
        }

        // If all attempts fail, print failure and return 0
        //Serial.println("Fail");
        time = millis() + 250;
        return 0;  // Failed after multiple attempts
    }
}