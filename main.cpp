#include <iostream>
#include <fstream>

int main() {
	// Variable Declarations
	double lat1;
	double lon1;
	double lat2;
	double lon2;
	double lat3;
	double lon3;
	double lat4;
	double lon4;

	// Point 1
	std::cout << "Type a latitude coordinate: ";
	std::cin >> lat1;
	std::cout << "Type a longitude coordinate: ";
	std::cin >> lon1;

	// Point 2
	std::cout << "Type another latitude coordinate: ";
	std::cin >> lat2;
	std::cout << "Type another longitude coordinate: ";
	std::cin >> lon2;

	// Point 3
	std::cout << "Type your third latitude coordinate: ";
	std::cin >> lat3;
	std::cout << "Type your third longitude coordinate: ";
	std::cin >> lon3;

	// Point 4
	std::cout << "Type your fourth latitude coordinate: ";
	std::cin >> lat4;
	std::cout << "Type your fourth longitude coordinate: ";
	std::cin >> lon4;

	// Export GPX File
	std::ofstream course;
	course.open("test.gpx");
	course << "<?xml version = \"1.0\" encoding = \"UTF-8\"?>" << '\n';
	course << "<gpx version=\"1.1\" creator=\"Christian Boe\" xmlns=\"http://www.topografix.com/GPX/1/1\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd\">" << '\n';
	course << "<rte>" << '\n';
	course << "<name>Imported Course</name>" << '\n';
	course << "<rtept lat = \"" << lat1 << "\" lon = \"" << lon1 << "\"/>" << '\n';
	course << "<rtept lat = \"" << lat2 << "\" lon = \"" << lon2 << "\"/>" << '\n';
	course << "<rtept lat = \"" << lat3 << "\" lon = \"" << lon3 << "\"/>" << '\n';
	course << "<rtept lat = \"" << lat4 << "\" lon = \"" << lon4 << "\"/>" << '\n';
	course << "</rte>" << '\n';
	course << "</gpx>" << '\n';
	return 0;
}