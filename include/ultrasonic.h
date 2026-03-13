/* Created by Komlan Freedom TSOKPO on 2026-03-13.
    * 
    * Ce fichier contient les définitions de les classes Ultrasonic et ServoMotor pour la gestion du capteur à ultrasons et du servo moteur.
    * et de la classe ServoMotor pour la gestion du moteur servo. Ces classes encapsulent les fonctionnalités
    * nécessaires pour mesurer les distances et contrôler le moteur servo dans le cadre du projet.
    *
*/
#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <Arduino.h>
#include <ESP32Servo.h>
#include "config.h"

class Ultrasonic {
private:
    int _triggerPin;
    int _echoPin;

public:
    Ultrasonic() = default;
    void init(int triggerPin, int echoPin);
    float measureDistance();
};

class ServoMotor {
private:
    Servo _servo;
public:
    ServoMotor() = default;
    void init(int pin, int min_ANGLE_DEG = 0, int max_ANGLE_DEG = 180);
    void setAngle(int angle);
    int getAngle();
    int scanArea();
};

#endif // ULTRASONIC_H
