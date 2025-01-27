
/*!
	\file
	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2011-2021 Igor Mironchik

	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
*/

// Excel include.
#include <read-excel/book.hpp>
#include <read-excel/sheet.hpp>

// unit test helper.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <test/doctest/doctest.h>


TEST_CASE( "test_book" )
{
	Excel::Book book( "test/data/datetime.xls" );

	REQUIRE( book.sheetsCount() == 1 );

	Excel::Sheet * sheet = book.sheet( 0 );

	REQUIRE( sheet->rowsCount() == 1 );
	REQUIRE( sheet->columnsCount() == 1 );

	REQUIRE( std::fabs( sheet->cell( 0, 0 ).getDouble() - 43100.9999884259 ) < 1E-9 );
}
