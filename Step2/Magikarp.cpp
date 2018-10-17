/**
 * \file Magikarp.cpp
 *
 * \author Bryce Archer
 */

#include "stdafx.h"
#include "Magikarp.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring MagikarpImageName = L"images/magikarp.png";

/**
 * Constructor
 * \param aquarium Aquarium this fish is a member of
 */
CMagikarp::CMagikarp(CAquarium * aquarium) :
	CFish(aquarium, MagikarpImageName)
{
}


/**
 * Destructor
 */
CMagikarp::~CMagikarp()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode Returns the new saved node
 */
std::shared_ptr<xmlnode::CXmlNode>
		CMagikarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"magikarp");

	return itemNode;
}