#pragma once

/*
const int LOGO = 0;
const int MENU = 1;
const int STAGE = 2;
const int EXIT = 3;
*/
/*
const DWORD KEY_UP		  	 = 1;
const DWORD KEY_DOWN  	 = 2;
const DWORD KEY_LEFT	     = 4;
const DWORD KEY_RIGHT	 = 8;
const DWORD KEY_SPACE	 = 16;
const DWORD KEY_ENTER	 = 32;   
const DWORD KEY_CTRL	 = 64;	
const DWORD KEY_ALT		 = 128; 
const DWORD KEY_TAB = 256;   
const DWORD KEY_ESCAPE = 512;
*/

const DWORD KEY_UP		= 0x00000001;
const DWORD KEY_DOWN	= 0x00000002;
const DWORD KEY_LEFT	= 0x00000004;
const DWORD KEY_RIGHT	= 0x00000008;
const DWORD KEY_SPACE	= 0x00000010;
const DWORD KEY_ENTER	= 0x00000020;
const DWORD KEY_CTRL	= 0x00000040;
const DWORD KEY_ALT		= 0x00000080;
const DWORD KEY_TAB		= 0x00000100;
const DWORD KEY_ESCAPE	= 0x00000200;


const int BUFFER_OVER = 1;
const int MAX_SIZE = 2;

const SHORT ConsoleWidthSize  = 80;
const SHORT ConsoleHeightSize = 60;
