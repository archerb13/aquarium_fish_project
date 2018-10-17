/**
 * \file Bubbles.h
 *
 * \author Bryce Archer
 *
 * Class that implements a Magikarp
 */

#pragma once
#include "Item.h"
#include "Fish.h"
#include <memory>

/**
* Implements a Bubbles Fish
*/
class CBubbles : public CFish
{
public:
	CBubbles(CAquarium *aquarium);

	/// Defult constructor (disabled)
	CBubbles() = delete;

	/// Copy constructor (disabled)
	CBubbles(const CBubbles &) = delete;

	virtual ~CBubbles();

	/// Saves the type to an XML document
	/// Return type is a node
	std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};
