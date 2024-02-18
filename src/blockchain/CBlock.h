#ifndef __C_BLOCK_INCLUDED__
#define __C_BLOCK_INCLUDED__

#include <string>
#include<openssl/sha.h>

namespace blockchain
{
   class CBlock
   {
   private:
	   uint8_t mHash[SHA256_DIGEST_LENGTH];
	   uint8_t mPrevHash[SHA256_DIGEST_LENGTH];
	   CBlock* mPrevBlock;
	   uint8_t* mData;
	   uint32_t mDataSize;
	   time_t mCreatedTS;
	   uint32_t mNonce;
      public:
	   CBlock(CBlock* prevBlock,const uint8_t hash = 0);
	   ~CBlock();

	   void calculateHash(uint8_t ret = 0);
	   uint8_t* getHash();
	   std::string getHashStr();
	   CBlock* getPrevBlock();
	   void appendData(uint8_t* data,uint32_t size);
	   bool isDifficulty(int difficulty);
	   void mine(int difficulty);
	   uint32_t getNonce();


	   bool hasHash();
	   bool hasPrevHash();
	   uint8_t* getPrevHash();
	   std::string getPrevHashStr();
	   void setPrevHash(const uint8_t* prevHash);
	   void setPrevBlock(CBlock* block);

	   time_t getCreatedTS();
	   void setCreatedTS(time_t createdTS);
	   void setNonce(uint32_t nonce);
	   uint32_t getDataSize();
	   uint8_t* getData();
	   void setAllocatedData(uint8_t* data,uint32_t sz);

	   bool isValid();
    };
}
#endif
