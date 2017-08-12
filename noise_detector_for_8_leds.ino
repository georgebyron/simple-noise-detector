#define MICROPHONE A1
#define LED_1 6
#define LED_2 7
#define LED_3 8
#define LED_4 9
#define LED_5 10
#define LED_6 11
#define LED_7 12
#define LED_8 13

int leds[] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8};

void setup() {
  pinMode(MICROPHONE, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_8, OUTPUT);
  Serial.begin(115200);
}



void loop() {
  // put your main code here, to run repeatedly:
  int noise = analogRead(MICROPHONE);
  Serial.println(noise); 
  detector (noise);
  delay(100);
  blink_off();
}

void blink_on(int led) {
    digitalWrite(led, HIGH);
    }

void blink_off() {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
}

void control_blast () {
    blink_on(LED_1);
    blink_on(LED_2);
    blink_on(LED_3);
    blink_on(LED_4);
    blink_on(LED_5);
    blink_on(LED_6);
    blink_on(LED_7);
    blink_on(LED_8);
}

void detector (int noise) {
  int scale = 15;
  int n = 0;
  while (noise > scale) {
    scale += 20;
    blink_on(leds[n]);
    n++;
    if (n > 7) {
      break;
    }
  }
}

