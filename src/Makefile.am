lib_LTLIBRARIES = libmcm.la
check_PROGRAMS = mathtest

# libconfigfiles_la_SOURCES = grammar.yy  lexer.ll  parser.h  token.h lexer.h config_creator.h configfile.h configfile.cpp
libmcm_la_SOURCES = 	vectors.c matrix.c camera-matrices.c
mathtest_SOURCES = main.c vectors.c matrix.c matrix-test.c camera-matrices.c

TESTS = $(check_PROGRAMS)

# for bison/flex
# AM_CPPFLAGS = -Isrc/
# AM_YFLAGS = -d -p__yacc_prefix__
# AM_LFLAGS = -P__lex_prefix__ -o lex.yy.c

library_includedir = $(includedir)/$(PACKAGE)-$(VERSION)
library_include_HEADERS = libmcm.h vectors.h matrix.h camera-matrices.h operators.h

# setting c++ flags:
# AM_CXXFLAGS = -Wall -ansi -pedantic -ggdb -pg

# setting c preprocessor flags for main project
libmcm_la_CPPFLAGS = -D PACKAGE=\"$(PACKAGE)\" -D VERSION=\"$(VERSION)\"

library_nonversioned_includedir = $(includedir)/$(PACKAGE)

install-data-hook:
	@test -L $(library_nonversioned_includedir) && echo "   !!!   The nonversioned library include dir <$(library_nonversioned_includedir)> is already covered by a link. You'll have to update yourself". || true
	test -L $(library_nonversioned_includedir) || ln -s $(library_includedir) $(library_nonversioned_includedir)

