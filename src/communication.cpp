//only functions
//You must only do this: when you get distance from sonar store it in a global variable called distanceFront or change it. 
//Then when using line sensor set a boolean global variable called isOnLine to true or false, depending if the robot os on the line or not. 
//Also change the robotID to the correct value for your robot.

//SET UP

// Define RX and TX pins for HC-12
const int HC12_RX = 0;
const int HC12_TX = 1;
SoftwareSerial HC12(HC12_RX, HC12_TX);
//ohter stuff needed
boolean isOnLine = false;
bool taskActive = false;
bool finished = false;
int robotID = 1; // change for your robot, 1=line foloower, 2=line maze, 3=physical maze

//ADD TO YOUR BOT CODE

//Comminication
bool done = false;
unsigned long taskStartTime = 0;
const unsigned long taskDuration = 20000; // 20 seconds for demonstration

bool taskRunning = false;
void communication(){
  if (HC12.available() > 0) {
    String receivedMessage = HC12.readStringUntil('\n');
    receivedMessage.trim();
    //Serial.println("Received: " + receivedMessage);

    // Parse the message
    String fields[3];
    int fieldCount = 0;
    splitString(receivedMessage, '|', fields, fieldCount);

    if (fieldCount > 1) {
      String senderID = fields[0];
      String command = fields[1];

      if(senderID == robotID){
        if (command == "START") {
          taskActive = true;
          taskStartTime = millis();
          //Serial.println("Slave: Task started.");
        } else if (command == "REQUEST" && taskActive) {
          //data to send, front distance, left wheel speed, right wheel speed, line sensor data
          int sonar = distanceFront;
          float speed = rotation.calculateSpeed();
          // Perform task and send periodic updates
          //HC12.println("1|DATA|" + String(sonar)+"|"+String(speed) + "\n");
          if(isOnLine){
            Serial.println(robotID + "|DATA|" + String(sonar)+"|"+String(speed) + "|" + "True\n");
          }else{
            Serial.println(robotID + "|DATA|" + String(sonar)+"|"+String(speed) + "|" + "False\n");
          }

          //motor.forward();
          //Serial.println("Slave: Sent data update.");

        }else if(finished == true){
          Serial.println("1|DONE\n");
        }
      }
    }
  }
}

// Utility function to split a string
void splitString(String input, char delimiter, String output[], int &count) {
  count = 0;
  int start = 0;
  int end = input.indexOf(delimiter);

  while (end != -1) {
    output[count++] = input.substring(start, end);
    start = end + 1;
    end = input.indexOf(delimiter, start);
  }
  output[count++] = input.substring(start);
}