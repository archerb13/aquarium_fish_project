/**
 * \file DecorCastle.h
 *
 * \author Bryce Archer
 *
 * Class that implements a Castle to move around
 */

#pragma once
#include "Item.h"
#include <memory>

/**
 * Class to define a castle
 */
class CDecorCastle : public CItem
{
public:
	/// Constructor
	CDecorCastle(CAquarium *aquarium);

	/// Defult constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle &) = delete;

	virtual ~CDecorCastle();

	std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};
