/**
 * \file Aquarium.h
 *
 * \author Bryce Archer
 *
 * Base class for our aquarium
 */

#pragma once

#include <memory>
#include <vector>

#include "Item.h"


class CItem;

/**
 * Base class for our Aquarium
 */

class CAquarium
{
public:
	CAquarium();
	void Add(std::shared_ptr<CItem> item);
	virtual ~CAquarium();

	void OnDraw(Gdiplus::Graphics * graphics);
	void Save(const std::wstring & filename);

	void Load(const std::wstring & filename);

	///
	void Clear(const std::wstring & filename);


	//void Clear();

	std::shared_ptr<CItem> HitTest(int x, int y);

	void MoveToFront(std::shared_ptr<CItem> item);

	void Update(double elapsed);

	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

};

