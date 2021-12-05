/*
* Copyright (c) Tzvetan Mikov.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
 */

#include "apple2tc/a2symbols.h"

#include <cstdlib>

// Adapted from: https://github.com/whscullin/apple2js/blob/master/js/symbols.ts
// With the following license:
/*
The MIT License (MIT)

Copyright (c) 2013-2019 Will Scullin

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

struct SymDef {
  unsigned addr;
  const char *name;
};

static const SymDef s_symbols[] = {
#if 0
    { 0x00, "GOWARM" },
    { 0x03, "GOSTROUT" },
    { 0x0A, "USR" },
    { 0x0D, "CHARAC" },
    { 0x0E, "ENDCHR" },
    { 0x0F, "TKN.CNTR" },
    { 0x0F, "EOL.PNTR" },
    { 0x0F, "NUMDIM" },
    { 0x10, "DIMFLG" },
    { 0x11, "VALTYP" },
    { 0x13, "DATAFLG" },
    { 0x13, "GARFLG" },
    { 0x14, "SUBFLG" },
    { 0x15, "INPUTFLG" },
    { 0x16, "CPRMASK" },
    { 0x16, "SIGNFLG" },
    { 0x1A, "HGR.SHAPE" },
    { 0x1C, "HGR.BITS" },
    { 0x1D, "HGR.COUNT" },
    { 0x24, "MON.CH" },
    { 0x26, "MON.GBASL" },
    { 0x27, "MON.GBASH" },
    { 0x2C, "MON.H2" },
    { 0x2D, "MON.V2" },
    { 0x30, "MON.HMASK" },
    { 0x32, "MON.INVFLG" },
    { 0x33, "MON.PROMPT" },
    { 0x3C, "MON.A1L" },
    { 0x3D, "MON.A1H" },
    { 0x3E, "MON.A2L" },
    { 0x3F, "MON.A2H" },
    { 0x50, "LINNUM" },
    { 0x52, "TEMPPT" },
    { 0x53, "LASTPT" },
    { 0x55, "TEMPST" },
    { 0x5E, "INDEX" },
    { 0x60, "DEST" },
    { 0x62, "RESULT" },
    { 0x67, "TXTTAB" },
    { 0x69, "VARTAB" },
    { 0x6B, "ARYTAB" },
    { 0x6D, "STREND" },
    { 0x6F, "FRETOP" },
    { 0x71, "FRESPC" },
    { 0x73, "MEMSIZ" },
    { 0x75, "CURLIN" },
    { 0x77, "OLDLIN" },
    { 0x79, "OLDTEXT" },
    { 0x7B, "DATLIN" },
    { 0x7D, "DATPTR" },
    { 0x7F, "INPTR" },
    { 0x81, "VARNAM" },
    { 0x83, "VARPNT" },
    { 0x85, "FORPNT" },
    { 0x87, "TXPSV" },
    { 0x87, "LASTOP" },
    { 0x89, "CPRTYP" },
    { 0x8A, "TEMP3" },
    { 0x8A, "FNCNAM" },
    { 0x8C, "DSCPTR" },
    { 0x8F, "DSCLEN" },
    { 0x90, "JMPADRS" },
    { 0x91, "LENGTH" },
    { 0x92, "ARG.EXTENSION" },
    { 0x93, "TEMP1" },
    { 0x94, "ARYPNT" },
    { 0x94, "HIGHDS" },
    { 0x96, "HIGHTR" },
    { 0x98, "TEMP2" },
    { 0x99, "TMPEXP" },
    { 0x99, "INDX" },
    { 0x9A, "EXPON" },
    { 0x9B, "DPFLG" },
    { 0x9B, "LOWTR" },
    { 0x9C, "EXPSGN" },
    { 0x9D, "FAC" },
    { 0x9D, "DSCTMP" },
    { 0xA0, "VPNT" },
    { 0xA2, "FAC.SIGN" },
    { 0xA3, "SERLEN" },
    { 0xA4, "SHIFT.SIGN.EXT" },
    { 0xA5, "ARG" },
    { 0xAA, "ARG.SIGN" },
    { 0xAB, "SGNCPR" },
    { 0xAC, "FAC.EXTENSION" },
    { 0xAD, "SERPNT" },
    { 0xAB, "STRNG1" },
    { 0xAD, "STRNG2" },
    { 0xAF, "PRGEND" },
    { 0xB1, "CHRGET" },
    { 0xB7, "CHRGOT" },
    { 0xB8, "TXTPTR" },
    { 0xC9, "RNDSEED" },
    { 0xD0, "HGR.DX" },
    { 0xD2, "HGR.DY" },
    { 0xD3, "HGR.QUADRANT" },
    { 0xD4, "HGR.E" },
    { 0xD6, "LOCK" },
    { 0xD8, "ERRFLG" },
    { 0xDA, "ERRLIN" },
    { 0xDC, "ERRPOS" },
    { 0xDE, "ERRNUM" },
    { 0xDF, "ERRSTK" },
    { 0xE0, "HGR.X" },
    { 0xE2, "HGR.Y" },
    { 0xE4, "HGR.COLOR" },
    { 0xE5, "HGR.HORIZ" },
    { 0xE6, "HGR.PAGE" },
    { 0xE7, "HGR.SCALE" },
    { 0xE8, "HGR.SHAPE.PNTR" },
    { 0xEA, "HGR.COLLISIONS" },
    { 0xF0, "FIRST" },
    { 0xF1, "SPEEDZ" },
    { 0xF2, "TRCFLG" },
    { 0xF3, "FLASH.BIT" },
    { 0xF4, "TXTPSV" },
    { 0xF6, "CURLSV" },
    { 0xF8, "REMSTK" },
    { 0xF9, "HGR.ROTATION" },
    { 0x0100, "STACK" },
    { 0x0200, "INPUT.BUFFER" },
    { 0x03F5, "AMPERSAND.VECTOR" },
#endif
    {0xC000, "KEYBOARD"},
    {0xC001, "80STOREON"},
    {0xC002, "RAMRDOFF"},
    {0xC003, "RAMRDON"},
    {0xC004, "RAMWROFF"},
    {0xC005, "RAMWRON"},
    {0xC006, "INTCXOFF"},
    {0xC007, "INTCXON"},
    {0xC008, "ALTZPOFF"},
    {0xC009, "ALTZPON"},
    {0xC00A, "SLOT3OFF"},
    {0xC00B, "SLOT3ON"},
    {0xC00C, "CLR80VID"},
    {0xC00D, "SET80VID"},
    {0xC00E, "CLRALTCH"},
    {0xC00F, "SETALTCH"},
    {0xC010, "STROBE"},
    {0xC011, "BSRBANK2"},
    {0xC012, "BSRREAD"},
    {0xC013, "RAMRD"},
    {0xC014, "RAMWRT"},
    {0xC015, "INTCXROM"},
    {0xC016, "ALTZP"},
    {0xC017, "SLOT3ROM"},
    {0xC018, "80STRORE"},
    {0xC019, "VERTBLANK"},
    {0xC01A, "RDTEXT"},
    {0xC01B, "RDMIXED"},
    {0xC01C, "RDPAGE2"},
    {0xC01D, "RDHIRES"},
    {0xC01E, "RDALTCH"},
    {0xC01F, "RD80VID"},
    {0xC020, "TAPEOUT"},
    {0xC030, "SPEAKER"},
    {0xC050, "CLRTEXT"},
    {0xC051, "SETTEXT"},
    {0xC052, "CLRMIXED"},
    {0xC053, "SETMIXED"},
    {0xC054, "PAGE1"},
    {0xC055, "PAGE2"},
    {0xC056, "CLRHIRS"},
    {0xC057, "SETHIRES"},
    {0xC058, "CLRAN0"},
    {0xC059, "SETAN0"},
    {0xC05A, "CLRAN1"},
    {0xC05B, "SETAN1"},
    {0xC05C, "CLRAN2"},
    {0xC05D, "SETAN2"},
    {0xC05E, "CLRAN3"},
    {0xC05F, "SETAN3"},
    {0xC060, "TAPEIN"},
    {0xC061, "PB0"},
    {0xC062, "PB1"},
    {0xC063, "PB2"},
    {0xC064, "PADDLE0"},
    {0xC065, "PADDLE1"},
    {0xC066, "PADDLE2"},
    {0xC067, "PADDLE3"},
    {0xC070, "PDLTRIG"},
    {0xC07E, "SETIOUDIS"},
    {0xC07F, "CLRIOUDIS"},
    {0xC080, "RDBSR2"},
    {0xC081, "WRBSR2"},
    {0xC082, "OFFBSR2"},
    {0xC083, "RWBSR2"},
    {0xC084, "RDBSR2"},
    {0xC085, "WRBSR2"},
    {0xC086, "OFFBSR2"},
    {0xC087, "RWBSR2"},
    {0xC088, "RDBSR1"},
    {0xC089, "WRBSR1"},
    {0xC08A, "OFFBSR1"},
    {0xC08B, "RWBSR1"},
    {0xC08C, "RDBSR1"},
    {0xC08D, "WRBSR1"},
    {0xC08E, "OFFBSR1"},
    {0xC08F, "RWBSR1"},
    {0xD000, "TOKEN.ADDRESS.TABLE"},
    {0xD080, "UNFNC"},
    {0xD0B2, "MATHTBL"},
    {0xD0C7, "M.NEG"},
    {0xD0CA, "M.EQU"},
    {0xD0CD, "M.REL"},
    {0xD0D0, "TOKEN.NAME.TABLE"},
    {0xD260, "ERROR.MESSAGES"},
    {0xD350, "QT.ERROR"},
    {0xD358, "QT.IN"},
    {0xD35D, "QT.BREAK"},
    {0xD365, "GTFORPNT"},
    {0xD393, "BLTU"},
    {0xD39A, "BLTU2"},
    {0xD3D6, "CHKMEM"},
    {0xD3E3, "REASON"},
    {0xD410, "MEMERR"},
    {0xD412, "ERROR"},
    {0xD431, "PRINT.ERROR.LINNUM"},
    {0xD43C, "RESTART"},
    {0xD45C, "NUMBERED.LINE"},
    {0xD4B5, "PUT.NEW.LINE"},
    {0xD4F2, "FIX.LINKS"},
    {0xD52C, "INLIN"},
    {0xD52E, "INLIN2"},
    {0xD553, "INCHR"},
    {0xD559, "PARSE.INPUT.LINE"},
    {0xD56C, "PARSE"},
    {0xD61A, "FNDLIN"},
    {0xD61E, "FL1"},
    {0xD648, "RTS.1"},
    {0xD649, "NEW"},
    {0xD64B, "SCRTCH"},
    {0xD665, "SETPTRS"},
    {0xD66A, "CLEAR"},
    {0xD66C, "CLEARC"},
    {0xD683, "STKINI"},
    {0xD696, "RTS.2"},
    {0xD697, "STXTPT"},
    {0xD6A5, "LIST"},
    {0xD6DA, "LIST.0"},
    {0xD6FE, "LIST.1"},
    {0xD702, "LIST.2"},
    {0xD724, "LIST.3"},
    {0xD72C, "GETCHR"},
    {0xD734, "LIST.4"},
    {0xD766, "FOR"},
    {0xD7AF, "STEP"},
    {0xD7D2, "NEWSTT"},
    {0xD805, "TRACE."},
    {0xD826, "GOEND"},
    {0xD828, "EXECUTE.STATEMENT"},
    {0xD82A, "EXECUTE.STATEMENT.1"},
    {0xD842, "COLON."},
    {0xD846, "SYNERR.1"},
    {0xD849, "RESTORE"},
    {0xD853, "SETDA"},
    {0xD857, "RTS.3"},
    {0xD858, "ISCNTC"},
    {0xD863, "CONTROL.C.TYPED"},
    {0xD86E, "STOP"},
    {0xD870, "END"},
    {0xD871, "END2"},
    {0xD88A, "END4"},
    {0xD896, "CONT"},
    {0xD8AF, "RTS.4"},
    {0xD8B0, "SAVE"},
    {0xD8C9, "LOAD"},
    {0xD8F0, "VARTIO"},
    {0xD901, "PROGIO"},
    {0xD912, "RUN"},
    {0xD921, "GOSUB"},
    {0xD935, "GO.TO.LINE"},
    {0xD93E, "GOTO"},
    {0xD96A, "RTS.5"},
    {0xD96B, "POP"},
    {0xD97C, "UNDERR"},
    {0xD981, "SYNERR.2"},
    {0xD984, "RETURN"},
    {0xD995, "DATA"},
    {0xD998, "ADDON"},
    {0xD9A2, "RTS.6"},
    {0xD9A3, "DATAN"},
    {0xD9A6, "REMN"},
    {0xD9C5, "PULL3"},
    {0xD9C9, "IF"},
    {0xD9DC, "REM"},
    {0xD9E1, "IF.TRUE"},
    {0xD9EC, "ONGOTO"},
    {0xD9F4, "ON.1"},
    {0xD9F8, "ON.2"},
    {0xDA0B, "RTS.7"},
    {0xDA0C, "LINGET"},
    {0xDA46, "LET"},
    {0xDA63, "LET2"},
    {0xDA7A, "LET.STRING"},
    {0xDA7B, "PUTSTR"},
    {0xDACF, "PR.STRING"},
    {0xDAD5, "PRINT"},
    {0xDAD7, "PRINT2"},
    {0xDAFB, "CRDO"},
    {0xDB00, "NEGATE"},
    {0xDB02, "RTS.8"},
    {0xDB03, "PR.COMMA"},
    {0xDB16, "PR.TAB.OR.SPC"},
    {0xDB2C, "NXSPC"},
    {0xDB2F, "PR.NEXT.CHAR"},
    {0xDB35, "DOSPC"},
    {0xDB3A, "STROUT"},
    {0xDB3D, "STRPRT"},
    {0xDB57, "OUTSP"},
    {0xDB5A, "OUTQUES"},
    {0xDB5C, "OUTDO"},
    {0xDB71, "INPUTERR"},
    {0xDB7B, "READERR"},
    {0xDB7F, "ERLIN"},
    {0xDB86, "INPERR"},
    {0xDB87, "RESPERR"},
    {0xDBA0, "GET"},
    {0xDBB2, "INPUT"},
    {0xDBDC, "NXIN"},
    {0xDBE2, "READ"},
    {0xDBE9, "INPUT.FLAG.ZERO"},
    {0xDBEB, "PROCESS.INPUT.LIST"},
    {0xDBF1, "PROCESS.INPUT.ITEM"},
    {0xDC2B, "INSTART"},
    {0xDC69, "INPUT.DATA"},
    {0xDC72, "INPUT.MORE"},
    {0xDC99, "INPFIN"},
    {0xDCA0, "FINDATA"},
    {0xDCC6, "INPDONE"},
    {0xDCDF, "ERR.EXTRA"},
    {0xDCEF, "ERR.REENTRY"},
    {0xDCF9, "NEXT"},
    {0xDCFF, "NEXT.1"},
    {0xDD02, "NEXT.2"},
    {0xDD0D, "GERR"},
    {0xDD0F, "NEXT.3"},
    {0xDD67, "FRMNUM"},
    {0xDD6A, "CHKNUM"},
    {0xDD6C, "CHKSTR"},
    {0xDD6D, "CHKVAL"},
    {0xDD78, "JERROR"},
    {0xDD7B, "FRMEVL"},
    {0xDD86, "FRMEVL.1"},
    {0xDD95, "FRMEVL.2"},
    {0xDDCD, "FRM.PRECEDENCE.TEST"},
    {0xDDD6, "NXOP"},
    {0xDDD7, "SAVOP"},
    {0xDDE4, "FRM.RELATIONAL"},
    {0xDDF6, "PREFNC"},
    {0xDDFD, "FRM.RECURSE"},
    {0xDE0D, "SNTXERR"},
    {0xDE10, "FRM.STACK.1"},
    {0xDE15, "FRM.STACK.2"},
    {0xDE20, "FRM.STACK.3"},
    {0xDE35, "NOTMATH"},
    {0xDE38, "GOEX"},
    {0xDE3A, "FRM.PERFORM.1"},
    {0xDE43, "FRM.PERFORM.2"},
    {0xDE5D, "EXIT"},
    {0xDE60, "FRM.ELEMENT"},
    {0xDE81, "STRTXT"},
    {0xDE90, "NOT."},
    {0xDE98, "EQUOP"},
    {0xDEA4, "FN."},
    {0xDEAB, "SGN."},
    {0xDEB2, "PARCHK"},
    {0xDEB8, "CHKCLS"},
    {0xDEBB, "CHKOPN"},
    {0xDEBE, "CHKCOM"},
    {0xDEC0, "SYNCHR"},
    {0xDEC9, "SYNERR"},
    {0xDECE, "MIN"},
    {0xDED0, "EQUL"},
    {0xDED5, "FRM.VARIABLE"},
    {0xDED7, "FRM.VARIABLE.CALL"},
    {0xDEF9, "SCREEN"},
    {0xDF0C, "UNARY"},
    {0xDF4F, "OR"},
    {0xDF55, "AND"},
    {0xDF5D, "FALSE"},
    {0xDF60, "TRUE"},
    {0xDF65, "RELOPS"},
    {0xDF7D, "STRCMP"},
    {0xDFAA, "STRCMP.1"},
    {0xDFB0, "NUMCMP"},
    {0xDFB5, "STRCMP.2"},
    {0xDFC1, "CMPDONE"},
    {0xDFCD, "PDL"},
    {0xDFD6, "NXDIM"},
    {0xDFD9, "DIM"},
    {0xDFE3, "PTRGET"},
    {0xDFE8, "PTRGET2"},
    {0xDFEA, "PTRGET3"},
    {0xDFF4, "BADNAM"},
    {0xDFF7, "NAMOK"},
    {0xE007, "PTRGET4"},
    {0xE07D, "ISLETC"},
    {0xE087, "NAME.NOT.FOUND"},
    {0xE09A, "C.ZERO"},
    {0xE09C, "MAKE.NEW.VARIABLE"},
    {0xE0DE, "SET.VARPNT.AND.YA"},
    {0xE0ED, "GETARY"},
    {0xE0EF, "GETARY2"},
    {0xE0FE, "NEG32768"},
    {0xE102, "MAKINT"},
    {0xE108, "MKINT"},
    {0xE10C, "AYINT"},
    {0xE119, "MI1"},
    {0xE11B, "MI2"},
    {0xE11E, "ARRAY"},
    {0xE196, "SUBERR"},
    {0xE199, "IQERR"},
    {0xE19B, "JER"},
    {0xE19E, "USE.OLD.ARRAY"},
    {0xE1B8, "MAKE.NEW.ARRAY"},
    {0xE24B, "FIND.ARRAY.ELEMENT"},
    {0xE253, "FAE.1"},
    {0xE269, "GSE"},
    {0xE26C, "GME"},
    {0xE26F, "FAE.2"},
    {0xE270, "FAE.3"},
    {0xE2AC, "RTS.9"},
    {0xE2AD, "MULTIPLY.SUBSCRIPT"},
    {0xE2B6, "MULTIPLY.SUBS.1"},
    {0xE2DE, "FRE"},
    {0xE2F2, "GIVAYF"},
    {0xE2FF, "POS"},
    {0xE301, "SNGFLT"},
    {0xE306, "ERRDIR"},
    {0xE30E, "UNDFNC"},
    {0xE313, "DEF"},
    {0xE341, "FNC."},
    {0xE354, "FUNCT"},
    {0xE3AF, "FNCDATA"},
    {0xE3C5, "STR"},
    {0xE3D5, "STRINI"},
    {0xE3DD, "STRSPA"},
    {0xE3E7, "STRLIT"},
    {0xE3ED, "STRLT2"},
    {0xE42A, "PUTNEW"},
    {0xE432, "JERR"},
    {0xE435, "PUTEMP"},
    {0xE452, "GETSPA"},
    {0xE484, "GARBAG"},
    {0xE488, "FIND.HIGHEST.STRING"},
    {0xE519, "CHECK.SIMPLE.VARIABLE"},
    {0xE523, "CHECK.VARIABLE"},
    {0xE552, "CHECK.BUMP"},
    {0xE55D, "CHECK.EXIT"},
    {0xE562, "MOVE.HIGHEST.STRING.TO.TOP"},
    {0xE597, "CAT"},
    {0xE5D4, "MOVINS"},
    {0xE5E2, "MOVSTR"},
    {0xE5E6, "MOVSTR.1"},
    {0xE5FD, "FRESTR"},
    {0xE600, "FREFAC"},
    {0xE604, "FRETMP"},
    {0xE635, "FRETMS"},
    {0xE646, "CHRSTR"},
    {0xE65A, "LEFTSTR"},
    {0xE660, "SUBSTRING.1"},
    {0xE667, "SUBSTRING.2"},
    {0xE668, "SUBSTRING.3"},
    {0xE686, "RIGHTSTR"},
    {0xE691, "MIDSTR"},
    {0xE6B9, "SUBSTRING.SETUP"},
    {0xE6D6, "LEN"},
    {0xE6DC, "GETSTR"},
    {0xE6E5, "ASC"},
    {0xE6F2, "GOIQ"},
    {0xE6F5, "GTBYTC"},
    {0xE6F8, "GETBYT"},
    {0xE6FB, "CONINT"},
    {0xE707, "VAL"},
    {0xE73D, "POINT"},
    {0xE746, "GTNUM"},
    {0xE74C, "COMBYTE"},
    {0xE752, "GETADR"},
    {0xE764, "PEEK"},
    {0xE77B, "POKE"},
    {0xE784, "WAIT"},
    {0xE79F, "RTS.10"},
    {0xE7A0, "FADDH"},
    {0xE7A7, "FSUB"},
    {0xE7AA, "FSUBT"},
    {0xE7B9, "FADD.1"},
    {0xE7BE, "FADD"},
    {0xE7C1, "FADDT"},
    {0xE7CE, "FADD.2"},
    {0xE7FA, "FADD.3"},
    {0xE829, "NORMALIZE.FAC.1"},
    {0xE82E, "NORMALIZE.FAC.2"},
    {0xE84E, "ZERO.FAC"},
    {0xE850, "STA.IN.FAC.SIGN.AND.EXP"},
    {0xE852, "STA.IN.FAC.SIGN"},
    {0xE855, "FADD.4"},
    {0xE874, "NORMALIZE.FAC.3"},
    {0xE880, "NORMALIZE.FAC.4"},
    {0xE88D, "NORMALIZE.FAC.5"},
    {0xE88F, "NORMALIZE.FAC.6"},
    {0xE89D, "RTS.11"},
    {0xE89E, "COMPLEMENT.FAC"},
    {0xE8A4, "COMPLEMENT.FAC.MANTISSA"},
    {0xE8C6, "INCREMENT.FAC.MANTISSA"},
    {0xE8D4, "RTS.12"},
    {0xE8D5, "OVERFLOW"},
    {0xE8DA, "SHIFT.RIGHT.1"},
    {0xE8DC, "SHIFT.RIGHT.2"},
    {0xE8F0, "SHIFT.RIGHT"},
    {0xE8FD, "L"},
    // 0xE8FD, "SHIFT.RIGHT.3" },
    {0xE907, "SHIFT.RIGHT.4"},
    {0xE911, "SHIFT.RIGHT.5"},
    {0xE913, "CON.ONE"},
    {0xE918, "POLY.LOG"},
    {0xE92D, "CON.SQR.HALF"},
    {0xE932, "CON.SQR.TWO"},
    {0xE937, "CON.NEG.HALF"},
    {0xE93C, "CON.LOG.TWO"},
    {0xE941, "LOG"},
    {0xE948, "GIQ"},
    {0xE94B, "LOG.2"},
    {0xE97F, "FMULT"},
    {0xE982, "FMULTT"},
    {0xE9B0, "MULTIPLY.1"},
    {0xE9B5, "MULTIPLY.2"},
    {0xE9E2, "RTS.13"},
    {0xE9E3, "LOAD.ARG.FROM.YA"},
    {0xEA0E, "ADD.EXPONENTS"},
    {0xEA10, "ADD.EXPONENTS.1"},
    {0xEA2B, "OUTOFRNG"},
    {0xEA31, "ZERO"},
    {0xEA36, "JOV"},
    {0xEA39, "MUL10"},
    {0xEA50, "CON.TEN"},
    {0xEA55, "DIV10"},
    {0xEA5E, "DIV"},
    {0xEA66, "FDIV"},
    {0xEA69, "FDIVT"},
    {0xEAE6, "COPY.RESULT.INTO.FAC"},
    {0xEAF9, "LOAD.FAC.FROM.YA"},
    {0xEB1E, "STORE.FAC.IN.TEMP2.ROUNDED"},
    {0xEB21, "STORE.FAC.IN.TEMP1.ROUNDED"},
    {0xEB27, "SETFOR"},
    {0xEB2B, "STORE.FAC.AT.YX.ROUNDED"},
    {0xEB53, "COPY.ARG.TO.FAC"},
    {0xEB55, "MFA"},
    {0xEB63, "COPY.FAC.TO.ARG.ROUNDED"},
    {0xEB66, "MAF"},
    {0xEB71, "RTS.14"},
    {0xEB72, "ROUND.FAC"},
    {0xEB7A, "INCREMENT.MANTISSA"},
    {0xEB82, "SIGN"},
    {0xEB86, "SIGN1"},
    {0xEB88, "SIGN2"},
    {0xEB8F, "RTS.15"},
    {0xEB90, "SGN"},
    {0xEB93, "FLOAT"},
    {0xEB9B, "FLOAT.1"},
    {0xEBA0, "FLOAT.2"},
    {0xEBAF, "ABS"},
    {0xEBB2, "FCOMP"},
    {0xEBB4, "FCOMP2"},
    {0xEBF2, "QINT"},
    {0xEC11, "RTS.16"},
    {0xEC12, "QINT.2"},
    {0xEC23, "INT"},
    {0xEC40, "QINT.3"},
    {0xEC49, "RTS.17"},
    {0xEC4A, "FIN"},
    {0xEC61, "FIN.1"},
    {0xEC64, "FIN.2"},
    {0xEC66, "FIN.3"},
    {0xEC87, "FIN.4"},
    {0xEC8A, "FIN.5"},
    {0xEC8C, "FIN.6"},
    {0xEC98, "FIN.10"},
    {0xEC9E, "FIN.7"},
    {0xECA0, "FIN.8"},
    {0xECC1, "FIN.9"},
    {0xECD5, "ADDACC"},
    {0xECE8, "GETEXP"},
    {0xED0A, "CON.99999999.9"},
    {0xED0F, "CON.999999999"},
    {0xED14, "CON.BILLION"},
    {0xED19, "INPRT"},
    {0xED24, "LINPRT"},
    {0xED2E, "PRINT.FAC"},
    {0xED31, "GO.STROUT"},
    {0xED34, "FOUT"},
    {0xED36, "FOUT.1"},
    {0xED8C, "FOUT.2"},
    {0xEE17, "FOUT.3"},
    {0xEE57, "FOUT.4"},
    {0xEE5A, "FOUT.5"},
    {0xEE5F, "FOUT.6"},
    {0xEE64, "CON.HALF"},
    {0xEE69, "DECTBL"},
    // 0xEE8D, "DECTBL.END" },
    {0xEE8D, "SQR"},
    {0xEE97, "FPWRT"},
    {0xEED0, "NEGOP"},
    {0xEEDA, "RTS.18"},
    {0xEEDB, "CON.LOG.E"},
    {0xEEE0, "POLY.EXP"},
    {0xEF09, "EXP"},
    {0xEF5C, "POLYNOMIAL.ODD"},
    {0xEF72, "POLYNOMIAL"},
    {0xEF76, "SERMAIN"},
    {0xEFA5, "RTS.19"},
    {0xEFA6, "CON.RND.1"},
    {0xEFAA, "CON.RND.2"},
    {0xEFAE, "RND"},
    {0xEFE7, "GO.MOVMF"},
    {0xEFEA, "COS"},
    {0xEFF1, "SIN"},
    {0xF023, "SIN.1"},
    {0xF026, "SIN.2"},
    {0xF03A, "TAN"},
    {0xF062, "TAN.1"},
    {0xF066, "CON.PI.HALF"},
    {0xF06B, "CON.PI.DOUB"},
    {0xF070, "QUARTER"},
    {0xF075, "POLY.SIN"},
    {0xF09E, "ATN"},
    {0xF0CD, "RTS.20"},
    {0xF0CE, "POLY.ATN"},
    {0xF10B, "GENERIC.CHRGET"},
    {0xF128, "COLD.START"},
    // 0xF128, "GENERIC.END" },
    {0xF1D5, "CALL"},
    {0xF1DE, "IN.NUMBER"},
    {0xF1E5, "PR.NUMBER"},
    {0xF1EC, "PLOTFNS"},
    {0xF206, "GOERR"},
    {0xF209, "LINCOOR"},
    {0xF225, "PLOT"},
    {0xF232, "HLIN"},
    {0xF241, "VLIN"},
    {0xF24F, "COLOR"},
    {0xF256, "VTAB"},
    {0xF262, "SPEED"},
    {0xF26D, "TRACE"},
    {0xF26F, "NOTRACE"},
    {0xF273, "NORMAL"},
    {0xF277, "INVERSE"},
    {0xF279, "N.I."},
    {0xF27B, "N.I.F."},
    {0xF280, "FLASH"},
    {0xF286, "HIMEM"},
    {0xF296, "JMM"},
    {0xF299, "SETHI"},
    {0xF2A6, "LOMEM"},
    {0xF2CB, "ONERR"},
    {0xF2E9, "HANDLERR"},
    {0xF318, "RESUME"},
    {0xF32E, "JSYN"},
    {0xF331, "DEL"},
    {0xF390, "GR"},
    {0xF399, "TEXT"},
    {0xF39F, "STORE"},
    {0xF3BC, "RECALL"},
    {0xF3D8, "HGR2"},
    {0xF3E2, "HGR"},
    {0xF3EA, "SETHPG"},
    {0xF3F2, "HCLR"},
    {0xF3F6, "BKGND"},
    {0xF411, "HPOSN"},
    {0xF457, "HPLOT0"},
    {0xF465, "MOVE.LEFT.OR.RIGHT"},
    {0xF46E, "LR.1"},
    {0xF471, "LR.2"},
    {0xF476, "LR.3"},
    {0xF478, "LR.4"},
    {0xF47E, "COLOR.SHIFT"},
    {0xF48A, "MOVE.RIGHT"},
    {0xF49C, "LRUDX1"},
    {0xF49D, "LRUDX2"},
    {0xF4B3, "LRUD1"},
    {0xF4B4, "LRUD2"},
    {0xF4C4, "LRUD3"},
    {0xF4C8, "LRUD4"},
    {0xF4CD, "CON.03"},
    {0xF4D3, "MOVE.UP.OR.DOWN"},
    {0xF501, "UD.1"},
    {0xF505, "MOVE.DOWN"},
    {0xF508, "CON.04"},
    {0xF530, "HLINRL"},
    {0xF53A, "HGLIN"},
    {0xF57C, "MOVEX"},
    {0xF581, "MOVEX2"},
    {0xF5B2, "MSKTBL"},
    {0xF5B9, "CON.1C"},
    {0xF5BA, "COSINE.TABLE"},
    {0xF5CB, "HFIND"},
    {0xF600, "RTS.22"},
    {0xF601, "DRAW0"},
    {0xF605, "DRAW1"},
    {0xF65D, "XDRAW0"},
    {0xF661, "XDRAW1"},
    {0xF6B9, "HFNS"},
    {0xF6E6, "GGERR"},
    {0xF6E9, "HCOLOR"},
    {0xF6F5, "RTS.23"},
    {0xF6F6, "COLORTBL"},
    {0xF6FE, "HPLOT"},
    {0xF721, "ROT"},
    {0xF727, "SCALE"},
    {0xF72D, "DRWPNT"},
    {0xF769, "DRAW"},
    {0xF76F, "XDRAW"},
    {0xF775, "SHLOAD"},
    {0xF7BC, "TAPEPNT"},
    {0xF7D9, "GETARYPT"},
    {0xF7E7, "HTAB"},
    {0xF800, "MON.PLOT"},
    {0xF819, "MON.HLINE"},
    {0xF828, "MON.VLINE"},
    {0xF864, "MON.SETCOL"},
    {0xF871, "MON.SCRN"},
    {0xFB1E, "MON.PREAD"},
    {0xFB39, "MON.SETTXT"},
    {0xFB40, "MON.SETGR"},
    {0xFB5B, "MON.TABV"},
    {0xFC58, "MON.HOME"},
    {0xFCA8, "MON.WAIT"},
    {0xFCFA, "MON.RD2BIT"},
    {0xFD0C, "MON.RDKEY"},
    {0xFD6A, "MON.GETLN"},
    {0xFDED, "MON.COUT"},
    {0xFE8B, "MON.INPORT"},
    {0xFE95, "MON.OUTPORT"},
    {0xFECD, "MON.WRITE"},
    {0xFEFD, "MON.READ"},
    {0xFF02, "MON.READ2"},
};

const char *findApple2Symbol(unsigned offset) {
  static_assert(sizeof(uintptr_t) > sizeof(unsigned), "unsigbed must fit in const void*");

  const auto *elem = (const SymDef *)bsearch(
      (const void *)(uintptr_t)offset,
      s_symbols,
      sizeof(s_symbols) / sizeof(s_symbols[0]),
      sizeof(s_symbols[0]),
      [](const void *_key, const void *_elem) {
        auto key = (unsigned)(uintptr_t)_key;
        const auto *elem = (const SymDef *)_elem;
        return key < elem->addr ? -1 : key == elem->addr ? 0 : 1;
      });

  return elem ? elem->name : nullptr;
}

std::string apple2SymbolResolver(CPUInst inst) {
  if (cpuAddrModeHasOperand(inst.addrMode) && inst.addrMode != CPUAddrMode::Imm) {
    if (const char *name = findApple2Symbol(inst.operand))
      return name;
  }
  return {};
}
