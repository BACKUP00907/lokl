 #include<stdlib.h> 	
 #include<stdint.h>
 #include<string.h>
#include <chrono>
#include <iostream>

using namespace std::chrono;



 #define hog       265
 uint8_t nhog = hog;
  	//defs
	#define RANDOMX_ARGON_MEMORY       262144
	constexpr uint32_t ArgonBlockSize = 1024;
	#define RANDOMX_DATASET_ITEM_SIZE 64

	constexpr uint32_t CacheSize = RANDOMX_ARGON_MEMORY * ArgonBlockSize;
	constexpr size_t CacheLineSize = RANDOMX_DATASET_ITEM_SIZE;
	//end defs

	//func defs
	uint64_t load64_native(const void *src) {
		uint64_t w;
		memcpy(&w, src, sizeof w);
		return w;
	}
	//end funcdefs
	constexpr uint64_t superscalarMul0 = 6364136223846793005ULL;
	constexpr uint64_t superscalarAdd1 = 9298411001130361340ULL;
	constexpr uint64_t superscalarAdd2 = 12065312585734608966ULL;
	constexpr uint64_t superscalarAdd3 = 9306329213124626780ULL;
	constexpr uint64_t superscalarAdd4 = 5281919268842080866ULL;
	constexpr uint64_t superscalarAdd5 = 10536153434571861004ULL;
	constexpr uint64_t superscalarAdd6 = 3398623926847679864ULL;
	constexpr uint64_t superscalarAdd7 = 9549104520008361294ULL;

	static inline uint8_t* getMixBlock(uint64_t registerValue, uint8_t *memory) {
		constexpr uint32_t mask = CacheSize / CacheLineSize - 1;
		return memory + (registerValue & mask) * CacheLineSize;
	}

	void initDatasetItem( uint8_t* out, uint64_t itemNumber ) {
		uint64_t rl[8];
		uint8_t* mixBlock;
		uint64_t registerValue = itemNumber;
		rl[0] = (itemNumber + 1) * superscalarMul0;
		rl[1] = rl[0] ^ superscalarAdd1;
		rl[2] = rl[0] ^ superscalarAdd2;
		rl[3] = rl[0] ^ superscalarAdd3;
		rl[4] = rl[0] ^ superscalarAdd4;
		rl[5] = rl[0] ^ superscalarAdd5;
		rl[6] = rl[0] ^ superscalarAdd6;
		rl[7] = rl[0] ^ superscalarAdd7;

    		uint8_t hf = (uint8_t)8545;
			uint8_t* hafg ;
    		hafg = &hf;
		
		mixBlock = getMixBlock(registerValue, hafg);


		for (unsigned q = 0; q < 8; ++q)
			rl[q] ^= load64_native(mixBlock + 8 * q);

		
		memcpy(out, &rl, 64);
		
		
	}

	

int main(){
	uint8_t* igj;
	igj = &nhog ;
  	auto start = high_resolution_clock::now();
		initDatasetItem( igj ,1);
	auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);
  std::cout << duration;
}
