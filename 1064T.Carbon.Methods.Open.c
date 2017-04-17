#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in3,    subPower,       sensorAnalog)
#pragma config(Sensor, dgtl1,  ledArcade,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  ledTank,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  hangGuide,      sensorTouch)
#pragma config(Sensor, dgtl12, clawPiston,     sensorDigitalOut)
#pragma config(Sensor, I2C_1,  leftDrive,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightDrive,     sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  liftSense,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           topRight,      tmotorVex393TurboSpeed_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           midRight,      tmotorVex393TurboSpeed_MC29, openLoop, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port3,           bottomRight,   tmotorVex393TurboSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port6,           yLiftRight,    tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_3)
#pragma config(Motor,  port7,           yLiftLeft,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           bottomLeft,    tmotorVex393TurboSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port9,           midLeft,       tmotorVex393TurboSpeed_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port10,          topLeft,       tmotorVex393TurboSpeed_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

//----///////////////////////////////GLOBALS/////////////////////////////////////////////////----

float wheelDiameter = 4.145;
int eDriveTicks  = 392;

//--------------------LCD variables-------------------------------
//Declare count variable to keep track of our choice
int driveCount = 1; //drivemodecount
int autonSelec = 0; //auton mode
//lcd buttons
const short leftButton   = 1;
const short centerButton = 2;
const short rightButton  = 4;

//----//////////////////////////////SPEAKER METHODS///////////////////////////////////////////----

void dangerman()
{
	//        355 = Tempo
	//          6 = Default octave
	//    Quarter = Default note length
	//        10% = Break between notes
	//
	PlayTone( 1320,   23); wait1Msec( 254);  // Note(A, Duration(Quarter .))
	PlayTone( 1175,    8); wait1Msec(  85);  // Note(G, Duration(Eighth))
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1320,    8); wait1Msec(  85);  // Note(A, Duration(Eighth))
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone(  880,    8); wait1Msec(  85);  // Note(A5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  880,   15); wait1Msec( 169);  // Note(D)
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone( 1320,   23); wait1Msec( 254);  // Note(A, Duration(Quarter .))
	PlayTone( 1175,    8); wait1Msec(  85);  // Note(G, Duration(Eighth))
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1320,    8); wait1Msec(  85);  // Note(A, Duration(Eighth))
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone(  880,    8); wait1Msec(  85);  // Note(A5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  880,   15); wait1Msec( 169);  // Note(D)
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1046,   15); wait1Msec( 169);  // Note(C7)
	PlayTone( 1320,   30); wait1Msec( 338);  // Note(A, Duration(Half))
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone(  880,    8); wait1Msec(  85);  // Note(A5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  880,   15); wait1Msec( 169);  // Note(D)
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone( 1320,   23); wait1Msec( 254);  // Note(A, Duration(Quarter .))
	PlayTone( 1175,    8); wait1Msec(  85);  // Note(G, Duration(Eighth))
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1320,    8); wait1Msec(  85);  // Note(A, Duration(Eighth))
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone(  880,    8); wait1Msec(  85);  // Note(A5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  880,   15); wait1Msec( 169);  // Note(D)
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone( 1320,   23); wait1Msec( 254);  // Note(A, Duration(Quarter .))
	PlayTone( 1175,    8); wait1Msec(  85);  // Note(G, Duration(Eighth))
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1320,    8); wait1Msec(  85);  // Note(A, Duration(Eighth))
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone(  880,    8); wait1Msec(  85);  // Note(A5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  880,   15); wait1Msec( 169);  // Note(D)
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1320,   15); wait1Msec( 169);  // Note(A)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1046,   15); wait1Msec( 169);  // Note(C7)
	PlayTone( 1174,   30); wait1Msec( 338);  // Note(D7, Duration(Half))
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone(  880,    8); wait1Msec(  85);  // Note(A5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  880,   15); wait1Msec( 169);  // Note(D)
	PlayTone(    0,   15); wait1Msec( 169);  // Note(Rest)
	PlayTone( 1320,   23); wait1Msec( 254);  // Note(A, Duration(Quarter .))
	PlayTone( 1320,    8); wait1Msec(  85);  // Note(A, Duration(Eighth))
	PlayTone( 1398,   46); wait1Msec( 507);  // Note(A#, Duration(Half .))
	PlayTone(  932,    8); wait1Msec(  85);  // Note(A#5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  933,   15); wait1Msec( 169);  // Note(D#)
	PlayTone(    0,   30); wait1Msec( 338);  // Note(Rest, Duration(Half))
	PlayTone( 1398,   15); wait1Msec( 169);  // Note(A#)
	PlayTone( 1398,   30); wait1Msec( 338);  // Note(A#, Duration(Half))
	PlayTone( 1109,   30); wait1Msec( 338);  // Note(F#, Duration(Half))
	PlayTone(  933,   30); wait1Msec( 338);  // Note(D#, Duration(Half))
	PlayTone( 1398,   23); wait1Msec( 254);  // Note(A#, Duration(Quarter .))
	PlayTone( 1398,    8); wait1Msec(  85);  // Note(A#, Duration(Eighth))
	PlayTone( 1481,   46); wait1Msec( 507);  // Note(B, Duration(Half .))
	PlayTone(  987,    8); wait1Msec(  85);  // Note(B5, Duration(Eighth))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone(  988,   15); wait1Msec( 169);  // Note(E)
	PlayTone(    0,   30); wait1Msec( 338);  // Note(Rest, Duration(Half))
	PlayTone( 1481,   15); wait1Msec( 169);  // Note(B)
	PlayTone( 1481,   30); wait1Msec( 338);  // Note(B, Duration(Half))
	PlayTone( 1175,   30); wait1Msec( 338);  // Note(G, Duration(Half))
	PlayTone(  988,   30); wait1Msec( 338);  // Note(E, Duration(Half))
	PlayTone( 1481,   23); wait1Msec( 254);  // Note(B, Duration(Quarter .))
	PlayTone( 1174,    8); wait1Msec(  85);  // Note(D7, Duration(Eighth))
	PlayTone( 1318,   91); wait1Msec(1014);  // Note(E7, Duration(Whole .))
	PlayTone( 1318,   15); wait1Msec( 169);  // Note(E7)
	PlayTone( 1318,    8); wait1Msec(  85);  // Note(E7, Duration(Eighth))
	PlayTone( 1318,    8); wait1Msec(  85);  // Note(E7, Duration(Eighth))
	PlayTone( 1318,   15); wait1Msec( 169);  // Note(E7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1396,   15); wait1Msec( 169);  // Note(F7)
	PlayTone( 1174,   15); wait1Msec( 169);  // Note(D7)
	PlayTone( 1318,   23); wait1Msec( 254);  // Note(E7, Duration(Quarter .))
	PlayTone(    0,    8); wait1Msec(  85);  // Note(Rest, Duration(Eighth))
	PlayTone( 1481,   15); wait1Msec( 169);  // Note(B)
	PlayTone( 1318,   91); wait1Msec(1014);  // Note(E7, Duration(Whole .))
	return;
}

//----///////////////////////////////DRIVER METHODS///////////////////////////////////////////----

void time(int Msecs){//This method pauses code for a specified time
	wait1Msec(Msecs);
}

void lift(int power){//User csontrol method controls the robots lift (positive power raises the lift
	motor[yLiftRight] =  power;
	motor[yLiftLeft]  = -power;
}

void liftTime(int power, int ms){
	motor[yLiftRight] =  power;
	motor[yLiftLeft]  = -power;
	time(ms);
}

void stopLift(int ms){
	motor[yLiftRight] =  0;
	motor[yLiftLeft]  =  0;
	time(ms);
}

void stopLiftW(){
	motor[yLiftRight] =  0;
	motor[yLiftLeft]  =  0;
}

void autonClaw(int open){
	if (open == 1){
		SensorValue[clawPiston] = 1;
	}
	else{
		SensorValue[clawPiston] = 0;
	}
}

void drive(int left, int right){//Tank drive control method
	motor[topLeft]     =  left;
	motor[midLeft]     = -left;
	motor[bottomLeft]  =  left;
	motor[topRight]    =  right;
	motor[midRight]    = -right;
	motor[bottomRight] =  right;
}

void driveTime(int left, int right, int ms){//Tank drive auton control method
	motor[topLeft]     =  left;
	motor[midLeft]     = -left;
	motor[bottomLeft]  =  left;
	motor[topRight]    =  right;
	motor[midRight]    = -right;
	motor[bottomRight] =  right;
	time(ms);
}

void stopDrive(int timeLength){ //stop the drive
	motor[topLeft]     =  0;
	motor[midLeft]     =  0;
	motor[bottomLeft]  =  0;
	motor[topRight]    =  0;
	motor[midRight]    =  0;
	motor[bottomRight] =  0;
	time(timeLength);
}

void autoDrive(int speed, int dist){///////////////////in development///////////////////////
	nMotorEncoder[leftDrive]  = 0;
	int ticks = dist/(wheelDiameter*PI) * eDriveTicks;
	while (abs(nMotorEncoder[leftDrive])<ticks*.6){

		motor[topLeft]     =  speed;
		motor[midLeft]     = -speed;
		motor[bottomLeft]  =  speed;
		motor[topRight]    = -speed;
		motor[midRight]    =  speed;
		motor[bottomRight] = -speed;
	}
	while(abs(nMotorEncoder[leftDrive]) < ticks){

		motor[topLeft]     =  speed/3;
		motor[midLeft]     = -speed/3;
		motor[bottomLeft]  =  speed/3;
		motor[topRight]    = -speed/3;
		motor[midRight]    =  speed/3;
		motor[bottomRight] = -speed/3;
	}
	stopDrive(1);
}

//----///////////////////////////////SENSOR METHODS//////////////////////////////////////////----



//----///////////////////////////////Auton Selections////////////////////////////////////////----
void auton1(){ //////////////////////Skills////////////////////////////////////////
  drive(127,-127); time(600);
	drive(-127,127); time(200);
	lift(127); drive(0,0);time(1200);
	drive(127,-127); lift(0); time(1500);
	drive(-127,127); lift(0); time(800);
	drive(0,0); lift(0); time(1000);
}
void auton2(){
	driveTime(127,127,100);
}
void auton3(){
	driveTime(127,127,100);
}
void auton4(){
	driveTime(127,127,100);
}

void displayBatteryValues(){ //displays power levels
	string mainBatteryVoltage, expanderBattery;
	displayLCDString(0,0,"Cor Power: ");
	displayLCDString(1,0,"Sub Power: ");
	sprintf(mainBatteryVoltage,"%1.2f%c",nImmediateBatteryLevel/1000.0,'V');
	sprintf(expanderBattery,"%1.2f%c",SensorValue[subPower]/283.2, 'V');
	displayLCDString(0,10,mainBatteryVoltage);
	displayLCDString(1,10,expanderBattery);
}

void resetLcd(){
	bLCDBacklight = true;
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
}

void waitForPress(){//Pauses the lcd display until a button is pressed
	while(nLCDButtons == 0){}
	time(5);
}

void waitForRelease(){//Pauses the lcd display until a button is released
	while(nLCDButtons != 0){}
	time(5);
}

void nothing(){ //Display emtpy slot on the lcd
	displayLCDCenteredString(0, "slot");
	displayLCDCenteredString(1, "here");
	time(10);
}