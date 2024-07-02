#include "blockchain/CChain.h"
#include <iostream>

using namespace std;
using namespace blockchain;

int main(int argc,char **argv)
{
  cout<<"Start.\n";

  CChain chain(1,storage::EST_LOCAL);
  cout<<"Chain initialized!\n";
  cout<<"Current block count: "<<chain.getBlockCount()<<"\n";

  if(chain.isValid())
	  cout<<"Chain is valid\n";
  else
  {
	  cout<<"INVALID CHAIN\n";
	  return 1;
  }

  CBlock* current = chain.getCurrentBlock();

  uint8_t* garbage = new uint8_t[32];
  for(uint32_t n = 0; n<32;n++)
	  garbage[n] = clock() %255;

  cout<<"Garbage generated!\n";

  chain.appendToCurrentBlock(garbage,32);
  delete[] garbage;

  cout<<"Garbage append to current block.\n";

  chain.nextBlock();

  cout<<"next block mined\n";
  cout<<"Genesis hash: "<< chain.getCurrentBlock()->getPrevBlock()->getHashStr()<<"\nNonce: "<< chain.getCurrentBlock()->getNonce()<<"\n";

  garbage = new uint8_t[32];
  for(uint32_t n = 0; n < 32; n++)
	  garbage[n] = clock() %255;

  cout<<"\nGarbage genearted\n";

  chain.appendToCurrentBlock(garbage,32);
  delete[] garbage;

  cout<<"\nGarbage append to current block\n";
  chain.nextBlock();
  cout<<"\nNext block mined\n";
  cout<<"\nPrevious hash: "<<chain.getCurrentBlock()->getPrevBlock()->getHashStr()<<"\nNonce: "<<chain.getCurrentBlock()->getNonce()<<"\n";
  
  cout<<"Current block count: "<<chain.getBlockCount()<<"\n";
  cout<<"\n"<<"## BLOCK LIST ##"<<"\n";

  CBlock* cur = chain.getCurrentBlock();
  while(cur = cur->getPrevBlock())
  {
     time_t ts = cur->getCreatedTS();
     string tstr(ctime(&ts));
     tstr.resize(tstr.size()-1);

     cout<<"Block " << cur->getHashStr()<<"\tTimeStamp " <<tstr << "\tData Size "<<cur->getDataSize()<<"\n"; 
  }
  
  
  return 0;

}
