// STD
#include <iostream>

// VM
#include "vm_test.hpp"


int main()
{
	global::console.log("Testing x86-64 virtual machine");

	constexpr std::uint8_t buffer[] = {
		
		// ADD (DISPLACED DESTINATION) VARIANTS

		// MODE 2
		0x49, 0x81, 0x81, 0x20, 0x04, 0x00, 0x00, 0x37, 0x13, 0x00, 0x00,	// ADD [R9+0x420], 1337

		// MODE 3
		0x66, 0x48, 0x81, 0xC3, 0x00, 0x00, 0x05, 0x00,						// ADD RBX, 50000

		// ADD (DISPLACED SOURCE) VARIANTS
		// MODE 0
		// 0x4C, 0x03, 0x07,							// ADD R8, [RDI]
		// 
		// // MODE 1
		// 0x67, 0x4C, 0x03, 0x47, 0x0A,				// ADD R8, [EDI+0x0A]
		// 
		// // MODE 2
		// 0x4C, 0x03, 0x87, 0x00, 0x01, 0x00, 0x00,	// ADD R8, [RDI+0x100]
		// 
		// // MODE 3
		// 0x4C, 0x03, 0xC7								// ADD R8, RDI
	};

	auto test_engine = vm_tester(buffer);

	test_engine.prepare_test();
	test_engine.run();


	return 0;
}

