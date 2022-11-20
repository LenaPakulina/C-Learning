#ifndef CHARS_H
#define CHARS_H

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

int16_t cp1251[256] = {
	/*0x00 */ 0x0000, // #NULL
	/*0x01 */ 0x0001, // #START OF HEADING
	/*0x02 */ 0x0002, // #START OF TEXT
	/*0x03 */ 0x0003, // #END OF TEXT
	/*0x04 */ 0x0004, // #END OF TRANSMISSION
	/*0x05 */ 0x0005, // #ENQUIRY
	/*0x06 */ 0x0006, // #ACKNOWLEDGE
	/*0x07 */ 0x0007, // #BELL
	/*0x08 */ 0x0008, // #BACKSPACE
	/*0x09 */ 0x0009, // #HORIZONTAL TABULATION
	/*0x0A */ 0x000A, // #LINE FEED
	/*0x0B */ 0x000B, // #VERTICAL TABULATION
	/*0x0C */ 0x000C, // #FORM FEED
	/*0x0D */ 0x000D, // #CARRIAGE RETURN
	/*0x0E */ 0x000E, // #SHIFT OUT
	/*0x0F */ 0x000F, // #SHIFT IN
	/*0x10 */ 0x0010, // #DATA LINK ESCAPE
	/*0x11 */ 0x0011, // #DEVICE CONTROL ONE
	/*0x12 */ 0x0012, // #DEVICE CONTROL TWO
	/*0x13 */ 0x0013, // #DEVICE CONTROL THREE
	/*0x14 */ 0x0014, // #DEVICE CONTROL FOUR
	/*0x15 */ 0x0015, // #NEGATIVE ACKNOWLEDGE
	/*0x16 */ 0x0016, // #SYNCHRONOUS IDLE
	/*0x17 */ 0x0017, // #END OF TRANSMISSION BLOCK
	/*0x18 */ 0x0018, // #CANCEL
	/*0x19 */ 0x0019, // #END OF MEDIUM
	/*0x1A */ 0x001A, // #SUBSTITUTE
	/*0x1B */ 0x001B, // #ESCAPE
	/*0x1C */ 0x001C, // #FILE SEPARATOR
	/*0x1D */ 0x001D, // #GROUP SEPARATOR
	/*0x1E */ 0x001E, // #RECORD SEPARATOR
	/*0x1F */ 0x001F, // #UNIT SEPARATOR
	/*0x20 */ 0x0020, // #SPACE
	/*0x21 */ 0x0021, // #EXCLAMATION MARK
	/*0x22 */ 0x0022, // #QUOTATION MARK
	/*0x23 */ 0x0023, // #NUMBER SIGN
	/*0x24 */ 0x0024, // #DOLLAR SIGN
	/*0x25 */ 0x0025, // #PERCENT SIGN
	/*0x26 */ 0x0026, // #AMPERSAND
	/*0x27 */ 0x0027, // #APOSTROPHE
	/*0x28 */ 0x0028, // #LEFT PARENTHESIS
	/*0x29 */ 0x0029, // #RIGHT PARENTHESIS
	/*0x2A */ 0x002A, // #ASTERISK
	/*0x2B */ 0x002B, // #PLUS SIGN
	/*0x2C */ 0x002C, // #COMMA
	/*0x2D */ 0x002D, // #HYPHEN-MINUS
	/*0x2E */ 0x002E, // #FULL STOP
	/*0x2F */ 0x002F, // #SOLIDUS
	/*0x30 */ 0x0030, // #DIGIT ZERO
	/*0x31 */ 0x0031, // #DIGIT ONE
	/*0x32 */ 0x0032, // #DIGIT TWO
	/*0x33 */ 0x0033, // #DIGIT THREE
	/*0x34 */ 0x0034, // #DIGIT FOUR
	/*0x35 */ 0x0035, // #DIGIT FIVE
	/*0x36 */ 0x0036, // #DIGIT SIX
	/*0x37 */ 0x0037, // #DIGIT SEVEN
	/*0x38 */ 0x0038, // #DIGIT EIGHT
	/*0x39 */ 0x0039, // #DIGIT NINE
	/*0x3A */ 0x003A, // #COLON
	/*0x3B */ 0x003B, // #SEMICOLON
	/*0x3C */ 0x003C, // #LESS-THAN SIGN
	/*0x3D */ 0x003D, // #EQUALS SIGN
	/*0x3E */ 0x003E, // #GREATER-THAN SIGN
	/*0x3F */ 0x003F, // #QUESTION MARK
	/*0x40 */ 0x0040, // #COMMERCIAL AT
	/*0x41 */ 0x0041, // #LATIN CAPITAL LETTER A
	/*0x42 */ 0x0042, // #LATIN CAPITAL LETTER B
	/*0x43 */ 0x0043, // #LATIN CAPITAL LETTER C
	/*0x44 */ 0x0044, // #LATIN CAPITAL LETTER D
	/*0x45 */ 0x0045, // #LATIN CAPITAL LETTER E
	/*0x46 */ 0x0046, // #LATIN CAPITAL LETTER F
	/*0x47 */ 0x0047, // #LATIN CAPITAL LETTER G
	/*0x48 */ 0x0048, // #LATIN CAPITAL LETTER H
	/*0x49 */ 0x0049, // #LATIN CAPITAL LETTER I
	/*0x4A */ 0x004A, // #LATIN CAPITAL LETTER J
	/*0x4B */ 0x004B, // #LATIN CAPITAL LETTER K
	/*0x4C */ 0x004C, // #LATIN CAPITAL LETTER L
	/*0x4D */ 0x004D, // #LATIN CAPITAL LETTER M
	/*0x4E */ 0x004E, // #LATIN CAPITAL LETTER N
	/*0x4F */ 0x004F, // #LATIN CAPITAL LETTER O
	/*0x50 */ 0x0050, // #LATIN CAPITAL LETTER P
	/*0x51 */ 0x0051, // #LATIN CAPITAL LETTER Q
	/*0x52 */ 0x0052, // #LATIN CAPITAL LETTER R
	/*0x53 */ 0x0053, // #LATIN CAPITAL LETTER S
	/*0x54 */ 0x0054, // #LATIN CAPITAL LETTER T
	/*0x55 */ 0x0055, // #LATIN CAPITAL LETTER U
	/*0x56 */ 0x0056, // #LATIN CAPITAL LETTER V
	/*0x57 */ 0x0057, // #LATIN CAPITAL LETTER W
	/*0x58 */ 0x0058, // #LATIN CAPITAL LETTER X
	/*0x59 */ 0x0059, // #LATIN CAPITAL LETTER Y
	/*0x5A */ 0x005A, // #LATIN CAPITAL LETTER Z
	/*0x5B */ 0x005B, // #LEFT SQUARE BRACKET
	/*0x5C */ 0x005C, // #REVERSE SOLIDUS
	/*0x5D */ 0x005D, // #RIGHT SQUARE BRACKET
	/*0x5E */ 0x005E, // #CIRCUMFLEX ACCENT
	/*0x5F */ 0x005F, // #LOW LINE
	/*0x60 */ 0x0060, // #GRAVE ACCENT
	/*0x61 */ 0x0061, // #LATIN SMALL LETTER A
	/*0x62 */ 0x0062, // #LATIN SMALL LETTER B
	/*0x63 */ 0x0063, // #LATIN SMALL LETTER C
	/*0x64 */ 0x0064, // #LATIN SMALL LETTER D
	/*0x65 */ 0x0065, // #LATIN SMALL LETTER E
	/*0x66 */ 0x0066, // #LATIN SMALL LETTER F
	/*0x67 */ 0x0067, // #LATIN SMALL LETTER G
	/*0x68 */ 0x0068, // #LATIN SMALL LETTER H
	/*0x69 */ 0x0069, // #LATIN SMALL LETTER I
	/*0x6A */ 0x006A, // #LATIN SMALL LETTER J
	/*0x6B */ 0x006B, // #LATIN SMALL LETTER K
	/*0x6C */ 0x006C, // #LATIN SMALL LETTER L
	/*0x6D */ 0x006D, // #LATIN SMALL LETTER M
	/*0x6E */ 0x006E, // #LATIN SMALL LETTER N
	/*0x6F */ 0x006F, // #LATIN SMALL LETTER O
	/*0x70 */ 0x0070, // #LATIN SMALL LETTER P
	/*0x71 */ 0x0071, // #LATIN SMALL LETTER Q
	/*0x72 */ 0x0072, // #LATIN SMALL LETTER R
	/*0x73 */ 0x0073, // #LATIN SMALL LETTER S
	/*0x74 */ 0x0074, // #LATIN SMALL LETTER T
	/*0x75 */ 0x0075, // #LATIN SMALL LETTER U
	/*0x76 */ 0x0076, // #LATIN SMALL LETTER V
	/*0x77 */ 0x0077, // #LATIN SMALL LETTER W
	/*0x78 */ 0x0078, // #LATIN SMALL LETTER X
	/*0x79 */ 0x0079, // #LATIN SMALL LETTER Y
	/*0x7A */ 0x007A, // #LATIN SMALL LETTER Z
	/*0x7B */ 0x007B, // #LEFT CURLY BRACKET
	/*0x7C */ 0x007C, // #VERTICAL LINE
	/*0x7D */ 0x007D, // #RIGHT CURLY BRACKET
	/*0x7E */ 0x007E, // #TILDE
	/*0x7F */ 0x007F, // #DELETE
	/*0x80 */ 0x0402, // #CYRILLIC CAPITAL LETTER DJE
	/*0x81 */ 0x0403, // #CYRILLIC CAPITAL LETTER GJE
	/*0x82 */ 0x201A, // #SINGLE LOW-9 QUOTATION MARK
	/*0x83 */ 0x0453, // #CYRILLIC SMALL LETTER GJE
	/*0x84 */ 0x201E, // #DOUBLE LOW-9 QUOTATION MARK
	/*0x85 */ 0x2026, // #HORIZONTAL ELLIPSIS
	/*0x86 */ 0x2020, // #DAGGER
	/*0x87 */ 0x2021, // #DOUBLE DAGGER
	/*0x88 */ 0x20AC, // #EURO SIGN
	/*0x89 */ 0x2030, // #PER MILLE SIGN
	/*0x8A */ 0x0409, // #CYRILLIC CAPITAL LETTER LJE
	/*0x8B */ 0x2039, // #SINGLE LEFT-POINTING ANGLE QUOTATION MARK
	/*0x8C */ 0x040A, // #CYRILLIC CAPITAL LETTER NJE
	/*0x8D */ 0x040C, // #CYRILLIC CAPITAL LETTER KJE
	/*0x8E */ 0x040B, // #CYRILLIC CAPITAL LETTER TSHE
	/*0x8F */ 0x040F, // #CYRILLIC CAPITAL LETTER DZHE
	/*0x90 */ 0x0452, // #CYRILLIC SMALL LETTER DJE
	/*0x91 */ 0x2018, // #LEFT SINGLE QUOTATION MARK
	/*0x92 */ 0x2019, // #RIGHT SINGLE QUOTATION MARK
	/*0x93 */ 0x201C, // #LEFT DOUBLE QUOTATION MARK
	/*0x94 */ 0x201D, // #RIGHT DOUBLE QUOTATION MARK
	/*0x95 */ 0x2022, // #BULLET
	/*0x96 */ 0x2013, // #EN DASH
	/*0x97 */ 0x2014, // #EM DASH
	/*0x98 */ 0     , // #UNDEFINED
	/*0x99 */ 0x2122, // #TRADE MARK SIGN
	/*0x9A */ 0x0459, // #CYRILLIC SMALL LETTER LJE
	/*0x9B */ 0x203A, // #SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
	/*0x9C */ 0x045A, // #CYRILLIC SMALL LETTER NJE
	/*0x9D */ 0x045C, // #CYRILLIC SMALL LETTER KJE
	/*0x9E */ 0x045B, // #CYRILLIC SMALL LETTER TSHE
	/*0x9F */ 0x045F, // #CYRILLIC SMALL LETTER DZHE
	/*0xA0 */ 0x00A0, // #NO-BREAK SPACE
	/*0xA1 */ 0x040E, // #CYRILLIC CAPITAL LETTER SHORT U
	/*0xA2 */ 0x045E, // #CYRILLIC SMALL LETTER SHORT U
	/*0xA3 */ 0x0408, // #CYRILLIC CAPITAL LETTER JE
	/*0xA4 */ 0x00A4, // #CURRENCY SIGN
	/*0xA5 */ 0x0490, // #CYRILLIC CAPITAL LETTER GHE WITH UPTURN
	/*0xA6 */ 0x00A6, // #BROKEN BAR
	/*0xA7 */ 0x00A7, // #SECTION SIGN
	/*0xA8 */ 0x0401, // #CYRILLIC CAPITAL LETTER IO
	/*0xA9 */ 0x00A9, // #COPYRIGHT SIGN
	/*0xAA */ 0x0404, // #CYRILLIC CAPITAL LETTER UKRAINIAN IE
	/*0xAB */ 0x00AB, // #LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
	/*0xAC */ 0x00AC, // #NOT SIGN
	/*0xAD */ 0x00AD, // #SOFT HYPHEN
	/*0xAE */ 0x00AE, // #REGISTERED SIGN
	/*0xAF */ 0x0407, // #CYRILLIC CAPITAL LETTER YI
	/*0xB0 */ 0x00B0, // #DEGREE SIGN
	/*0xB1 */ 0x00B1, // #PLUS-MINUS SIGN
	/*0xB2 */ 0x0406, // #CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I
	/*0xB3 */ 0x0456, // #CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I
	/*0xB4 */ 0x0491, // #CYRILLIC SMALL LETTER GHE WITH UPTURN
	/*0xB5 */ 0x00B5, // #MICRO SIGN
	/*0xB6 */ 0x00B6, // #PILCROW SIGN
	/*0xB7 */ 0x00B7, // #MIDDLE DOT
	/*0xB8 */ 0x0451, // #CYRILLIC SMALL LETTER IO
	/*0xB9 */ 0x2116, // #NUMERO SIGN
	/*0xBA */ 0x0454, // #CYRILLIC SMALL LETTER UKRAINIAN IE
	/*0xBB */ 0x00BB, // #RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
	/*0xBC */ 0x0458, // #CYRILLIC SMALL LETTER JE
	/*0xBD */ 0x0405, // #CYRILLIC CAPITAL LETTER DZE
	/*0xBE */ 0x0455, // #CYRILLIC SMALL LETTER DZE
	/*0xBF */ 0x0457, // #CYRILLIC SMALL LETTER YI
	/*0xC0 */ 0x0410, // #CYRILLIC CAPITAL LETTER A
	/*0xC1 */ 0x0411, // #CYRILLIC CAPITAL LETTER BE
	/*0xC2 */ 0x0412, // #CYRILLIC CAPITAL LETTER VE
	/*0xC3 */ 0x0413, // #CYRILLIC CAPITAL LETTER GHE
	/*0xC4 */ 0x0414, // #CYRILLIC CAPITAL LETTER DE
	/*0xC5 */ 0x0415, // #CYRILLIC CAPITAL LETTER IE
	/*0xC6 */ 0x0416, // #CYRILLIC CAPITAL LETTER ZHE
	/*0xC7 */ 0x0417, // #CYRILLIC CAPITAL LETTER ZE
	/*0xC8 */ 0x0418, // #CYRILLIC CAPITAL LETTER I
	/*0xC9 */ 0x0419, // #CYRILLIC CAPITAL LETTER SHORT I
	/*0xCA */ 0x041A, // #CYRILLIC CAPITAL LETTER KA
	/*0xCB */ 0x041B, // #CYRILLIC CAPITAL LETTER EL
	/*0xCC */ 0x041C, // #CYRILLIC CAPITAL LETTER EM
	/*0xCD */ 0x041D, // #CYRILLIC CAPITAL LETTER EN
	/*0xCE */ 0x041E, // #CYRILLIC CAPITAL LETTER O
	/*0xCF */ 0x041F, // #CYRILLIC CAPITAL LETTER PE
	/*0xD0 */ 0x0420, // #CYRILLIC CAPITAL LETTER ER
	/*0xD1 */ 0x0421, // #CYRILLIC CAPITAL LETTER ES
	/*0xD2 */ 0x0422, // #CYRILLIC CAPITAL LETTER TE
	/*0xD3 */ 0x0423, // #CYRILLIC CAPITAL LETTER U
	/*0xD4 */ 0x0424, // #CYRILLIC CAPITAL LETTER EF
	/*0xD5 */ 0x0425, // #CYRILLIC CAPITAL LETTER HA
	/*0xD6 */ 0x0426, // #CYRILLIC CAPITAL LETTER TSE
	/*0xD7 */ 0x0427, // #CYRILLIC CAPITAL LETTER CHE
	/*0xD8 */ 0x0428, // #CYRILLIC CAPITAL LETTER SHA
	/*0xD9 */ 0x0429, // #CYRILLIC CAPITAL LETTER SHCHA
	/*0xDA */ 0x042A, // #CYRILLIC CAPITAL LETTER HARD SIGN
	/*0xDB */ 0x042B, // #CYRILLIC CAPITAL LETTER YERU
	/*0xDC */ 0x042C, // #CYRILLIC CAPITAL LETTER SOFT SIGN
	/*0xDD */ 0x042D, // #CYRILLIC CAPITAL LETTER E
	/*0xDE */ 0x042E, // #CYRILLIC CAPITAL LETTER YU
	/*0xDF */ 0x042F, // #CYRILLIC CAPITAL LETTER YA
	/*0xE0 */ 0x0430, // #CYRILLIC SMALL LETTER A
	/*0xE1 */ 0x0431, // #CYRILLIC SMALL LETTER BE
	/*0xE2 */ 0x0432, // #CYRILLIC SMALL LETTER VE
	/*0xE3 */ 0x0433, // #CYRILLIC SMALL LETTER GHE
	/*0xE4 */ 0x0434, // #CYRILLIC SMALL LETTER DE
	/*0xE5 */ 0x0435, // #CYRILLIC SMALL LETTER IE
	/*0xE6 */ 0x0436, // #CYRILLIC SMALL LETTER ZHE
	/*0xE7 */ 0x0437, // #CYRILLIC SMALL LETTER ZE
	/*0xE8 */ 0x0438, // #CYRILLIC SMALL LETTER I
	/*0xE9 */ 0x0439, // #CYRILLIC SMALL LETTER SHORT I
	/*0xEA */ 0x043A, // #CYRILLIC SMALL LETTER KA
	/*0xEB */ 0x043B, // #CYRILLIC SMALL LETTER EL
	/*0xEC */ 0x043C, // #CYRILLIC SMALL LETTER EM
	/*0xED */ 0x043D, // #CYRILLIC SMALL LETTER EN
	/*0xEE */ 0x043E, // #CYRILLIC SMALL LETTER O
	/*0xEF */ 0x043F, // #CYRILLIC SMALL LETTER PE
	/*0xF0 */ 0x0440, // #CYRILLIC SMALL LETTER ER
	/*0xF1 */ 0x0441, // #CYRILLIC SMALL LETTER ES
	/*0xF2 */ 0x0442, // #CYRILLIC SMALL LETTER TE
	/*0xF3 */ 0x0443, // #CYRILLIC SMALL LETTER U
	/*0xF4 */ 0x0444, // #CYRILLIC SMALL LETTER EF
	/*0xF5 */ 0x0445, // #CYRILLIC SMALL LETTER HA
	/*0xF6 */ 0x0446, // #CYRILLIC SMALL LETTER TSE
	/*0xF7 */ 0x0447, // #CYRILLIC SMALL LETTER CHE
	/*0xF8 */ 0x0448, // #CYRILLIC SMALL LETTER SHA
	/*0xF9 */ 0x0449, // #CYRILLIC SMALL LETTER SHCHA
	/*0xFA */ 0x044A, // #CYRILLIC SMALL LETTER HARD SIGN
	/*0xFB */ 0x044B, // #CYRILLIC SMALL LETTER YERU
	/*0xFC */ 0x044C, // #CYRILLIC SMALL LETTER SOFT SIGN
	/*0xFD */ 0x044D, // #CYRILLIC SMALL LETTER E
	/*0xFE */ 0x044E, // #CYRILLIC SMALL LETTER YU
	/*0xFF */ 0x044F // #CYRILLIC SMALL LETTER YA
};

int16_t iso8859[256] = {
	/*0x00*/ 0x0000, // # NULL
	/*0x01*/ 0x0001, // # START OF HEADING
	/*0x02*/ 0x0002, // # START OF TEXT
	/*0x03*/ 0x0003, // # END OF TEXT
	/*0x04*/ 0x0004, // # END OF TRANSMISSION
	/*0x05*/ 0x0005, // # ENQUIRY
	/*0x06*/ 0x0006, // # ACKNOWLEDGE
	/*0x07*/ 0x0007, // # BELL
	/*0x08*/ 0x0008, // # BACKSPACE
	/*0x09*/ 0x0009, // # HORIZONTAL TABULATION
	/*0x0A*/ 0x000A, // # LINE FEED
	/*0x0B*/ 0x000B, // # VERTICAL TABULATION
	/*0x0C*/ 0x000C, // # FORM FEED
	/*0x0D*/ 0x000D, // # CARRIAGE RETURN
	/*0x0E*/ 0x000E, // # SHIFT OUT
	/*0x0F*/ 0x000F, // # SHIFT IN
	/*0x10*/ 0x0010, // # DATA LINK ESCAPE
	/*0x11*/ 0x0011, // # DEVICE CONTROL ONE
	/*0x12*/ 0x0012, // # DEVICE CONTROL TWO
	/*0x13*/ 0x0013, // # DEVICE CONTROL THREE
	/*0x14*/ 0x0014, // # DEVICE CONTROL FOUR
	/*0x15*/ 0x0015, // # NEGATIVE ACKNOWLEDGE
	/*0x16*/ 0x0016, // # SYNCHRONOUS IDLE
	/*0x17*/ 0x0017, // # END OF TRANSMISSION BLOCK
	/*0x18*/ 0x0018, // # CANCEL
	/*0x19*/ 0x0019, // # END OF MEDIUM
	/*0x1A*/ 0x001A, // # SUBSTITUTE
	/*0x1B*/ 0x001B, // # ESCAPE
	/*0x1C*/ 0x001C, // # FILE SEPARATOR
	/*0x1D*/ 0x001D, // # GROUP SEPARATOR
	/*0x1E*/ 0x001E, // # RECORD SEPARATOR
	/*0x1F*/ 0x001F, // # UNIT SEPARATOR
	/*0x20*/ 0x0020, // # SPACE
	/*0x21*/ 0x0021, // # EXCLAMATION MARK
	/*0x22*/ 0x0022, // # QUOTATION MARK
	/*0x23*/ 0x0023, // # NUMBER SIGN
	/*0x24*/ 0x0024, // # DOLLAR SIGN
	/*0x25*/ 0x0025, // # PERCENT SIGN
	/*0x26*/ 0x0026, // # AMPERSAND
	/*0x27*/ 0x0027, // # APOSTROPHE
	/*0x28*/ 0x0028, // # LEFT PARENTHESIS
	/*0x29*/ 0x0029, // # RIGHT PARENTHESIS
	/*0x2A*/ 0x002A, // # ASTERISK
	/*0x2B*/ 0x002B, // # PLUS SIGN
	/*0x2C*/ 0x002C, // # COMMA
	/*0x2D*/ 0x002D, // # HYPHEN-MINUS
	/*0x2E*/ 0x002E, // # FULL STOP
	/*0x2F*/ 0x002F, // # SOLIDUS
	/*0x30*/ 0x0030, // # DIGIT ZERO
	/*0x31*/ 0x0031, // # DIGIT ONE
	/*0x32*/ 0x0032, // # DIGIT TWO
	/*0x33*/ 0x0033, // # DIGIT THREE
	/*0x34*/ 0x0034, // # DIGIT FOUR
	/*0x35*/ 0x0035, // # DIGIT FIVE
	/*0x36*/ 0x0036, // # DIGIT SIX
	/*0x37*/ 0x0037, // # DIGIT SEVEN
	/*0x38*/ 0x0038, // # DIGIT EIGHT
	/*0x39*/ 0x0039, // # DIGIT NINE
	/*0x3A*/ 0x003A, // # COLON
	/*0x3B*/ 0x003B, // # SEMICOLON
	/*0x3C*/ 0x003C, // # LESS-THAN SIGN
	/*0x3D*/ 0x003D, // # EQUALS SIGN
	/*0x3E*/ 0x003E, // # GREATER-THAN SIGN
	/*0x3F*/ 0x003F, // # QUESTION MARK
	/*0x40*/ 0x0040, // # COMMERCIAL AT
	/*0x41*/ 0x0041, // # LATIN CAPITAL LETTER A
	/*0x42*/ 0x0042, // # LATIN CAPITAL LETTER B
	/*0x43*/ 0x0043, // # LATIN CAPITAL LETTER C
	/*0x44*/ 0x0044, // # LATIN CAPITAL LETTER D
	/*0x45*/ 0x0045, // # LATIN CAPITAL LETTER E
	/*0x46*/ 0x0046, // # LATIN CAPITAL LETTER F
	/*0x47*/ 0x0047, // # LATIN CAPITAL LETTER G
	/*0x48*/ 0x0048, // # LATIN CAPITAL LETTER H
	/*0x49*/ 0x0049, // # LATIN CAPITAL LETTER I
	/*0x4A*/ 0x004A, // # LATIN CAPITAL LETTER J
	/*0x4B*/ 0x004B, // # LATIN CAPITAL LETTER K
	/*0x4C*/ 0x004C, // # LATIN CAPITAL LETTER L
	/*0x4D*/ 0x004D, // # LATIN CAPITAL LETTER M
	/*0x4E*/ 0x004E, // # LATIN CAPITAL LETTER N
	/*0x4F*/ 0x004F, // # LATIN CAPITAL LETTER O
	/*0x50*/ 0x0050, // # LATIN CAPITAL LETTER P
	/*0x51*/ 0x0051, // # LATIN CAPITAL LETTER Q
	/*0x52*/ 0x0052, // # LATIN CAPITAL LETTER R
	/*0x53*/ 0x0053, // # LATIN CAPITAL LETTER S
	/*0x54*/ 0x0054, // # LATIN CAPITAL LETTER T
	/*0x55*/ 0x0055, // # LATIN CAPITAL LETTER U
	/*0x56*/ 0x0056, // # LATIN CAPITAL LETTER V
	/*0x57*/ 0x0057, // # LATIN CAPITAL LETTER W
	/*0x58*/ 0x0058, // # LATIN CAPITAL LETTER X
	/*0x59*/ 0x0059, // # LATIN CAPITAL LETTER Y
	/*0x5A*/ 0x005A, // # LATIN CAPITAL LETTER Z
	/*0x5B*/ 0x005B, // # LEFT SQUARE BRACKET
	/*0x5C*/ 0x005C, // # REVERSE SOLIDUS
	/*0x5D*/ 0x005D, // # RIGHT SQUARE BRACKET
	/*0x5E*/ 0x005E, // # CIRCUMFLEX ACCENT
	/*0x5F*/ 0x005F, // # LOW LINE
	/*0x60*/ 0x0060, // # GRAVE ACCENT
	/*0x61*/ 0x0061, // # LATIN SMALL LETTER A
	/*0x62*/ 0x0062, // # LATIN SMALL LETTER B
	/*0x63*/ 0x0063, // # LATIN SMALL LETTER C
	/*0x64*/ 0x0064, // # LATIN SMALL LETTER D
	/*0x65*/ 0x0065, // # LATIN SMALL LETTER E
	/*0x66*/ 0x0066, // # LATIN SMALL LETTER F
	/*0x67*/ 0x0067, // # LATIN SMALL LETTER G
	/*0x68*/ 0x0068, // # LATIN SMALL LETTER H
	/*0x69*/ 0x0069, // # LATIN SMALL LETTER I
	/*0x6A*/ 0x006A, // # LATIN SMALL LETTER J
	/*0x6B*/ 0x006B, // # LATIN SMALL LETTER K
	/*0x6C*/ 0x006C, // # LATIN SMALL LETTER L
	/*0x6D*/ 0x006D, // # LATIN SMALL LETTER M
	/*0x6E*/ 0x006E, // # LATIN SMALL LETTER N
	/*0x6F*/ 0x006F, // # LATIN SMALL LETTER O
	/*0x70*/ 0x0070, // # LATIN SMALL LETTER P
	/*0x71*/ 0x0071, // # LATIN SMALL LETTER Q
	/*0x72*/ 0x0072, // # LATIN SMALL LETTER R
	/*0x73*/ 0x0073, // # LATIN SMALL LETTER S
	/*0x74*/ 0x0074, // # LATIN SMALL LETTER T
	/*0x75*/ 0x0075, // # LATIN SMALL LETTER U
	/*0x76*/ 0x0076, // # LATIN SMALL LETTER V
	/*0x77*/ 0x0077, // # LATIN SMALL LETTER W
	/*0x78*/ 0x0078, // # LATIN SMALL LETTER X
	/*0x79*/ 0x0079, // # LATIN SMALL LETTER Y
	/*0x7A*/ 0x007A, // # LATIN SMALL LETTER Z
	/*0x7B*/ 0x007B, // # LEFT CURLY BRACKET
	/*0x7C*/ 0x007C, // # VERTICAL LINE
	/*0x7D*/ 0x007D, // # RIGHT CURLY BRACKET
	/*0x7E*/ 0x007E, // # TILDE
	/*0x7F*/ 0x007F, // # DELETE
	/*0x80*/ 0x0080, // # <control>
	/*0x81*/ 0x0081, // # <control>
	/*0x82*/ 0x0082, // # <control>
	/*0x83*/ 0x0083, // # <control>
	/*0x84*/ 0x0084, // # <control>
	/*0x85*/ 0x0085, // # <control>
	/*0x86*/ 0x0086, // # <control>
	/*0x87*/ 0x0087, // # <control>
	/*0x88*/ 0x0088, // # <control>
	/*0x89*/ 0x0089, // # <control>
	/*0x8A*/ 0x008A, // # <control>
	/*0x8B*/ 0x008B, // # <control>
	/*0x8C*/ 0x008C, // # <control>
	/*0x8D*/ 0x008D, // # <control>
	/*0x8E*/ 0x008E, // # <control>
	/*0x8F*/ 0x008F, // # <control>
	/*0x90*/ 0x0090, // # <control>
	/*0x91*/ 0x0091, // # <control>
	/*0x92*/ 0x0092, // # <control>
	/*0x93*/ 0x0093, // # <control>
	/*0x94*/ 0x0094, // # <control>
	/*0x95*/ 0x0095, // # <control>
	/*0x96*/ 0x0096, // # <control>
	/*0x97*/ 0x0097, // # <control>
	/*0x98*/ 0x0098, // # <control>
	/*0x99*/ 0x0099, // # <control>
	/*0x9A*/ 0x009A, // # <control>
	/*0x9B*/ 0x009B, // # <control>
	/*0x9C*/ 0x009C, // # <control>
	/*0x9D*/ 0x009D, // # <control>
	/*0x9E*/ 0x009E, // # <control>
	/*0x9F*/ 0x009F, // # <control>
	/*0xA0*/ 0x00A0, // # NO-BREAK SPACE
	/*0xA1*/ 0x0401, // # CYRILLIC CAPITAL LETTER IO
	/*0xA2*/ 0x0402, // # CYRILLIC CAPITAL LETTER DJE
	/*0xA3*/ 0x0403, // # CYRILLIC CAPITAL LETTER GJE
	/*0xA4*/ 0x0404, // # CYRILLIC CAPITAL LETTER UKRAINIAN IE
	/*0xA5*/ 0x0405, // # CYRILLIC CAPITAL LETTER DZE
	/*0xA6*/ 0x0406, // # CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I
	/*0xA7*/ 0x0407, // # CYRILLIC CAPITAL LETTER YI
	/*0xA8*/ 0x0408, // # CYRILLIC CAPITAL LETTER JE
	/*0xA9*/ 0x0409, // # CYRILLIC CAPITAL LETTER LJE
	/*0xAA*/ 0x040A, // # CYRILLIC CAPITAL LETTER NJE
	/*0xAB*/ 0x040B, // # CYRILLIC CAPITAL LETTER TSHE
	/*0xAC*/ 0x040C, // # CYRILLIC CAPITAL LETTER KJE
	/*0xAD*/ 0x00AD, // # SOFT HYPHEN
	/*0xAE*/ 0x040E, // # CYRILLIC CAPITAL LETTER SHORT U
	/*0xAF*/ 0x040F, // # CYRILLIC CAPITAL LETTER DZHE
	/*0xB0*/ 0x0410, // # CYRILLIC CAPITAL LETTER A
	/*0xB1*/ 0x0411, // # CYRILLIC CAPITAL LETTER BE
	/*0xB2*/ 0x0412, // # CYRILLIC CAPITAL LETTER VE
	/*0xB3*/ 0x0413, // # CYRILLIC CAPITAL LETTER GHE
	/*0xB4*/ 0x0414, // # CYRILLIC CAPITAL LETTER DE
	/*0xB5*/ 0x0415, // # CYRILLIC CAPITAL LETTER IE
	/*0xB6*/ 0x0416, // # CYRILLIC CAPITAL LETTER ZHE
	/*0xB7*/ 0x0417, // # CYRILLIC CAPITAL LETTER ZE
	/*0xB8*/ 0x0418, // # CYRILLIC CAPITAL LETTER I
	/*0xB9*/ 0x0419, // # CYRILLIC CAPITAL LETTER SHORT I
	/*0xBA*/ 0x041A, // # CYRILLIC CAPITAL LETTER KA
	/*0xBB*/ 0x041B, // # CYRILLIC CAPITAL LETTER EL
	/*0xBC*/ 0x041C, // # CYRILLIC CAPITAL LETTER EM
	/*0xBD*/ 0x041D, // # CYRILLIC CAPITAL LETTER EN
	/*0xBE*/ 0x041E, // # CYRILLIC CAPITAL LETTER O
	/*0xBF*/ 0x041F, // # CYRILLIC CAPITAL LETTER PE
	/*0xC0*/ 0x0420, // # CYRILLIC CAPITAL LETTER ER
	/*0xC1*/ 0x0421, // # CYRILLIC CAPITAL LETTER ES
	/*0xC2*/ 0x0422, // # CYRILLIC CAPITAL LETTER TE
	/*0xC3*/ 0x0423, // # CYRILLIC CAPITAL LETTER U
	/*0xC4*/ 0x0424, // # CYRILLIC CAPITAL LETTER EF
	/*0xC5*/ 0x0425, // # CYRILLIC CAPITAL LETTER HA
	/*0xC6*/ 0x0426, // # CYRILLIC CAPITAL LETTER TSE
	/*0xC7*/ 0x0427, // # CYRILLIC CAPITAL LETTER CHE
	/*0xC8*/ 0x0428, // # CYRILLIC CAPITAL LETTER SHA
	/*0xC9*/ 0x0429, // # CYRILLIC CAPITAL LETTER SHCHA
	/*0xCA*/ 0x042A, // # CYRILLIC CAPITAL LETTER HARD SIGN
	/*0xCB*/ 0x042B, // # CYRILLIC CAPITAL LETTER YERU
	/*0xCC*/ 0x042C, // # CYRILLIC CAPITAL LETTER SOFT SIGN
	/*0xCD*/ 0x042D, // # CYRILLIC CAPITAL LETTER E
	/*0xCE*/ 0x042E, // # CYRILLIC CAPITAL LETTER YU
	/*0xCF*/ 0x042F, // # CYRILLIC CAPITAL LETTER YA
	/*0xD0*/ 0x0430, // # CYRILLIC SMALL LETTER A
	/*0xD1*/ 0x0431, // # CYRILLIC SMALL LETTER BE
	/*0xD2*/ 0x0432, // # CYRILLIC SMALL LETTER VE
	/*0xD3*/ 0x0433, // # CYRILLIC SMALL LETTER GHE
	/*0xD4*/ 0x0434, // # CYRILLIC SMALL LETTER DE
	/*0xD5*/ 0x0435, // # CYRILLIC SMALL LETTER IE
	/*0xD6*/ 0x0436, // # CYRILLIC SMALL LETTER ZHE
	/*0xD7*/ 0x0437, // # CYRILLIC SMALL LETTER ZE
	/*0xD8*/ 0x0438, // # CYRILLIC SMALL LETTER I
	/*0xD9*/ 0x0439, // # CYRILLIC SMALL LETTER SHORT I
	/*0xDA*/ 0x043A, // # CYRILLIC SMALL LETTER KA
	/*0xDB*/ 0x043B, // # CYRILLIC SMALL LETTER EL
	/*0xDC*/ 0x043C, // # CYRILLIC SMALL LETTER EM
	/*0xDD*/ 0x043D, // # CYRILLIC SMALL LETTER EN
	/*0xDE*/ 0x043E, // # CYRILLIC SMALL LETTER O
	/*0xDF*/ 0x043F, // # CYRILLIC SMALL LETTER PE
	/*0xE0*/ 0x0440, // # CYRILLIC SMALL LETTER ER
	/*0xE1*/ 0x0441, // # CYRILLIC SMALL LETTER ES
	/*0xE2*/ 0x0442, // # CYRILLIC SMALL LETTER TE
	/*0xE3*/ 0x0443, // # CYRILLIC SMALL LETTER U
	/*0xE4*/ 0x0444, // # CYRILLIC SMALL LETTER EF
	/*0xE5*/ 0x0445, // # CYRILLIC SMALL LETTER HA
	/*0xE6*/ 0x0446, // # CYRILLIC SMALL LETTER TSE
	/*0xE7*/ 0x0447, // # CYRILLIC SMALL LETTER CHE
	/*0xE8*/ 0x0448, // # CYRILLIC SMALL LETTER SHA
	/*0xE9*/ 0x0449, // # CYRILLIC SMALL LETTER SHCHA
	/*0xEA*/ 0x044A, // # CYRILLIC SMALL LETTER HARD SIGN
	/*0xEB*/ 0x044B, // # CYRILLIC SMALL LETTER YERU
	/*0xEC*/ 0x044C, // # CYRILLIC SMALL LETTER SOFT SIGN
	/*0xED*/ 0x044D, // # CYRILLIC SMALL LETTER E
	/*0xEE*/ 0x044E, // # CYRILLIC SMALL LETTER YU
	/*0xEF*/ 0x044F, // # CYRILLIC SMALL LETTER YA
	/*0xF0*/ 0x2116, // # NUMERO SIGN
	/*0xF1*/ 0x0451, // # CYRILLIC SMALL LETTER IO
	/*0xF2*/ 0x0452, // # CYRILLIC SMALL LETTER DJE
	/*0xF3*/ 0x0453, // # CYRILLIC SMALL LETTER GJE
	/*0xF4*/ 0x0454, // # CYRILLIC SMALL LETTER UKRAINIAN IE
	/*0xF5*/ 0x0455, // # CYRILLIC SMALL LETTER DZE
	/*0xF6*/ 0x0456, // # CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I
	/*0xF7*/ 0x0457, // # CYRILLIC SMALL LETTER YI
	/*0xF8*/ 0x0458, // # CYRILLIC SMALL LETTER JE
	/*0xF9*/ 0x0459, // # CYRILLIC SMALL LETTER LJE
	/*0xFA*/ 0x045A, // # CYRILLIC SMALL LETTER NJE
	/*0xFB*/ 0x045B, // # CYRILLIC SMALL LETTER TSHE
	/*0xFC*/ 0x045C, // # CYRILLIC SMALL LETTER KJE
	/*0xFD*/ 0x00A7, // # SECTION SIGN
	/*0xFE*/ 0x045E, // # CYRILLIC SMALL LETTER SHORT U
	/*0xFF*/ 0x045F // # CYRILLIC SMALL LETTER DZHE
};

int16_t koi8[256] = {
	/*0x00*/ 0x0000, // # NULL
	/*0x01*/ 0x0001, // # START OF HEADING
	/*0x02*/ 0x0002, // # START OF TEXT
	/*0x03*/ 0x0003, // # END OF TEXT
	/*0x04*/ 0x0004, // # END OF TRANSMISSION
	/*0x05*/ 0x0005, // # ENQUIRY
	/*0x06*/ 0x0006, // # ACKNOWLEDGE
	/*0x07*/ 0x0007, // # BELL
	/*0x08*/ 0x0008, // # BACKSPACE
	/*0x09*/ 0x0009, // # HORIZONTAL TABULATION
	/*0x0A*/ 0x000A, // # LINE FEED
	/*0x0B*/ 0x000B, // # VERTICAL TABULATION
	/*0x0C*/ 0x000C, // # FORM FEED
	/*0x0D*/ 0x000D, // # CARRIAGE RETURN
	/*0x0E*/ 0x000E, // # SHIFT OUT
	/*0x0F*/ 0x000F, // # SHIFT IN
	/*0x10*/ 0x0010, // # DATA LINK ESCAPE
	/*0x11*/ 0x0011, // # DEVICE CONTROL ONE
	/*0x12*/ 0x0012, // # DEVICE CONTROL TWO
	/*0x13*/ 0x0013, // # DEVICE CONTROL THREE
	/*0x14*/ 0x0014, // # DEVICE CONTROL FOUR
	/*0x15*/ 0x0015, // # NEGATIVE ACKNOWLEDGE
	/*0x16*/ 0x0016, // # SYNCHRONOUS IDLE
	/*0x17*/ 0x0017, // # END OF TRANSMISSION BLOCK
	/*0x18*/ 0x0018, // # CANCEL
	/*0x19*/ 0x0019, // # END OF MEDIUM
	/*0x1A*/ 0x001A, // # SUBSTITUTE
	/*0x1B*/ 0x001B, // # ESCAPE
	/*0x1C*/ 0x001C, // # FILE SEPARATOR
	/*0x1D*/ 0x001D, // # GROUP SEPARATOR
	/*0x1E*/ 0x001E, // # RECORD SEPARATOR
	/*0x1F*/ 0x001F, // # UNIT SEPARATOR
	/*0x20*/ 0x0020, // # SPACE
	/*0x21*/ 0x0021, // # EXCLAMATION MARK
	/*0x22*/ 0x0022, // # QUOTATION MARK
	/*0x23*/ 0x0023, // # NUMBER SIGN
	/*0x24*/ 0x0024, // # DOLLAR SIGN
	/*0x25*/ 0x0025, // # PERCENT SIGN
	/*0x26*/ 0x0026, // # AMPERSAND
	/*0x27*/ 0x0027, // # APOSTROPHE
	/*0x28*/ 0x0028, // # LEFT PARENTHESIS
	/*0x29*/ 0x0029, // # RIGHT PARENTHESIS
	/*0x2A*/ 0x002A, // # ASTERISK
	/*0x2B*/ 0x002B, // # PLUS SIGN
	/*0x2C*/ 0x002C, // # COMMA
	/*0x2D*/ 0x002D, // # HYPHEN-MINUS
	/*0x2E*/ 0x002E, // # FULL STOP
	/*0x2F*/ 0x002F, // # SOLIDUS
	/*0x30*/ 0x0030, // # DIGIT ZERO
	/*0x31*/ 0x0031, // # DIGIT ONE
	/*0x32*/ 0x0032, // # DIGIT TWO
	/*0x33*/ 0x0033, // # DIGIT THREE
	/*0x34*/ 0x0034, // # DIGIT FOUR
	/*0x35*/ 0x0035, // # DIGIT FIVE
	/*0x36*/ 0x0036, // # DIGIT SIX
	/*0x37*/ 0x0037, // # DIGIT SEVEN
	/*0x38*/ 0x0038, // # DIGIT EIGHT
	/*0x39*/ 0x0039, // # DIGIT NINE
	/*0x3A*/ 0x003A, // # COLON
	/*0x3B*/ 0x003B, // # SEMICOLON
	/*0x3C*/ 0x003C, // # LESS-THAN SIGN
	/*0x3D*/ 0x003D, // # EQUALS SIGN
	/*0x3E*/ 0x003E, // # GREATER-THAN SIGN
	/*0x3F*/ 0x003F, // # QUESTION MARK
	/*0x40*/ 0x0040, // # COMMERCIAL AT
	/*0x41*/ 0x0041, // # LATIN CAPITAL LETTER A
	/*0x42*/ 0x0042, // # LATIN CAPITAL LETTER B
	/*0x43*/ 0x0043, // # LATIN CAPITAL LETTER C
	/*0x44*/ 0x0044, // # LATIN CAPITAL LETTER D
	/*0x45*/ 0x0045, // # LATIN CAPITAL LETTER E
	/*0x46*/ 0x0046, // # LATIN CAPITAL LETTER F
	/*0x47*/ 0x0047, // # LATIN CAPITAL LETTER G
	/*0x48*/ 0x0048, // # LATIN CAPITAL LETTER H
	/*0x49*/ 0x0049, // # LATIN CAPITAL LETTER I
	/*0x4A*/ 0x004A, // # LATIN CAPITAL LETTER J
	/*0x4B*/ 0x004B, // # LATIN CAPITAL LETTER K
	/*0x4C*/ 0x004C, // # LATIN CAPITAL LETTER L
	/*0x4D*/ 0x004D, // # LATIN CAPITAL LETTER M
	/*0x4E*/ 0x004E, // # LATIN CAPITAL LETTER N
	/*0x4F*/ 0x004F, // # LATIN CAPITAL LETTER O
	/*0x50*/ 0x0050, // # LATIN CAPITAL LETTER P
	/*0x51*/ 0x0051, // # LATIN CAPITAL LETTER Q
	/*0x52*/ 0x0052, // # LATIN CAPITAL LETTER R
	/*0x53*/ 0x0053, // # LATIN CAPITAL LETTER S
	/*0x54*/ 0x0054, // # LATIN CAPITAL LETTER T
	/*0x55*/ 0x0055, // # LATIN CAPITAL LETTER U
	/*0x56*/ 0x0056, // # LATIN CAPITAL LETTER V
	/*0x57*/ 0x0057, // # LATIN CAPITAL LETTER W
	/*0x58*/ 0x0058, // # LATIN CAPITAL LETTER X
	/*0x59*/ 0x0059, // # LATIN CAPITAL LETTER Y
	/*0x5A*/ 0x005A, // # LATIN CAPITAL LETTER Z
	/*0x5B*/ 0x005B, // # LEFT SQUARE BRACKET
	/*0x5C*/ 0x005C, // # REVERSE SOLIDUS
	/*0x5D*/ 0x005D, // # RIGHT SQUARE BRACKET
	/*0x5E*/ 0x005E, // # CIRCUMFLEX ACCENT
	/*0x5F*/ 0x005F, // # LOW LINE
	/*0x60*/ 0x0060, // # GRAVE ACCENT
	/*0x61*/ 0x0061, // # LATIN SMALL LETTER A
	/*0x62*/ 0x0062, // # LATIN SMALL LETTER B
	/*0x63*/ 0x0063, // # LATIN SMALL LETTER C
	/*0x64*/ 0x0064, // # LATIN SMALL LETTER D
	/*0x65*/ 0x0065, // # LATIN SMALL LETTER E
	/*0x66*/ 0x0066, // # LATIN SMALL LETTER F
	/*0x67*/ 0x0067, // # LATIN SMALL LETTER G
	/*0x68*/ 0x0068, // # LATIN SMALL LETTER H
	/*0x69*/ 0x0069, // # LATIN SMALL LETTER I
	/*0x6A*/ 0x006A, // # LATIN SMALL LETTER J
	/*0x6B*/ 0x006B, // # LATIN SMALL LETTER K
	/*0x6C*/ 0x006C, // # LATIN SMALL LETTER L
	/*0x6D*/ 0x006D, // # LATIN SMALL LETTER M
	/*0x6E*/ 0x006E, // # LATIN SMALL LETTER N
	/*0x6F*/ 0x006F, // # LATIN SMALL LETTER O
	/*0x70*/ 0x0070, // # LATIN SMALL LETTER P
	/*0x71*/ 0x0071, // # LATIN SMALL LETTER Q
	/*0x72*/ 0x0072, // # LATIN SMALL LETTER R
	/*0x73*/ 0x0073, // # LATIN SMALL LETTER S
	/*0x74*/ 0x0074, // # LATIN SMALL LETTER T
	/*0x75*/ 0x0075, // # LATIN SMALL LETTER U
	/*0x76*/ 0x0076, // # LATIN SMALL LETTER V
	/*0x77*/ 0x0077, // # LATIN SMALL LETTER W
	/*0x78*/ 0x0078, // # LATIN SMALL LETTER X
	/*0x79*/ 0x0079, // # LATIN SMALL LETTER Y
	/*0x7A*/ 0x007A, // # LATIN SMALL LETTER Z
	/*0x7B*/ 0x007B, // # LEFT CURLY BRACKET
	/*0x7C*/ 0x007C, // # VERTICAL LINE
	/*0x7D*/ 0x007D, // # RIGHT CURLY BRACKET
	/*0x7E*/ 0x007E, // # TILDE
	/*0x7F*/ 0x007F, // # DELETE
	/*0x80*/ 0x2500, // # BOX DRAWINGS LIGHT HORIZONTAL
	/*0x81*/ 0x2502, // # BOX DRAWINGS LIGHT VERTICAL
	/*0x82*/ 0x250C, // # BOX DRAWINGS LIGHT DOWN AND RIGHT
	/*0x83*/ 0x2510, // # BOX DRAWINGS LIGHT DOWN AND LEFT
	/*0x84*/ 0x2514, // # BOX DRAWINGS LIGHT UP AND RIGHT
	/*0x85*/ 0x2518, // # BOX DRAWINGS LIGHT UP AND LEFT
	/*0x86*/ 0x251C, // # BOX DRAWINGS LIGHT VERTICAL AND RIGHT
	/*0x87*/ 0x2524, // # BOX DRAWINGS LIGHT VERTICAL AND LEFT
	/*0x88*/ 0x252C, // # BOX DRAWINGS LIGHT DOWN AND HORIZONTAL
	/*0x89*/ 0x2534, // # BOX DRAWINGS LIGHT UP AND HORIZONTAL
	/*0x8A*/ 0x253C, // # BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL
	/*0x8B*/ 0x2580, // # UPPER HALF BLOCK
	/*0x8C*/ 0x2584, // # LOWER HALF BLOCK
	/*0x8D*/ 0x2588, // # FULL BLOCK
	/*0x8E*/ 0x258C, // # LEFT HALF BLOCK
	/*0x8F*/ 0x2590, // # RIGHT HALF BLOCK
	/*0x90*/ 0x2591, // # LIGHT SHADE
	/*0x91*/ 0x2592, // # MEDIUM SHADE
	/*0x92*/ 0x2593, // # DARK SHADE
	/*0x93*/ 0x2320, // # TOP HALF INTEGRAL
	/*0x94*/ 0x25A0, // # BLACK SQUARE
	/*0x95*/ 0x2219, // # BULLET OPERATOR
	/*0x96*/ 0x221A, // # SQUARE ROOT
	/*0x97*/ 0x2248, // # ALMOST EQUAL TO
	/*0x98*/ 0x2264, // # LESS-THAN OR EQUAL TO
	/*0x99*/ 0x2265, // # GREATER-THAN OR EQUAL TO
	/*0x9A*/ 0x00A0, // # NO-BREAK SPACE
	/*0x9B*/ 0x2321, // # BOTTOM HALF INTEGRAL
	/*0x9C*/ 0x00B0, // # DEGREE SIGN
	/*0x9D*/ 0x00B2, // # SUPERSCRIPT TWO
	/*0x9E*/ 0x00B7, // # MIDDLE DOT
	/*0x9F*/ 0x00F7, // # DIVISION SIGN
	/*0xA0*/ 0x2550, // # BOX DRAWINGS DOUBLE HORIZONTAL
	/*0xA1*/ 0x2551, // # BOX DRAWINGS DOUBLE VERTICAL
	/*0xA2*/ 0x2552, // # BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE
	/*0xA3*/ 0x0451, // # CYRILLIC SMALL LETTER IO
	/*0xA4*/ 0x2553, // # BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE
	/*0xA5*/ 0x2554, // # BOX DRAWINGS DOUBLE DOWN AND RIGHT
	/*0xA6*/ 0x2555, // # BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE
	/*0xA7*/ 0x2556, // # BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE
	/*0xA8*/ 0x2557, // # BOX DRAWINGS DOUBLE DOWN AND LEFT
	/*0xA9*/ 0x2558, // # BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE
	/*0xAA*/ 0x2559, // # BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE
	/*0xAB*/ 0x255A, // # BOX DRAWINGS DOUBLE UP AND RIGHT
	/*0xAC*/ 0x255B, // # BOX DRAWINGS UP SINGLE AND LEFT DOUBLE
	/*0xAD*/ 0x255C, // # BOX DRAWINGS UP DOUBLE AND LEFT SINGLE
	/*0xAE*/ 0x255D, // # BOX DRAWINGS DOUBLE UP AND LEFT
	/*0xAF*/ 0x255E, // # BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE
	/*0xB0*/ 0x255F, // # BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE
	/*0xB1*/ 0x2560, // # BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
	/*0xB2*/ 0x2561, // # BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE
	/*0xB3*/ 0x0401, // # CYRILLIC CAPITAL LETTER IO
	/*0xB4*/ 0x2562, // # BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE
	/*0xB5*/ 0x2563, // # BOX DRAWINGS DOUBLE VERTICAL AND LEFT
	/*0xB6*/ 0x2564, // # BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE
	/*0xB7*/ 0x2565, // # BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE
	/*0xB8*/ 0x2566, // # BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL
	/*0xB9*/ 0x2567, // # BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE
	/*0xBA*/ 0x2568, // # BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE
	/*0xBB*/ 0x2569, // # BOX DRAWINGS DOUBLE UP AND HORIZONTAL
	/*0xBC*/ 0x256A, // # BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE
	/*0xBD*/ 0x256B, // # BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE
	/*0xBE*/ 0x256C, // # BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL
	/*0xBF*/ 0x00A9, // # COPYRIGHT SIGN
	/*0xC0*/ 0x044E, // # CYRILLIC SMALL LETTER YU
	/*0xC1*/ 0x0430, // # CYRILLIC SMALL LETTER A
	/*0xC2*/ 0x0431, // # CYRILLIC SMALL LETTER BE
	/*0xC3*/ 0x0446, // # CYRILLIC SMALL LETTER TSE
	/*0xC4*/ 0x0434, // # CYRILLIC SMALL LETTER DE
	/*0xC5*/ 0x0435, // # CYRILLIC SMALL LETTER IE
	/*0xC6*/ 0x0444, // # CYRILLIC SMALL LETTER EF
	/*0xC7*/ 0x0433, // # CYRILLIC SMALL LETTER GHE
	/*0xC8*/ 0x0445, // # CYRILLIC SMALL LETTER HA
	/*0xC9*/ 0x0438, // # CYRILLIC SMALL LETTER I
	/*0xCA*/ 0x0439, // # CYRILLIC SMALL LETTER SHORT I
	/*0xCB*/ 0x043A, // # CYRILLIC SMALL LETTER KA
	/*0xCC*/ 0x043B, // # CYRILLIC SMALL LETTER EL
	/*0xCD*/ 0x043C, // # CYRILLIC SMALL LETTER EM
	/*0xCE*/ 0x043D, // # CYRILLIC SMALL LETTER EN
	/*0xCF*/ 0x043E, // # CYRILLIC SMALL LETTER O
	/*0xD0*/ 0x043F, // # CYRILLIC SMALL LETTER PE
	/*0xD1*/ 0x044F, // # CYRILLIC SMALL LETTER YA
	/*0xD2*/ 0x0440, // # CYRILLIC SMALL LETTER ER
	/*0xD3*/ 0x0441, // # CYRILLIC SMALL LETTER ES
	/*0xD4*/ 0x0442, // # CYRILLIC SMALL LETTER TE
	/*0xD5*/ 0x0443, // # CYRILLIC SMALL LETTER U
	/*0xD6*/ 0x0436, // # CYRILLIC SMALL LETTER ZHE
	/*0xD7*/ 0x0432, // # CYRILLIC SMALL LETTER VE
	/*0xD8*/ 0x044C, // # CYRILLIC SMALL LETTER SOFT SIGN
	/*0xD9*/ 0x044B, // # CYRILLIC SMALL LETTER YERU
	/*0xDA*/ 0x0437, // # CYRILLIC SMALL LETTER ZE
	/*0xDB*/ 0x0448, // # CYRILLIC SMALL LETTER SHA
	/*0xDC*/ 0x044D, // # CYRILLIC SMALL LETTER E
	/*0xDD*/ 0x0449, // # CYRILLIC SMALL LETTER SHCHA
	/*0xDE*/ 0x0447, // # CYRILLIC SMALL LETTER CHE
	/*0xDF*/ 0x044A, // # CYRILLIC SMALL LETTER HARD SIGN
	/*0xE0*/ 0x042E, // # CYRILLIC CAPITAL LETTER YU
	/*0xE1*/ 0x0410, // # CYRILLIC CAPITAL LETTER A
	/*0xE2*/ 0x0411, // # CYRILLIC CAPITAL LETTER BE
	/*0xE3*/ 0x0426, // # CYRILLIC CAPITAL LETTER TSE
	/*0xE4*/ 0x0414, // # CYRILLIC CAPITAL LETTER DE
	/*0xE5*/ 0x0415, // # CYRILLIC CAPITAL LETTER IE
	/*0xE6*/ 0x0424, // # CYRILLIC CAPITAL LETTER EF
	/*0xE7*/ 0x0413, // # CYRILLIC CAPITAL LETTER GHE
	/*0xE8*/ 0x0425, // # CYRILLIC CAPITAL LETTER HA
	/*0xE9*/ 0x0418, // # CYRILLIC CAPITAL LETTER I
	/*0xEA*/ 0x0419, // # CYRILLIC CAPITAL LETTER SHORT I
	/*0xEB*/ 0x041A, // # CYRILLIC CAPITAL LETTER KA
	/*0xEC*/ 0x041B, // # CYRILLIC CAPITAL LETTER EL
	/*0xED*/ 0x041C, // # CYRILLIC CAPITAL LETTER EM
	/*0xEE*/ 0x041D, // # CYRILLIC CAPITAL LETTER EN
	/*0xEF*/ 0x041E, // # CYRILLIC CAPITAL LETTER O
	/*0xF0*/ 0x041F, // # CYRILLIC CAPITAL LETTER PE
	/*0xF1*/ 0x042F, // # CYRILLIC CAPITAL LETTER YA
	/*0xF2*/ 0x0420, // # CYRILLIC CAPITAL LETTER ER
	/*0xF3*/ 0x0421, // # CYRILLIC CAPITAL LETTER ES
	/*0xF4*/ 0x0422, // # CYRILLIC CAPITAL LETTER TE
	/*0xF5*/ 0x0423, // # CYRILLIC CAPITAL LETTER U
	/*0xF6*/ 0x0416, // # CYRILLIC CAPITAL LETTER ZHE
	/*0xF7*/ 0x0412, // # CYRILLIC CAPITAL LETTER VE
	/*0xF8*/ 0x042C, // # CYRILLIC CAPITAL LETTER SOFT SIGN
	/*0xF9*/ 0x042B, // # CYRILLIC CAPITAL LETTER YERU
	/*0xFA*/ 0x0417, // # CYRILLIC CAPITAL LETTER ZE
	/*0xFB*/ 0x0428, // # CYRILLIC CAPITAL LETTER SHA
	/*0xFC*/ 0x042D, // # CYRILLIC CAPITAL LETTER E
	/*0xFD*/ 0x0429, // # CYRILLIC CAPITAL LETTER SHCHA
	/*0xFE*/ 0x0427, // # CYRILLIC CAPITAL LETTER CHE
	/*0xFF*/ 0x042A  // # CYRILLIC CAPITAL LETTER HARD SIGN
};

int16_t* charsets[] = {
	cp1251,
	koi8,
	iso8859,
};


#endif // CHARS_H
