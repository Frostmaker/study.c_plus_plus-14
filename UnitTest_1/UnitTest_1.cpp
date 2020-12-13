#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_14/Lab_14.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_1
{
	TEST_CLASS(CountTest)
	{
	public:
		
		TEST_METHOD(CountMethod1)
		{
			string str{ "\"I am Carlo Ventresca,\" he said, his English perfect." };
			Assert::AreEqual(count_words(str), 9);
		}


		TEST_METHOD(CountMethod2)
		{
			string str{ " " };
			Assert::AreEqual(count_words(str), 0);
		}


		TEST_METHOD(CountMethod3)
		{
			string str{ "    \"Don't      forget your police    cap,\" said Alexander    Ivanovich. \"You left   it on the table.\"      " };
			Assert::AreEqual(count_words(str), 14);
		}
	};



	TEST_CLASS(DeleteCharsTest)
	{
	public:

		TEST_METHOD(DeleteCharsMethod1)
		{
			string str{ "Your young wife is tumbling in your room with one man." };
			string res{ "Your young wife is tumbling in your room with one man." };
			delete_char(str, "x");
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(DeleteCharsMethod2)
		{
			string str{ "Your young wife is tumbling in your room with one man." };
			string res{ "Yur yung wife is tumbling in yur rm with ne man." };
			delete_char(str, "o");
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(DeleteCharsMethod3)
		{
			string str{ "    \"Don't      forget your police    cap,\" said Alexander    Ivanovich. \"You left   it on the table.\"      " };
			string res{ "    \"Don't      forgt your polic    cap,\" said Alxandr    Ivanovich. \"You lft   it on th tabl.\"      " };
			delete_char(str, "e");
			Assert::AreEqual(str, res);
		}
	};



	TEST_CLASS(InsertWordTest)
	{
	public:

		TEST_METHOD(InsertWordMethod1)
		{
			string str{ "You'll ruin the _." };
			string res{ "You'll ruin the _cake." };
			insert_substr(str, "_", "cake");
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(InsertWordMethod2)
		{
			string str{ "You'll ruin the _ and _." };
			string res{ "You'll ruin the _travel and _." };
			insert_substr(str, "_", "travel");
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(InsertWordMethod3)
		{
			auto func = [] {
				string str{ "You'll ruin the  and ." };
				string res{ "You'll ruin the  and ." };
				insert_substr(str, "_", "fun");
			};
			Assert::ExpectException<int>(func);
		}
	};



	TEST_CLASS(ChangeStringTest)
	{
	public:

		TEST_METHOD(ChangeStringMethod1)
		{
			string str{ "And who's this hero?" };
			string res{ "And :D this :D" };
			change_str(str, ":D");
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(ChangeStringMethod2)
		{
			string str{ "Veni, vidi, vici " };
			string res{ "Veni, morethat5letters vici " };
			change_str(str, "morethat5letters");
			Assert::AreEqual(str, res);
		}


		TEST_METHOD(ChangeStringMethod3)
		{
			string str{ "DO" };
			string res{ "DO" };
			change_str(str, "neverchanges");
			Assert::AreEqual(str, res);
		}
	};
}
