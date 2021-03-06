#pragma config(Sensor, in1,    potentiometerScissorsLeft, sensorPotentiometer)
#pragma config(Sensor, in2,    potentiometerScissorsRight, sensorNone)
#pragma config(Motor,  port1,           anglePivot,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           mobileGoalLift, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           scissorsLeft,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           scissorsRight, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          grab,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int threshold = 15; // torelance between each joystick
int limitRPM = 160; // For high torque motor the has a limit speed
int sisSpeed = 90; // For scissors speed
float mult = 100;

float err = 0;
float errPri = 0;

int leftPot = SensorValue[potentiometerScissorsLeft];
int rightPot = SensorValue[potentiometerScissorsRight];

int activate = 0;

int left = 80;
int right = 100;

task main()
{
	while(true){
		leftPot = SensorValue[potentiometerScissorsLeft];
		rightPot = SensorValue[potentiometerScissorsRight];
		int bias = 15;

		// Scissors Lift
		if((vexRT[Btn5U] == 1 || vexRT[Btn5UXmtr2] == 1)){
			motor[scissorsLeft] = left;
			motor[scissorsRight] = right;
		}

		else if((vexRT[Btn5D] == 1 || vexRT[Btn5DXmtr2] == 1)){
			motor[scissorsLeft] = -40;
			motor[scissorsRight] = -40;
		}

		else{
			motor[scissorsRight] = 25 + (leftPot - rightPot)/2;
			motor[scissorsLeft] = 25;
		}
	}
}
