#pragma once
#include "Zwierze.h"
namespace Zwierzeta {
	class Owca :
		public Zwierze
	{
	public:
		Owca(Swiat &swiat);
		~Owca();
	};
}