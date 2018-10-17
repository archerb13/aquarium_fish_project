/**
 * \file Item.h
 *
 * \author Bryce Archer
 *
 * Base class for any item in our aquarium
 */

#pragma once
#include <memory>
#include <string>
#include "XmlNode.h"

class CAquarium;

/**
 * Base class for an item in our aquarium.
 */
class CItem
{
protected:
	CItem(CAquarium *aquarium, const std::wstring &filename);
	
	/// The fish image
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

public:
	virtual ~CItem();

	/// Draw this item
	/// \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics *graphics);

	/**
	 * Save this item to an XML node
	 * \param node The node we are going to be a child of
	 */
	virtual std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/**
	* Deletes this item from an XML node
	* \param node The node we are going to be a child of
	*/
	std::shared_ptr<xmlnode::CXmlNode>
		XmlDel(const std::shared_ptr<xmlnode::CXmlNode>& node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/** Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	bool HitTest(int x, int y);

	/// Defualt constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}
	
	/// Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium *GetAquarium() { return mAquarium; }

	bool mMirror = false;   ///< True mirrors the item image

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }


private:
	/// The Aquarium this item is contained in
	CAquarium *mAquarium;

	// Item location in the aquarium
	double mX = 0;	///< X location for the center of the item
	double mY = 0;	///< Y location for the center of the item
};

