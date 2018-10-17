/**
 * \file Bubbles.cpp
 *
 * \author Bryce Archer
 */

#include "stdafx.h"
#include "Bubbles.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring BubblesImageName = L"images/bubbles.png";

/**
 * Constructor
 * \param aquarium Aquarium this fish is a member of
 */
CBubbles::CBubbles(CAquarium * aquarium) :
	CFish(aquarium, BubblesImageName)
{
}


/**
 * Destructor
 */
CBubbles::~CBubbles()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns a node with the type
 */
std::shared_ptr<xmlnode::CXmlNode>
		CBubbles::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"bubbles");

	return itemNode;
}
