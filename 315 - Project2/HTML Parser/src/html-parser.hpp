// Student Name: Christopher Bell
// Program Name: Basic HTML Parsing and Crawling
// Creation Date: Feb. 22, 2018
// Last Modified Date: Mar. 12, 2018
// CSCI Course: 315
// Grade Received: 100/100

#ifndef HTML_PARSER_HPP
#define HTML_PARSER_HPP

#include <string>
#include <vector>

using namespace std; // Did this for ease of reading this page.

// Struct for an HTML <tag>
struct Link {
	string filename; // HTML page in question
	string href; // Link an <a> tag
};

class HTMLParser {
	public:
		HTMLParser();
		~HTMLParser();
		void parse(string filename);
		bool isBalanced(string filename);
		int pageVisitAmount(string filename);

	private:
		bool fileExist(const string &filename) const;
		void pageUniqueVisit(const string &filename, vector<string> &result) const;

		// Container holding all balanced links
		vector<string> mBalanced;
		vector<Link> mLinks;
};

#endif
