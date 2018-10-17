/**
 * \file FishBeta.cpp
 *
 * \author Bryce Archer
 */

#include "stdafx.h"
#include "FishBeta.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * \param aquarium Aquarium this fish is a member of
 */
CFishBeta::CFishBeta(CAquarium *aquarium) :
	CFish(aquarium, FishBetaImageName)
{
}


/**
 * Destructor
 */
CFishBeta::~CFishBeta()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Node with its type
 */
std::shared_ptr<xmlnode::CXmlNode>
		CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"beta");

	return itemNode;
}