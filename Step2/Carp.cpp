/**
 * \file Bubbles.cpp
 *
 * \author Bryce Archer
 */

#include "stdafx.h"
#include "Carp.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring CarpImageName = L"images/carp.png";

/**
 * Constructor
 * \param aquarium Aquarium this fish is a member of
 */
CCarp::CCarp(CAquarium * aquarium) : 
	CFish(aquarium, CarpImageName)
{
}



/**
 * Destructor
 */
CCarp::~CCarp()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Node with its type
 */
std::shared_ptr<xmlnode::CXmlNode>
		CCarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"carp");

	return itemNode;
}