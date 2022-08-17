#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <string>

// IS INT
template<typename T>
struct is_int 
{
	static const bool value = false;
};
template<>
struct is_int<int8_t> 
{ 
	static const bool value = true;
};
template<>
struct is_int<int16_t> 
{ 
	static const bool value = true;
};
template<>
struct is_int<int32_t> 
{ 
	static const bool value = true;
};
template<>
struct is_int<int64_t> 
{ 
	static const bool value = true;
};

// IS STRING
template<typename T>
struct is_string
{
	static const bool value = false;
};
template<>
struct is_string<std::string> 
{ 
	static const bool value = true;
};

// IS CONTAINER
template<typename T>
struct is_container
{
	static const bool value = false;
};
template<typename T>
struct is_container<std::vector<T>> 
{ 
	static const bool value = true;
};
template<typename T>
struct is_container<std::list<T>> 
{ 
	static const bool value = true;
};

//////////

template <typename T, std::enable_if_t<is_int<T>::value, bool> = true>
void print_ip([[maybe_unused]]const T& ip)
{
	for (size_t i = sizeof(T); i > 0 ; i--) {
		std::cout << (int)*((unsigned char *)(&ip) + i - 1);
		// printf("%d", *(((unsigned char *) &ip) + i - 1));
		if (i != 1) {
			std::cout << ".";
		}
	}
	std::cout << std::endl;
}

template <typename T, std::enable_if_t<is_string<T>::value, bool> = true>
void print_ip([[maybe_unused]]const T& ip)
{
	std::cout << ip << std::endl;
}

template <typename T, std::enable_if_t<is_container<T>::value, bool> = true>
void print_ip(const T& ip)
{
	for (const auto& c : ip) {
		std::cout << c;
		if (c != ip.back()) {
			std::cout << ".";
		}
	}
	std::cout << std::endl;
}

int main(int, char**)
{
	print_ip( int8_t{-1} ); // 255
	print_ip( int16_t{0} ); // 0.0
	print_ip( int32_t{2130706433} ); // 127.0.0.1
	print_ip( int64_t{8875824491850138409} );// 123.45.67.89.101.112.131.41 
	print_ip( std::string{"Hello, World!"} ); // Hello, World!
	print_ip( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400 
	print_ip( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100 p
	// print_ip( std::make_tuple(123, 456, 789, 0) ); // 123.456.789.0

	return 0;
}
