#include <Stepper.h>

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
int in5Pin = 8;
int in6Pin = 7;
int in7Pin = 6;
int in8Pin = 5;
int in9Pin = 13;
int in10Pin = 14;
int in11Pin = 15;
int in12Pin = 16;
int limitInput = 4;
int limitOutput = 3;
int limitDistributor = 2;

int stepConveyor = 2;
int stepDistributor = 2;

Stepper motorInput(240, in1Pin, in2Pin, in3Pin, in4Pin);
Stepper motorOutput(240, in5Pin, in6Pin, in7Pin, in8Pin);
Stepper motorDistributor(240, in9Pin, in10Pin, in11Pin, in12Pin);

void setup()
{
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);
    pinMode(in5Pin, OUTPUT);
    pinMode(in6Pin, OUTPUT);
    pinMode(in7Pin, OUTPUT);
    pinMode(in8Pin, OUTPUT);
    pinMode(limitInput, INPUT);
    pinMode(limitOutput, INPUT);
    pinMode(limitDistributor, INPUT);
    // this line is for Leonardo's, it delays the serial interface
    // until the terminal window is opened
    while (!Serial)
        ;

    Serial.begin(9600);
    motorInput.setSpeed(2);
    motorOutput.setSpeed(2);
    motorDistributor.setSpeed(2);
}

void loop()
{
    if (digitalRead(limitInput) == HIGH)
    {

        motorInput.step(stepConveyor);
    }

    if (digitalRead(limitDistributor) == HIGH)
    {
        motorDistributor.step(stepDistributor);
    }

    if (digitalRead(limitOutput) == HIGH)
    {
        motorOutput.step(stepConveyor);
    }
}
