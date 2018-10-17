#include "stdafx.h"

#include "Fish.h"
#include "Aquarium.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedY = 50;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium *aquarium, const std::wstring &filename) :
	CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
}


CFish::~CFish()
{
}


/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);

	int wid = GetWidth() / 2;
	int earlyTurn = 1024 -10 - wid;
	int leftTurn = 0 + 10 + wid;

	int hit = GetHeight() / 2;
	int hitTurn = 800 - 10 - hit;
	int bottomTurn = 0 + 40 + hit;

// The X portion of swimming
	if (mSpeedX > 0 && earlyTurn <= GetX())
	{
			mSpeedX = -mSpeedX;
			SetMirror(mSpeedX < 0);
	}

	if (mSpeedX < 0 && leftTurn >= GetX())
	{
			mSpeedX = -mSpeedX;
			SetMirror(mSpeedX < 0);
	}

// The Y portion of siwmming
	if (mSpeedY > 0 && hitTurn <= GetY())
	{
		mSpeedY = -mSpeedY;
	}

	if (mSpeedY < 0 && bottomTurn >= GetY())
	{
			mSpeedY = -mSpeedY;
	}
}
