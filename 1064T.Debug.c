#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    Gyro2,          sensorGyro)
#pragma config(Sensor, in3,    AccelX,         sensorAccelerometer)
#pragma config(Sensor, in4,    AccelY,         sensorAccelerometer)
#pragma config(Sensor, in5,    AccelZ,         sensorAccelerometer)
#pragma config(Sensor, dgtl1,  ledTank,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  ledArcade,      sensorLEDtoVCC)
#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           YRightLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           YLeftLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LeftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ClawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          ClawRight,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

//init global varibals
int GLOBAL_display = 0;

const int GLOBAL_DOUBLE_CLICK_SPEED = 250;
const short lcdRightButton = 1;
const short lcdCenterButton = 2;
const short lcdLeftButton = 4;
// driver methods
// drive Tank code method
void driveTank(int joyLeft, int joyRight){
	motor[leftFront] = vexRT[Ch3];
	motor[rightFront] = vexRT[Ch2];
	motor[leftBack] = vexRT[Ch3];
	motor[rightBack] = vexRT[Ch2];
}
//drive arcade mode method
void driveArcade(int joy){
	motor[leftFront] = joy;
	motor[rightFront] = joy;
	motor[leftBack] = joy;
	motor[rightBack] = joy;
}

void driveForward(float time){ //TODO: PID LOOP
	motor[leftFront] = 127;
	motor[rightFront] = 127;
	motor[leftBack] = 127;
	motor[rightBack] = 127;
	wait1Msec(time);
	motor[leftFront] = 0;
	motor[rightFront] = 0;
	motor[leftBack] = 0;
	motor[rightBack] = 0;
}

void driveBackward(float time){ //TODO: PID LOOP
	motor[leftFront] = -127;
	motor[rightFront] = -127;
	motor[leftBack] = -127;
	motor[rightBack] = -127;
	wait1Msec(time);
	motor[leftFront] = 0;
	motor[rightFront] = 0;
	motor[leftBack] = 0;
	motor[rightBack] = 0;
}
//lift method raise
void lift(int power){
	motor[YRightLift] = -power;
	motor[RightLift] = -power;
	motor[YLeftLift] = power;
	motor[LeftLift] =  power;
}
//claw method
void claw(int power){
	motor[ClawLeft] = power;
	motor[ClawRight] = power;
}

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

void lcdDisplay(long delta){
	string mainBattery, backupBattery;
	bLCDBacklight = true;
	clearLCDLine(0);
	clearLCDLine(1);
	

	switch(GLOBAL_display){
		case -1: //Locked with password
			break;
		case 0:
			displayLCDCenteredString(0, "106T            ");
			displayLCDCenteredString(1, "Press any key   ");
			
			waitForPress(); // added to stop the flickering of the lcd (bug patch)
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 1;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				GLOBAL_display = 1;
			}else if(nLCDButtons == lcdLeftButton){
				waitForRelease();
				GLOBAL_display =1;
			}
			break;
		case 1:
			displayLCDCenteredString(0, "1. Auton Select ");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 0;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 0;
				}else{ // Enter

				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 2;
			}
			break;
		case 2:
			displayLCDCenteredString(0, "2.    Debug     ");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 1;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 0;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 50;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 3;
			}
			break;
		case 3:
			displayLCDCenteredString(0, "3.   Settings   ");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 2;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 0;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 0; // TODO: make settings
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 1;
			}
			break;
		case 50: // Debug Menu - Gyro 1
			displayLCDCenteredString(0, "50.     Gyro - 1");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){ // Right button Click
				waitForRelease();
				GLOBAL_display = 54;
			}else if(nLCDButtons == lcdCenterButton){ // Center button clicked
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 2;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 60;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 51;
			}
			break;
		case 51: // Debug Menu - Gyro 2
			displayLCDCenteredString(0, "51.     Gyro - 2");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 50;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 2;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 61;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 52;
			}
			break;
		case 52: // Debug Menu - Acelerometer
			displayLCDCenteredString(0, "52. Acelerometer");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 51;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 2;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 62;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 54; // GOTO: DEBUG - Line Followers
			}
			break;
		case 54: // Debug Menu - UPS
			displayLCDCenteredString(0, "54.    UPS      ");
			displayLCDCenteredString(1, "<      [X]     >");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 53;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					GLOBAL_display = 2;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 65;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 50;
			}
			break;
		case 60: // Debug - Gyro 1
			displayLCDCenteredString(0, "60.    Gyro - 1 ");
			displayLCDNumber(1,0, SensorValue[Gyro]);
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 67;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					// GLOBAL_display = 50;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 50;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				waitForRelease();
				GLOBAL_display = 61;
			}
			break;
		case 61: // Debug - Gyro 2
			displayLCDCenteredString(0, "61. Gyro - 2    ");
			displayLCDNumber(1,0, SensorValue[Gyro2]);
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 61;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page
					//GLOBAL_display = 2;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 51;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Next Page
				//waitForLCDButtonRelease();
				//GLOBAL_display = 50;
			}
			break;
		case 62: // Debug - Acelerometer - X
			displayLCDCenteredString(0, "62. Accel - X   ");
			displayLCDNumber(1,0, SensorValue[AccelX]);
			waitForPress();
			if(nLCDButtons == lcdRightButton){ // X
				waitForRelease();
				GLOBAL_display = 62;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(500);
				if(nLCDButtons == lcdCenterButton){ //Go back one page or go to Y
					GLOBAL_display = 52;
					wait1Msec(500);
				}else{ // Enter
					GLOBAL_display = 63;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Go to Z
				waitForRelease();
				GLOBAL_display = 64;
			}
			break;
		case 63: // Debug - Acelerometer - Y
			displayLCDCenteredString(0, "63. Accel - Y   ");
			displayLCDNumber(1,0, SensorValue[AccelY]);
			waitForPress();
			if(nLCDButtons == lcdRightButton){ // X
				waitForRelease();
				GLOBAL_display = 62;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page or go to Y
					GLOBAL_display = 52;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 63;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Go to Z
				waitForRelease();
				GLOBAL_display = 64;
			}
			break;
		case 64: // Debug - Acelerometer - Z
			displayLCDCenteredString(0, "64. Accel - Z   ");
			displayLCDNumber(1,0, SensorValue[AccelZ]);
			waitForPress();
			if(nLCDButtons == lcdRightButton){ // X
				waitForRelease();
				GLOBAL_display = 62;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page or go to Y
					GLOBAL_display = 52;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 63;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Go to Z
				waitForRelease();
				GLOBAL_display = 64;
			}
			break;
		case 65: // Debug - Updates Per Seconds
			displayLCDCenteredString(0, "64. Accel - Z   ");
			displayLCDNumber(1,0, delta);
			waitForPress();
			if(nLCDButtons == lcdRightButton){ // X
				waitForRelease();
				GLOBAL_display = 62;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				if(nLCDButtons == lcdCenterButton){ //Go back one page or go to Y
					GLOBAL_display = 64;
					wait1Msec(GLOBAL_DOUBLE_CLICK_SPEED);
				}else{ // Enter
					GLOBAL_display = 64;
				}
			}else if(nLCDButtons == lcdLeftButton){ // Go to Z
				waitForRelease();
				GLOBAL_display = 64;
			}
			break;
		case 68:
			//Display the Primary Robot battery voltage
			displayLCDString(0, 0, "Primary: ");
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
			displayNextLCDString(mainBattery);

			//Display the Backup battery voltage
			displayLCDString(1, 0, "Backup: ");
			sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
			displayNextLCDString(backupBattery);
			//TODO: BUTTONS
			break;
		case 80: // Autonomous 1
			break;
		default:
			displayLCDCenteredString(0, "106T-Invalid Arg");
			displayLCDCenteredString(1, "Press any key   ");
			waitForPress();
			if(nLCDButtons == lcdRightButton){
				waitForRelease();
				GLOBAL_display = 0;
			}else if(nLCDButtons == lcdCenterButton){
				waitForRelease();
				GLOBAL_display = 0;
			}else if(nLCDButtons == lcdLeftButton){
				waitForRelease();
				GLOBAL_display = 0;
			}
			break;
	}
}

void pre_auton(){

}

task autonomous(){
}

task usercontrol(){
	bool useTank = true;

	long lastTime = nSysTime;

	if(!useTank){
		turnLEDOn(dgtl2);
		turnLEDOff(dgtl1);
		}else{
		turnLEDOn(dgtl1);
		turnLEDOff(dgtl2);
	}

	while(true){
		long time = nSysTime;
		long delta = time - lastTime;
		lastTime = time;

		lcdDisplay(delta);

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

		if(vexRT[Btn6U]){ // Lift up
			lift(127);
			}else if(vexRT[Btn5U]){// Lift down
			lift(-127);
			}else{
			lift(0);
		}

		if(vexRT[Btn6D]){ // Open claw
			claw(127);
			}else if(vexRT[Btn5D]){ // Close claw
			claw(-127);
			}else{
			claw(0);
		}

		if(useTank){
			int joyRight = vexRT[Ch2];
			int joyLeft = vexRT[Ch3];
			driveTank(joyLeft, joyRight);
			}else{
			int joy_x = vexRT[Ch1];
			int joy_y = vexRT[Ch2];

			motor[leftFront] = joy_y + joy_x;
			motor[leftBack] = joy_y + joy_x;
			motor[rightFront] = joy_y - joy_x;
			motor[rightBack] = joy_y - joy_x;
		}
	}
}
