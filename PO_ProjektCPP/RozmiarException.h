#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class RozmiarException 
{
public:
	RozmiarException(const string& msg): msg_(msg){}
	~RozmiarException(){}
	string getMessage() const{
		return (msg_);
	}
private:
	string msg_;
};

