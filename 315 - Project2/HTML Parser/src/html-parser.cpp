// Student Name: Christopher Bell
// Program Name: Basic HTML Parsing and Crawling
// Creation Date: Feb. 22, 2018
// Last Modified Date: Mar. 12, 2018
// CSCI Course: 315
// Grade Received: 100/100

#include "html-parser.hpp"
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

HTMLParser::HTMLParser() {
}

HTMLParser::~HTMLParser() {
}

/* As the project2.pdf suggested, this one WAS the hardest. Who would've thought?
This function parses through all of the webpages and reads everything into the
proper place.  */
void HTMLParser::parse(std::string filename) {
	bool isBalanced = true; // Default = Link is Balanced
	std::stack<std::string> tags; // Stack for HTML tags = It's FILO so we can see it in correct order from the original page
	std::vector<Link> pageLinks; // Page Links vector that add's to mLinks if balanced

	std::ifstream file(filename); // Read the file
	if (!file.is_open()) { // If the file doesn't exist, we can end early
		std::cout << "File '" << filename << "' does not exist..." << std::endl;
		return;
	}

	char symbol;
	std::string tag; // HTML Tag to read, using as char array

	while (file.get(symbol)) { // Get the symbol while file isn't eof
		if (symbol == '<') { // If it's a start of an HTML tag
			std::getline(file, tag, '>'); // Read the whole tag until we arrive at ">"

			if (tag[0] != '/') { // If it's an open tag, add into the tag list
				std::string check; // See if there's a <a> tag without attr
				std::stringstream temp(tag);

				temp >> check; // Get "a"
				if (check == "a") {
					std::getline(temp, check, '='); // Skip "href ="
					temp >> check; // Get the URL

					// Save the URL to the pageLinks vector
					Link link;
					link.filename = filename;
					link.href = check;

					pageLinks.push_back(link);
				}
			}

			if (isBalanced) { // If it's balanced...
				if (tag[0] != '/') { // If the first symbol is a start tag...
					std::stringstream temp(tag); // Remove attr from tag
					temp >> tag;
					tags.push(tag);
				} else { // If they are closing tags
					std::string needOpenTag = tag.erase(0, 1); // Remove '/'
					if (!tags.empty() && tags.top() == needOpenTag) { // If pair open/close...
						tags.pop(); // Remove open
					} else {
						isBalanced = false;
						break; // Exit from the loop
					}
				}
			}
		}
	}

	if (isBalanced) {
		mBalanced.push_back(filename); // Mark filename as balanced
		mLinks.insert(mLinks.end(), pageLinks.begin(), pageLinks.end()); // Add to pageLinks
	}
}

// Function that simply checks for the balance of tags.
bool HTMLParser::isBalanced(std::string filename) {
	return std::find(mBalanced.begin(), mBalanced.end(), filename) != mBalanced.end();
}

/* The next three functions are all dedicated to getting the unique ammount of
page visits (to pages that work anyway).  */
int HTMLParser::pageVisitAmount(std::string filename) {
	std::vector<std::string> result; // Unique links with existing page

	pageUniqueVisit(filename, result);
	if (std::find(result.begin(), result.end(), filename) == result.end()) { // Ignore a certain page
		return result.size();
	}

	return result.size() - 1;
}

// RECURSIVENESS FOR THE WIN!!!
void HTMLParser::pageUniqueVisit(const std::string &filename, std::vector<std::string> &result) const {
	for (std::size_t i = 0; i < mLinks.size(); ++i) { // Traverse all of the links!! (insert meme picture here)
		if (mLinks[i].filename == filename) { // Link for filename
			std::string href = mLinks[i].href;

			if (std::find(result.begin(), result.end(), href) == result.end()) { // Check if unique index
				if (fileExist(mLinks[i].href)) { // If the page exists...
					result.push_back(mLinks[i].href); // Add to the result.
					pageUniqueVisit(mLinks[i].href, result); // Try to find link in href page.
				}
			}
		}
	}
}

bool HTMLParser::fileExist(const std::string &filename) const {
	std::ifstream file(filename);
	return (bool)file;
}
