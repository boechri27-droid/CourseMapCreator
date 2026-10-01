#include <iostream>
#include <fstream> // Write to file functionality
#include <iomanip> // Set precision of doubles when writing to files or using std::cout
double findCoordinate(double cornerCoord[4], int imgWidth, int imgHeight, double coord, char axis);
int createGPXFile(double coord[], int points);

int main() {
	int points;
	// Get # of points
	std::cout << "Type your number of points: ";
	std::cin >> points;
	double* coord = new double[points * 2];
	double* finalCoord = new double[points * 2];
	double cornerCoord[4];
	int imgWidth;
	int imgHeight;


	// Find origin lon, lat
	std::cout << "Type an origin longitude coordinate: ";
	std::cin >> cornerCoord[0];
	std::cout << "Type an origin latitude coordinate: ";
	std::cin >> cornerCoord[1];
	
	// Find top-right lon, lat
	std::cout << "Type the top-right longitude coordinate: ";
	std::cin >> cornerCoord[2];
	std::cout << "Type the top-right latitude coordinate: ";
	std::cin >> cornerCoord[3];

	// Find image dimensions
	std::cout << "Type the image width: ";
	std::cin >> imgWidth;
	std::cout << "Type the image height: ";
	std::cin >> imgHeight;

	// Find screen points
	for (int i = 0; i < points * 2; i += 2) {
		std::cout << "Type screenX coordinate #" << i + 1 << ": ";
		std::cin >> coord[i];
		std::cout << "Type screenY coordinate #" << i + 1 << ": ";
		std::cin >> coord[i + 1];
	}

	// Find lat, lon coords
	for (int i = 0; i < points * 2; i += 2) {
		finalCoord[i] = findCoordinate(cornerCoord, imgWidth, imgHeight, coord[i], 'X');
		finalCoord[i + 1] = findCoordinate(cornerCoord, imgWidth, imgHeight, coord[i + 1], 'Y');
	}

	// Create GPX file
	createGPXFile(finalCoord, points);

	// Delete dynamically allocated arrays
	delete[] coord;
	delete[] finalCoord;
}

double findCoordinate(double cornerCoord[4], int imgWidth, int imgHeight, double coord, char axis) {
	if (axis == 'X') {
		double percentage = coord / imgWidth;
		double distance = cornerCoord[2] - cornerCoord[0];
		return cornerCoord[0] + percentage * distance;
	} else if (axis == 'Y') {
		double percentage = coord / imgHeight;
		double distance = cornerCoord[3] - cornerCoord[1];
		return cornerCoord[1] + percentage * distance;
	} else {
	    return -1.0;
	}
}

int createGPXFile(double coord[], int points) {
	std::ofstream course;
	course.open("test.gpx");
	if (course.is_open()) {
		course << std::fixed << std::setprecision(7);
		course << "<?xml version = \"1.0\" encoding = \"UTF-8\"?>" << '\n';
		course << "<gpx version=\"1.1\" creator=\"Christian Boe\" xmlns=\"http://www.topografix.com/GPX/1/1\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd\">" << '\n';
		course << "<rte>" << '\n';
		course << "<name>Imported Course</name>" << '\n';
		std::cout << "coord[0]: " << coord[0] << " coord[1]: " << coord[1] << " coord[2]: " << coord[2] << " coord[3]: " << coord[3] << '\n';
		for (int i = 0; i < points * 2; i += 2) {
		    std::cout << "i is " << i << '\n';
			course << "<rtept lat = \"" << coord[i + 1] << "\" lon = \"" << coord[i] << "\"/>" << '\n';
		}
		course << "</rte>" << '\n';
		course << "</gpx>" << '\n';
		course.close();
	} else {
		std::cerr << "Course file did not open." << '\n';
		return 0;
	}
	return 1;
}
