#include "sonar.h"

//gets the distance from the ultra sonic sensor
int Sonar::getDistance(){
    int time = 0;
    int distance = 0;
    digitalWrite(_TriggerPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(_TriggerPin, HIGH); //sends power to the sensor
    delayMicroseconds(10);      
    digitalWrite(_TriggerPin, LOW);  //sets back to low
    time = pulseIn(_EchoPin, HIGH); //will return how long it took the sensor to recive a wave
    //if 0 then error occurd
    if(time==0){
        //Serial.println("Error getting distance");
        return 0;
    }else{
        distance = (time * 0.0343) / 2; //distance = time*speed of sound per milisecond / 2 (travels to object and back) 
    }
    return distance;
} 
int Sonar::test_distance() {
    // Define the maximum number of attempts to obtain valid readings
    const int MAX_ATTEMPTS = 3;
    
    // Define the acceptable variance between two distance readings
    const int MAX_VARIANCE = 5;  // More flexible variance threshold

    // Loop to attempt readings up to the maximum number of attempts
    for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
        // Measure the distance twice
        int distance1 = getDistance(); 
        int distance2 = getDistance(); 

        // Check if both readings are valid and within the acceptable variance
        if (distance1 >= 0 && distance2 >= 0 && abs(distance1 - distance2) <= MAX_VARIANCE) {
            // If readings are valid and consistent, print success and return 1
            //Serial.println("Correct");
            return distance1;  // Valid and consistent readings
        }
    }

    // If all attempts fail, print failure and return 0
    //Serial.println("Fail");
    return 0;  // Failed after multiple attempts
}