/**
 * \file DecorCastle.cpp
 *
 * \author Bryce Archer
 */

#include "stdafx.h"
#include "DecorCastle.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring CastleImageName = L"images/castle.png";

/**
 * Constructor
 * \param aquarium Aquarium this fish is a member of
 */
CDecorCastle::CDecorCastle(CAquarium * aquarium) :
	CItem(aquarium, CastleImageName)
{
}


/**
 * Destructor
 */
CDecorCastle::~CDecorCastle()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Node with its type
 */
std::shared_ptr<xmlnode::CXmlNode>
		CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"castle");

	return itemNode;
}