/*
 * SatelliteReceive.cpp
 *
 *  Created on: 9. jan. 2011
 *      Author: develop
 */

#include "SatelliteReceive.h"

SatelliteReceive::SatelliteReceive(){
	reversing[4] = false;
	reversing[0] = false;
	reversing[2] = false;
	reversing[3] = false;
	reversing[5] = false;
	reversing[1] = false;
}

void SatelliteReceive::setReversing(bool thro, bool aile, bool elev, bool rudd, bool gear, bool flap){
	reversing[4] = thro;
	reversing[0] = aile;
	reversing[2] = elev;
	reversing[3] = rudd;
	reversing[5] = gear;
	reversing[1] = flap;
}

void SatelliteReceive::regByte(int byte){
	if(byte == 0x01 && prevByte == 0x03) {
		lastMessageTime = millis();

		cByte = true;
		channel = 0;
	} else if (channel < 7){
		if(cByte){ //Second byte
			channels[channel] = (prevByte * 256) + byte;
			channel++;
		}
	}
	prevByte = byte;
	cByte = !cByte;
}

int SatelliteReceive::getThro(){
	if(reversing[4]) return RXMAX - channels[4];
	else return channels[4];
}

int SatelliteReceive::getAile(){
	if(reversing[0]) return RXMAX + 1024 - channels[0];
	else return channels[0] - 1024;
}

int SatelliteReceive::getElev(){
	if(reversing[2]) return RXMAX + 2048 - channels[2];
	else return channels[2] - 2048;
}

int SatelliteReceive::getRudd(){
	if(reversing[3]) return RXMAX + 3072 - channels[3];
	else return channels[3] - 3072;
}

int SatelliteReceive::getGear(){
	if(reversing[5]) return RXMAX + 4096 - channels[5];
	else return channels[5] - 4096;
}

int SatelliteReceive::getFlap(){
	if(reversing[1]) return RXMAX + 5120 - channels[1];
	else return channels[1] - 5120;
}

bool SatelliteReceive::getThroRev(){
	return reversing[4];
}

bool SatelliteReceive::getAileRev(){
	return reversing[0];
}

bool SatelliteReceive::getElevRev(){
	return reversing[2];
}

bool SatelliteReceive::getRuddRev(){
	return reversing[3];
}

bool SatelliteReceive::getGearRev(){
	return reversing[5];
}

bool SatelliteReceive::getFlapRev(){
	return reversing[1];
}

long SatelliteReceive::getTimeSinceMessage(){
	return millis() - lastMessageTime;
}
