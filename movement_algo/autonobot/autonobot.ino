int vel = 175;

// left wheels
#define leftWheels_LPWM 2
#define leftWheels_RPWM 4

// right wheels
#define rightWheels_LPWM 7
#define rightWheels_RPWM 8

/*
 * forward --> rw_RPWM, lw_RPWM = True, rw_LPWM, lw_LPWM = False
 * backward --> rw_LPWM, lw_LPWM = True, rw_RPWM, lw_RPWM = False
 * left --> rw_RPWM, lw_LPWM = True, rw_LPWM, lw_RPWM = False
 * right --> rw_LPWM, lw_RPWM = True, rw_RPWM, lw_LPWM = False
 */

void go(int dir){
  // forward, backward, left, right
  String dir_names[5] = {"forward", "backward", "left", "right", "stop"};
  int dirs[5][4] = {{vel, 0, vel, 0}, {0, vel, 0, vel}, {vel, 0, 0, vel}, {0, vel, vel, 0}, {0, 0, 0, 0}};
  // in each direction array, the formation is --> {lw_LPWM, lw_RPWM, rw_LPWM, rw_RPWM}
  Serial.println(dir_names[dir]);

  analogWrite(leftWheels_LPWM, dirs[dir][0]);
  analogWrite(leftWheels_RPWM, dirs[dir][1]);
  analogWrite(rightWheels_LPWM, dirs[dir][2]);
  analogWrite(rightWheels_RPWM, dirs[dir][3]);

  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftWheels_LPWM, OUTPUT);
  pinMode(rightWheels_LPWM, OUTPUT);
  pinMode(leftWheels_RPWM, OUTPUT);
  pinMode(rightWheels_RPWM, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int dirzzz;
  if (Serial.available()){
    int wat = Serial.read();
    Serial.println(wat);
    if (wat == 119){
      Serial.println("w");
      dirzzz = 0;
    }
    else if (wat == 115){
      Serial.println("s");
      dirzzz = 1;
    }
    else if (wat == 97){
      Serial.println("a");
      dirzzz = 2;
    }
    else if (wat == 100){
      Serial.println("d");
      dirzzz = 3;
    }
    else{
      Serial.println("wrong button yo");
      dirzzz = 4;
    }
  go(dirzzz);
  }

}
