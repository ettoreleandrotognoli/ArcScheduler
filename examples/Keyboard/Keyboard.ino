#include "Scheduler.h"
#include "Keyboard.h"

const int LED_PIN = 13;
int LED_VALUE = 0;

arc::Scheduler scheduler;
arc::Keyboard<2> keyboard((byte[]){0,1});

enum Button {
    On=0,
    Off
};

void toggleLed(){
    LED_VALUE = (LED_VALUE + 1) % 2;
    digitalWrite(LED_PIN, LED_VALUE);
}

void setup(){
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LED_VALUE);
    scheduler.every(50, [](arc::Scheduler& scheduler){
        keyboard.tick();
    });
    keyboard.onKeyDown[On] = [](const arc::KeyEvent& event) {
        Serial.println("onKeyDown(On)");
        Serial.print("HoldTicks: ");
        Serial.println(event.holdTicks);
        Serial.print("LastChange: ");
        Serial.println(event.lastChange);
    };
    keyboard.onKeyUp[On] = [](const arc::KeyEvent& event) {
        Serial.println("onKeyUp(On)");
        Serial.print("HoldTicks: ");
        Serial.println(event.holdTicks);
        Serial.print("LastChange: ");
        Serial.println(event.lastChange);
    };
    keyboard.onHoldDown[On] = [](const arc::KeyEvent& event) {
        Serial.println("onHoldDown(On)");
        Serial.print("HoldTicks: ");
        Serial.println(event.holdTicks);
        Serial.print("LastChange: ");
        Serial.println(event.lastChange);
    };
    keyboard.onKeyDown[Off] = [](const arc::KeyEvent& event) {
        Serial.println("onKeyDown(Off)");
        Serial.print("HoldTicks: ");
        Serial.println(event.holdTicks);
        Serial.print("LastChange: ");
        Serial.println(event.lastChange);
    };
    keyboard.onKeyUp[Off] = [](const arc::KeyEvent& event) {
        Serial.println("onKeyUp(Off)");
        Serial.print("HoldTicks: ");
        Serial.println(event.holdTicks);
        Serial.print("LastChange: ");
        Serial.println(event.lastChange);
    };
    keyboard.onHoldDown[Off] = [](const arc::KeyEvent& event) {
        Serial.println("onHoldDown(Off)");
        Serial.print("HoldTicks: ");
        Serial.println(event.holdTicks);
        Serial.print("LastChange: ");
        Serial.println(event.lastChange);
    };
}

void loop(){
    scheduler.loop();
}