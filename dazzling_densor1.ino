// Defining Led Pins
#define RED_LED 7
#define GREEN_LED 6

// Defining Sensors Pins
#define FIRST_MOTION_SENSOR 2
#define SECOND_MOTION_SENSOR 3

volatile bool firstMotionDetected = false;
volatile bool secondMotionDetected = false;
volatile int firstSensorValue = 0;
volatile int secondSensorValue = 0;

void setup()
{
  Serial.begin(9600);

  // Setting pin Mode of Actuators (LEDS) and Sensors
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(FIRST_MOTION_SENSOR, INPUT);
  pinMode(SECOND_MOTION_SENSOR, INPUT);

  // Attaching the interrupts
  attachInterrupt(digitalPinToInterrupt(FIRST_MOTION_SENSOR), firstMotionISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SECOND_MOTION_SENSOR), secondMotionISR, CHANGE);
}

void loop()
{

}

void firstMotionISR()
{
  static bool value = LOW;
  value = !value;
  digitalWrite(RED_LED, value);
  firstMotionDetected = value;

  if (firstMotionDetected)
  {
  firstSensorValue = analogRead(FIRST_MOTION_SENSOR);
  // Printing the Analog Value of First Motion Sensor when motion detected
  Serial.print("Motion Detected AND VALUE OF PIR 1: ");
  Serial.println(firstSensorValue);
  }
}

void secondMotionISR()
{
  static bool value = LOW;
  value = !value;
  digitalWrite(GREEN_LED, value);
  secondMotionDetected = value;

  if (secondMotionDetected)
  {
  secondSensorValue = analogRead(SECOND_MOTION_SENSOR);
  // Printing the Analog Value of Second Motion Sensor when motion detected
  Serial.print("Motion Detected AND VALUE OF PIR 2: ");
  Serial.println(secondSensorValue);
  }
}