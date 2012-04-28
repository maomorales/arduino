//Smart Table 4
//April 27th, 2012
//

const int MAX_GOALS = 10;
const int DETECTION_THRESHOLD = 500;
const int DOOR_A = A4;
const int DOOR_B = 6;
int goalsTeamA = 0;
int goalsTeamB = 0;


boolean ballInDoorA(int sensorDoorA) {
  return sensorDoorA >= DETECTION_THRESHOLD;
}

boolean ballInDoorB(int sensorDoorB) {
  return sensorDoorB >= DETECTION_THRESHOLD;
}

void teamAScores() {
  goalsTeamA ++;
}

void teamBScores() {
  goalsTeamB ++;
}

void showResultsInConsole() {
  Serial.print("TeamA: ");
  Serial.print(goalsTeamA);
  Serial.print(" ------- ");
  Serial.print("TeamB: ");
  Serial.print(goalsTeamB);
  
  Serial.println();
}

void showResultsAndDelay() {
  showResultsInConsole();
  delay(1500);
}

void checkIfGameFinished() {
  if (goalsTeamA == MAX_GOALS || goalsTeamB == MAX_GOALS) {
    Serial.println("Game Finished!!! - congratulations to winner!!");
    delay(200);
    exit(0);
  }
}

/**
 * Arduino initial setup
 */
 void setup(){
  Serial.begin(9600);
  pinMode(DOOR_A, INPUT);
  pinMode(DOOR_B, INPUT);
}


/**
 * I/O loop
 */
void loop(){  
  
  int sensorDoorA = analogRead(DOOR_A);
  int sensorDoorB = 0;
//  int sensorDoorB = analogRead(DOOR_B);
  
  // Fake door with digital input
  if (digitalRead(DOOR_B) == HIGH) {
    sensorDoorB = 0;
  } else {
    sensorDoorB = 800;
  }
  
  if (ballInDoorA(sensorDoorA)) {
    teamBScores();
    showResultsAndDelay();
  }
  
  if (ballInDoorB(sensorDoorB)) {
    teamAScores();
    showResultsAndDelay();
  }
  
  
  checkIfGameFinished();

}

