 /*********************************************************//**
  * Filename: module.h
  * Author: Gavin Lu
  * Date: 11/08/2018
  *
  * This file contains the Module class declaration.
  ************************************************************/
#ifndef MODULE_H
#define MODULE_H

class Module
{

	//Public members
	public:
		virtual ~Module();
		virtual void tick() = 0;
		virtual void refresh() = 0;

};

#endif
