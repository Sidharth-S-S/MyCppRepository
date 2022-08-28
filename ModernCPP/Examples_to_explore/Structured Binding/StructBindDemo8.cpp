#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <tuple>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{	
	
	{     //HANDLING A 'pair' TYPE
		cout << endl << "=== EXPERIMENT 1: Decompose: pair - binding - pair =====" <<endl;
		auto p = std::pair<std::string, int>("C++", 17);
		auto [name, version] = p;
		cout << " name = " << name << " ; version = " << version << endl;
	}

	{    //HANDLING A 'map' TYPE
		cout << endl << "\n=== EXPERIMENT 2: Decompose: map / 'hash-table' - =====" << endl;
		auto database = map<string, int>{{"c++", 17}, {"Rust", 10}, {"Java", 2000}};
		for(const auto& [key, value] : database)
			cout << "key = " << key << " ; value = " << value << endl;		
	}

	{  //HANDLING A 'tuple' TYPE
		cout << endl << "\n=== EXPERIMENT 3: Decompose: tuple - =====" << endl;
		using DatabaseRow = std::tuple<int, std::string, double>;

		auto database = std::vector<DatabaseRow>{
			{100, "Fried tasty fresh cheese",   3.45},
			{400, "Super hot toasted coffee.", 6.25},
			{500, "Fresh Orange Juice",        4.50},
		};

		for(const auto& [id, name, price]: database)
			cout << " ROW=> id = " << id
					  << " ; name = "   << name
					  << " ; price = "  << price 
					  << endl;
	}

	{
		cout << endl << "\n=== Decompose: tuple with Reference - =====" << endl;
		using DatabaseRow = tuple<int, string, double>;
		auto row = DatabaseRow{200, "Coffee", 4.5};
		auto& [id, name, price] = row;

		
		cout << "[BEFORE] => Product{ id =" <<std::get<0>(row) <<";" << endl;
		cout << "name =" << std::get<1>(row).c_str() <<";";
		cout << "price =" << std::get<2>(row) <<";";
        //modifying values...
		id = 500, name = "italian-sytle coffee", price = 10.60;

		
	    cout << "[AFTER] => Product{ id =" <<std::get<0>(row) <<";" << endl;
		cout << "name =" << std::get<1>(row).c_str() <<";";
		cout << "price =" << std::get<2>(row) <<";";
	}

	{
		std::puts("\n=== EXPERIMENT 4: Decompose: Structs - =====");
		struct GeoCoordinate{
			std::string name;
			double      latitude;
			double      longitude;
		};
		auto geoDatabase = std::deque<GeoCoordinate>{
			 {"Bogota",         4.7110,  -74.0721}
			,{"Beijing",       39.9042,  116.4074}
			,{"Gauteng",      -26.2708,   28.1123}			
			,{"Buenos Aires", -34.6037,  -58.3816}
			,{"Brasilia",     -15.8267,  -47.9218}
		};
		std::cout << std::setprecision(3);
		std::for_each(geoDatabase.begin(), geoDatabase.end(),
					  [](const auto& city){
						  const auto& [name, lat, lon] = city;
						  std::cout << std::setw(15) << std::left  << name
									<< std::setw(8) << std::right << lat
									<< std::setw(8) << lon 
									<< "\n";						  
						  
					  }); 
	}

	{
		cout << "\n=== EXPERIMENT 5: Decompose: C-Array - =====" <<endl;
		double array [3] = {10.23, 90.23, 100.0};
		auto [x, y, z] = array;
	
		cout <<"array {x=" << x <<"," <<"y=" << y <<"," << "z=" << z <<"}"<< endl;
	}		
	return 0;
}
