#pragma config(Sensor, in1,    sensorArm,      sensorPotentiometer)
#pragma config(Sensor, in2,    sensorGrab,     sensorPotentiometer)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           TrightMotor,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BrightMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           grabMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BleftMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           TleftMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void openGrab(int speed){
	motor[grabMotor]= speed;
	wait1Msec(1000);	//Open for two seconds
}

void grabing(int speed){
		motor[grabMotor]= -speed;
		wait1Msec(1000);	// two seconds of grabing
}

void droping(int speed){
		motor[grabMotor]= speed;
		wait1Msec(1500);	// two seconds of droping
}

void lifting(int speed){
	motor[TrightMotor]= speed;
	motor[BrightMotor]= speed;
	motor[BleftMotor]= speed;
	motor[TleftMotor]= speed;
}

void move(int speed) {
		motor[leftMotor] = speed;
		motor[rightMotor] = speed;
}

void turnLeft(int speed){
	motor[leftMotor]= -speed;
	motor[rightMotor]= speed;
}

void turnRight(int speed){
	motor[leftMotor]= speed;
	motor[rightMotor]= -speed;
}

task main()
{

	////////////////////////////////////////////////////////
	//                 First Motion	  										//
	////////////////////////////////////////////////////////

	//Drop the hand down
	move(90);
	wait1Msec(700);
	move(-127);
	wait1Msec(500);

	//Move Stright to the cube
	move(127); // at the maximume speed
	wait1Msec(2000); // for 2 seconds

	grabing(127); // Starts to grab

	move(127); // go stright
	wait1Msec(2000); // for 2 seconds

	lifting(127); // Move the arm up
	droping(127); // release it

	turnLeft(100); // turn left
	wait1Msec(500); // for 300 micosecond
	move(127); // Move forward at a maximume speed
	wait1Msec(5000); // for 5 second

	turnLeft(100); // Turn left back at a speed of 100
	move(127); // Turn left back at a miximume speed
	wait1Msec(500); // for 500 microsecond



	////////////////////////////////////////////////////////
	//                 Second Motion											//
	////////////////////////////////////////////////////////

	// Use this code, if our robot started at the right of the competition field

	move(127); //move straight to stars
	wait1Msec(3000); // keep moving forward for three 3 seconds

	move(127);	//keeping moving
	grabing(127); //while moving grabing
	wait1Msec(2000); // keep the action for 2 seconds

	turnRight(100);//turn right (replace here for the exavt measurement, once figure out the exact measurement)
	wait1Msec(2000); //move for 2 seconds

	move(127); // move forward
	wait1Msec(3000) //going for 3 seconds

	lifting(100); // lift the arm up
	wait1Msec(2000) //getting the arm up for 2 seconds

	droping(127); // droping the object
	wait1Msec (1000); //drop with in one second

	turnLeft (100); // then turn left (should replace with the exact measuremen, once figure out the exact measurement)
	wait1Msec (2000);

	move (127);//move forward
	wait1Msec (2000) //move for two seconds

	move (-127) //move backward
	wait1Msec (3000) //for3 seconds

	////////////////////////////////////////////////////////
	//                 Third Motion											  //
	////////////////////////////////////////////////////////

	// Use this code, when our robot started of at the left of the competition board

	move(127); //move straight to stars
	wait1Msec(3000); // keep moving forward for three 3 seconds

	move(127);	//keeping moving
	grabing(127); //while moving grabing
	wait1Msec(2000); // keep the action for 2 seconds

	turnLeft(100);//turn left (replace here for the exavt measurement, once figure out the exact measurement)
	wait1Msec(2000); //move for 2 seconds

	move(127); // move forward
	wait1Msec(3000) //going for 3 seconds

	lifting(100); // lift the arm up
	wait1Msec(2000) //getting the arm up for 2 seconds

	droping(127); // droping the object
	wait1Msec (1000); //drop with in one second

	turnRight (100); // then turn right (should replace with the exact measuremen, once figure out the exact measurement)
	wait1Msec (2000);

	move (127);//move forward
	wait1Msec (2000) //move for two seconds

	move (-127) //move backward
	wait1Msec (3000) //for3 seconds
}
