/*
 * SpectrumReceive.h
 *
 *  Created on: 9. jan. 2011
 *      Author: develop
 */

#ifndef SPECTRUMRECIVE_H_
#define SPECTRUMRECIVE_H_

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define RXCENTER 511
#define RXTRAVEL 358 // (511 center - 63 trim) / 1,25 maxTravel
#define RXMIN 0//153 // 511center - 358travel
#define RXMAX 1022//869 // 511center + 358travel

class SatelliteReceive{
public:
	SatelliteReceive();
	void setReversing(bool thro, bool aile, bool elev, bool rudd, bool gear, bool flap);
	void regByte(int byte);
	int getThro();
	int getAile();
	int getElev();
	int getRudd();
	int getGear();
	int getFlap();

	bool getThroRev();
	bool getAileRev();
	bool getElevRev();
	bool getRuddRev();
	bool getGearRev();
	bool getFlapRev();

	long getTimeSinceMessage();

private:
	bool reversing[7];
	int channels[7];
	byte prevByte;
	int value;
	byte byteCount;
	bool cByte;
	long lastMessageTime;
};


#endif /* SPECTRUMRECIVE_H_ */
