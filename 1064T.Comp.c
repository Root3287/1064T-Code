#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    Gyro1,          sensorGyro)
#pragma config(Sensor, in2,    Gyro2,          sensorGyro)
#pragma config(Sensor, in3,    power,          sensorAnalog)
#pragma config(Sensor, dgtl1,  ledTank,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  ledArcade,      sensorLEDtoVCC)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_4)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_3)
#pragma config(Motor,  port5,           YRightLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RightLift,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           YLeftLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LeftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ClawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          ClawRight,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

#include "1064T.Methods.c"

task userDisplay(){
	resetLcd();
	while(true){
		if (nLCDButtons == 1){
			driveCount--;
			resetLcd();
			while(nLCDButtons == 1)(wait1Msec(10));
		}
		if(nLCDButtons == 4){
			driveCount++;
			resetLcd();
			while(nLCDButtons == 4)(wait1Msec(10));
		}
		if(driveCount < 0){
			driveCount = 10;
		}
		else if(driveCount > 10){
			driveCount = 0;
		}
		switch (driveCount){
		case 0:
			displayBatteryValues();
			break;
		case 1:
			avgGyroValue();
			break;
		case 2:
			nothing();
			break;
			nothing();
		case 3:
			break;
		case 4:
			nothing();
			break;
		case 5:
			nothing();
			break;
		case 6:
			nothing();
			break;
		case 7:
			nothing();
			break;
		case 8:
			nothing();
			break;
		case 9:
			nothing();
			break;
		case 10:
			nothing();
			break;
		}
		time(10);
	}
}

void pre_auton(){
	bStopTasksBetweenModes = true;
	resetLcd();
	selectAuton();
	resetGyro();
}

task autonomous(){
	lcdAuton();
}
//---------------END of auton---------------------------------------

task usercontrol(){
	resetLcd();
	startTask(userDisplay);

	bool useTank = true;

	if(!useTank){ //LED driver type indicater
		turnLEDOn(dgtl2);
		turnLEDOff(dgtl1);
		}else{
		turnLEDOn(dgtl1);
		turnLEDOff(dgtl2);
	}

	while(true){
		if(vexRT[Btn8U]){ //driver assist to raise lift
			autonLift(127, 1000);
		}

		if(vexRT[Btn8D]){ //driver assist to raise lift
			autonLift(-127, 950);
		}

		if(vexRT[Btn8R]){//driver assist turn
			gyroTurn(-450);
		}

		if(vexRT[Btn8L]){
			gyroTurn(450);
		}

		if(vexRT[Btn7L]){
			claw(-127); time(300);
		}

		if(vexRt[Btn7R]){
			claw(127); time(300);
		}

		bool useTank = true;

		if(!useTank){ //LED driver type indicater
			turnLEDOn(dgtl2);
			turnLEDOff(dgtl1);
			}else{
			turnLEDOn(dgtl1);
			turnLEDOff(dgtl2);
		}
		if(vexRT[Btn7U]){
			if(useTank){
				useTank = false;
				turnLEDOn(dgtl2);
				turnLEDOff(dgtl1);
				}else{
				useTank = true;
				turnLEDOn(dgtl1);
				turnLEDOff(dgtl2);
			}
			wait1Msec(200);
		}
		if(useTank){
			int joyRight = vexRT[Ch2];
			int joyLeft = vexRT[Ch3];
			drive(joyLeft, joyRight);
			}else{
			int joy_x = vexRT[Ch1];
			int joy_y = vexRT[Ch2];

			motor[leftFront] = joy_y + joy_x;
			motor[leftBack] = joy_y + joy_x;
			motor[rightFront] = joy_y - joy_x;
			motor[rightBack] = joy_y - joy_x;
		}
		if(vexRT[Btn6U]){ // Lift up
			lift(127);
			}else if(vexRT[Btn6D]){// Lift down
			lift(-127);
			}else{
			lift(0);
		}

		if(vexRT[Btn5U]){ // Open claw
			claw(-127);
			}else if(vexRT[Btn5D]){ // Close claw
			claw(127);
			}else{
			claw(0);
		}
	}
}
