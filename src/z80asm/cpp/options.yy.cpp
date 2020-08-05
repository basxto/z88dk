// cpp/options.yy.cpp generated by reflex 2.0.1 from cpp/options.l

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_dotall              true
#define REFLEX_OPTION_fast                true
#define REFLEX_OPTION_freespace           true
#define REFLEX_OPTION_header_file         "cpp/options.yy.h"
#define REFLEX_OPTION_lex                 lex
#define REFLEX_OPTION_lexer               OptionsLexer
#define REFLEX_OPTION_noline              true
#define REFLEX_OPTION_outfile             "cpp/options.yy.cpp"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top user code                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


	// silence warnings from RE-flex
	#ifdef _MSC_VER
	#pragma warning(disable:4102)
	#pragma warning(disable:4800)
	#else
	#ifdef __GNUC__
	//#pragma GCC   diagnostic ignored "-Wignored-qualifiers"
	#else
	#ifdef __clang__
	//#pragma clang diagnostic ignored "-Wignored-qualifiers"
	#endif
	#endif
	#endif

	#include "Arch.h"
	#include "Cpu.h"
	#include "Options.h"

	#include <string>
	#include <utility>
	#include <vector>

	#include <cassert>
	#include <climits>
	#include <cstring>
	#include <cstdlib>


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class OptionsLexer : public reflex::AbstractLexer<reflex::Matcher> {
 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  OptionsLexer(
      const reflex::Input& input = reflex::Input(),
      std::ostream&        os    = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
  }
  static const int INITIAL = 0;
  virtual int lex();
  int lex(
      const reflex::Input& input,
      std::ostream        *os = NULL)
  {
    in(input);
    if (os)
      out(*os);
    return lex();
  }
};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %{ user code %}                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// z80asm restart
// Copyright (C) Paulo Custodio, 2011-2020
// License: The Artistic License 2.0, http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------


	static int parseNum(const std::string& text);
	static void optionDefine(const std::string& text);
	static void optionInludePath(const std::string& text);
	static void optionLibraryPath(const std::string& text);


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

extern void reflex_code_INITIAL(reflex::Matcher&);

int OptionsLexer::lex()
{
  static const reflex::Pattern PATTERN_INITIAL(reflex_code_INITIAL);
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
  }
  while (true)
  {
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
              return int();
            }
            else
            {
              out().put(matcher().input());
            }
            break;
          case 1: // rule at line 53: -v\z :
{ theOptions.verbose = true; return true; }
            break;
          case 2: // rule at line 54: -\?\z|-h\z :
{ ExitManual(); }

            break;
          case 3: // rule at line 56: -mz80\z :
{ theCpu.Init(Cpu::Type::Z80); return true; }
            break;
          case 4: // rule at line 57: -mz80n\z :
{ theCpu.Init(Cpu::Type::Z80N); return true; }
            break;
          case 5: // rule at line 58: -mz180\z :
{ theCpu.Init(Cpu::Type::Z180); return true; }
            break;
          case 6: // rule at line 59: -mr2k\z :
{ theCpu.Init(Cpu::Type::R2K); return true; }
            break;
          case 7: // rule at line 60: -mr3k\z :
{ theCpu.Init(Cpu::Type::R3K); return true; }
            break;
          case 8: // rule at line 61: -m8080\z :
{ theCpu.Init(Cpu::Type::I8080); return true; }
            break;
          case 9: // rule at line 62: -m8085\z :
{ theCpu.Init(Cpu::Type::I8085); return true; }
            break;
          case 10: // rule at line 63: -mgbz80\z :
{ theCpu.Init(Cpu::Type::GBZ80); return true; }
            break;
          case 11: // rule at line 64: -mti83\z :
{ theCpu.Init(Cpu::Type::Z80);
				  theArch.Init(Arch::Type::TI83);
				  return true; }
            break;
          case 12: // rule at line 67: -mti83plus\z :
{ theCpu.Init(Cpu::Type::Z80);
				  theArch.Init(Arch::Type::TI83PLUS);
				  return true; }
            break;
          case 13: // rule at line 70: -IXIY\z :
{ theOptions.swapIxIy = true; return true; }
            break;
          case 14: // rule at line 71: -opt-speed\z :
{ theOptions.optimizeSpeed = true; return true; }
            break;
          case 15: // rule at line 72: -debug\z :
{ theOptions.debugInfo = true;
				  theOptions.doMapFile = true;
				  return true; }
            break;
          case 16: // rule at line 75: -m\z :
{ theOptions.doMapFile = true; return true; }
            break;
          case 17: // rule at line 76: -I[\x00-\xff]+\z :
{ optionInludePath(text() + 2);  return true; }
            break;
          case 18: // rule at line 77: -L[\x00-\xff]+\z :
{ optionLibraryPath(text() + 2);  return true; }
            break;
          case 19: // rule at line 78: -D(?:[A-Z_a-z][0-9A-Z_a-z]*)(?:=(?:(?:0[Xx][0-9A-Fa-f]+|\$[0-9A-Fa-f]+|[0-9][0-9A-Fa-f]*[Hh])|(?:[0-9]+)))?\z :
{
				  optionDefine(text() + 2); return true; }

            break;
          case 20: // rule at line 81: [\x00-\xff] :
{ return false; }

            break;
        }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 3: user code                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


// parse NUM
static int parseNum(const std::string& text) {
	char *end = nullptr;
	const char *p = text.c_str();
	long lval;
	int radix;
	char suffix = '\0';

	if (p[0] == '\0') {		// empty
		return -1;
	}
	else if (p[0] == '$') {
		p++;
		radix = 16;
	}
	else if (p[0] == '0' && tolower(p[1]) == 'x') {
		p += 2;
		radix = 16;
	}
	else if (isdigit(p[0]) && tolower(p[strlen(p)-1]) == 'h') {
		suffix = p[strlen(p) - 1];
		radix = 16;
	}
	else {
		radix = 10;
	}

	lval = strtol(p, &end, radix);
	if (end == nullptr || *end != suffix || errno == ERANGE || lval < 0 || lval > INT_MAX)
		return -1;
	else
		return static_cast<int>(lval);
}

static void optionDefine(const std::string& text) {
	using namespace std;

	auto p = text.find('=');
	if (p == string::npos) {		// -Dvar
		theOptions.defines.push_back({ text, 1});
	}
	else {							// -Dvar=value
		string name = text.substr(0, p);
		int num = parseNum(text.c_str() + p + 1);
		assert(num >= 0);

		theOptions.defines.push_back({ name, num});
	}
}

static void optionInludePath(const std::string& text) {
	theOptions.includePath.push_back(text);
}

static void optionLibraryPath(const std::string& text) {
	theOptions.libraryPath.push_back(text);
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  TABLES                                                                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

#if defined(OS_WIN)
#pragma warning(disable:4101 4102)
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-label"
#elif defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-label"
#endif

void reflex_code_INITIAL(reflex::Matcher& m)
{
  int c0 = 0, c1 = 0;
  m.FSM_INIT(c1);

S0:
  m.FSM_FIND();
  c1 = m.FSM_CHAR();
  if (c1 == '-') goto S2;
  if (0 <= c1) goto S13;
  return m.FSM_HALT(c1);

S2:
  m.FSM_TAKE(20);
  c1 = m.FSM_CHAR();
  if (c1 == 'v') goto S15;
  if (c1 == 'o') goto S30;
  if (c1 == 'm') goto S21;
  if (c1 == 'h') goto S19;
  if (c1 == 'd') goto S32;
  if (c1 == 'L') goto S34;
  if (c1 == 'I') goto S28;
  if (c1 == 'D') goto S35;
  if (c1 == '?') goto S17;
  return m.FSM_HALT(c1);

S13:
  m.FSM_TAKE(20);
  return m.FSM_HALT();

S15:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(1, c1);
  }
  return m.FSM_HALT(c1);

S17:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(2, c1);
  }
  return m.FSM_HALT(c1);

S19:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(2, c1);
  }
  return m.FSM_HALT(c1);

S21:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(16, c1);
  }
  if (c1 == 'z') goto S43;
  if (c1 == 't') goto S53;
  if (c1 == 'r') goto S46;
  if (c1 == 'g') goto S51;
  if (c1 == '8') goto S49;
  return m.FSM_HALT(c1);

S28:
  c1 = m.FSM_CHAR();
  if (c1 == 'X') goto S57;
  if (0 <= c1) goto S60;
  return m.FSM_HALT(c1);

S30:
  c1 = m.FSM_CHAR();
  if (c1 == 'p') goto S62;
  return m.FSM_HALT(c1);

S32:
  c1 = m.FSM_CHAR();
  if (c1 == 'e') goto S64;
  return m.FSM_HALT(c1);

S34:
  c1 = m.FSM_CHAR();
  if (0 <= c1) goto S66;
  return m.FSM_HALT(c1);

S35:
  c1 = m.FSM_CHAR();
  if ('a' <= c1 && c1 <= 'z') goto S68;
  if (c1 == '_') goto S68;
  if ('A' <= c1 && c1 <= 'Z') goto S68;
  return m.FSM_HALT(c1);

S39:
  m.FSM_TAKE(1);
  return m.FSM_HALT();

S41:
  m.FSM_TAKE(2);
  return m.FSM_HALT();

S43:
  c1 = m.FSM_CHAR();
  if (c1 == '8') goto S75;
  if (c1 == '1') goto S77;
  return m.FSM_HALT(c1);

S46:
  c1 = m.FSM_CHAR();
  if (c1 == '3') goto S81;
  if (c1 == '2') goto S79;
  return m.FSM_HALT(c1);

S49:
  c1 = m.FSM_CHAR();
  if (c1 == '0') goto S83;
  return m.FSM_HALT(c1);

S51:
  c1 = m.FSM_CHAR();
  if (c1 == 'b') goto S85;
  return m.FSM_HALT(c1);

S53:
  c1 = m.FSM_CHAR();
  if (c1 == 'i') goto S87;
  return m.FSM_HALT(c1);

S55:
  m.FSM_TAKE(16);
  return m.FSM_HALT();

S57:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(17, c1);
  }
  if (c1 == 'I') goto S89;
  if (0 <= c1) goto S60;
  return m.FSM_HALT(c1);

S60:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(17, c1);
  }
  if (0 <= c1) goto S60;
  return m.FSM_HALT(c1);

S62:
  c1 = m.FSM_CHAR();
  if (c1 == 't') goto S94;
  return m.FSM_HALT(c1);

S64:
  c1 = m.FSM_CHAR();
  if (c1 == 'b') goto S96;
  return m.FSM_HALT(c1);

S66:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(18, c1);
  }
  if (0 <= c1) goto S66;
  return m.FSM_HALT(c1);

S68:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  if ('a' <= c1 && c1 <= 'z') goto S68;
  if (c1 == '_') goto S68;
  if ('A' <= c1 && c1 <= 'Z') goto S68;
  if (c1 == '=') goto S102;
  if ('0' <= c1 && c1 <= '9') goto S68;
  return m.FSM_HALT(c1);

S75:
  c1 = m.FSM_CHAR();
  if (c1 == '0') goto S106;
  return m.FSM_HALT(c1);

S77:
  c1 = m.FSM_CHAR();
  if (c1 == '8') goto S109;
  return m.FSM_HALT(c1);

S79:
  c1 = m.FSM_CHAR();
  if (c1 == 'k') goto S111;
  return m.FSM_HALT(c1);

S81:
  c1 = m.FSM_CHAR();
  if (c1 == 'k') goto S113;
  return m.FSM_HALT(c1);

S83:
  c1 = m.FSM_CHAR();
  if (c1 == '8') goto S115;
  return m.FSM_HALT(c1);

S85:
  c1 = m.FSM_CHAR();
  if (c1 == 'z') goto S118;
  return m.FSM_HALT(c1);

S87:
  c1 = m.FSM_CHAR();
  if (c1 == '8') goto S120;
  return m.FSM_HALT(c1);

S89:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(17, c1);
  }
  if (c1 == 'Y') goto S122;
  if (0 <= c1) goto S60;
  return m.FSM_HALT(c1);

S92:
  m.FSM_TAKE(17);
  return m.FSM_HALT();

S94:
  c1 = m.FSM_CHAR();
  if (c1 == '-') goto S124;
  return m.FSM_HALT(c1);

S96:
  c1 = m.FSM_CHAR();
  if (c1 == 'u') goto S126;
  return m.FSM_HALT(c1);

S98:
  m.FSM_TAKE(18);
  return m.FSM_HALT();

S100:
  m.FSM_TAKE(19);
  return m.FSM_HALT();

S102:
  c1 = m.FSM_CHAR();
  if ('1' <= c1 && c1 <= '9') goto S141;
  if (c1 == '0') goto S128;
  if (c1 == '$') goto S137;
  return m.FSM_HALT(c1);

S106:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(3, c1);
  }
  if (c1 == 'n') goto S150;
  return m.FSM_HALT(c1);

S109:
  c1 = m.FSM_CHAR();
  if (c1 == '0') goto S152;
  return m.FSM_HALT(c1);

S111:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(6, c1);
  }
  return m.FSM_HALT(c1);

S113:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(7, c1);
  }
  return m.FSM_HALT(c1);

S115:
  c1 = m.FSM_CHAR();
  if (c1 == '5') goto S160;
  if (c1 == '0') goto S158;
  return m.FSM_HALT(c1);

S118:
  c1 = m.FSM_CHAR();
  if (c1 == '8') goto S162;
  return m.FSM_HALT(c1);

S120:
  c1 = m.FSM_CHAR();
  if (c1 == '3') goto S164;
  return m.FSM_HALT(c1);

S122:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(13, c1);
  }
  if (0 <= c1) goto S60;
  return m.FSM_HALT(c1);

S124:
  c1 = m.FSM_CHAR();
  if (c1 == 's') goto S169;
  return m.FSM_HALT(c1);

S126:
  c1 = m.FSM_CHAR();
  if (c1 == 'g') goto S171;
  return m.FSM_HALT(c1);

S128:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  if (c1 == 'x') goto S173;
  if (c1 == 'h') goto S183;
  if ('a' <= c1 && c1 <= 'f') goto S177;
  if (c1 == 'X') goto S173;
  if (c1 == 'H') goto S183;
  if ('A' <= c1 && c1 <= 'F') goto S177;
  if ('0' <= c1 && c1 <= '9') goto S141;
  return m.FSM_HALT(c1);

S137:
  c1 = m.FSM_CHAR();
  if ('a' <= c1 && c1 <= 'f') goto S186;
  if ('A' <= c1 && c1 <= 'F') goto S186;
  if ('0' <= c1 && c1 <= '9') goto S186;
  return m.FSM_HALT(c1);

S141:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  if (c1 == 'h') goto S183;
  if ('a' <= c1 && c1 <= 'f') goto S177;
  if (c1 == 'H') goto S183;
  if ('A' <= c1 && c1 <= 'F') goto S177;
  if ('0' <= c1 && c1 <= '9') goto S141;
  return m.FSM_HALT(c1);

S148:
  m.FSM_TAKE(3);
  return m.FSM_HALT();

S150:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(4, c1);
  }
  return m.FSM_HALT(c1);

S152:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(5, c1);
  }
  return m.FSM_HALT(c1);

S154:
  m.FSM_TAKE(6);
  return m.FSM_HALT();

S156:
  m.FSM_TAKE(7);
  return m.FSM_HALT();

S158:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(8, c1);
  }
  return m.FSM_HALT(c1);

S160:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(9, c1);
  }
  return m.FSM_HALT(c1);

S162:
  c1 = m.FSM_CHAR();
  if (c1 == '0') goto S199;
  return m.FSM_HALT(c1);

S164:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(11, c1);
  }
  if (c1 == 'p') goto S203;
  return m.FSM_HALT(c1);

S167:
  m.FSM_TAKE(13);
  return m.FSM_HALT();

S169:
  c1 = m.FSM_CHAR();
  if (c1 == 'p') goto S205;
  return m.FSM_HALT(c1);

S171:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(15, c1);
  }
  return m.FSM_HALT(c1);

S173:
  c1 = m.FSM_CHAR();
  if ('a' <= c1 && c1 <= 'f') goto S209;
  if ('A' <= c1 && c1 <= 'F') goto S209;
  if ('0' <= c1 && c1 <= '9') goto S209;
  return m.FSM_HALT(c1);

S177:
  c1 = m.FSM_CHAR();
  if (c1 == 'h') goto S214;
  if ('a' <= c1 && c1 <= 'f') goto S177;
  if (c1 == 'H') goto S214;
  if ('A' <= c1 && c1 <= 'F') goto S177;
  if ('0' <= c1 && c1 <= '9') goto S177;
  return m.FSM_HALT(c1);

S183:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  if ('0' <= c1 && c1 <= '9') goto S183;
  return m.FSM_HALT(c1);

S186:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  if ('a' <= c1 && c1 <= 'f') goto S186;
  if ('A' <= c1 && c1 <= 'F') goto S186;
  if ('0' <= c1 && c1 <= '9') goto S186;
  return m.FSM_HALT(c1);

S191:
  m.FSM_TAKE(4);
  return m.FSM_HALT();

S193:
  m.FSM_TAKE(5);
  return m.FSM_HALT();

S195:
  m.FSM_TAKE(8);
  return m.FSM_HALT();

S197:
  m.FSM_TAKE(9);
  return m.FSM_HALT();

S199:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(10, c1);
  }
  return m.FSM_HALT(c1);

S201:
  m.FSM_TAKE(11);
  return m.FSM_HALT();

S203:
  c1 = m.FSM_CHAR();
  if (c1 == 'l') goto S218;
  return m.FSM_HALT(c1);

S205:
  c1 = m.FSM_CHAR();
  if (c1 == 'e') goto S220;
  return m.FSM_HALT(c1);

S207:
  m.FSM_TAKE(15);
  return m.FSM_HALT();

S209:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  if ('a' <= c1 && c1 <= 'f') goto S209;
  if ('A' <= c1 && c1 <= 'F') goto S209;
  if ('0' <= c1 && c1 <= '9') goto S209;
  return m.FSM_HALT(c1);

S214:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(19, c1);
  }
  return m.FSM_HALT(c1);

S216:
  m.FSM_TAKE(10);
  return m.FSM_HALT();

S218:
  c1 = m.FSM_CHAR();
  if (c1 == 'u') goto S222;
  return m.FSM_HALT(c1);

S220:
  c1 = m.FSM_CHAR();
  if (c1 == 'e') goto S224;
  return m.FSM_HALT(c1);

S222:
  c1 = m.FSM_CHAR();
  if (c1 == 's') goto S226;
  return m.FSM_HALT(c1);

S224:
  c1 = m.FSM_CHAR();
  if (c1 == 'd') goto S228;
  return m.FSM_HALT(c1);

S226:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(12, c1);
  }
  return m.FSM_HALT(c1);

S228:
  c1 = m.FSM_CHAR();
  if (m.FSM_META_EOB(c1)) {
    m.FSM_TAKE(14, c1);
  }
  return m.FSM_HALT(c1);

S230:
  m.FSM_TAKE(12);
  return m.FSM_HALT();

S232:
  m.FSM_TAKE(14);
  return m.FSM_HALT();
}

