#include <iostream>
#include <fstream>

int main() {
	std::ofstream course;
	course.open("test.gpx");
	course << "< ? xml version = \"1.0\" encoding = \"UTF - 8\" ? >" << '\n';
	course << "<gpx version = \"1.1\" xmlns = \"http://topografix.com\">" << '\n';
	course << "<rte>" << '/n';
	course << "<rtept lat = \"37.774929\" lon = \"-122.419416\" / >" << '\n';
	course << "</rte>" << '\n';
	course << "</gpx>" << '\n';
	return 0;
}