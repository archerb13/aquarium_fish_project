/**
 * \file Carp.h
 *
 * \author Bryce Archer
 *
 * Class that implements a Killer Carp
 */

#pragma once
#include "Item.h"
#include "Aquarium.h"
#include "Fish.h"
#include <memory>

/**
 * Class to define Carp
 */
class CCarp : public CFish
{
public:
	/// Constructor
	CCarp(CAquarium *aquarium);

	/// Defult constructor (disabled)
	CCarp() = delete;

	/// Copy constructor (disabled)
	CCarp(const CCarp &) = delete;

	/// Virtual destructor
	virtual ~CCarp();

	/**
	* Save this item to an XML node
	* \param node The node we are going to be a child of
	*/
	std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};
