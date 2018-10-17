#pragma once
/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */

#include "Item.h"

class CFish : public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish &) = delete;

	virtual ~CFish();

	void Update(double elapsed);

	/// Get the width of the image
	/// \returns items width
	int GetWidth() const { return mItemImage->GetWidth(); }
	
	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mItemImage->GetHeight(); }


private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;


protected:
	CFish(CAquarium * aquarium, const std::wstring & filename);

};

