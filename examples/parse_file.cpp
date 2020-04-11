// This file is a part of toml++ and is subject to the the terms of the MIT license.
// Copyright (c) 2019-2020 Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/tomlplusplus/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
/*

	This example demonstrates how to use the toml::json_formatter to
	re-serialize TOML data as JSON.

*/
#include <iostream>
#include <fstream>
#include "utf8_console.h"
#define TOML_UNRELEASED_FEATURES 1
#include <toml++/toml.h>
using namespace std::string_view_literals;

int main(int argc, char** argv)
{
	init_utf8_console();

	auto path = std::string{ argc > 1 ? argv[1] : "example.toml" };
	auto file = std::ifstream{ path };
	if (!file)
	{
		std::cerr << "The file '"sv << path << "' could not be opened for reading."sv << std::endl;
		return 1;
	}
	try
	{
		const auto tbl = toml::parse(file, std::move(path));
		std::cout << tbl << std::endl;
	}
	catch (const toml::parse_error& err)
	{
		std::cerr << err << std::endl;
		return 1;
	}
	return 0;
}
