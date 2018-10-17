/**
 * \file Magikarp.h
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
 * Class to define Magikarp
 */
class CMagikarp : public CFish
{
public:
	CMagikarp(CAquarium *aquarium);

	/// Defult constructor (disabled)
	CMagikarp() = delete;

	/// Copy constructor (disabled)
	CMagikarp(const CMagikarp &) = delete;

	virtual ~CMagikarp();

	std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

};

