#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in6,    rightPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in7,    leftPotentiometer, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  shaft,          sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  left,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  right,          sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port2,           Tright,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Bright,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightGrab,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftGrab,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           Bleft,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Tleft,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393_HBridge, openLoop, encoderPort, I2C_1)

int x;
int rightPotentio;
int leftPotentio;

void liftArm(int speed) {
 	motor[Tright] = speed;
	motor[Bright] = speed;
	motor[Bleft] = speed;
	motor[Tleft] = speed;
}

void grapAtRange(int range){
	rightPotentio = SensorValue[rightPotentiometer];
	leftPotentio = SensorValue[leftPotentiometer];

	if(rightPotentio > range){
		motor[rightGrab] = abs(rightPotentio - range)/10;
		}else if (rightPotentio < range){
		motor[rightGrab] = abs(rightPotentio - range)/-10;
	}

	if(leftPotentio > range){
		motor[leftGrab] = abs(leftPotentio - range)/10;
		}else if (leftPotentio < range){
		motor[leftGrab] = abs(leftPotentio - range)/-10;
	}
}


task main()
{
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	while(true){
		rightPotentio = SensorValue[rightPotentiometer];
		leftPotentio = SensorValue[leftPotentiometer];

		motor[rightMotor] = vexRT[Ch2];
		motor[leftMotor] = vexRT[Ch3];



		if(vexRT[Btn6U] == 1) {
			liftArm(80);
			}else if(vexRT[Btn6D] == 1) {
			liftArm(-10);
			} else {
			liftArm(15);
		}

		if(vexRT[Btn5D] == 1){
			motor[leftGrab] = 80;
			motor[rightGrab] = 80;
			}else if(vexRT[Btn5U] == 1){
			motor[leftGrab] = -80;
			motor[rightGrab] = -80;
			}else{
			if(leftPotentio > rightPotentio){
				grapAtRange(rightPotentio);
				}else if(rightPotentio > leftPotentio){
				grapAtRange(leftPotentio);
			}
		}
	}
}
