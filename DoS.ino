/* This Sketch sends random characters from a virtual keyboard,
 * moves the mouse from 0 to 500 pixels to any direction (random)
 * and clicks with left, right or middle mouse button.
 * It makes it WITHOUT DELAY so the computer becomes uncontrollable.
 * by Aztemat.
 * LISENCE GNU GPL v3
 */
char r;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(3, HIGH);
  if(digitalRead(2) == LOW){
    Serial.begin(9600);
    while(!Serial);
    Serial.println("WARNING");
    Serial.println("If you want to see the DDos attack,");
    Serial.println("save your work, send '10' and wait for 10 seg.");
    Serial.println("If you want to bypass this security system");
    Serial.println("connect a jumper between pins 2 and 3,");
    Serial.println("else connect it between pin 2 and ground.");
    while(Serial.read() != 10);
    Serial.println("STARTING COUNT DOWN:");
    for(int i = 10; i > 0; i--){
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
      delay(950);      
      Serial.println(i);       
    }
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(950);
    Serial.println("0. GOOD BYE USER!");
    delay(1000);    
  }else{
    Serial.println("STARTING COUNT DOWN DIRECTLY:");
    for(int i = 60; i >= 0; i--){
      Serial.println(i);
      delay(1000);
    }
  }
  Mouse.begin();
  Keyboard.begin();
  randomSeed(analogRead(A0));
  digitalWrite(13, OUTPUT);
}

void loop() {
  Mouse.move(random(-501, 501), random(-501, 501), random(-6, 6));
  Keyboard.println(char(random(255)));
  r = random(3);
  if(r == 0){
    Mouse.click(MOUSE_LEFT);
  }
  if(r == 1){
    Mouse.click(MOUSE_MIDDLE);
  }
  if(r == 2){
    Mouse.click(MOUSE_RIGHT);
  }  
}
