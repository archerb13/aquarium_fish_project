#include "stdafx.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "FishBeta.h"
#include "Carp.h"
#include "Magikarp.h"
#include "DecorCastle.h"
#include "Bubbles.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}

		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr, L"Testing empty aquarium");

			std::shared_ptr<CFishBeta> fish1 = std::make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1, L"Testing fish at 100, 200");

			// Test to ensure nullptr if we hit away from any image
			Assert::IsTrue(aquarium.HitTest(0, 200) == nullptr, L"Testing fish at 00, 200");

			// Add two overlapping fish
			std::shared_ptr<CFishBeta> fish2 = std::make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(400, 400);
			aquarium.Add(fish2);

			std::shared_ptr<CFishBeta> fish3 = std::make_shared<CFishBeta>(&aquarium);
			fish3->SetLocation(400, 400);
			aquarium.Add(fish3);

			// Ensure the top one is found
			Assert::IsTrue(aquarium.HitTest(400, 400) == fish3, L"Testing overlapping fish");
		}

		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			// Convert null terminated string to wstring
			return wstring(path_nts);
		}

		/**
		* Read a file into a wstring and return it.
		* \param filename Name of the file to read
		* \return File contents
		*/
		wstring ReadFile(const wstring &filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}

		TEST_METHOD(TestCAquariumSave)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;
			CAquarium aquarium2;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);
			TestEmpty(file1);

			aquarium2.Load(file1);
			aquarium2.Save(file1);
			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetas(file2);

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetas(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypes(file3);

			aquarium2.Load(file3);
			aquarium2.Save(file3);
			TestAllTypes(file3);

			aquarium3.Clear(file3);
			TestEmpty(file3);
		}

		/**
		* Test to ensure an aquarium .aqua file is empty
		*/
		void TestEmpty(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			Assert::IsTrue(regex_search(xml, wregex(L"<\?xml.*\?>")));
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua/>")));

		}

		/**
		*  Populate an aquarium with three Beta fish
		 */
		void PopulateThreeBetas(CAquarium *aquarium)
		{
			const unsigned int RandomSeed = 1238197374;

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);
		}

		void TestThreeBetas(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
		}

		/**
		*  Populate an aquarium with three Beta fish
		*/
		void PopulateAllTypes(CAquarium *aquarium)
		{
			const unsigned int RandomSeed = 1238197374;

			shared_ptr<CMagikarp> fish1 = make_shared<CMagikarp>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CCarp> fish2 = make_shared<CCarp>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CBubbles> fish3 = make_shared<CBubbles>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);

			shared_ptr<CFishBeta> fish4 = make_shared<CFishBeta>(aquarium);
			fish4->SetLocation(500, 100);
			aquarium->Add(fish4);

			shared_ptr<CDecorCastle> fish5 = make_shared<CDecorCastle>(aquarium);
			fish5->SetLocation(300, 200);
			aquarium->Add(fish5);
		}

		void TestAllTypes(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"500\" y=\"100\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"300\" y=\"200\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"magikarp\"/><item.* type=\"carp\"/><item.* type=\"bubbles\"/><item.* type=\"beta\"/><item.* type=\"castle\"/></aqua>")));

		}
	};
}