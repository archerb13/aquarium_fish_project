/**
 * \file FishBeta.h
 *
 * \author Bryce Archer
 *
 * Class the implements a Beta Fish
 */

#pragma once
#include "Item.h"
#include "Fish.h"
#include <memory>

/**
 * Implements a Beta Fish
 */
class CFishBeta : public CFish
{
public:
	CFishBeta(CAquarium * aquarium);

	/// Defult constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta &) = delete;

	virtual ~CFishBeta();

	virtual std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
 };

